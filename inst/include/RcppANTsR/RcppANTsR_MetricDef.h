#ifndef __RCPPANTSR_METRIC_H
#define __RCPPANTSR_METRIC_H

#include "itkMacro.h"
#include "itkImage.h"
#include "itkVectorImage.h"
#include "itkVector.h"
#include "itkImageToImageMetricv4.h"
#include "itkMeanSquaresImageToImageMetricv4.h"
#include "itkCorrelationImageToImageMetricv4.h"
#include "itkMattesMutualInformationImageToImageMetricv4.h"
#include "itkANTSNeighborhoodCorrelationImageToImageMetricv4.h"
#include "itkDemonsImageToImageMetricv4.h"
#include "itkJointHistogramMutualInformationImageToImageMetricv4.h"

#include <RcppCommon.h>

namespace Rcpp {

// itk to antsr
template <> inline SEXP wrap( const itk::MeanSquaresImageToImageMetricv4< itk::Image<double,2>, itk::Image<double,2> >::Pointer & metric );
template <> inline SEXP wrap( const itk::MeanSquaresImageToImageMetricv4< itk::Image<double,3>, itk::Image<double,3> >::Pointer & metric );
template <> inline SEXP wrap( const itk::MeanSquaresImageToImageMetricv4< itk::Image<double,4>, itk::Image<double,4> >::Pointer & metric );

template <> inline SEXP wrap( const itk::MeanSquaresImageToImageMetricv4< itk::Image<float,2>, itk::Image<float,2> >::Pointer & metric );
template <> inline SEXP wrap( const itk::MeanSquaresImageToImageMetricv4< itk::Image<float,3>, itk::Image<float,3> >::Pointer & metric );
template <> inline SEXP wrap( const itk::MeanSquaresImageToImageMetricv4< itk::Image<float,4>, itk::Image<float,4> >::Pointer & metric );

template <> inline SEXP wrap( const itk::CorrelationImageToImageMetricv4< itk::Image<double,2>, itk::Image<double,2> >::Pointer & metric );
template <> inline SEXP wrap( const itk::CorrelationImageToImageMetricv4< itk::Image<double,3>, itk::Image<double,3> >::Pointer & metric );
template <> inline SEXP wrap( const itk::CorrelationImageToImageMetricv4< itk::Image<double,4>, itk::Image<double,4> >::Pointer & metric );

template <> inline SEXP wrap( const itk::CorrelationImageToImageMetricv4< itk::Image<float,2>, itk::Image<float,2> >::Pointer & metric );
template <> inline SEXP wrap( const itk::CorrelationImageToImageMetricv4< itk::Image<float,3>, itk::Image<float,3> >::Pointer & metric );
template <> inline SEXP wrap( const itk::CorrelationImageToImageMetricv4< itk::Image<float,4>, itk::Image<float,4> >::Pointer & metric );

template <> inline SEXP wrap( const itk::ANTSNeighborhoodCorrelationImageToImageMetricv4< itk::Image<double,2>, itk::Image<double,2> >::Pointer & metric );
template <> inline SEXP wrap( const itk::ANTSNeighborhoodCorrelationImageToImageMetricv4< itk::Image<double,3>, itk::Image<double,3> >::Pointer & metric );
template <> inline SEXP wrap( const itk::ANTSNeighborhoodCorrelationImageToImageMetricv4< itk::Image<double,4>, itk::Image<double,4> >::Pointer & metric );

template <> inline SEXP wrap( const itk::ANTSNeighborhoodCorrelationImageToImageMetricv4< itk::Image<float,2>, itk::Image<float,2> >::Pointer & metric );
template <> inline SEXP wrap( const itk::ANTSNeighborhoodCorrelationImageToImageMetricv4< itk::Image<float,3>, itk::Image<float,3> >::Pointer & metric );
template <> inline SEXP wrap( const itk::ANTSNeighborhoodCorrelationImageToImageMetricv4< itk::Image<float,4>, itk::Image<float,4> >::Pointer & metric );

template <> inline SEXP wrap( const itk::MattesMutualInformationImageToImageMetricv4< itk::Image<double,2>, itk::Image<double,2> >::Pointer & metric );
template <> inline SEXP wrap( const itk::MattesMutualInformationImageToImageMetricv4< itk::Image<double,3>, itk::Image<double,3> >::Pointer & metric );
template <> inline SEXP wrap( const itk::MattesMutualInformationImageToImageMetricv4< itk::Image<double,4>, itk::Image<double,4> >::Pointer & metric );

template <> inline SEXP wrap( const itk::MattesMutualInformationImageToImageMetricv4< itk::Image<float,2>, itk::Image<float,2> >::Pointer & metric );
template <> inline SEXP wrap( const itk::MattesMutualInformationImageToImageMetricv4< itk::Image<float,3>, itk::Image<float,3> >::Pointer & metric );
template <> inline SEXP wrap( const itk::MattesMutualInformationImageToImageMetricv4< itk::Image<float,4>, itk::Image<float,4> >::Pointer & metric );

template <> inline SEXP wrap( const itk::JointHistogramMutualInformationImageToImageMetricv4< itk::Image<double,2>, itk::Image<double,2> >::Pointer & metric );
template <> inline SEXP wrap( const itk::JointHistogramMutualInformationImageToImageMetricv4< itk::Image<double,3>, itk::Image<double,3> >::Pointer & metric );
template <> inline SEXP wrap( const itk::JointHistogramMutualInformationImageToImageMetricv4< itk::Image<double,4>, itk::Image<double,4> >::Pointer & metric );

template <> inline SEXP wrap( const itk::JointHistogramMutualInformationImageToImageMetricv4< itk::Image<float,2>, itk::Image<float,2> >::Pointer & metric );
template <> inline SEXP wrap( const itk::JointHistogramMutualInformationImageToImageMetricv4< itk::Image<float,3>, itk::Image<float,3> >::Pointer & metric );
template <> inline SEXP wrap( const itk::JointHistogramMutualInformationImageToImageMetricv4< itk::Image<float,4>, itk::Image<float,4> >::Pointer & metric );

template <> inline SEXP wrap( const itk::DemonsImageToImageMetricv4< itk::Image<double,2>, itk::Image<double,2> >::Pointer & metric );
template <> inline SEXP wrap( const itk::DemonsImageToImageMetricv4< itk::Image<double,3>, itk::Image<double,3> >::Pointer & metric );
template <> inline SEXP wrap( const itk::DemonsImageToImageMetricv4< itk::Image<double,4>, itk::Image<double,4> >::Pointer & metric );

template <> inline SEXP wrap( const itk::DemonsImageToImageMetricv4< itk::Image<float,2>, itk::Image<float,2> >::Pointer & metric );
template <> inline SEXP wrap( const itk::DemonsImageToImageMetricv4< itk::Image<float,3>, itk::Image<float,3> >::Pointer & metric );
template <> inline SEXP wrap( const itk::DemonsImageToImageMetricv4< itk::Image<float,4>, itk::Image<float,4> >::Pointer & metric );

// antsr to itk
template <> inline itk::ImageToImageMetricv4< itk::Image<double,2>, itk::Image<double,2> >::Pointer as( SEXP itkImageToImageMetricR );
template <> inline itk::ImageToImageMetricv4< itk::Image<double,3>, itk::Image<double,3> >::Pointer as( SEXP itkImageToImageMetricR );
template <> inline itk::ImageToImageMetricv4< itk::Image<double,4>, itk::Image<double,4> >::Pointer as( SEXP itkImageToImageMetricR );

template <> inline itk::ImageToImageMetricv4< itk::Image<float,2>, itk::Image<float,2> >::Pointer as( SEXP itkImageToImageMetricR );
template <> inline itk::ImageToImageMetricv4< itk::Image<float,3>, itk::Image<float,3> >::Pointer as( SEXP itkImageToImageMetricR );
template <> inline itk::ImageToImageMetricv4< itk::Image<float,4>, itk::Image<float,4> >::Pointer as( SEXP itkImageToImageMetricR );

template <> inline itk::MeanSquaresImageToImageMetricv4< itk::Image<double,2>, itk::Image<double,2> >::Pointer as( SEXP itkImageToImageMetricR );
template <> inline itk::MeanSquaresImageToImageMetricv4< itk::Image<double,3>, itk::Image<double,3> >::Pointer as( SEXP itkImageToImageMetricR );
template <> inline itk::MeanSquaresImageToImageMetricv4< itk::Image<double,4>, itk::Image<double,4> >::Pointer as( SEXP itkImageToImageMetricR );

template <> inline itk::MeanSquaresImageToImageMetricv4< itk::Image<float,2>, itk::Image<float,2> >::Pointer as( SEXP itkImageToImageMetricR );
template <> inline itk::MeanSquaresImageToImageMetricv4< itk::Image<float,3>, itk::Image<float,3> >::Pointer as( SEXP itkImageToImageMetricR );
template <> inline itk::MeanSquaresImageToImageMetricv4< itk::Image<float,4>, itk::Image<float,4> >::Pointer as( SEXP itkImageToImageMetricR );

template <> inline itk::CorrelationImageToImageMetricv4< itk::Image<double,2>, itk::Image<double,2> >::Pointer as( SEXP itkImageToImageMetricR );
template <> inline itk::CorrelationImageToImageMetricv4< itk::Image<double,3>, itk::Image<double,3> >::Pointer as( SEXP itkImageToImageMetricR );
template <> inline itk::CorrelationImageToImageMetricv4< itk::Image<double,4>, itk::Image<double,4> >::Pointer as( SEXP itkImageToImageMetricR );

template <> inline itk::CorrelationImageToImageMetricv4< itk::Image<float,2>, itk::Image<float,2> >::Pointer as( SEXP itkImageToImageMetricR );
template <> inline itk::CorrelationImageToImageMetricv4< itk::Image<float,3>, itk::Image<float,3> >::Pointer as( SEXP itkImageToImageMetricR );
template <> inline itk::CorrelationImageToImageMetricv4< itk::Image<float,4>, itk::Image<float,4> >::Pointer as( SEXP itkImageToImageMetricR );

template <> inline itk::ANTSNeighborhoodCorrelationImageToImageMetricv4< itk::Image<double,2>, itk::Image<double,2> >::Pointer as( SEXP itkImageToImageMetricR );
template <> inline itk::ANTSNeighborhoodCorrelationImageToImageMetricv4< itk::Image<double,3>, itk::Image<double,3> >::Pointer as( SEXP itkImageToImageMetricR );
template <> inline itk::ANTSNeighborhoodCorrelationImageToImageMetricv4< itk::Image<double,4>, itk::Image<double,4> >::Pointer as( SEXP itkImageToImageMetricR );

template <> inline itk::ANTSNeighborhoodCorrelationImageToImageMetricv4< itk::Image<float,2>, itk::Image<float,2> >::Pointer as( SEXP itkImageToImageMetricR );
template <> inline itk::ANTSNeighborhoodCorrelationImageToImageMetricv4< itk::Image<float,3>, itk::Image<float,3> >::Pointer as( SEXP itkImageToImageMetricR );
template <> inline itk::ANTSNeighborhoodCorrelationImageToImageMetricv4< itk::Image<float,4>, itk::Image<float,4> >::Pointer as( SEXP itkImageToImageMetricR );

template <> inline itk::MattesMutualInformationImageToImageMetricv4< itk::Image<double,2>, itk::Image<double,2> >::Pointer as( SEXP itkImageToImageMetricR );
template <> inline itk::MattesMutualInformationImageToImageMetricv4< itk::Image<double,3>, itk::Image<double,3> >::Pointer as( SEXP itkImageToImageMetricR );
template <> inline itk::MattesMutualInformationImageToImageMetricv4< itk::Image<double,4>, itk::Image<double,4> >::Pointer as( SEXP itkImageToImageMetricR );

template <> inline itk::MattesMutualInformationImageToImageMetricv4< itk::Image<float,2>, itk::Image<float,2> >::Pointer as( SEXP itkImageToImageMetricR );
template <> inline itk::MattesMutualInformationImageToImageMetricv4< itk::Image<float,3>, itk::Image<float,3> >::Pointer as( SEXP itkImageToImageMetricR );
template <> inline itk::MattesMutualInformationImageToImageMetricv4< itk::Image<float,4>, itk::Image<float,4> >::Pointer as( SEXP itkImageToImageMetricR );

template <> inline itk::JointHistogramMutualInformationImageToImageMetricv4< itk::Image<double,2>, itk::Image<double,2> >::Pointer as( SEXP itkImageToImageMetricR );
template <> inline itk::JointHistogramMutualInformationImageToImageMetricv4< itk::Image<double,3>, itk::Image<double,3> >::Pointer as( SEXP itkImageToImageMetricR );
template <> inline itk::JointHistogramMutualInformationImageToImageMetricv4< itk::Image<double,4>, itk::Image<double,4> >::Pointer as( SEXP itkImageToImageMetricR );

template <> inline itk::JointHistogramMutualInformationImageToImageMetricv4< itk::Image<float,2>, itk::Image<float,2> >::Pointer as( SEXP itkImageToImageMetricR );
template <> inline itk::JointHistogramMutualInformationImageToImageMetricv4< itk::Image<float,3>, itk::Image<float,3> >::Pointer as( SEXP itkImageToImageMetricR );
template <> inline itk::JointHistogramMutualInformationImageToImageMetricv4< itk::Image<float,4>, itk::Image<float,4> >::Pointer as( SEXP itkImageToImageMetricR );

template <> inline itk::DemonsImageToImageMetricv4< itk::Image<double,2>, itk::Image<double,2> >::Pointer as( SEXP itkImageToImageMetricR );
template <> inline itk::DemonsImageToImageMetricv4< itk::Image<double,3>, itk::Image<double,3> >::Pointer as( SEXP itkImageToImageMetricR );
template <> inline itk::DemonsImageToImageMetricv4< itk::Image<double,4>, itk::Image<double,4> >::Pointer as( SEXP itkImageToImageMetricR );

template <> inline itk::DemonsImageToImageMetricv4< itk::Image<float,2>, itk::Image<float,2> >::Pointer as( SEXP itkImageToImageMetricR );
template <> inline itk::DemonsImageToImageMetricv4< itk::Image<float,3>, itk::Image<float,3> >::Pointer as( SEXP itkImageToImageMetricR );
template <> inline itk::DemonsImageToImageMetricv4< itk::Image<float,4>, itk::Image<float,4> >::Pointer as( SEXP itkImageToImageMetricR );

}


#endif
