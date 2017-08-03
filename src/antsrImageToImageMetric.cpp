
#include <algorithm>
#include <vector>
#include <string>
#include <RcppANTsR.h>

#include "antsUtilities.h"
#include "itkDisplacementFieldTransform.h"
#include "itkImageToImageMetricv4.h"
#include "itkMeanSquaresImageToImageMetricv4.h"
#include "itkCorrelationImageToImageMetricv4.h"
#include "itkMattesMutualInformationImageToImageMetricv4.h"
#include "itkANTSNeighborhoodCorrelationImageToImageMetricv4.h"
#include "itkDemonsImageToImageMetricv4.h"
#include "itkJointHistogramMutualInformationImageToImageMetricv4.h"
#include "itkImageMaskSpatialObject.h"
#include "itkMersenneTwisterRandomVariateGenerator.h"
#include "itkImageRandomConstIteratorWithIndex.h"

template< class ImageType >
SEXP antsrImageToImageMetric( std::string type, SEXP r_fixed, SEXP r_moving )
{
  typedef typename ImageType::Pointer           ImagePointerType;

  ImagePointerType fixed = Rcpp::as<ImagePointerType>( r_fixed );
  ImagePointerType moving = Rcpp::as<ImagePointerType>( r_moving );

  //supportedTypes = c("MeanSquares", "MattesMutualInformation", "ANTSNeighborhoodCorrelation", "Correlation", "Demons", "JointHistogramMutualInformation")
  if ( type == "MeanSquares" ) {
    typedef itk::MeanSquaresImageToImageMetricv4<ImageType,ImageType> MetricType;
    typename MetricType::Pointer metric = MetricType::New();
    metric->SetFixedImage( fixed );
    metric->SetMovingImage( moving );
    return( Rcpp::wrap(metric) );
  }
  else if ( type == "Correlation" ) {
    typedef itk::CorrelationImageToImageMetricv4<ImageType,ImageType> MetricType;
    typename MetricType::Pointer metric = MetricType::New();
    metric->SetFixedImage( fixed );
    metric->SetMovingImage( moving );
    return( Rcpp::wrap(metric) );
  }
  else if ( type == "ANTSNeighborhoodCorrelation" ) {
    typedef itk::ANTSNeighborhoodCorrelationImageToImageMetricv4<ImageType,ImageType> MetricType;
    typename MetricType::Pointer metric = MetricType::New();
    metric->SetFixedImage( fixed );
    metric->SetMovingImage( moving );

    return( Rcpp::wrap(metric) );
  }
  else if ( type == "Demons" ) {
    typedef itk::DemonsImageToImageMetricv4<ImageType,ImageType> MetricType;
    typename MetricType::Pointer metric = MetricType::New();
    metric->SetFixedImage( fixed );
    metric->SetMovingImage( moving );

    /* This block needed to prevent exception on call to Initialize() */
    typedef itk::DisplacementFieldTransform<typename MetricType::InternalComputationValueType,
      ImageType::ImageDimension> TransformType;
    typedef typename TransformType::DisplacementFieldType     DisplacementFieldType;

    typename DisplacementFieldType::Pointer itkField = DisplacementFieldType::New();
    itkField->SetRegions( moving->GetLargestPossibleRegion() );
    itkField->SetSpacing( moving->GetSpacing() );
    itkField->SetOrigin( moving->GetOrigin() );
    itkField->SetDirection( moving->GetDirection() );
    itkField->Allocate();
    //itkField->FillBuffer(0);

    typename TransformType::Pointer idTransform = TransformType::New();
    idTransform->SetDisplacementField( itkField );

    metric->SetMovingTransform( idTransform );
    return( Rcpp::wrap(metric) );
  }
  else if ( type == "MattesMutualInformation" ) {
    typedef itk::MattesMutualInformationImageToImageMetricv4<ImageType,ImageType> MetricType;
    typename MetricType::Pointer metric = MetricType::New();
    metric->SetFixedImage( fixed );
    metric->SetMovingImage( moving );
   return( Rcpp::wrap(metric) );
  }
  else if ( type == "JointHistogramMutualInformation" ) {
    typedef itk::JointHistogramMutualInformationImageToImageMetricv4<ImageType,ImageType> MetricType;
    typename MetricType::Pointer metric = MetricType::New();
    metric->SetFixedImage( fixed );
    metric->SetMovingImage( moving );
    return( Rcpp::wrap(metric) );
  }
  else {
    Rcpp::Rcout << "Invalid metric type: " << type << std::endl;
  }
  return( Rcpp::wrap(NA_REAL) );
}

