#ifndef __RCPPANTSR_IMAGETOIMAGEMETRIC_HPP
#define __RCPPANTSR_IMAGETOIMAGEMETRIC_HPP

#include "itkMacro.h"
#include "itkImage.h"
#include "itkVectorImage.h"
#include "itkVector.h"
#include "itkImageToImageMetricv4.h"
#include <Rcpp.h>

namespace Rcpp {

/*
template <> inline
SEXP wrap( const itk::ImageRegionIteratorWithIndex< itk::IMAGETYPE<PIXELTYPE,DIMENSION> > & iterator )
{
  typedef itk::IMAGETYPE<PIXELTYPE,DIMENSION>          ImageType;
  typedef ImageType::Pointer                           ImagePointerType;
  typedef itk::ImageRegionIteratorWithIndex<ImageType> IteratorType;

  IteratorType* rawPointer = new IteratorType( iterator );
  Rcpp::XPtr< IteratorType > xptr( rawPointer, true ) ;

  Rcpp::S4 itkImageIterator( std::string( "antsImageIterator" ) );
  itkImageIterator.slot( "pixeltype" ) = "PIXELTYPE";
  itkImageIterator.slot( "dimension" ) = DIMENSION;
  itkImageIterator.slot( "components" ) = 1;
  itkImageIterator.slot( "pointer" ) = xptr;

  return(wrap(itkImageIterator));
}
*/


template <> inline
SEXP wrap( const itk::MeanSquaresImageToImageMetricv4< itk::Image<double,2>, itk::Image<double,2> >::Pointer & metric )
{
  typedef itk::Image<double,2>                                    ImageType;
  typedef itk::MeanSquaresImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                     MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                           XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "double";
  itkImageToImageMetric.slot( "dimension" ) = 2;
  itkImageToImageMetric.slot( "type" ) = "MeanSquares";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::MeanSquaresImageToImageMetricv4< itk::Image<double,3>, itk::Image<double,3> >::Pointer & metric )
{
  typedef itk::Image<double,3>                                    ImageType;
  typedef itk::MeanSquaresImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                     MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                           XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "double";
  itkImageToImageMetric.slot( "dimension" ) = 3;
  itkImageToImageMetric.slot( "type" ) = "MeanSquares";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::MeanSquaresImageToImageMetricv4< itk::Image<double,4>, itk::Image<double,4> >::Pointer & metric )
{
  typedef itk::Image<double,4>                                    ImageType;
  typedef itk::MeanSquaresImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                     MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                           XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "double";
  itkImageToImageMetric.slot( "dimension" ) = 4;
  itkImageToImageMetric.slot( "type" ) = "MeanSquares";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::MeanSquaresImageToImageMetricv4< itk::Image<float,2>, itk::Image<float,2> >::Pointer & metric )
{
  typedef itk::Image<float,2>                                    ImageType;
  typedef itk::MeanSquaresImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                     MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                           XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "float";
  itkImageToImageMetric.slot( "dimension" ) = 2;
  itkImageToImageMetric.slot( "type" ) = "MeanSquares";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::MeanSquaresImageToImageMetricv4< itk::Image<float,3>, itk::Image<float,3> >::Pointer & metric )
{
  typedef itk::Image<float,3>                                       ImageType;
  typedef itk::MeanSquaresImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                             XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "float";
  itkImageToImageMetric.slot( "dimension" ) = 3;
  itkImageToImageMetric.slot( "type" ) = "MeanSquares";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::MeanSquaresImageToImageMetricv4< itk::Image<float,4>, itk::Image<float,4> >::Pointer & metric )
{
  typedef itk::Image<float,4>                                    ImageType;
  typedef itk::MeanSquaresImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                     MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                           XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "float";
  itkImageToImageMetric.slot( "dimension" ) = 4;
  itkImageToImageMetric.slot( "type" ) = "MeanSquares";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}


template <> inline
SEXP wrap( const itk::CorrelationImageToImageMetricv4< itk::Image<double,2>, itk::Image<double,2> >::Pointer & metric )
{
  typedef itk::Image<double,2>                                    ImageType;
  typedef itk::CorrelationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                     MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                           XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "double";
  itkImageToImageMetric.slot( "dimension" ) = 2;
  itkImageToImageMetric.slot( "type" ) = "Correlation";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::CorrelationImageToImageMetricv4< itk::Image<double,3>, itk::Image<double,3> >::Pointer & metric )
{
  typedef itk::Image<double,3>                                    ImageType;
  typedef itk::CorrelationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                     MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                           XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "double";
  itkImageToImageMetric.slot( "dimension" ) = 3;
  itkImageToImageMetric.slot( "type" ) = "Correlation";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::CorrelationImageToImageMetricv4< itk::Image<double,4>, itk::Image<double,4> >::Pointer & metric )
{
  typedef itk::Image<double,4>                                    ImageType;
  typedef itk::CorrelationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                     MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                           XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "double";
  itkImageToImageMetric.slot( "dimension" ) = 4;
  itkImageToImageMetric.slot( "type" ) = "Correlation";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::CorrelationImageToImageMetricv4< itk::Image<float,2>, itk::Image<float,2> >::Pointer & metric )
{
  typedef itk::Image<float,2>                                    ImageType;
  typedef itk::CorrelationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                     MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                           XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "float";
  itkImageToImageMetric.slot( "dimension" ) = 2;
  itkImageToImageMetric.slot( "type" ) = "Correlation";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::CorrelationImageToImageMetricv4< itk::Image<float,3>, itk::Image<float,3> >::Pointer & metric )
{
  typedef itk::Image<float,3>                                       ImageType;
  typedef itk::CorrelationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                             XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "float";
  itkImageToImageMetric.slot( "dimension" ) = 3;
  itkImageToImageMetric.slot( "type" ) = "Correlation";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::CorrelationImageToImageMetricv4< itk::Image<float,4>, itk::Image<float,4> >::Pointer & metric )
{
  typedef itk::Image<float,4>                                    ImageType;
  typedef itk::CorrelationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                     MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                           XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "float";
  itkImageToImageMetric.slot( "dimension" ) = 4;
  itkImageToImageMetric.slot( "type" ) = "Correlation";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::ANTSNeighborhoodCorrelationImageToImageMetricv4< itk::Image<double,2>, itk::Image<double,2> >::Pointer & metric )
{
  typedef itk::Image<double,2>                                    ImageType;
  typedef itk::ANTSNeighborhoodCorrelationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                     MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                           XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "double";
  itkImageToImageMetric.slot( "dimension" ) = 2;
  itkImageToImageMetric.slot( "type" ) = "ANTSNeighborhoodCorrelation";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::ANTSNeighborhoodCorrelationImageToImageMetricv4< itk::Image<double,3>, itk::Image<double,3> >::Pointer & metric )
{
  typedef itk::Image<double,3>                                    ImageType;
  typedef itk::ANTSNeighborhoodCorrelationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                     MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                           XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "double";
  itkImageToImageMetric.slot( "dimension" ) = 3;
  itkImageToImageMetric.slot( "type" ) = "ANTSNeighborhoodCorrelation";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::ANTSNeighborhoodCorrelationImageToImageMetricv4< itk::Image<double,4>, itk::Image<double,4> >::Pointer & metric )
{
  typedef itk::Image<double,4>                                    ImageType;
  typedef itk::ANTSNeighborhoodCorrelationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                     MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                           XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "double";
  itkImageToImageMetric.slot( "dimension" ) = 4;
  itkImageToImageMetric.slot( "type" ) = "ANTSNeighborhoodCorrelation";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::ANTSNeighborhoodCorrelationImageToImageMetricv4< itk::Image<float,2>, itk::Image<float,2> >::Pointer & metric )
{
  typedef itk::Image<float,2>                                    ImageType;
  typedef itk::ANTSNeighborhoodCorrelationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                     MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                           XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "float";
  itkImageToImageMetric.slot( "dimension" ) = 2;
  itkImageToImageMetric.slot( "type" ) = "ANTSNeighborhoodCorrelation";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::ANTSNeighborhoodCorrelationImageToImageMetricv4< itk::Image<float,3>, itk::Image<float,3> >::Pointer & metric )
{
  typedef itk::Image<float,3>                                       ImageType;
  typedef itk::ANTSNeighborhoodCorrelationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                             XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "float";
  itkImageToImageMetric.slot( "dimension" ) = 3;
  itkImageToImageMetric.slot( "type" ) = "ANTSNeighborhoodCorrelation";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::ANTSNeighborhoodCorrelationImageToImageMetricv4< itk::Image<float,4>, itk::Image<float,4> >::Pointer & metric )
{
  typedef itk::Image<float,4>                                    ImageType;
  typedef itk::ANTSNeighborhoodCorrelationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                     MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                           XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "float";
  itkImageToImageMetric.slot( "dimension" ) = 4;
  itkImageToImageMetric.slot( "type" ) = "ANTSNeighborhoodCorrelation";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::MattesMutualInformationImageToImageMetricv4< itk::Image<double,2>, itk::Image<double,2> >::Pointer & metric )
{
  typedef itk::Image<double,2>                                    ImageType;
  typedef itk::MattesMutualInformationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                     MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                           XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "double";
  itkImageToImageMetric.slot( "dimension" ) = 2;
  itkImageToImageMetric.slot( "type" ) = "MattesMutualInformation";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::MattesMutualInformationImageToImageMetricv4< itk::Image<double,3>, itk::Image<double,3> >::Pointer & metric )
{
  typedef itk::Image<double,3>                                    ImageType;
  typedef itk::MattesMutualInformationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                     MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                           XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "double";
  itkImageToImageMetric.slot( "dimension" ) = 3;
  itkImageToImageMetric.slot( "type" ) = "MattesMutualInformation";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::MattesMutualInformationImageToImageMetricv4< itk::Image<double,4>, itk::Image<double,4> >::Pointer & metric )
{
  typedef itk::Image<double,4>                                    ImageType;
  typedef itk::MattesMutualInformationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                     MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                           XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "double";
  itkImageToImageMetric.slot( "dimension" ) = 4;
  itkImageToImageMetric.slot( "type" ) = "MattesMutualInformation";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::MattesMutualInformationImageToImageMetricv4< itk::Image<float,2>, itk::Image<float,2> >::Pointer & metric )
{
  typedef itk::Image<float,2>                                    ImageType;
  typedef itk::MattesMutualInformationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                     MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                           XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "float";
  itkImageToImageMetric.slot( "dimension" ) = 2;
  itkImageToImageMetric.slot( "type" ) = "MattesMutualInformation";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::MattesMutualInformationImageToImageMetricv4< itk::Image<float,3>, itk::Image<float,3> >::Pointer & metric )
{
  typedef itk::Image<float,3>                                       ImageType;
  typedef itk::MattesMutualInformationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                             XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "float";
  itkImageToImageMetric.slot( "dimension" ) = 3;
  itkImageToImageMetric.slot( "type" ) = "MattesMutualInformation";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::MattesMutualInformationImageToImageMetricv4< itk::Image<float,4>, itk::Image<float,4> >::Pointer & metric )
{
  typedef itk::Image<float,4>                                    ImageType;
  typedef itk::MattesMutualInformationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                     MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                           XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "float";
  itkImageToImageMetric.slot( "dimension" ) = 4;
  itkImageToImageMetric.slot( "type" ) = "MattesMutualInformation";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::JointHistogramMutualInformationImageToImageMetricv4< itk::Image<double,2>, itk::Image<double,2> >::Pointer & metric )
{
  typedef itk::Image<double,2>                                    ImageType;
  typedef itk::JointHistogramMutualInformationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                     MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                           XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "double";
  itkImageToImageMetric.slot( "dimension" ) = 2;
  itkImageToImageMetric.slot( "type" ) = "JointHistogramMutualInformation";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::JointHistogramMutualInformationImageToImageMetricv4< itk::Image<double,3>, itk::Image<double,3> >::Pointer & metric )
{
  typedef itk::Image<double,3>                                    ImageType;
  typedef itk::JointHistogramMutualInformationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                     MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                           XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "double";
  itkImageToImageMetric.slot( "dimension" ) = 3;
  itkImageToImageMetric.slot( "type" ) = "JointHistogramMutualInformation";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::JointHistogramMutualInformationImageToImageMetricv4< itk::Image<double,4>, itk::Image<double,4> >::Pointer & metric )
{
  typedef itk::Image<double,4>                                    ImageType;
  typedef itk::JointHistogramMutualInformationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                     MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                           XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "double";
  itkImageToImageMetric.slot( "dimension" ) = 4;
  itkImageToImageMetric.slot( "type" ) = "JointHistogramMutualInformation";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::JointHistogramMutualInformationImageToImageMetricv4< itk::Image<float,2>, itk::Image<float,2> >::Pointer & metric )
{
  typedef itk::Image<float,2>                                    ImageType;
  typedef itk::JointHistogramMutualInformationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                     MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                           XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "float";
  itkImageToImageMetric.slot( "dimension" ) = 2;
  itkImageToImageMetric.slot( "type" ) = "JointHistogramMutualInformation";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::JointHistogramMutualInformationImageToImageMetricv4< itk::Image<float,3>, itk::Image<float,3> >::Pointer & metric )
{
  typedef itk::Image<float,3>                                       ImageType;
  typedef itk::JointHistogramMutualInformationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                             XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "float";
  itkImageToImageMetric.slot( "dimension" ) = 3;
  itkImageToImageMetric.slot( "type" ) = "JointHistogramMutualInformation";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::JointHistogramMutualInformationImageToImageMetricv4< itk::Image<float,4>, itk::Image<float,4> >::Pointer & metric )
{
  typedef itk::Image<float,4>                                    ImageType;
  typedef itk::JointHistogramMutualInformationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                     MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                           XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "float";
  itkImageToImageMetric.slot( "dimension" ) = 4;
  itkImageToImageMetric.slot( "type" ) = "JointHistogramMutualInformation";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::DemonsImageToImageMetricv4< itk::Image<double,2>, itk::Image<double,2> >::Pointer & metric )
{
  typedef itk::Image<double,2>                                    ImageType;
  typedef itk::DemonsImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                     MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                           XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "double";
  itkImageToImageMetric.slot( "dimension" ) = 2;
  itkImageToImageMetric.slot( "type" ) = "Demons";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::DemonsImageToImageMetricv4< itk::Image<double,3>, itk::Image<double,3> >::Pointer & metric )
{
  typedef itk::Image<double,3>                                    ImageType;
  typedef itk::DemonsImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                     MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                           XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "double";
  itkImageToImageMetric.slot( "dimension" ) = 3;
  itkImageToImageMetric.slot( "type" ) = "Demons";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::DemonsImageToImageMetricv4< itk::Image<double,4>, itk::Image<double,4> >::Pointer & metric )
{
  typedef itk::Image<double,4>                                    ImageType;
  typedef itk::DemonsImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                     MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                           XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "double";
  itkImageToImageMetric.slot( "dimension" ) = 4;
  itkImageToImageMetric.slot( "type" ) = "Demons";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::DemonsImageToImageMetricv4< itk::Image<float,2>, itk::Image<float,2> >::Pointer & metric )
{
  typedef itk::Image<float,2>                                    ImageType;
  typedef itk::DemonsImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                     MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                           XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "float";
  itkImageToImageMetric.slot( "dimension" ) = 2;
  itkImageToImageMetric.slot( "type" ) = "Demons";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::DemonsImageToImageMetricv4< itk::Image<float,3>, itk::Image<float,3> >::Pointer & metric )
{
  typedef itk::Image<float,3>                                       ImageType;
  typedef itk::DemonsImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                             XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "float";
  itkImageToImageMetric.slot( "dimension" ) = 3;
  itkImageToImageMetric.slot( "type" ) = "Demons";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}

template <> inline
SEXP wrap( const itk::DemonsImageToImageMetricv4< itk::Image<float,4>, itk::Image<float,4> >::Pointer & metric )
{
  typedef itk::Image<float,4>                                    ImageType;
  typedef itk::DemonsImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                     MetricPointerType;
  typedef Rcpp::XPtr<MetricPointerType>                           XPtrType;

  MetricPointerType* rawPointer = new MetricPointerType( metric );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImageToImageMetric( std::string( "antsrImageToImageMetric" ) );
  itkImageToImageMetric.slot( "pixeltype" ) = "float";
  itkImageToImageMetric.slot( "dimension" ) = 4;
  itkImageToImageMetric.slot( "type" ) = "Demons";
  itkImageToImageMetric.slot( "isVector" ) = false;
  itkImageToImageMetric.slot( "pointer" ) = xptr;

  return(wrap(itkImageToImageMetric));
}







template <> inline
itk::MeanSquaresImageToImageMetricv4< itk::Image<double,2>, itk::Image<double,2> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 2;
  typedef itk::Image<double,Dim>                                    ImageType;
  typedef itk::MeanSquaresImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "double") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "MeanSquares") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::MeanSquaresImageToImageMetricv4< itk::Image<double,3>, itk::Image<double,3> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 3;
  typedef itk::Image<double,Dim>                                    ImageType;
  typedef itk::MeanSquaresImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "double") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "MeanSquares") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::MeanSquaresImageToImageMetricv4< itk::Image<double,4>, itk::Image<double,4> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 4;
  typedef itk::Image<double,Dim>                                    ImageType;
  typedef itk::MeanSquaresImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "double") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "MeanSquares") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::MeanSquaresImageToImageMetricv4< itk::Image<float,2>, itk::Image<float,2> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 2;
  typedef itk::Image<float,Dim>                                     ImageType;
  typedef itk::MeanSquaresImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "float") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "MeanSquares") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::MeanSquaresImageToImageMetricv4< itk::Image<float,3>, itk::Image<float,3> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 3;
  typedef itk::Image<float,Dim>                                     ImageType;
  typedef itk::MeanSquaresImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "float") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "MeanSquares") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::MeanSquaresImageToImageMetricv4< itk::Image<float,4>, itk::Image<float,4> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 4;
  typedef itk::Image<float,Dim>                                     ImageType;
  typedef itk::MeanSquaresImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "float") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "MeanSquares") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::CorrelationImageToImageMetricv4< itk::Image<double,2>, itk::Image<double,2> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 2;
  typedef itk::Image<double,Dim>                                    ImageType;
  typedef itk::CorrelationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "double") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "Correlation") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::CorrelationImageToImageMetricv4< itk::Image<double,3>, itk::Image<double,3> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 3;
  typedef itk::Image<double,Dim>                                    ImageType;
  typedef itk::CorrelationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "double") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "Correlation") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::CorrelationImageToImageMetricv4< itk::Image<double,4>, itk::Image<double,4> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 4;
  typedef itk::Image<double,Dim>                                    ImageType;
  typedef itk::CorrelationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "double") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "Correlation") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::CorrelationImageToImageMetricv4< itk::Image<float,2>, itk::Image<float,2> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 2;
  typedef itk::Image<float,Dim>                                     ImageType;
  typedef itk::CorrelationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "float") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "Correlation") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::CorrelationImageToImageMetricv4< itk::Image<float,3>, itk::Image<float,3> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 3;
  typedef itk::Image<float,Dim>                                     ImageType;
  typedef itk::CorrelationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "float") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "Correlation") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::CorrelationImageToImageMetricv4< itk::Image<float,4>, itk::Image<float,4> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 4;
  typedef itk::Image<float,Dim>                                     ImageType;
  typedef itk::CorrelationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "float") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "Correlation") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::ANTSNeighborhoodCorrelationImageToImageMetricv4< itk::Image<double,2>, itk::Image<double,2> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 2;
  typedef itk::Image<double,Dim>                                    ImageType;
  typedef itk::ANTSNeighborhoodCorrelationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "double") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "ANTSNeighborhoodCorrelation") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::ANTSNeighborhoodCorrelationImageToImageMetricv4< itk::Image<double,3>, itk::Image<double,3> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 3;
  typedef itk::Image<double,Dim>                                    ImageType;
  typedef itk::ANTSNeighborhoodCorrelationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "double") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "ANTSNeighborhoodCorrelation") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::ANTSNeighborhoodCorrelationImageToImageMetricv4< itk::Image<double,4>, itk::Image<double,4> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 4;
  typedef itk::Image<double,Dim>                                    ImageType;
  typedef itk::ANTSNeighborhoodCorrelationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "double") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "ANTSNeighborhoodCorrelation") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::ANTSNeighborhoodCorrelationImageToImageMetricv4< itk::Image<float,2>, itk::Image<float,2> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 2;
  typedef itk::Image<float,Dim>                                     ImageType;
  typedef itk::ANTSNeighborhoodCorrelationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "float") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "ANTSNeighborhoodCorrelation") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::ANTSNeighborhoodCorrelationImageToImageMetricv4< itk::Image<float,3>, itk::Image<float,3> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 3;
  typedef itk::Image<float,Dim>                                     ImageType;
  typedef itk::ANTSNeighborhoodCorrelationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "float") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "ANTSNeighborhoodCorrelation") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::ANTSNeighborhoodCorrelationImageToImageMetricv4< itk::Image<float,4>, itk::Image<float,4> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 4;
  typedef itk::Image<float,Dim>                                     ImageType;
  typedef itk::ANTSNeighborhoodCorrelationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "float") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "ANTSNeighborhoodCorrelation") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::MattesMutualInformationImageToImageMetricv4< itk::Image<double,2>, itk::Image<double,2> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 2;
  typedef itk::Image<double,Dim>                                    ImageType;
  typedef itk::MattesMutualInformationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "double") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "MattesMutualInformation") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::MattesMutualInformationImageToImageMetricv4< itk::Image<double,3>, itk::Image<double,3> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 3;
  typedef itk::Image<double,Dim>                                    ImageType;
  typedef itk::MattesMutualInformationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "double") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "MattesMutualInformation") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::MattesMutualInformationImageToImageMetricv4< itk::Image<double,4>, itk::Image<double,4> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 4;
  typedef itk::Image<double,Dim>                                    ImageType;
  typedef itk::MattesMutualInformationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "double") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "MattesMutualInformation") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::MattesMutualInformationImageToImageMetricv4< itk::Image<float,2>, itk::Image<float,2> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 2;
  typedef itk::Image<float,Dim>                                     ImageType;
  typedef itk::MattesMutualInformationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "float") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "MattesMutualInformation") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::MattesMutualInformationImageToImageMetricv4< itk::Image<float,3>, itk::Image<float,3> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 3;
  typedef itk::Image<float,Dim>                                     ImageType;
  typedef itk::MattesMutualInformationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "float") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "MattesMutualInformation") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::MattesMutualInformationImageToImageMetricv4< itk::Image<float,4>, itk::Image<float,4> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 4;
  typedef itk::Image<float,Dim>                                     ImageType;
  typedef itk::MattesMutualInformationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "float") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "MattesMutualInformation") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::JointHistogramMutualInformationImageToImageMetricv4< itk::Image<double,2>, itk::Image<double,2> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 2;
  typedef itk::Image<double,Dim>                                    ImageType;
  typedef itk::JointHistogramMutualInformationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "double") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "JointHistogramMutualInformation") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::JointHistogramMutualInformationImageToImageMetricv4< itk::Image<double,3>, itk::Image<double,3> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 3;
  typedef itk::Image<double,Dim>                                    ImageType;
  typedef itk::JointHistogramMutualInformationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "double") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "JointHistogramMutualInformation") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::JointHistogramMutualInformationImageToImageMetricv4< itk::Image<double,4>, itk::Image<double,4> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 4;
  typedef itk::Image<double,Dim>                                    ImageType;
  typedef itk::JointHistogramMutualInformationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "double") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "JointHistogramMutualInformation") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::JointHistogramMutualInformationImageToImageMetricv4< itk::Image<float,2>, itk::Image<float,2> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 2;
  typedef itk::Image<float,Dim>                                     ImageType;
  typedef itk::JointHistogramMutualInformationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "float") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "JointHistogramMutualInformation") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::JointHistogramMutualInformationImageToImageMetricv4< itk::Image<float,3>, itk::Image<float,3> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 3;
  typedef itk::Image<float,Dim>                                     ImageType;
  typedef itk::JointHistogramMutualInformationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "float") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "JointHistogramMutualInformation") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::JointHistogramMutualInformationImageToImageMetricv4< itk::Image<float,4>, itk::Image<float,4> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 4;
  typedef itk::Image<float,Dim>                                     ImageType;
  typedef itk::JointHistogramMutualInformationImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "float") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "JointHistogramMutualInformation") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::DemonsImageToImageMetricv4< itk::Image<double,2>, itk::Image<double,2> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 2;
  typedef itk::Image<double,Dim>                                    ImageType;
  typedef itk::DemonsImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "double") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "Demons") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::DemonsImageToImageMetricv4< itk::Image<double,3>, itk::Image<double,3> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 3;
  typedef itk::Image<double,Dim>                                    ImageType;
  typedef itk::DemonsImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "double") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "Demons") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::DemonsImageToImageMetricv4< itk::Image<double,4>, itk::Image<double,4> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 4;
  typedef itk::Image<double,Dim>                                    ImageType;
  typedef itk::DemonsImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "double") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "Demons") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::DemonsImageToImageMetricv4< itk::Image<float,2>, itk::Image<float,2> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 2;
  typedef itk::Image<float,Dim>                                     ImageType;
  typedef itk::DemonsImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "float") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "Demons") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::DemonsImageToImageMetricv4< itk::Image<float,3>, itk::Image<float,3> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 3;
  typedef itk::Image<float,Dim>                                     ImageType;
  typedef itk::DemonsImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "float") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "Demons") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::DemonsImageToImageMetricv4< itk::Image<float,4>, itk::Image<float,4> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 4;
  typedef itk::Image<float,Dim>                                     ImageType;
  typedef itk::DemonsImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "float") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) ||
      (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "Demons") )
    {
    Rcpp::stop( "Invalid S4 object type");
    }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::ImageToImageMetricv4< itk::Image<double,2>, itk::Image<double,2> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 2;
  typedef itk::Image<double,Dim>                                    ImageType;
  typedef itk::ImageToImageMetricv4<ImageType,ImageType>            MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "double") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) )
      {
      Rcpp::stop( "Invalid S4 object type (name/pixeltype/dimension)");
      }
  if ( (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "MeanSquares") &&
       (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "Correlation") &&
       (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "MattesMutualInformation") &&
       (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "Demons") &&
       (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "JointHistogramMutualInformation") &&
       (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "ANTSNeighborhoodCorrelation") )
     {
     Rcpp::stop( "Invalid S4 object type (type)");
     }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::ImageToImageMetricv4< itk::Image<double,3>, itk::Image<double,3> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 3;
  typedef itk::Image<double,Dim>                                    ImageType;
  typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "double") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) )
      {
      Rcpp::stop( "Invalid S4 object type (name/pixeltype/dimension)");
      }
  if ( (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "MeanSquares") &&
       (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "Correlation") &&
       (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "MattesMutualInformation") &&
       (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "Demons") &&
       (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "JointHistogramMutualInformation") &&
       (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "ANTSNeighborhoodCorrelation") )
     {
     Rcpp::stop( "Invalid S4 object type (type)");
     }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::ImageToImageMetricv4< itk::Image<double,4>, itk::Image<double,4> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 4;
  typedef itk::Image<double,Dim>                                    ImageType;
  typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "double") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) )
      {
      Rcpp::stop( "Invalid S4 object type (name/pixeltype/dimension)");
      }
  if ( (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "MeanSquares") &&
       (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "Correlation") &&
       (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "MattesMutualInformation") &&
       (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "Demons") &&
       (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "JointHistogramMutualInformation") &&
       (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "ANTSNeighborhoodCorrelation") )
     {
     Rcpp::stop( "Invalid S4 object type (type)");
     }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::ImageToImageMetricv4< itk::Image<float,2>, itk::Image<float,2> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 2;
  typedef itk::Image<float,Dim>                                     ImageType;
  typedef itk::ImageToImageMetricv4<ImageType,ImageType>            MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "float") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) )
      {
      Rcpp::stop( "Invalid S4 object type (name/pixeltype/dimension)");
      }
  if ( (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "MeanSquares") &&
       (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "Correlation") &&
       (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "MattesMutualInformation") &&
       (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "Demons") &&
       (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "JointHistogramMutualInformation") &&
       (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "ANTSNeighborhoodCorrelation") )
     {
     Rcpp::stop( "Invalid S4 object type (type)");
     }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::ImageToImageMetricv4< itk::Image<float,3>, itk::Image<float,3> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 3;
  typedef itk::Image<float,Dim>                                     ImageType;
  typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "float") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) )
      {
      Rcpp::stop( "Invalid S4 object type (name/pixeltype/dimension)");
      }
  if ( (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "MeanSquares") &&
       (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "Correlation") &&
       (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "MattesMutualInformation") &&
       (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "Demons") &&
       (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "JointHistogramMutualInformation") &&
       (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "ANTSNeighborhoodCorrelation") )
     {
     Rcpp::stop( "Invalid S4 object type (type)");
     }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}

