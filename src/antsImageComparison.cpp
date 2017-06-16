
#include <algorithm>
#include <vector>
#include <string>
#include <RcppANTsR.h>
#include "itkImage.h"
#include "itkVectorImage.h"
#include "itkBinaryThresholdImageFilter.h"
#include "itkBinaryFunctorImageFilter.h"
#include "itkLogicOpsFunctors.h"

template< class PixelType , unsigned int Dimension >
SEXP antsImageComparisonImageNumeric( typename itk::Image< PixelType , Dimension >::Pointer image, SEXP r_numeric, SEXP r_operator )
{
  //Rcpp::Rcout << "antsImageComparisonImageNumeric " << Rcpp::as< std::string >( r_operator ) << " "
  //  <<  Rcpp::as<PixelType>( r_numeric ) << std::endl;

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

RcppExport SEXP antsImageComparisonImageNumeric( SEXP r_antsimage, SEXP r_numeric, SEXP r_operator ) {
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
        ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
        return antsImageComparisonImageNumeric< PixelType , ImageDimension >( img, r_numeric, r_operator );
        }
      else if( dimension == 3 )
        {
        const int ImageDimension = 3;
        typedef double PixelType;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
        return antsImageComparisonImageNumeric< PixelType , ImageDimension >( img, r_numeric, r_operator );
        }
      else if( dimension == 2 )
        {
        const int ImageDimension = 2;
        typedef double PixelType;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
        return antsImageComparisonImageNumeric< PixelType , ImageDimension >( img, r_numeric, r_operator );
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
        ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
        return antsImageComparisonImageNumeric< PixelType , ImageDimension >( img, r_numeric, r_operator );
        }
      else if( dimension == 3 )
        {
        const int ImageDimension = 3;
        typedef float PixelType;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
        return antsImageComparisonImageNumeric< PixelType , ImageDimension >( img, r_numeric, r_operator );
        }
      else if( dimension == 2 )
        {
        const int ImageDimension = 2;
        typedef float PixelType;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
        return antsImageComparisonImageNumeric< PixelType , ImageDimension >( img, r_numeric, r_operator );
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
        return antsImageComparisonImageNumeric< PixelType , ImageDimension >( img, r_numeric, r_operator );
        }
      else if( dimension == 3 )
        {
        const int ImageDimension = 3;
        typedef unsigned int PixelType;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
        return antsImageComparisonImageNumeric< PixelType , ImageDimension >( img, r_numeric, r_operator );
        }
      else if( dimension == 2 )
        {
        const int ImageDimension = 2;
        typedef unsigned int PixelType;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
        return antsImageComparisonImageNumeric< PixelType , ImageDimension >( img, r_numeric, r_operator );
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
        return antsImageComparisonImageNumeric< PixelType , ImageDimension >( img, r_numeric, r_operator );
        }
      else if( dimension == 3 )
        {
        const int ImageDimension = 3;
        typedef unsigned char PixelType;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
        return antsImageComparisonImageNumeric< PixelType , ImageDimension >( img, r_numeric, r_operator );
        }
      else if( dimension == 2 )
        {
        const int ImageDimension = 2;
        typedef unsigned char PixelType;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img = Rcpp::as<ImagePointerType>( r_antsimage );
        return antsImageComparisonImageNumeric< PixelType , ImageDimension >( img, r_numeric, r_operator );
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
SEXP antsImageComparisonImageImage( typename itk::Image< PixelType , Dimension >::Pointer image1,
                                    typename itk::Image< PixelType , Dimension >::Pointer image2,
                                    SEXP r_operator )
{
  //Rcpp::Rcout << "antsImageComparisonImageImage " << Rcpp::as< std::string >( r_operator ) << std::endl;

  typedef itk::Image< PixelType , Dimension > ImageType;

  if( !image1.IsNotNull() || !image2.IsNotNull() ) {
    return Rcpp::wrap(NA_REAL);
  }

  if ( Rcpp::as< std::string >( r_operator ) == "==" )
  {
    typedef itk::Image< unsigned char, Dimension > OutputImageType;
    typedef itk::BinaryFunctorImageFilter<ImageType, ImageType, OutputImageType,
      itk::Functor::Equal<PixelType,PixelType,unsigned char>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput1( image1 );
    filter->SetInput2( image2 );
    filter->Update();
    typename OutputImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "!=" )
  {
    typedef itk::Image< unsigned char, Dimension > OutputImageType;
    typedef itk::BinaryFunctorImageFilter<ImageType, ImageType, OutputImageType,
      itk::Functor::NotEqual<PixelType,PixelType,unsigned char>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput1( image1 );
    filter->SetInput2( image2 );
    filter->Update();
    typename OutputImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "<=" )
    {
    typedef itk::Image< unsigned char, Dimension > OutputImageType;
    typedef itk::BinaryFunctorImageFilter<ImageType, ImageType, OutputImageType,
      itk::Functor::LessEqual<PixelType,PixelType,unsigned char>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput1( image1 );
    filter->SetInput2( image2 );
    filter->Update();
    typename OutputImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
    }
  else if ( Rcpp::as< std::string >( r_operator ) == ">=" )
    {
    typedef itk::Image< unsigned char, Dimension > OutputImageType;
    typedef itk::BinaryFunctorImageFilter<ImageType, ImageType, OutputImageType,
      itk::Functor::GreaterEqual<PixelType,PixelType,unsigned char>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput1( image1 );
    filter->SetInput2( image2 );
    filter->Update();
    typename OutputImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
    }
  else if ( Rcpp::as< std::string >( r_operator ) == "<" )
    {
    typedef itk::Image< unsigned char, Dimension > OutputImageType;
    typedef itk::BinaryFunctorImageFilter<ImageType, ImageType, OutputImageType,
      itk::Functor::Less<PixelType,PixelType,unsigned char>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput1( image1 );
    filter->SetInput2( image2 );
    filter->Update();
    typename OutputImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
    }
  else if ( Rcpp::as< std::string >( r_operator ) == ">" )
    {
    typedef itk::Image< unsigned char, Dimension > OutputImageType;
    typedef itk::BinaryFunctorImageFilter<ImageType, ImageType, OutputImageType,
      itk::Functor::Greater<PixelType,PixelType,unsigned char>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput1( image1 );
    filter->SetInput2( image2 );
    filter->Update();
    typename OutputImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
    }

  Rcpp::Rcout << "Unsupported operator: " << Rcpp::as< std::string >( r_operator ) << std::endl;
  return Rcpp::wrap(NA_REAL);
}

RcppExport SEXP antsImageComparisonImageImage( SEXP r_antsimage1, SEXP r_antsimage2, SEXP r_operator ) {
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
  unsigned int dimension2 = Rcpp::as< int >( antsimage2.slot( "dimension" ) );

  pixeltype = pixeltype_highest_precision( pixeltype, pixeltype2 );

  if ( dimension != dimension2 ) {
    Rcpp::Rcout << "antsImages must have same dimensions" << std::endl;
    return Rcpp::wrap(NA_REAL);
  }

  if( pixeltype == "double" )
    {
      if( dimension == 4 )
        {
        const int ImageDimension = 4;
        typedef double PixelType;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img1 = Rcpp::as<ImagePointerType>( r_antsimage1 );
        ImagePointerType img2 = Rcpp::as<ImagePointerType>( r_antsimage2 );
        return antsImageComparisonImageImage< PixelType , ImageDimension >( img1, img2, r_operator );
        }
      else if( dimension == 3 )
        {
        const int ImageDimension = 3;
        typedef double PixelType;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img1 = Rcpp::as<ImagePointerType>( r_antsimage1 );
        ImagePointerType img2 = Rcpp::as<ImagePointerType>( r_antsimage2 );
        return antsImageComparisonImageImage< PixelType , ImageDimension >( img1, img2, r_operator );
        }
      else if( dimension == 2 )
        {
        const int ImageDimension = 2;
        typedef double PixelType;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img1 = Rcpp::as<ImagePointerType>( r_antsimage1 );
        ImagePointerType img2 = Rcpp::as<ImagePointerType>( r_antsimage2 );
        return antsImageComparisonImageImage< PixelType , ImageDimension >( img1, img2, r_operator );
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
        ImagePointerType img1 = Rcpp::as<ImagePointerType>( r_antsimage1 );
        ImagePointerType img2 = Rcpp::as<ImagePointerType>( r_antsimage2 );
        return antsImageComparisonImageImage< PixelType , ImageDimension >( img1, img2, r_operator );
        }
      else if( dimension == 3 )
        {
        const int ImageDimension = 3;
        typedef float PixelType;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img1 = Rcpp::as<ImagePointerType>( r_antsimage1 );
        ImagePointerType img2 = Rcpp::as<ImagePointerType>( r_antsimage2 );
        return antsImageComparisonImageImage< PixelType , ImageDimension >( img1, img2, r_operator );
        }
      else if( dimension == 2 )
        {
        const int ImageDimension = 2;
        typedef float PixelType;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img1 = Rcpp::as<ImagePointerType>( r_antsimage1 );
        ImagePointerType img2 = Rcpp::as<ImagePointerType>( r_antsimage2 );
        return antsImageComparisonImageImage< PixelType , ImageDimension >( img1, img2, r_operator );
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
        ImagePointerType img1 = Rcpp::as<ImagePointerType>( r_antsimage1 );
        ImagePointerType img2 = Rcpp::as<ImagePointerType>( r_antsimage2 );
        return antsImageComparisonImageImage< PixelType , ImageDimension >( img1, img2, r_operator );
        }
      else if( dimension == 3 )
        {
        const int ImageDimension = 3;
        typedef unsigned int PixelType;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img1 = Rcpp::as<ImagePointerType>( r_antsimage1 );
        ImagePointerType img2 = Rcpp::as<ImagePointerType>( r_antsimage2 );
        return antsImageComparisonImageImage< PixelType , ImageDimension >( img1, img2, r_operator );
        }
      else if( dimension == 2 )
        {
        const int ImageDimension = 2;
        typedef unsigned int PixelType;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img1 = Rcpp::as<ImagePointerType>( r_antsimage1 );
        ImagePointerType img2 = Rcpp::as<ImagePointerType>( r_antsimage2 );
        return antsImageComparisonImageImage< PixelType , ImageDimension >( img1, img2, r_operator );
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
        ImagePointerType img1 = Rcpp::as<ImagePointerType>( r_antsimage1 );
        ImagePointerType img2 = Rcpp::as<ImagePointerType>( r_antsimage2 );
        return antsImageComparisonImageImage< PixelType , ImageDimension >( img1, img2, r_operator );
        }
      else if( dimension == 3 )
        {
        const int ImageDimension = 3;
        typedef unsigned char PixelType;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img1 = Rcpp::as<ImagePointerType>( r_antsimage1 );
        ImagePointerType img2 = Rcpp::as<ImagePointerType>( r_antsimage2 );
        return antsImageComparisonImageImage< PixelType , ImageDimension >( img1, img2, r_operator );
        }
      else if( dimension == 2 )
        {
        const int ImageDimension = 2;
        typedef unsigned char PixelType;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef ImageType::Pointer ImagePointerType;
        ImagePointerType img1 = Rcpp::as<ImagePointerType>( r_antsimage1 );
        ImagePointerType img2 = Rcpp::as<ImagePointerType>( r_antsimage2 );
        return antsImageComparisonImageImage< PixelType , ImageDimension >( img1, img2, r_operator );
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