//pixeltype, precision, dimension, type, isVector
RcppExport SEXP antsrImageToImageMetric( SEXP r_pixeltype,
  SEXP r_dimension, SEXP r_type, SEXP r_isVector, SEXP r_fixed, SEXP r_moving )
{
try
{
  std::string pixeltype = Rcpp::as< std::string >( r_pixeltype );
  std::string type = Rcpp::as< std::string >( r_type );
  unsigned int dimension = Rcpp::as< int >( r_dimension );

  unsigned int isVector = Rcpp::as< int >( r_isVector ); // unused for now
  if ( isVector ) {
    Rcpp::stop("Multichannel images not yet supported");
  }

  if ( (dimension < 1) || (dimension > 4) )
    {
    Rcpp::stop("Unsupported image dimension");
    }

  if( pixeltype == "double" )
    {
    typedef double PixelType;
    if( dimension == 4 )
	    {
      typedef itk::Image<PixelType,4> ImageType;
      return antsrImageToImageMetric<ImageType>( type, r_fixed, r_moving );
      }
    else if( dimension == 3 )
	    {
      typedef itk::Image<PixelType,3> ImageType;
      return antsrImageToImageMetric<ImageType>( type, r_fixed, r_moving );
	    }
    else if( dimension == 2 )
	    {
      typedef itk::Image<PixelType,2> ImageType;
      return antsrImageToImageMetric<ImageType>( type, r_fixed, r_moving );
	    }
	  }
  else if( pixeltype == "float" )
    {
    typedef float PixelType;
    if( dimension == 4 )
	    {
      typedef itk::Image<PixelType,4> ImageType;
      return antsrImageToImageMetric<ImageType>( type, r_fixed, r_moving );
      }
    else if( dimension == 3 )
	    {
      typedef itk::Image<PixelType,3> ImageType;
      return antsrImageToImageMetric<ImageType>( type, r_fixed, r_moving );
	    }
    else if( dimension == 2 )
	    {
      typedef itk::Image<PixelType,2> ImageType;
      return antsrImageToImageMetric<ImageType>( type, r_fixed, r_moving );
	    }
    }
  else {
    Rcpp::stop("Only float and double images are supported");
  }

  return( Rcpp::wrap(NA_REAL) );

}
catch( itk::ExceptionObject & err )
  {
  Rcpp::Rcout << "ITK ExceptionObject caught !" << std::endl;
  Rcpp::Rcout << err << std::endl;
  Rcpp::stop("ITK exception caught");
  }
catch( const std::exception& exc )
  {
  forward_exception_to_r( exc ) ;
  }
catch(...)
  {
	Rcpp::stop("c++ exception (unknown reason)");
  }
return Rcpp::wrap(NA_REAL); //not reached
}


template< class MetricType >
void antsrImageToImageMetric_SetFixedImage( SEXP r_metric, SEXP r_antsimage, bool isMask )
{
  typedef typename MetricType::FixedImageType   ImageType;
  typedef typename ImageType::Pointer           ImagePointerType;
  typedef typename MetricType::Pointer          MetricPointerType;
  typedef itk::ImageMaskSpatialObject<ImageType::ImageDimension>  ImageMaskSpatialObjectType;
  typedef typename ImageMaskSpatialObjectType::ImageType          MaskImageType;

  MetricPointerType metric = Rcpp::as<MetricPointerType>( r_metric );
  ImagePointerType image = Rcpp::as<ImagePointerType>( r_antsimage );

  if ( isMask ) {
    typename ImageMaskSpatialObjectType::Pointer mask = ImageMaskSpatialObjectType::New();
    typedef itk::CastImageFilter<ImageType,MaskImageType> CastFilterType;
    typename CastFilterType::Pointer cast = CastFilterType::New();
    cast->SetInput( image );
    cast->Update();
    mask->SetImage( cast->GetOutput() );
    metric->SetMovingImageMask(mask);
  }
  else {
    metric->SetFixedImage(image);
  }

}

