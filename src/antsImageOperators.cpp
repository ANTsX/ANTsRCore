
#include <algorithm>
#include <vector>
#include <string>
#include <RcppANTsR.h>
#include "itkAddImageFilter.h"
#include "itkDefaultConvertPixelTraits.h"
#include "itkMultiplyImageFilter.h"
#include "itkImage.h"
#include "itkVectorImage.h"
#include "itkImageBase.h"
#include "itkImageRegionConstIterator.h"
#include "itkImageRegionIterator.h"
#include "itkImageRegionIteratorWithIndex.h"
#include "itkNeighborhoodIterator.h"
#include "itkPermuteAxesImageFilter.h"
#include "itkCentralDifferenceImageFunction.h"
#include "itkContinuousIndex.h"
#include "itkBinaryThresholdImageFilter.h"
#include "vnl/vnl_matrix.h"
#include "vnl/vnl_vector.h"
#include "vnl/algo/vnl_determinant.h"

template< class PixelType , unsigned int Dimension >
SEXP antsImageOperatorsImageNumeric( typename itk::Image< PixelType , Dimension >::Pointer image, SEXP r_numeric, SEXP r_operator )
{
  //Rcpp::Rcout << "antsImageOperatorsImageNumeric: " << Rcpp::as< std::string >( r_operator ) <<  std::endl;
  typedef itk::Image< PixelType , Dimension > ImageType;

  if( !image.IsNotNull() ) {
    return Rcpp::wrap(NA_REAL);
  }

  PixelType numeric = Rcpp::as<PixelType>( r_numeric );

  if ( Rcpp::as< std::string >( r_operator ) == "==" )
  {
    typedef itk::Image< unsigned char, Dimension > OutputImageType;

    typedef itk::BinaryThresholdImageFilter<ImageType, OutputImageType> FilterType;
    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput( image );
    filter->SetLowerThreshold( numeric );
    filter->SetUpperThreshold( numeric );
    filter->SetInsideValue(1);
    filter->SetOutsideValue(0);
    filter->Update();
    typename OutputImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "!=" )
  {
    typedef itk::Image< unsigned char, Dimension > OutputImageType;

    typedef itk::BinaryThresholdImageFilter<ImageType, OutputImageType> FilterType;
    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput( image );
    filter->SetLowerThreshold( numeric );
    filter->SetUpperThreshold( numeric );
    filter->SetInsideValue(0);
    filter->SetOutsideValue(1);
    filter->Update();
    typename OutputImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "<=" )
    {
      typedef itk::Image< unsigned char, Dimension > OutputImageType;

      typedef itk::BinaryThresholdImageFilter<ImageType, OutputImageType> FilterType;
      typename FilterType::Pointer filter = FilterType::New();
      filter->SetInput( image );
      filter->SetUpperThreshold( numeric );
      filter->SetInsideValue(1);
      filter->SetOutsideValue(0);
      filter->Update();
      typename OutputImageType::Pointer outImage = filter->GetOutput();

      return Rcpp::wrap(outImage);
    }
  else if ( Rcpp::as< std::string >( r_operator ) == ">=" )
    {
      typedef itk::Image< unsigned char, Dimension > OutputImageType;

      typedef itk::BinaryThresholdImageFilter<ImageType, OutputImageType> FilterType;
      typename FilterType::Pointer filter = FilterType::New();
      filter->SetInput( image );
      filter->SetLowerThreshold( numeric );
      filter->SetInsideValue(1);
      filter->SetOutsideValue(0);
      filter->Update();
      typename OutputImageType::Pointer outImage = filter->GetOutput();

      return Rcpp::wrap(outImage);
    }
  else if ( Rcpp::as< std::string >( r_operator ) == "<" )
    {
      typedef itk::Image< unsigned char, Dimension > OutputImageType;

      typedef itk::BinaryThresholdImageFilter<ImageType, OutputImageType> FilterType;
      typename FilterType::Pointer filter = FilterType::New();
      filter->SetInput( image );
      filter->SetLowerThreshold( numeric );
      filter->SetInsideValue(0);
      filter->SetOutsideValue(1);
      filter->Update();
      typename OutputImageType::Pointer outImage = filter->GetOutput();

      return Rcpp::wrap(outImage);
    }
  else if ( Rcpp::as< std::string >( r_operator ) == ">" )
    {
      typedef itk::Image< unsigned char, Dimension > OutputImageType;

      typedef itk::BinaryThresholdImageFilter<ImageType, OutputImageType> FilterType;
      typename FilterType::Pointer filter = FilterType::New();
      filter->SetInput( image );
      filter->SetUpperThreshold( numeric );
      filter->SetInsideValue(0);
      filter->SetOutsideValue(1);
      filter->Update();
      typename OutputImageType::Pointer outImage = filter->GetOutput();

      return Rcpp::wrap(outImage);
    }

  Rcpp::Rcout << "Unsupported operator: " << Rcpp::as< std::string >( r_operator ) << std::endl;
  return Rcpp::wrap(NA_REAL);
}

