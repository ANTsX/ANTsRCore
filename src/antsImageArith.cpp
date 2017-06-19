#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <RcppANTsR.h>

#include "itkAddImageFilter.h"
#include "itkBinaryFunctorImageFilter.h"
#include "itkCastImageFilter.h"
#include "itkDivideImageFilter.h"
#include "itkImage.h"
#include "itkModulusImageFilter.h"
#include "itkMultiplyImageFilter.h"
#include "itkPowImageFilter.h"
#include "itkSubtractImageFilter.h"

/*
  Define S4 generics for group Arith: "+", "-", "*", "^", "%%", "%/%", "/"

  FIXME: C++ modulus returns different results for negative inputs than R
    in C++: -5 %% 4 returns -2
    in R:   -5 %% 4 returns 3
*/
namespace itk
   {
   namespace Functor
   {
   template< typename TInput1, typename TInput2, typename TOutput >
   class FMod
   {
   public:
     FMod() {}
     ~FMod() {}
     bool operator!=(const FMod &) const
     {
       return false;
     }

    bool operator==(const FMod & other) const
     {
       return !( *this != other );
     }

     inline TOutput operator()(const TInput1 & A, const TInput2 & B ) const
     {
       if ( std::is_same<TInput1, double>::value || std::is_same<TInput1, float>::value )
       {
         return static_cast<TOutput>( std::fmod( static_cast<TInput1>(A), static_cast<TInput1>(B) ) );
       }
       else
       {
          return static_cast<TOutput>( static_cast<unsigned int>(A) % static_cast<unsigned int>(B) );
       }

     }
   };
  }
  }


template< class PixelType , unsigned int Dimension >
SEXP antsImageArithImageNumeric( typename itk::Image< PixelType , Dimension >::Pointer image, SEXP r_numeric, SEXP r_operator )
{
  //Rcpp::Rcout << "antsImageArithImageNumeric " << Rcpp::as< std::string >( r_operator ) << " "
  //  <<  Rcpp::as<PixelType>( r_numeric ) << std::endl;

  typedef itk::Image< PixelType , Dimension > ImageType;

  if( !image.IsNotNull() ) {
    return Rcpp::wrap(NA_REAL);
  }

  PixelType numeric = Rcpp::as<PixelType>( r_numeric );

  if ( Rcpp::as< std::string >( r_operator ) == "+" )
  {
    typedef itk::AddImageFilter<ImageType, ImageType, ImageType> FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput1( image );
    filter->SetConstant2( numeric );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "-" )
  {
    typedef itk::SubtractImageFilter<ImageType, ImageType, ImageType> FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput1( image );
    filter->SetConstant2( numeric );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "*" )
  {
    typedef itk::MultiplyImageFilter<ImageType, ImageType, ImageType> FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput1( image );
    filter->SetConstant2( numeric );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "/" )
  {
    typedef itk::DivideImageFilter<ImageType, ImageType, ImageType> FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput1( image );
    filter->SetConstant2( numeric );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "%%" )
  {
    typedef itk::BinaryFunctorImageFilter<ImageType, ImageType, ImageType,
      itk::Functor::FMod<PixelType,PixelType,PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput1( image );
    filter->SetConstant2( numeric );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "%/%" )
  {
    typedef itk::Image<int, Dimension>                                    IntImageType;
    typedef itk::CastImageFilter<ImageType,IntImageType>                  CastType;
    typedef itk::DivideImageFilter<IntImageType, IntImageType, ImageType> FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    typename CastType::Pointer cast1 = CastType::New();
    //typename CastType::Pointer cast2 = CastType::New();
    cast1->SetInput( image );
    //cast2->SetInput( image2 );
    filter->SetInput1( cast1->GetOutput() );
    filter->SetConstant2( (int) numeric );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "^" )
  {

    typedef itk::PowImageFilter<ImageType, ImageType> FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput1( image );
    filter->SetConstant2( numeric );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);

  }

  Rcpp::Rcout << "Unsupported operator: " << Rcpp::as< std::string >( r_operator ) << std::endl;
  return Rcpp::wrap(NA_REAL);
}