//pixeltype, precision, dimension, type, isVector
RcppExport SEXP antsrImageToImageMetric_SetFixedImage( SEXP r_metric,
  SEXP r_antsimage, SEXP r_isMask )
{
try
{
  //Rcpp::Rcout << "antsrImageToImageMetric_SetFixedImage()" << std::endl;

  Rcpp::S4 antsmetric( r_metric ) ;
  std::string pixeltype = Rcpp::as< std::string >( antsmetric.slot( "pixeltype" ) );
  unsigned int dimension = Rcpp::as< int >( antsmetric.slot( "dimension" ) );
  //bool isVector = Rcpp::as<bool>( antsmetric.slot("isVector") );
  bool isMask = Rcpp::as<bool>( r_isMask );

  //Rcpp::Rcout << "Pixeltype: " << pixeltype << std::endl;

  //if ( isVector ) {
  //  Rcpp::stop("Multichannel images not yet supported");
  //}

  if ( (dimension < 1) || (dimension > 4) )
    {
    Rcpp::stop("Unsupported image dimension");
    }

  if( pixeltype == "double" )
    {
    typedef double PixelType;
    if( dimension == 4 )
	    {
      typedef itk::Image<PixelType,4> ImageType;
      typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
      antsrImageToImageMetric_SetFixedImage<MetricType>( r_metric, r_antsimage, isMask );
      }
    else if( dimension == 3 )
	    {
      typedef itk::Image<PixelType,3> ImageType;
      typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
      antsrImageToImageMetric_SetFixedImage<MetricType>( r_metric, r_antsimage, isMask  );
	    }
    else if( dimension == 2 )
	    {
      typedef itk::Image<PixelType,2> ImageType;
      typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
      antsrImageToImageMetric_SetFixedImage<MetricType>( r_metric, r_antsimage, isMask  );
	    }
	  }
  else if( pixeltype == "float" )
    {
    typedef float PixelType;
    if( dimension == 4 )
	    {
      typedef itk::Image<PixelType,4> ImageType;
      typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
      antsrImageToImageMetric_SetFixedImage<MetricType>( r_metric, r_antsimage, isMask  );
      }
    else if( dimension == 3 )
	    {
      typedef itk::Image<PixelType,3> ImageType;
      typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
      antsrImageToImageMetric_SetFixedImage<MetricType>( r_metric, r_antsimage, isMask  );
	    }
    else if( dimension == 2 )
	    {
      typedef itk::Image<PixelType,2> ImageType;
      typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
      antsrImageToImageMetric_SetFixedImage<MetricType>( r_metric, r_antsimage, isMask  );
	    }
    }
  else {
    Rcpp::stop("Only float and double images are supported");
  }

  return( Rcpp::wrap(NA_REAL) );

}
catch( itk::ExceptionObject & err )
  {
  Rcpp::Rcout << "ITK ExceptionObject caught !" << std::endl;
  Rcpp::Rcout << err << std::endl;
  Rcpp::stop("ITK exception caught");
  }
catch( const std::exception& exc )
  {
  forward_exception_to_r( exc ) ;
  }
catch(...)
  {
	Rcpp::stop("c++ exception (unknown reason)");
  }
return Rcpp::wrap(NA_REAL); //not reached
}


template< class MetricType >
void antsrImageToImageMetric_SetMovingImage( SEXP r_metric, SEXP r_antsimage, bool isMask )
{
  typedef typename MetricType::MovingImageType  ImageType;
  typedef typename ImageType::Pointer           ImagePointerType;
  typedef typename MetricType::Pointer          MetricPointerType;
  typedef itk::ImageMaskSpatialObject<ImageType::ImageDimension>  ImageMaskSpatialObjectType;
  typedef typename ImageMaskSpatialObjectType::ImageType          MaskImageType;


  MetricPointerType metric = Rcpp::as<MetricPointerType>( r_metric );
  ImagePointerType image = Rcpp::as<ImagePointerType>( r_antsimage );

  if ( isMask ) {
    typename ImageMaskSpatialObjectType::Pointer mask = ImageMaskSpatialObjectType::New();
    typedef itk::CastImageFilter<ImageType,MaskImageType> CastFilterType;
    typename CastFilterType::Pointer cast = CastFilterType::New();
    cast->SetInput( image );
    cast->Update();
    mask->SetImage( cast->GetOutput() );
    metric->SetMovingImageMask(mask);
  }
  else {
    metric->SetMovingImage(image);
  }

}

