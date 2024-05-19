#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <RcppANTsR.h>

#include "itkBinaryFunctorImageFilter.h"
#include "itkCastImageFilter.h"
#include "itkDefaultConvertPixelTraits.h"
#include "itkImage.h"
#include "itkMaskedStatisticsImageFilter.h"


template< class ImageType >
SEXP antsImageStats( SEXP r_antsimage, SEXP r_mask, SEXP r_narm )
{
  //Rcpp::Rcout << "antsImageStats " << Rcpp::as< std::string >( r_narm ) << std::endl;

  //typedef typename ImageType::PixelType PixelType;
  typedef typename ImageType::Pointer ImagePointerType;
  //typedef itk::DefaultConvertPixelTraits<PixelType> PixelConvertType;
  typedef itk::MaskedStatisticsImageFilter<ImageType> FilterType;
  typedef typename FilterType::MaskImagePointer MaskImagePointer;
  typedef typename FilterType::PixelValueType ValueType;

  ImagePointerType image = Rcpp::as<ImagePointerType>(r_antsimage);
  Rcpp::S4 antsimage(r_antsimage);
  bool narm = Rcpp::as<bool>( r_narm );

  typename FilterType::Pointer filter = FilterType::New();
  filter->SetInput( image );
  if ( r_mask != R_NilValue)
    {
    MaskImagePointer mask = Rcpp::as<MaskImagePointer>(r_mask);
    filter->SetMask(mask);
    }
  filter->SetRemoveNA( narm );
  filter->Update();

  ValueType mean = filter->GetMean();
  ValueType min = filter->GetMinimum();
  ValueType max = filter->GetMaximum();
  ValueType sd = filter->GetSigma();
  ValueType variance = filter->GetVariance();
  ValueType sum =  filter->GetSum();
  ValueType sumsq = filter->GetSumOfSquares();

  Rcpp::List L = Rcpp::List::create(Rcpp::Named("mean") = mean ,
    Rcpp::Named("min") = min,
    Rcpp::Named("max") = max,
    Rcpp::Named("sd") = sd,
    Rcpp::Named("variance") = variance,
    Rcpp::Named("sum") = sum,
    Rcpp::Named("sumofsquares") = sumsq );

  return Rcpp::wrap(L);
}

