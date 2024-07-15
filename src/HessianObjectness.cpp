#include <exception>
#include <vector>
#include <string>
#include <algorithm>
#include <ants.h>
#include "antsUtilities.h"
#include "ReadWriteData.h"

#include "itkHessianToObjectnessMeasureImageFilter.h"
#include "itkMultiScaleHessianBasedMeasureImageFilter.h"
#include "itkSymmetricSecondRankTensor.h"
#include "itkNumericTraits.h"

#include "RcppANTsR.h"


template<class PrecisionType, unsigned int Dimension>
SEXP HessianObjectnessHelper(
  SEXP r_inputImage,
  SEXP r_outputImage,
  unsigned int objectDimension,
  bool isBrightObject,
  float sigmaMin,
  float sigmaMax,
  unsigned int numberOfSigmaSteps,
  bool useSigmaLogarithmicSpacing,
  float alpha,
  float beta,
  float gamma,
   bool setScaleObjectnessMeasure )
{

  using ImageType = itk::Image<PrecisionType, Dimension>;
  using ImagePointerType = typename ImageType::Pointer;

  typename ImageType::Pointer inputImage = Rcpp::as< ImagePointerType >( r_inputImage );
  typename ImageType::Pointer outputImage = Rcpp::as< ImagePointerType >( r_outputImage );

  using PixelType = typename ImageType::PixelType;
  const unsigned int ImageDimension = ImageType::ImageDimension;
  using RealPixelType = typename itk::NumericTraits<PixelType>::RealType; 
  
  using HessianPixelType = itk::SymmetricSecondRankTensor<RealPixelType, ImageDimension>;
  using HessianImageType = itk::Image<HessianPixelType, ImageDimension>;
  using ObjectnessFilterType = itk::HessianToObjectnessMeasureImageFilter<HessianImageType, ImageType>;
  using MultiScaleEnhancementFilterType = itk::MultiScaleHessianBasedMeasureImageFilter<ImageType, HessianImageType, ImageType>;

  typename ObjectnessFilterType::Pointer objectnessFilter = ObjectnessFilterType::New();
  objectnessFilter->SetScaleObjectnessMeasure( setScaleObjectnessMeasure );
  objectnessFilter->SetBrightObject( isBrightObject );
  objectnessFilter->SetAlpha( alpha );
  objectnessFilter->SetBeta( beta );
  objectnessFilter->SetGamma( gamma );
  objectnessFilter->SetObjectDimension( objectDimension );

  typename MultiScaleEnhancementFilterType::Pointer multiScaleEnhancementFilter = MultiScaleEnhancementFilterType::New();
  multiScaleEnhancementFilter->SetInput( inputImage );
  if( useSigmaLogarithmicSpacing )
    {
    multiScaleEnhancementFilter->SetSigmaStepMethodToLogarithmic();
    } 
  else 
    {
    multiScaleEnhancementFilter->SetSigmaStepMethodToEquispaced();
    }
  multiScaleEnhancementFilter->SetSigmaMinimum( sigmaMin  );
  multiScaleEnhancementFilter->SetSigmaMaximum( sigmaMax );
  multiScaleEnhancementFilter->SetNumberOfSigmaSteps( numberOfSigmaSteps );
  multiScaleEnhancementFilter->SetHessianToMeasureFilter( objectnessFilter );
  multiScaleEnhancementFilter->Update();

  outputImage = multiScaleEnhancementFilter->GetOutput();
  outputImage->Update();
  outputImage->DisconnectPipeline();

  r_outputImage = Rcpp::wrap( outputImage  );
  return( r_outputImage );
}

// [[Rcpp::export]]
SEXP hessianObjectnessR(
  SEXP r_inputImage,
  SEXP r_objectDimension,
  SEXP r_isBrightObject,
  SEXP r_sigmaMin,
  SEXP r_sigmaMax,
  SEXP r_numberOfSigmaSteps,
  SEXP r_useSigmaLogarithmicSpacing,
  SEXP r_alpha,
  SEXP r_beta,
  SEXP r_gamma,
  SEXP r_setScaleObjectnessMeasure )
{
try
  {
  Rcpp::S4 inputImage( r_inputImage );
  Rcpp::S4 s4_outputImage( r_inputImage );
  SEXP outputImage;

  unsigned int imageDimension = Rcpp::as<int>( inputImage.slot( "dimension" ) );
  std::string pixelType = Rcpp::as<std::string>( inputImage.slot( "pixeltype" ) );

  unsigned int objectDimension = Rcpp::as<int>( r_objectDimension ); 
  bool isBrightObject = Rcpp::as<bool>( r_isBrightObject );
  float sigmaMin = Rcpp::as<float>( r_sigmaMin );
  float sigmaMax = Rcpp::as<float>( r_sigmaMax );
  unsigned int numberOfSigmaSteps = Rcpp::as<int>( r_numberOfSigmaSteps ); 
  bool useSigmaLogarithmicSpacing = Rcpp::as<bool>( r_useSigmaLogarithmicSpacing );
  float alpha = Rcpp::as<float>( r_alpha );
  float beta = Rcpp::as<float>( r_beta );
  float gamma = Rcpp::as<float>( r_gamma );
  bool setScaleObjectnessMeasure = Rcpp::as<bool>( r_setScaleObjectnessMeasure );

  if( pixelType.compare( "float" ) == 0 && imageDimension == 2 )
    {
    typedef float PrecisionType;
    const unsigned int ImageDimension = 2;

    outputImage = HessianObjectnessHelper<PrecisionType, ImageDimension>( 
      inputImage, s4_outputImage, objectDimension, isBrightObject, sigmaMin, 
      sigmaMax, numberOfSigmaSteps, useSigmaLogarithmicSpacing, alpha, 
      beta, gamma, setScaleObjectnessMeasure );
    return( outputImage );  
    }
  else if( pixelType.compare( "float" ) == 0 && imageDimension == 3 )
    {
    typedef float PrecisionType;
    const unsigned int ImageDimension = 3;

    outputImage = HessianObjectnessHelper<PrecisionType, ImageDimension>( 
      inputImage, s4_outputImage, objectDimension, isBrightObject, sigmaMin, 
      sigmaMax, numberOfSigmaSteps, useSigmaLogarithmicSpacing, alpha, 
      beta, gamma, setScaleObjectnessMeasure );
    return( outputImage );
    }
  else
    {
    Rcpp::stop( "Unsupported image dimension or pixeltype." );
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
  Rcpp::stop( "C++ exception (unknown reason)" );
  }

return Rcpp::wrap( NA_REAL ); // should not be reached
}
