#include <exception>
#include <algorithm>
#include <vector>
#include "RcppANTsR.h"

#include "antsUtilities.h"
#include "antsAllocImage.h"
#include <algorithm>

#include "itkVectorIndexSelectionCastImageFilter.h"
#include "itkImageRegionIteratorWithIndex.h"
#include "vnl/algo/vnl_determinant.h"
#include "itkANTSImageRegistrationOptimizer.h"
#include "itkTimeVaryingVelocityFieldIntegrationImageFilter.h"
#include "itkWarpImageFilter.h"
#include "itkTimeVaryingVelocityFieldTransform.h"

#include "itkImageFileWriter.h"

#include "itkRescaleIntensityImageFilter.h"
#include "vnl/algo/vnl_determinant.h"
#include "itkDiscreteGaussianImageFilter.h"
#include "itkVectorLinearInterpolateImageFunction.h"
#include "itkGradientRecursiveGaussianImageFilter.h"
#include "itkVectorCurvatureAnisotropicDiffusionImageFilter.h"
#include "itkLaplacianRecursiveGaussianImageFilter.h"
#include "itkGradientRecursiveGaussianImageFilter.h"

#include "ReadWriteData.h"


template< class ImageType >
void velocityIntegrationHelper(
    SEXP r_refimg,
    std::string r_velocity,
    std::string r_deformation,
    SEXP r_t0,
    SEXP r_t1,
    SEXP r_dt )
{
  using PixelType = typename ImageType::PixelType;
  enum { Dimension = ImageType::ImageDimension };
  PixelType starttime = Rcpp::as< PixelType >( r_t0  );
  PixelType finishtime = Rcpp::as< PixelType >( r_t1  );
  PixelType dT = Rcpp::as< PixelType >( r_dt );
  using VectorType = itk::Vector<PixelType, Dimension>;

  typedef typename ImageType::Pointer       ImagePointerType;
  typename ImageType::Pointer input = Rcpp::as<ImagePointerType>( r_refimg );

  using DisplacementFieldType = itk::Image<VectorType, Dimension>;
  using TimeVaryingVelocityFieldType = itk::Image<VectorType, Dimension + 1>;
  using tvt = TimeVaryingVelocityFieldType;
  typename tvt::Pointer timeVaryingVelocity;

  ReadImage<tvt>(timeVaryingVelocity, r_velocity.c_str() );

  VectorType zero;
  zero.Fill(0);
  typename DisplacementFieldType::Pointer deformation =
    AllocImage<DisplacementFieldType>(input, zero);

  if( starttime < 0 )
    {
    starttime = 0;
    }
  if( starttime > 1 )
    {
    starttime = 1;
    }
  if( finishtime < 0 )
    {
    finishtime = 0;
    }
  if( finishtime > 1 )
    {
    finishtime = 1;
    }

  using IntegratorType = itk::TimeVaryingVelocityFieldIntegrationImageFilter<TimeVaryingVelocityFieldType, DisplacementFieldType>;
  typename IntegratorType::Pointer integrator = IntegratorType::New();
  integrator->SetInput( timeVaryingVelocity );
  integrator->SetLowerTimeBound( starttime );
  integrator->SetUpperTimeBound( finishtime );
  integrator->SetNumberOfIntegrationSteps( static_cast<unsigned int>( std::round( 1.0 / dT ) ) );
  integrator->Update();
  WriteImage<DisplacementFieldType>( integrator->GetOutput(), r_deformation.c_str() );
  return;
}

RcppExport SEXP ANTSIntegrateVelocityField(
  SEXP r_refimg,
  SEXP r_velocity,
  SEXP r_deformation,
  SEXP r_t0,
  SEXP r_t1,
  SEXP r_dt )
{
try
{
  Rcpp::S4 antsImage( r_refimg );
  std::string pixeltype = Rcpp::as< std::string >( antsImage.slot( "pixeltype" ));
  unsigned int dimension = Rcpp::as< int >( antsImage.slot( "dimension" ) );
//  bool physicalSpacing = Rcpp::as< bool >( sigmaInPhysicalCoordinates );
//  Rcpp::NumericVector sigma( r_sigma );
//  unsigned int kernelwidth = Rcpp::as< unsigned int >( r_kernelwidth );

  if ( (pixeltype == "float") & ( dimension == 2 ) )
  {
    typedef float PixelType;
    const unsigned int dim = 2;
    typedef itk::Image< PixelType, dim > ImageType;
    velocityIntegrationHelper< ImageType >( r_refimg,
      Rcpp::as<std::string>(r_velocity),
      Rcpp::as<std::string>(r_deformation),
      r_t0,
      r_t1,
      r_dt );
      return Rcpp::wrap(NA_REAL);
  }
  else if ( (pixeltype == "float") & ( dimension == 3 ) )
  {
    typedef float PixelType;
    const unsigned int dim = 3;
    typedef itk::Image< PixelType, dim > ImageType;
    velocityIntegrationHelper< ImageType >( r_refimg,
      Rcpp::as<std::string>(r_velocity),
      Rcpp::as<std::string>(r_deformation),
      r_t0,
      r_t1,
      r_dt );
      return Rcpp::wrap(NA_REAL);
  }
  else
  {
    Rcpp::stop("Unsupported image dimension or pixel type.");
  }
}

catch( itk::ExceptionObject & err )
{
  Rcpp::Rcout << "ITK ExceptionObject caught!" << std::endl;
  forward_exception_to_r( err );
}
catch( const std::exception& exc )
{
  Rcpp::Rcout << "STD ExceptionObject caught!" << std::endl;
  forward_exception_to_r( exc );
}
catch( ... )
{
  Rcpp::stop( "C++ exception (unknown reason)");
}
 return Rcpp::wrap(NA_REAL); // should not be reached
}