// [[Rcpp::export]]
SEXP AntsImageStats( SEXP r_antsimage, SEXP r_mask, SEXP r_narm ) {
try
  {
  if( r_antsimage == NULL )
    {
      Rcpp::Rcout << "Unspecified Arguments" << std::endl;
      return Rcpp::wrap( NA_REAL );
    }
  //Rcpp::Rcout << "antsImageStats" << std::endl;

  Rcpp::S4 antsimage( r_antsimage ) ;
  std::string pixeltype = Rcpp::as< std::string >( antsimage.slot( "pixeltype" ) );
  unsigned int dimension = Rcpp::as< int >( antsimage.slot( "dimension" ) );
  bool isVector = Rcpp::as<bool>( antsimage.slot("isVector") );

  if( pixeltype == "double" )
    {
      typedef double PixelType;
      if( dimension == 4 )
        {
        const int ImageDimension = 4;
        typedef itk::Image< PixelType , ImageDimension >      ImageType;
        typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;
        return ( !isVector ) ?
          antsImageStats< ImageType >( r_antsimage, r_mask, r_narm ) :
          antsImageStats< VectorImageType >( r_antsimage, r_mask, r_narm );
        }
      else if( dimension == 3 )
        {
        const int ImageDimension = 3;
        typedef itk::Image< PixelType , ImageDimension >      ImageType;
        typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;
        return ( !isVector ) ?
          antsImageStats< ImageType >( r_antsimage, r_mask, r_narm ) :
          antsImageStats< VectorImageType >( r_antsimage, r_mask, r_narm );
        }
      else if( dimension == 2 )
        {
        const int ImageDimension = 2;
        typedef itk::Image< PixelType , ImageDimension >      ImageType;
        typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;
        return ( !isVector ) ?
          antsImageStats< ImageType >( r_antsimage, r_mask, r_narm ) :
          antsImageStats< VectorImageType >( r_antsimage, r_mask, r_narm );
        }
      else
        {
        Rcpp::Rcout << "Unsupported Dimension" << std::endl ;
        return Rcpp::wrap( NA_REAL ) ;
        }
    }
  else if( pixeltype == "float" )
      {
      typedef float PixelType;
      if( dimension == 4 )
        {
        const int ImageDimension = 4;
        typedef itk::Image< PixelType , ImageDimension >      ImageType;
        typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;
        return ( !isVector ) ?
          antsImageStats< ImageType >( r_antsimage, r_mask, r_narm ) :
          antsImageStats< VectorImageType >( r_antsimage, r_mask, r_narm );
        }
      else if( dimension == 3 )
        {
        const int ImageDimension = 3;
        typedef itk::Image< PixelType , ImageDimension >      ImageType;
        typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;
        return ( !isVector ) ?
          antsImageStats< ImageType >( r_antsimage, r_mask, r_narm ) :
          antsImageStats< VectorImageType >( r_antsimage, r_mask, r_narm );
        }
      else if( dimension == 2 )
        {
        const int ImageDimension = 2;
        typedef itk::Image< PixelType , ImageDimension >      ImageType;
        typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;
        return ( !isVector ) ?
          antsImageStats< ImageType >( r_antsimage, r_mask, r_narm ) :
          antsImageStats< VectorImageType >( r_antsimage, r_mask, r_narm );
        }
      else
        {
        Rcpp::Rcout << "Unsupported Dimension" << std::endl ;
        return Rcpp::wrap( NA_REAL ) ;
        }
      }
  else if( pixeltype == "unsigned int" )
    {
    typedef unsigned int PixelType;
    if( dimension == 4 )
      {
      const int ImageDimension = 4;
        typedef itk::Image< PixelType , ImageDimension >      ImageType;
        typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;
        return ( !isVector ) ?
          antsImageStats< ImageType >( r_antsimage, r_mask, r_narm ) :
          antsImageStats< VectorImageType >( r_antsimage, r_mask, r_narm );
      }
    else if( dimension == 3 )
      {
      const int ImageDimension = 3;
        typedef itk::Image< PixelType , ImageDimension >      ImageType;
        typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;
        return ( !isVector ) ?
          antsImageStats< ImageType >( r_antsimage, r_mask, r_narm ) :
          antsImageStats< VectorImageType >( r_antsimage, r_mask, r_narm );
      }
    else if( dimension == 2 )
      {
      const int ImageDimension = 2;
        typedef itk::Image< PixelType , ImageDimension >      ImageType;
        typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;
        return ( !isVector ) ?
          antsImageStats< ImageType >( r_antsimage, r_mask, r_narm ) :
          antsImageStats< VectorImageType >( r_antsimage, r_mask, r_narm );
      }
    else
      {
      Rcpp::Rcout << "Unsupported Dimension" << std::endl ;
      return Rcpp::wrap( NA_REAL ) ;
      }
    }
  else if( pixeltype == "unsigned char" )
    {
    typedef unsigned char PixelType;
    if( dimension == 4 )
      {
      const int ImageDimension = 4;
        typedef itk::Image< PixelType , ImageDimension >      ImageType;
        typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;
        return ( !isVector ) ?
          antsImageStats< ImageType >( r_antsimage, r_mask, r_narm ) :
          antsImageStats< VectorImageType >( r_antsimage, r_mask, r_narm );
      }
    else if( dimension == 3 )
      {
      const int ImageDimension = 3;
        typedef itk::Image< PixelType , ImageDimension >      ImageType;
        typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;
        return ( !isVector ) ?
          antsImageStats< ImageType >( r_antsimage, r_mask, r_narm ) :
          antsImageStats< VectorImageType >( r_antsimage, r_mask, r_narm );
      }
    else if( dimension == 2 )
      {
      const int ImageDimension = 2;
        typedef itk::Image< PixelType , ImageDimension >      ImageType;
        typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;
        return ( !isVector ) ?
          antsImageStats< ImageType >( r_antsimage, r_mask, r_narm ) :
          antsImageStats< VectorImageType >( r_antsimage, r_mask, r_narm );
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