//pixeltype, precision, dimension, type, isVector
RcppExport SEXP antsrImageToImageMetric_SetMovingImage( SEXP r_metric,
  SEXP r_antsimage, SEXP r_isMask )
{
try
{
  //Rcpp::Rcout << "antsrImageToImageMetric_SetMovingImage()" << std::endl;

  Rcpp::S4 antsmetric( r_metric ) ;
  std::string pixeltype = Rcpp::as< std::string >( antsmetric.slot( "pixeltype" ) );
  unsigned int dimension = Rcpp::as< int >( antsmetric.slot( "dimension" ) );
  bool isMask = Rcpp::as<bool>( r_isMask );

  //if ( isVector ) {
  //  Rcpp::stop("Multichannel images not yet supported");
  //}

  if ( (dimension < 1) || (dimension > 4) )
    {
    Rcpp::stop("Unsupported image dimension");
    }

  if( pixeltype == "double" )
    {
    typedef double PixelType;
    if( dimension == 4 )
	    {
      typedef itk::Image<PixelType,4> ImageType;
      typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
      antsrImageToImageMetric_SetMovingImage<MetricType>( r_metric, r_antsimage, isMask  );
      }
    else if( dimension == 3 )
	    {
      typedef itk::Image<PixelType,3> ImageType;
      typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
      antsrImageToImageMetric_SetMovingImage<MetricType>( r_metric, r_antsimage, isMask  );
	    }
    else if( dimension == 2 )
	    {
      typedef itk::Image<PixelType,2> ImageType;
      typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
      antsrImageToImageMetric_SetMovingImage<MetricType>( r_metric, r_antsimage, isMask  );
	    }
	  }
  else if( pixeltype == "float" )
    {
    typedef float PixelType;
    if( dimension == 4 )
	    {
      typedef itk::Image<PixelType,4> ImageType;
      typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
      antsrImageToImageMetric_SetMovingImage<MetricType>( r_metric, r_antsimage, isMask  );
      }
    else if( dimension == 3 )
	    {
      typedef itk::Image<PixelType,3> ImageType;
      typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
      antsrImageToImageMetric_SetMovingImage<MetricType>( r_metric, r_antsimage, isMask  );
	    }
    else if( dimension == 2 )
	    {
      typedef itk::Image<PixelType,2> ImageType;
      typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
      antsrImageToImageMetric_SetMovingImage<MetricType>( r_metric, r_antsimage, isMask  );
	    }
    }
  else {
    Rcpp::stop("Only float and double images are supported");
  }

  return( Rcpp::wrap(NA_REAL) );

}
catch( itk::ExceptionObject & err )
  {
  Rcpp::Rcout << "ITK ExceptionObject caught !" << std::endl;
  Rcpp::Rcout << err << std::endl;
  Rcpp::stop("ITK exception caught");
  }
catch( const std::exception& exc )
  {
  forward_exception_to_r( exc ) ;
  }
catch(...)
  {
	Rcpp::stop("c++ exception (unknown reason)");
  }
return Rcpp::wrap(NA_REAL); //not reached
}


template< class MetricType >
SEXP antsrImageToImageMetric_GetValue( SEXP r_metric )
{
  //Rcpp::Rcout << "antsrImageToImageMetric_GetValue<MetricType>()" << std::endl;
  typedef typename MetricType::Pointer          MetricPointerType;
  MetricPointerType metric = Rcpp::as<MetricPointerType>( r_metric );
  return Rcpp::wrap( metric->GetValue() );
}