template <> inline
itk::ImageToImageMetricv4< itk::Image<float,4>, itk::Image<float,4> >::Pointer as( SEXP itkImageToImageMetricR )
{
  const unsigned int Dim = 4;
  typedef itk::Image<float,Dim>                                     ImageType;
  typedef itk::ImageToImageMetricv4<ImageType,ImageType> MetricType;
  typedef MetricType::Pointer                                       MetricPointerType;

  Rcpp::S4 itkImageMetric( itkImageToImageMetricR );

  if (!itkImageMetric.is( "antsrImageToImageMetric") ||
      (Rcpp::as<std::string>(itkImageMetric.slot("pixeltype")) != "float") ||
      (Rcpp::as<int>(itkImageMetric.slot("dimension")) != Dim) )
      {
      Rcpp::stop( "Invalid S4 object type (name/pixeltype/dimension)");
      }
  if ( (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "MeanSquares") &&
       (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "Correlation") &&
       (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "MattesMutualInformation") &&
       (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "Demons") &&
       (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "JointHistogramMutualInformation") &&
       (Rcpp::as<std::string>(itkImageMetric.slot("type")) != "ANTSNeighborhoodCorrelation") )
     {
     Rcpp::stop( "Invalid S4 object type (type)");
     }

  XPtr<MetricPointerType> xptr( static_cast<SEXP>( itkImageMetric.slot("pointer") ));
  return *xptr;
}



}

#endif