RcppExport SEXP antsImageArithImageNumeric( SEXP r_antsimage, SEXP r_numeric, SEXP r_operator ) {
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
      typedef double PixelType;
      if( dimension == 4 )
        {
        const int ImageDimension = 4;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
        return antsImageArithImageNumeric< PixelType , ImageDimension >( img, r_numeric, r_operator );
        }
      else if( dimension == 3 )
        {
        const int ImageDimension = 3;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
        return antsImageArithImageNumeric< PixelType , ImageDimension >( img, r_numeric, r_operator );
        }
      else if( dimension == 2 )
        {
        const int ImageDimension = 2;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
        return antsImageArithImageNumeric< PixelType , ImageDimension >( img, r_numeric, r_operator );
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
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
        return antsImageArithImageNumeric< PixelType , ImageDimension >( img, r_numeric, r_operator );
        }
      else if( dimension == 3 )
        {
        const int ImageDimension = 3;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
        return antsImageArithImageNumeric< PixelType , ImageDimension >( img, r_numeric, r_operator );
        }
      else if( dimension == 2 )
        {
        const int ImageDimension = 2;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
        return antsImageArithImageNumeric< PixelType , ImageDimension >( img, r_numeric, r_operator );
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
      ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
      return antsImageArithImageNumeric< PixelType , ImageDimension >( img, r_numeric, r_operator );
      }
    else if( dimension == 3 )
      {
      const int ImageDimension = 3;
      typedef unsigned int PixelType;
      typedef itk::Image< PixelType , ImageDimension > ImageType;
      typedef ImageType::Pointer ImagePointerType;
      ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
      return antsImageArithImageNumeric< PixelType , ImageDimension >( img, r_numeric, r_operator );
      }
    else if( dimension == 2 )
      {
      const int ImageDimension = 2;
      typedef unsigned int PixelType;
      typedef itk::Image< PixelType , ImageDimension > ImageType;
      typedef ImageType::Pointer ImagePointerType;
      ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
      return antsImageArithImageNumeric< PixelType , ImageDimension >( img, r_numeric, r_operator );
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
      ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
      return antsImageArithImageNumeric< PixelType , ImageDimension >( img, r_numeric, r_operator );
      }
    else if( dimension == 3 )
      {
      const int ImageDimension = 3;
      typedef unsigned char PixelType;
      typedef itk::Image< PixelType , ImageDimension > ImageType;
      typedef ImageType::Pointer ImagePointerType;
      ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
      return antsImageArithImageNumeric< PixelType , ImageDimension >( img, r_numeric, r_operator );
      }
    else if( dimension == 2 )
      {
      const int ImageDimension = 2;
      typedef unsigned char PixelType;
      typedef itk::Image< PixelType , ImageDimension > ImageType;
      typedef ImageType::Pointer ImagePointerType;
      ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
      return antsImageArithImageNumeric< PixelType , ImageDimension >( img, r_numeric, r_operator );
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

template< class PixelType , unsigned int Dimension >
SEXP antsImageArithNumericImage( SEXP r_numeric, typename itk::Image< PixelType , Dimension >::Pointer image, SEXP r_operator )
{
  //Rcpp::Rcout << "antsImageArithNumericImage " << Rcpp::as< std::string >( r_operator ) << " "
  //  <<  Rcpp::as<PixelType>( r_numeric ) << std::endl;

  typedef itk::Image< PixelType , Dimension > ImageType;

  if( !image.IsNotNull() ) {
    return Rcpp::wrap(NA_REAL);
  }

  PixelType numeric = Rcpp::as<PixelType>( r_numeric );

  if ( Rcpp::as< std::string >( r_operator ) == "+" )
  {
    typedef itk::AddImageFilter<ImageType, ImageType, ImageType> FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetConstant1( numeric );
    filter->SetInput2( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "-" )
  {
    typedef itk::SubtractImageFilter<ImageType, ImageType, ImageType> FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetConstant1( numeric );
    filter->SetInput2( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "*" )
  {
    typedef itk::MultiplyImageFilter<ImageType, ImageType, ImageType> FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetConstant1( numeric );
    filter->SetInput2( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "/" )
  {
    typedef itk::DivideImageFilter<ImageType, ImageType, ImageType> FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetConstant1( numeric );
    filter->SetInput2( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "%%" )
  {
    typedef itk::BinaryFunctorImageFilter<ImageType, ImageType, ImageType,
      itk::Functor::FMod<PixelType,PixelType,PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetConstant1( numeric );
    filter->SetConstant2( numeric );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "%/%" )
  {
    typedef itk::Image<int, Dimension>                                    IntImageType;
    typedef itk::CastImageFilter<ImageType,IntImageType>                  CastType;
    typedef itk::DivideImageFilter<IntImageType, IntImageType, ImageType> FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    typename CastType::Pointer cast1 = CastType::New();
    //typename CastType::Pointer cast2 = CastType::New();
    cast1->SetInput( image );
    //cast2->SetInput( image2 );
    filter->SetInput1( cast1->GetOutput() );
    filter->SetConstant( (int) numeric );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "^" )
  {

    typedef itk::PowImageFilter<ImageType, ImageType> FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetConstant1( numeric );
    filter->SetConstant2( numeric );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);

  }

  Rcpp::Rcout << "Unsupported operator: " << Rcpp::as< std::string >( r_operator ) << std::endl;
  return Rcpp::wrap(NA_REAL);
}

RcppExport SEXP antsImageArithNumericImage( SEXP r_numeric, SEXP r_antsimage, SEXP r_operator ) {
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
      typedef double PixelType;
      if( dimension == 4 )
        {
        const int ImageDimension = 4;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
        return antsImageArithNumericImage< PixelType , ImageDimension >( r_numeric, img, r_operator );
        }
      else if( dimension == 3 )
        {
        const int ImageDimension = 3;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
        return antsImageArithNumericImage< PixelType , ImageDimension >( r_numeric, img, r_operator );
        }
      else if( dimension == 2 )
        {
        const int ImageDimension = 2;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
        return antsImageArithNumericImage< PixelType , ImageDimension >( r_numeric, img, r_operator );
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
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
        return antsImageArithNumericImage< PixelType , ImageDimension >( r_numeric, img, r_operator );
        }
      else if( dimension == 3 )
        {
        const int ImageDimension = 3;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
        return antsImageArithNumericImage< PixelType , ImageDimension >( r_numeric, img, r_operator );
        }
      else if( dimension == 2 )
        {
        const int ImageDimension = 2;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
        return antsImageArithNumericImage< PixelType , ImageDimension >( r_numeric, img, r_operator );
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
      ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
      return antsImageArithNumericImage< PixelType , ImageDimension >( r_numeric, img, r_operator );
      }
    else if( dimension == 3 )
      {
      const int ImageDimension = 3;
      typedef unsigned int PixelType;
      typedef itk::Image< PixelType , ImageDimension > ImageType;
      typedef ImageType::Pointer ImagePointerType;
      ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
      return antsImageArithNumericImage< PixelType , ImageDimension >( r_numeric, img, r_operator );
      }
    else if( dimension == 2 )
      {
      const int ImageDimension = 2;
      typedef unsigned int PixelType;
      typedef itk::Image< PixelType , ImageDimension > ImageType;
      typedef ImageType::Pointer ImagePointerType;
      ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
      return antsImageArithNumericImage< PixelType , ImageDimension >( r_numeric, img, r_operator );
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
      ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
      return antsImageArithNumericImage< PixelType , ImageDimension >( r_numeric, img, r_operator );
      }
    else if( dimension == 3 )
      {
      const int ImageDimension = 3;
      typedef unsigned char PixelType;
      typedef itk::Image< PixelType , ImageDimension > ImageType;
      typedef ImageType::Pointer ImagePointerType;
      ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
      return antsImageArithNumericImage< PixelType , ImageDimension >( r_numeric, img, r_operator );
      }
    else if( dimension == 2 )
      {
      const int ImageDimension = 2;
      typedef unsigned char PixelType;
      typedef itk::Image< PixelType , ImageDimension > ImageType;
      typedef ImageType::Pointer ImagePointerType;
      ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
      return antsImageArithNumericImage< PixelType , ImageDimension >( r_numeric, img, r_operator );
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



template< class PixelType , unsigned int Dimension >
SEXP antsImageArithImageImage( typename itk::Image< PixelType , Dimension >::Pointer image1,
                               typename itk::Image< PixelType , Dimension >::Pointer image2,
                               SEXP r_operator )
{
  //Rcpp::Rcout << "antsImageArithImageImage " << Rcpp::as< std::string >( r_operator ) << std::endl;

  typedef itk::Image< PixelType , Dimension > ImageType;

  if( !image1.IsNotNull() || !image2.IsNotNull() ) {
    return Rcpp::wrap(NA_REAL);
  }

  if ( Rcpp::as< std::string >( r_operator ) == "+" )
  {
    typedef itk::AddImageFilter<ImageType, ImageType, ImageType> FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput1( image1 );
    filter->SetInput2( image2 );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "-" )
  {
    typedef itk::SubtractImageFilter<ImageType, ImageType, ImageType> FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput1( image1 );
    filter->SetInput2( image2 );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "*" )
  {
    typedef itk::MultiplyImageFilter<ImageType, ImageType, ImageType> FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput1( image1 );
    filter->SetInput2( image2 );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "/" )
  {
    typedef itk::DivideImageFilter<ImageType, ImageType, ImageType> FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput1( image1 );
    filter->SetInput2( image2 );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "%%" )
  {
    typedef itk::BinaryFunctorImageFilter<ImageType, ImageType, ImageType,
      itk::Functor::FMod<PixelType,PixelType,PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput1( image1 );
    filter->SetInput2( image2 );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "%/%" )
  {
    typedef itk::Image<int, Dimension>                                    IntImageType;
    typedef itk::CastImageFilter<ImageType,IntImageType>                  CastType;
    typedef itk::DivideImageFilter<IntImageType, IntImageType, ImageType> FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    typename CastType::Pointer cast1 = CastType::New();
    typename CastType::Pointer cast2 = CastType::New();
    cast1->SetInput( image1 );
    cast2->SetInput( image2 );
    filter->SetInput1( cast1->GetOutput() );
    filter->SetInput2( cast2->GetOutput() );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "^" )
  {
    typedef itk::PowImageFilter<ImageType, ImageType> FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput1( image1 );
    filter->SetInput2( image2 );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);

  }

  Rcpp::Rcout << "Unsupported operator: " << Rcpp::as< std::string >( r_operator ) << std::endl;
  return Rcpp::wrap(NA_REAL);
}

RcppExport SEXP antsImageArithImageImage( SEXP r_antsimage1, SEXP r_antsimage2, SEXP r_operator ) {
try
  {
  if( r_antsimage1 == NULL || r_antsimage2 == NULL || r_operator == NULL )
    {
      Rcpp::Rcout << "Unspecified Arguments" << std::endl;
      return Rcpp::wrap( NA_REAL );
    }

  Rcpp::S4 antsimage1( r_antsimage1 ) ;
  std::string pixeltype = Rcpp::as< std::string >( antsimage1.slot( "pixeltype" ) );
  unsigned int dimension = Rcpp::as< int >( antsimage1.slot( "dimension" ) );

  Rcpp::S4 antsimage2( r_antsimage2 ) ;
  std::string pixeltype2 = Rcpp::as< std::string >( antsimage2.slot( "pixeltype" ) );

  pixeltype = pixeltype_highest_precision( pixeltype, pixeltype2 );
  Rcpp::Rcout << "Arith returning pixeltype: " << pixeltype << std::endl;

if( pixeltype == "double" )
    {
      typedef double PixelType;
      if( dimension == 4 )
        {
        const int ImageDimension = 4;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img1 = Rcpp::as<ImagePointerType>( r_antsimage1 );
        ImagePointerType img2 = Rcpp::as<ImagePointerType>( r_antsimage2 );
        return antsImageArithImageImage< PixelType , ImageDimension >( img1, img2, r_operator );
        }
      else if( dimension == 3 )
        {
        const int ImageDimension = 3;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img1 = Rcpp::as<ImagePointerType>( r_antsimage1 );
        ImagePointerType img2 = Rcpp::as<ImagePointerType>( r_antsimage2 );
        return antsImageArithImageImage< PixelType , ImageDimension >( img1, img2, r_operator );
        }
      else if( dimension == 2 )
        {
        const int ImageDimension = 2;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img1 = Rcpp::as<ImagePointerType>( r_antsimage1 );
        ImagePointerType img2 = Rcpp::as<ImagePointerType>( r_antsimage2 );
        return antsImageArithImageImage< PixelType , ImageDimension >( img1, img2, r_operator );
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
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img1 = Rcpp::as<ImagePointerType>( r_antsimage1 );
        ImagePointerType img2 = Rcpp::as<ImagePointerType>( r_antsimage2 );
        return antsImageArithImageImage< PixelType , ImageDimension >( img1, img2, r_operator );
        }
      else if( dimension == 3 )
        {
        const int ImageDimension = 3;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img1 = Rcpp::as<ImagePointerType>( r_antsimage1 );
        ImagePointerType img2 = Rcpp::as<ImagePointerType>( r_antsimage2 );
        return antsImageArithImageImage< PixelType , ImageDimension >( img1, img2, r_operator );
        }
      else if( dimension == 2 )
        {
        const int ImageDimension = 2;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img1 = Rcpp::as<ImagePointerType>( r_antsimage1 );
        ImagePointerType img2 = Rcpp::as<ImagePointerType>( r_antsimage2 );
        return antsImageArithImageImage< PixelType , ImageDimension >( img1, img2, r_operator );
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
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img1 = Rcpp::as<ImagePointerType>( r_antsimage1 );
        ImagePointerType img2 = Rcpp::as<ImagePointerType>( r_antsimage2 );
        return antsImageArithImageImage< PixelType , ImageDimension >( img1, img2, r_operator );
        }
      else if( dimension == 3 )
        {
        const int ImageDimension = 3;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img1 = Rcpp::as<ImagePointerType>( r_antsimage1 );
        ImagePointerType img2 = Rcpp::as<ImagePointerType>( r_antsimage2 );
        return antsImageArithImageImage< PixelType , ImageDimension >( img1, img2, r_operator );
        }
      else if( dimension == 2 )
        {
        const int ImageDimension = 2;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img1 = Rcpp::as<ImagePointerType>( r_antsimage1 );
        ImagePointerType img2 = Rcpp::as<ImagePointerType>( r_antsimage2 );
        return antsImageArithImageImage< PixelType , ImageDimension >( img1, img2, r_operator );
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
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img1 = Rcpp::as<ImagePointerType>( r_antsimage1 );
        ImagePointerType img2 = Rcpp::as<ImagePointerType>( r_antsimage2 );
        return antsImageArithImageImage< PixelType , ImageDimension >( img1, img2, r_operator );
        }
      else if( dimension == 3 )
        {
        const int ImageDimension = 3;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img1 = Rcpp::as<ImagePointerType>( r_antsimage1 );
        ImagePointerType img2 = Rcpp::as<ImagePointerType>( r_antsimage2 );
        return antsImageArithImageImage< PixelType , ImageDimension >( img1, img2, r_operator );
        }
      else if( dimension == 2 )
        {
        const int ImageDimension = 2;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img1 = Rcpp::as<ImagePointerType>( r_antsimage1 );
        ImagePointerType img2 = Rcpp::as<ImagePointerType>( r_antsimage2 );
        return antsImageArithImageImage< PixelType , ImageDimension >( img1, img2, r_operator );
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