//pixeltype, precision, dimension, type, isVector
RcppExport SEXP antsrImageToImageMetric_GetValue( SEXP r_metric )
{
try
{
  //Rcpp::Rcout << "antsrImageToImageMetric_GetValue()" << std::endl;

  Rcpp::S4 antsmetric( r_metric );

  std::string pixeltype = Rcpp::as< std::string >( antsmetric.slot( "pixeltype" ) );
  unsigned int dimension = Rcpp::as< int >( antsmetric.slot( "dimension" ) );

  //if ( isVector ) {
  //  Rcpp::stop("Multichannel images not yet supported");
  //}

  if ( (dimension < 1) || (dimension > 4) )
    {
    Rcpp::stop("Unsupported image dimension");
    }

  if( pixeltype == "double" )
    {
    typedef double PixelType;
    if( dimension == 4 )
	    {
      typedef itk::Image<PixelType,4> ImageType;
      typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
      return antsrImageToImageMetric_GetValue<MetricType>( r_metric );
      }
    else if( dimension == 3 )
	    {
      typedef itk::Image<PixelType,3> ImageType;
      typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
      return antsrImageToImageMetric_GetValue<MetricType>( r_metric );
	    }
    else if( dimension == 2 )
	    {
      typedef itk::Image<PixelType,2> ImageType;
      typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
      return antsrImageToImageMetric_GetValue<MetricType>( r_metric );
	    }
	  }
  else if( pixeltype == "float" )
    {
    typedef float PixelType;
    if( dimension == 4 )
	    {
      typedef itk::Image<PixelType,4> ImageType;
      typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
      return antsrImageToImageMetric_GetValue<MetricType>( r_metric );
      }
    else if( dimension == 3 )
	    {
      typedef itk::Image<PixelType,3> ImageType;
      typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
      return antsrImageToImageMetric_GetValue<MetricType>( r_metric );
	    }
    else if( dimension == 2 )
	    {
      typedef itk::Image<PixelType,2> ImageType;
      typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
      return antsrImageToImageMetric_GetValue<MetricType>( r_metric );
	    }
    }
  else {
    Rcpp::stop("Only float and double images are supported");
  }

  return( Rcpp::wrap(NA_REAL) );

}
catch( itk::ExceptionObject & err )
  {
  Rcpp::Rcout << "ITK ExceptionObject caught !" << std::endl;
  Rcpp::Rcout << err << std::endl;
  Rcpp::stop("ITK exception caught");
  }
catch( const std::exception& exc )
  {
  forward_exception_to_r( exc ) ;
  }
catch(...)
  {
	Rcpp::stop("c++ exception (unknown reason)");
  }
return Rcpp::wrap(NA_REAL); //not reached
}