RcppExport SEXP antsImageOperatorsImageNumeric( SEXP r_antsimage, SEXP r_numeric, SEXP r_operator ) {
try
  {
  if( r_antsimage == NULL || r_numeric == NULL || r_operator == NULL )
    {
      Rcpp::Rcout << "Unspecified Arguments" << std::endl;
      return Rcpp::wrap( NA_REAL );
    }

  Rcpp::S4 antsimage( r_antsimage ) ;
  std::string pixeltype = Rcpp::as< std::string >( antsimage.slot( "pixeltype" ) );
  unsigned int dimension = Rcpp::as< int >( antsimage.slot( "dimension" ) );

  if( pixeltype == "double" )
    {
      if( dimension == 4 )
        {
        const int ImageDimension = 4;
        typedef double PixelType;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        Rcpp::XPtr< ImagePointerType > antsimage_xptr( static_cast< SEXP >( antsimage.slot( "pointer" ) ) );
        return antsImageOperatorsImageNumeric< PixelType , ImageDimension >( *antsimage_xptr, r_numeric, r_operator );
        }
      else if( dimension == 3 )
        {
        const int ImageDimension = 3;
        typedef double PixelType;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        Rcpp::XPtr< ImagePointerType > antsimage_xptr( static_cast< SEXP >( antsimage.slot( "pointer" ) ) );
        return antsImageOperatorsImageNumeric< PixelType , ImageDimension >( *antsimage_xptr, r_numeric, r_operator );
        }
      else if( dimension == 2 )
        {
        const int ImageDimension = 2;
        typedef double PixelType;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        Rcpp::XPtr< ImagePointerType > antsimage_xptr( static_cast< SEXP >( antsimage.slot( "pointer" ) ) );
        return antsImageOperatorsImageNumeric< PixelType , ImageDimension >( *antsimage_xptr, r_numeric, r_operator );
        }
      else
        {
        Rcpp::Rcout << "Unsupported Dimension" << std::endl ;
        return Rcpp::wrap( NA_REAL ) ;
        }
    }
  else if( pixeltype == "float" )
    {
      if( dimension == 4 )
        {
        const int ImageDimension = 4;
        typedef float PixelType;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        Rcpp::XPtr< ImagePointerType > antsimage_xptr( static_cast< SEXP >( antsimage.slot( "pointer" ) ) );
        return antsImageOperatorsImageNumeric< PixelType , ImageDimension >( *antsimage_xptr, r_numeric, r_operator );
        }
      else if( dimension == 3 )
        {
        const int ImageDimension = 3;
        typedef float PixelType;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        Rcpp::XPtr< ImagePointerType > antsimage_xptr( static_cast< SEXP >( antsimage.slot( "pointer" ) ) );
        return antsImageOperatorsImageNumeric< PixelType , ImageDimension >( *antsimage_xptr, r_numeric, r_operator );
        }
      else if( dimension == 2 )
        {
        const int ImageDimension = 2;
        typedef float PixelType;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        Rcpp::XPtr< ImagePointerType > antsimage_xptr( static_cast< SEXP >( antsimage.slot( "pointer" ) ) );
        return antsImageOperatorsImageNumeric< PixelType , ImageDimension >( *antsimage_xptr, r_numeric, r_operator );
        }
      else
        {
        Rcpp::Rcout << "Unsupported Dimension" << std::endl ;
        return Rcpp::wrap( NA_REAL ) ;
        }
    }
  else if( pixeltype == "unsigned int" )
    {
      if( dimension == 4 )
        {
        const int ImageDimension = 4;
        typedef unsigned int PixelType;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        Rcpp::XPtr< ImagePointerType > antsimage_xptr( static_cast< SEXP >( antsimage.slot( "pointer" ) ) );
        return antsImageOperatorsImageNumeric< PixelType , ImageDimension >( *antsimage_xptr, r_numeric, r_operator );
        }
      else if( dimension == 3 )
        {
        const int ImageDimension = 3;
        typedef unsigned int PixelType;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        Rcpp::XPtr< ImagePointerType > antsimage_xptr( static_cast< SEXP >( antsimage.slot( "pointer" ) ) );
        return antsImageOperatorsImageNumeric< PixelType , ImageDimension >( *antsimage_xptr, r_numeric, r_operator );
        }
      else if( dimension == 2 )
        {
        const int ImageDimension = 2;
        typedef unsigned int PixelType;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        Rcpp::XPtr< ImagePointerType > antsimage_xptr( static_cast< SEXP >( antsimage.slot( "pointer" ) ) );
        return antsImageOperatorsImageNumeric< PixelType , ImageDimension >( *antsimage_xptr, r_numeric, r_operator );
        }
      else
        {
        Rcpp::Rcout << "Unsupported Dimension" << std::endl ;
        return Rcpp::wrap( NA_REAL ) ;
        }
    }
  else if( pixeltype == "unsigned char" )
    {
      if( dimension == 4 )
        {
        const int ImageDimension = 4;
        typedef unsigned char PixelType;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        Rcpp::XPtr< ImagePointerType > antsimage_xptr( static_cast< SEXP >( antsimage.slot( "pointer" ) ) );
        return antsImageOperatorsImageNumeric< PixelType , ImageDimension >( *antsimage_xptr, r_numeric, r_operator );
        }
      else if( dimension == 3 )
        {
        const int ImageDimension = 3;
        typedef unsigned char PixelType;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        Rcpp::XPtr< ImagePointerType > antsimage_xptr( static_cast< SEXP >( antsimage.slot( "pointer" ) ) );
        return antsImageOperatorsImageNumeric< PixelType , ImageDimension >( *antsimage_xptr, r_numeric, r_operator );
        }
      else if( dimension == 2 )
        {
        const int ImageDimension = 2;
        typedef unsigned char PixelType;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        Rcpp::XPtr< ImagePointerType > antsimage_xptr( static_cast< SEXP >( antsimage.slot( "pointer" ) ) );
        return antsImageOperatorsImageNumeric< PixelType , ImageDimension >( *antsimage_xptr, r_numeric, r_operator );
        }
      else
      {
        Rcpp::Rcout << "Unsupported Dimension" << std::endl ;
        return Rcpp::wrap( NA_REAL ) ;
      }
    }

  }
catch( const std::exception& exc )
  {
    Rcpp::Rcout<< exc.what() << std::endl;
    return Rcpp::wrap( NA_REAL );
  }

// Never reached
return Rcpp::wrap( NA_REAL );

}