template< class MetricType >
void antsrImageToImageMetric_SetSampling( SEXP r_metric, std::string strategy, double percentage )
{
  typedef typename MetricType::MovingImageType  ImageType;
  typedef typename ImageType::Pointer           ImagePointerType;
  typedef typename MetricType::Pointer          MetricPointerType;

  typedef typename MetricType::FixedSampledPointSetType MetricSamplePointSetType;
  typedef typename MetricSamplePointSetType::PointType  SamplePointType;

  typename MetricSamplePointSetType::Pointer samplePointSet = MetricSamplePointSetType::New();
  samplePointSet->Initialize();

  MetricPointerType metric = Rcpp::as<MetricPointerType>( r_metric );

  typedef typename itk::Statistics::MersenneTwisterRandomVariateGenerator RandomizerType;
  typename RandomizerType::Pointer randomizer = RandomizerType::New();
  randomizer->SetSeed( 1234 );

  const typename ImageType::SpacingType oneThirdVirtualSpacing = metric->GetFixedImage()->GetSpacing() / 3.0;
  unsigned long index = 0;

  if ( strategy == "regular" )
    {
    const unsigned long sampleCount = static_cast<unsigned long>( std::ceil( 1.0 / percentage ) );
    unsigned long count = sampleCount; //Start at sampleCount to keep behavior backwards identical, using first element.
    itk::ImageRegionConstIteratorWithIndex<ImageType> It( metric->GetFixedImage(), metric->GetFixedImage()->GetRequestedRegion() );
    for( It.GoToBegin(); !It.IsAtEnd(); ++It )
      {
      if( count == sampleCount )
        {
        count = 0; //Reset counter
        SamplePointType point;
        metric->GetFixedImage()->TransformIndexToPhysicalPoint( It.GetIndex(), point );

        // randomly perturb the point within a voxel (approximately)
        for( unsigned int d = 0; d < ImageType::ImageDimension; d++ )
          {
          point[d] += randomizer->GetNormalVariate() * oneThirdVirtualSpacing[d];
          }
        if( !metric->GetFixedImageMask() || metric->GetFixedImageMask()->IsInside( point ) )
          {
          samplePointSet->SetPoint( index, point );
          ++index;
          }
        }
      ++count;
      }
      metric->SetFixedSampledPointSet( samplePointSet );
      metric->SetUseFixedSampledPointSet( true );
    }
    else if (strategy == "random")
      {
      const unsigned long totalVirtualDomainVoxels = metric->GetFixedImage()->GetRequestedRegion().GetNumberOfPixels();
      const unsigned long sampleCount = static_cast<unsigned long>( static_cast<float>( totalVirtualDomainVoxels ) * percentage );
      itk::ImageRandomConstIteratorWithIndex<ImageType> ItR( metric->GetFixedImage(), metric->GetFixedImage()->GetRequestedRegion() );
      ItR.SetNumberOfSamples( sampleCount );
      for( ItR.GoToBegin(); !ItR.IsAtEnd(); ++ItR )
        {
        SamplePointType point;
        metric->GetFixedImage()->TransformIndexToPhysicalPoint( ItR.GetIndex(), point );

        // randomly perturb the point within a voxel (approximately)
        for ( unsigned int d = 0; d < ImageType::ImageDimension; d++ )
          {
          point[d] += randomizer->GetNormalVariate() * oneThirdVirtualSpacing[d];
          }
        if( !metric->GetFixedImageMask() || metric->GetFixedImageMask()->IsInside( point ) )
          {
          samplePointSet->SetPoint( index, point );
          ++index;
          }
        }
        metric->SetFixedSampledPointSet( samplePointSet );
        metric->SetUseFixedSampledPointSet( true );
      }


}

//pixeltype, precision, dimension, type, isVector
RcppExport SEXP antsrImageToImageMetric_SetSampling( SEXP r_metric,
  SEXP r_strategy, SEXP r_percentage )
{
try
{
  Rcpp::S4 antsmetric( r_metric ) ;
  std::string pixeltype = Rcpp::as< std::string >( antsmetric.slot( "pixeltype" ) );
  unsigned int dimension = Rcpp::as< int >( antsmetric.slot( "dimension" ) );

  std::string strategy = Rcpp::as<std::string>( r_strategy );
  double percentage = Rcpp::as<double>( r_percentage );

  //Rcpp::Rcout << "antsrImageToImageMetric_SetSampling(metric," << strategy <<
  //  "," << percentage << ")" << std::endl;

  //if ( isVector ) {
  //  Rcpp::stop("Multichannel images not yet supported");
  //}

  if ( (dimension < 1) || (dimension > 4) )
    {
    Rcpp::stop("Unsupported image dimension");
    }

  if( pixeltype == "double" )
    {
    typedef double PixelType;
    if( dimension == 4 )
	    {
      typedef itk::Image<PixelType,4> ImageType;
      typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
      antsrImageToImageMetric_SetSampling<MetricType>( r_metric, strategy, percentage  );
      }
    else if( dimension == 3 )
	    {
      typedef itk::Image<PixelType,3> ImageType;
      typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
      antsrImageToImageMetric_SetSampling<MetricType>( r_metric, strategy, percentage  );
	    }
    else if( dimension == 2 )
	    {
      typedef itk::Image<PixelType,2> ImageType;
      typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
      antsrImageToImageMetric_SetSampling<MetricType>( r_metric, strategy, percentage  );
	    }
	  }
  else if( pixeltype == "float" )
    {
    typedef float PixelType;
    if( dimension == 4 )
	    {
      typedef itk::Image<PixelType,4> ImageType;
      typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
      antsrImageToImageMetric_SetSampling<MetricType>( r_metric, strategy, percentage  );
      }
    else if( dimension == 3 )
	    {
      typedef itk::Image<PixelType,3> ImageType;
      typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
      antsrImageToImageMetric_SetSampling<MetricType>( r_metric, strategy, percentage  );
	    }
    else if( dimension == 2 )
	    {
      typedef itk::Image<PixelType,2> ImageType;
      typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
      antsrImageToImageMetric_SetSampling<MetricType>( r_metric, strategy, percentage  );
	    }
    }
  else {
    Rcpp::stop("Only float and double images are supported");
  }

  return( Rcpp::wrap(NA_REAL) );

}
catch( itk::ExceptionObject & err )
  {
  Rcpp::Rcout << "ITK ExceptionObject caught !" << std::endl;
  Rcpp::Rcout << err << std::endl;
  Rcpp::stop("ITK exception caught");
  }
catch( const std::exception& exc )
  {
  forward_exception_to_r( exc ) ;
  }
catch(...)
  {
	Rcpp::stop("c++ exception (unknown reason)");
  }
return Rcpp::wrap(NA_REAL); //not reached
}


template< class MetricType >
void antsrImageToImageMetric_Initialize( SEXP r_metric )
{
  //Rcpp::Rcout << "antsrImageToImageMetric_GetValue<MetricType>()" << std::endl;
  typedef typename MetricType::Pointer          MetricPointerType;
  MetricPointerType metric = Rcpp::as<MetricPointerType>( r_metric );
  metric->Initialize();
}

RcppExport SEXP antsrImageToImageMetric_Initialize( SEXP r_metric )
{
try
{
  //Rcpp::Rcout << "antsrImageToImageMetric_Initialize()" << std::endl;

  Rcpp::S4 antsmetric( r_metric ) ;
  std::string pixeltype = Rcpp::as< std::string >( antsmetric.slot( "pixeltype" ) );
  unsigned int dimension = Rcpp::as< int >( antsmetric.slot( "dimension" ) );

  //if ( isVector ) {
  //  Rcpp::stop("Multichannel images not yet supported");
  //}

  if ( (dimension < 1) || (dimension > 4) )
    {
    Rcpp::stop("Unsupported image dimension");
    }

  if( pixeltype == "double" )
    {
    typedef double PixelType;
    if( dimension == 4 )
	    {
      typedef itk::Image<PixelType,4> ImageType;
      typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
      antsrImageToImageMetric_Initialize<MetricType>( r_metric );
      }
    else if( dimension == 3 )
	    {
      typedef itk::Image<PixelType,3> ImageType;
      typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
      antsrImageToImageMetric_Initialize<MetricType>( r_metric );
	    }
    else if( dimension == 2 )
	    {
      typedef itk::Image<PixelType,2> ImageType;
      typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
      antsrImageToImageMetric_Initialize<MetricType>( r_metric );
	    }
	  }
  else if( pixeltype == "float" )
    {
    typedef float PixelType;
    if( dimension == 4 )
	    {
      typedef itk::Image<PixelType,4> ImageType;
      typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
      antsrImageToImageMetric_Initialize<MetricType>( r_metric );
      }
    else if( dimension == 3 )
	    {
      typedef itk::Image<PixelType,3> ImageType;
      typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
      antsrImageToImageMetric_Initialize<MetricType>( r_metric );
	    }
    else if( dimension == 2 )
	    {
      typedef itk::Image<PixelType,2> ImageType;
      typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
      antsrImageToImageMetric_Initialize<MetricType>( r_metric );
	    }
    }
  else {
    Rcpp::stop("Only float and double images are supported");
  }

  return( Rcpp::wrap(NA_REAL) );

}
catch( itk::ExceptionObject & err )
  {
  Rcpp::Rcout << "ITK ExceptionObject caught !" << std::endl;
  Rcpp::Rcout << err << std::endl;
  Rcpp::stop("ITK exception caught");
  }
catch( const std::exception& exc )
  {
  forward_exception_to_r( exc ) ;
  }
catch(...)
  {
	Rcpp::stop("c++ exception (unknown reason)");
  }
return Rcpp::wrap(NA_REAL); //not reached
}
