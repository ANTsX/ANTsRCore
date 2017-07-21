#ifndef __RCPPANTSR_IMAGE_HPP
#define __RCPPANTSR_IMAGE_HPP

#include "itkMacro.h"
#include "itkImage.h"
#include "itkCastImageFilter.h"
#include <Rcpp.h>

namespace Rcpp {

/* Example code for implementing 'wrap' for an itk image class
template <> inline
SEXP wrap( const itk::IMAGETYPE<PIXELTYPE,DIMENSION>::Pointer &image )
{
  typedef itk::IMAGETYPE<PIXELTYPE,DIMENSION> ImageType;
  typedef ImageType::Pointer                  ImagePointerType;

  ImagePointerType* rawPointer = new ImagePointerType( image );
  Rcpp::XPtr< ImagePointerType > xptr( rawPointer , true ) ;

  Rcpp::S4 itkImage( std::string( "antsImage" ) );
  itkImage.slot( "pixeltype" ) = "PIXELTYPE";
  itkImage.slot( "dimension" ) = DIMENSION;
  itkImage.slot( "components" ) = image->GetNumberOfComponentsPerPixel();
  itkImage.slot( "pointer") = xptr;

  return(wrap(itkImage));
}
*/

template <typename PixelType, unsigned int Dimension>
class itkImageFinalizer
{
public:
  typedef itk::Image<PixelType,Dimension>   ImageType;
  typedef typename ImageType::Pointer       ImagePointerType;

  static void Finalize( ImagePointerType* ptr)
  {
    Rcpp::Rcout << "itkImageFinalizer::Finalize" << std::endl;
    (*ptr) = NULL;
    delete ptr;
  }
};

template <> inline
SEXP wrap( const itk::Image<double,2>::Pointer &image )
{
  typedef itk::Image<double,2>        ImageType;
  typedef ImageType::Pointer          ImagePointerType;
  //typedef itkImageFinalizer<double,2> FinalizerType;
  //typedef Rcpp::XPtr<ImagePointerType,PreserveStorage,FinalizerType::Finalize> XPtrType;
  typedef Rcpp::XPtr<ImagePointerType> XPtrType;

  ImagePointerType* rawPointer = new ImagePointerType( image );
  XPtrType xptr( rawPointer , true );

  Rcpp::S4 itkImage( std::string( "antsImage" ) );
  itkImage.slot( "pixeltype" ) = "double";
  itkImage.slot( "dimension" ) = 2;
  itkImage.slot( "components" ) = 1;
  itkImage.slot( "isVector" ) = false;
  itkImage.slot( "pointer") = xptr;

  return(wrap(itkImage));
}

template <> inline
SEXP wrap( const itk::Image<double,3>::Pointer &image )
{
  typedef itk::Image<double,3>        ImageType;
  typedef ImageType::Pointer ImagePointerType;

  ImagePointerType* rawPointer = new ImagePointerType( image );
  Rcpp::XPtr< ImagePointerType > xptr( rawPointer , true ) ;

  Rcpp::S4 itkImage( std::string( "antsImage" ) );
  itkImage.slot( "pixeltype" ) = "double";
  itkImage.slot( "dimension" ) = 3;
  itkImage.slot( "components" ) = 1;
  itkImage.slot( "isVector" ) = false;
  itkImage.slot( "pointer") = xptr;

  return(wrap(itkImage));
}

template <> inline
SEXP wrap( const itk::Image<double,4>::Pointer &image )
{
  typedef itk::Image<double,4>        ImageType;
  typedef ImageType::Pointer ImagePointerType;

  ImagePointerType* rawPointer = new ImagePointerType( image );
  Rcpp::XPtr< ImagePointerType  > xptr( rawPointer , true ) ;

  Rcpp::S4 itkImage( std::string( "antsImage" ) );
  itkImage.slot( "pixeltype" ) = "double";
  itkImage.slot( "dimension" ) = 4;
  itkImage.slot( "components" ) = 1;
  itkImage.slot( "isVector" ) = false;
  itkImage.slot( "pointer") = xptr;

  return(wrap(itkImage));
}

template <> inline
SEXP wrap( const itk::Image<float,2>::Pointer &image )
{
  typedef itk::Image<float,2>        ImageType;
  typedef ImageType::Pointer ImagePointerType;

  ImagePointerType* rawPointer = new ImagePointerType( image );
  Rcpp::XPtr< ImagePointerType > xptr( rawPointer , true ) ;

  Rcpp::S4 itkImage( std::string( "antsImage" ) );
  itkImage.slot( "pixeltype" ) = "float";
  itkImage.slot( "dimension" ) = 2;
  itkImage.slot( "components" ) = 1;
  itkImage.slot( "isVector" ) = false;
  itkImage.slot( "pointer") = xptr;

  return(wrap(itkImage));
}

template <> inline
SEXP wrap( const itk::Image<float,3>::Pointer &image )
{
  typedef itk::Image<float,3>        ImageType;
  typedef ImageType::Pointer ImagePointerType;

  ImagePointerType* rawPointer = new ImagePointerType( image );
  Rcpp::XPtr< ImagePointerType > xptr( rawPointer , true ) ;

  Rcpp::S4 itkImage( std::string( "antsImage" ) );
  itkImage.slot( "pixeltype" ) = "float";
  itkImage.slot( "dimension" ) = 3;
  itkImage.slot( "components" ) = 1;
  itkImage.slot( "isVector" ) = false;
  itkImage.slot( "pointer") = xptr;

  return(wrap(itkImage));
}

template <> inline
SEXP wrap( const itk::Image<float,4>::Pointer &image )
{
  typedef itk::Image<float,4>        ImageType;
  typedef ImageType::Pointer ImagePointerType;

  ImagePointerType* rawPointer = new ImagePointerType( image );
  Rcpp::XPtr< ImagePointerType > xptr( rawPointer , true ) ;

  Rcpp::S4 itkImage( std::string( "antsImage" ) );
  itkImage.slot( "pixeltype" ) = "float";
  itkImage.slot( "dimension" ) = 4;
  itkImage.slot( "components" ) = 1;
  itkImage.slot( "isVector" ) = false;
  itkImage.slot( "pointer") = xptr;

  return(wrap(itkImage));
}

template <> inline
SEXP wrap( const itk::Image<unsigned int,2>::Pointer &image )
{
  typedef itk::Image<unsigned int,2>        ImageType;
  typedef ImageType::Pointer ImagePointerType;

  ImagePointerType* rawPointer = new ImagePointerType( image );
  Rcpp::XPtr< ImagePointerType > xptr( rawPointer , true ) ;

  Rcpp::S4 itkImage( std::string( "antsImage" ) );
  itkImage.slot( "pixeltype" ) = "unsigned int";
  itkImage.slot( "dimension" ) = 2;
  itkImage.slot( "components" ) = 1;
  itkImage.slot( "isVector" ) = false;
  itkImage.slot( "pointer") = xptr;

  return(wrap(itkImage));
}

template <> inline
SEXP wrap( const itk::Image<unsigned int,3>::Pointer &image )
{
  typedef itk::Image<unsigned int,3>        ImageType;
  typedef ImageType::Pointer ImagePointerType;

  ImagePointerType* rawPointer = new ImagePointerType( image );
  Rcpp::XPtr< ImagePointerType > xptr( rawPointer , true ) ;

  Rcpp::S4 itkImage( std::string( "antsImage" ) );
  itkImage.slot( "pixeltype" ) = "unsigned int";
  itkImage.slot( "dimension" ) = 3;
  itkImage.slot( "components" ) = 1;
  itkImage.slot( "isVector" ) = false;
  itkImage.slot( "pointer") = xptr;

  return(wrap(itkImage));
}

template <> inline
SEXP wrap( const itk::Image<unsigned int,4>::Pointer &image )
{
  typedef itk::Image<unsigned int,4>        ImageType;
  typedef ImageType::Pointer ImagePointerType;

  ImagePointerType* rawPointer = new ImagePointerType( image );
  Rcpp::XPtr< ImagePointerType > xptr( rawPointer , true ) ;

  Rcpp::S4 itkImage( std::string( "antsImage" ) );
  itkImage.slot( "pixeltype" ) = "unsigned int";
  itkImage.slot( "dimension" ) = 4;
  itkImage.slot( "components" ) = 1;
  itkImage.slot( "isVector" ) = false;
  itkImage.slot( "pointer") = xptr;

  return(wrap(itkImage));
}


template <> inline
SEXP wrap( const itk::Image<unsigned char,2>::Pointer &image )
{
  typedef itk::Image<unsigned char,2>        ImageType;
  typedef ImageType::Pointer ImagePointerType;

  ImagePointerType* rawPointer = new ImagePointerType( image );
  Rcpp::XPtr< ImagePointerType > xptr( rawPointer , true ) ;

  Rcpp::S4 itkImage( std::string( "antsImage" ) );
  itkImage.slot( "pixeltype" ) = "unsigned char";
  itkImage.slot( "dimension" ) = 2;
  itkImage.slot( "components" ) = 1;
  itkImage.slot( "isVector" ) = false;
  itkImage.slot( "pointer") = xptr;

  return(wrap(itkImage));
}

template <> inline
SEXP wrap( const itk::Image<unsigned char,3>::Pointer &image )
{
  typedef itk::Image<unsigned char,3>        ImageType;
  typedef ImageType::Pointer ImagePointerType;

  ImagePointerType* rawPointer = new ImagePointerType( image );
  Rcpp::XPtr< ImagePointerType > xptr( rawPointer , true ) ;

  Rcpp::S4 itkImage( std::string( "antsImage" ) );
  itkImage.slot( "pixeltype" ) = "unsigned char";
  itkImage.slot( "dimension" ) = 3;
  itkImage.slot( "components" ) = 1;
  itkImage.slot( "isVector" ) = false;
  itkImage.slot( "pointer") = xptr;

  return(wrap(itkImage));
}

template <> inline
SEXP wrap( const itk::Image<unsigned char,4>::Pointer &image )
{
  typedef itk::Image<unsigned char,4>        ImageType;
  typedef ImageType::Pointer ImagePointerType;

  ImagePointerType* rawPointer = new ImagePointerType( image );
  Rcpp::XPtr< ImagePointerType > xptr( rawPointer , true ) ;

  Rcpp::S4 itkImage( std::string( "antsImage" ) );
  itkImage.slot( "pixeltype" ) = "unsigned char";
  itkImage.slot( "dimension" ) = 4;
  itkImage.slot( "components" ) = 1;
  itkImage.slot( "isVector" ) = false;
  itkImage.slot( "pointer") = xptr;

  return(wrap(itkImage));
}

template <class InputImageType, class OutputImageType>
typename OutputImageType::Pointer castSEXP( SEXP itkImageR )
{
  typedef itk::CastImageFilter<InputImageType,OutputImageType> FilterType;
  typename OutputImageType::Pointer output = NULL;

  Rcpp::S4 itkImageObject( itkImageR );

  if ( !( std::is_same<typename InputImageType::ValueType, typename OutputImageType::ValueType>::value ) ) {
    typename FilterType::Pointer filter = FilterType::New();
    typename InputImageType::Pointer img = Rcpp::as<typename InputImageType::Pointer>( itkImageR );
    filter->SetInput( img );
    filter->Update();
    output = filter->GetOutput();
    filter = NULL;
  }
  else {
    XPtr<typename OutputImageType::Pointer> xptr( static_cast<SEXP>( itkImageObject.slot("pointer") ));
    return *xptr;
  }
  return( output );
}


template <> inline
itk::Image<double,2>::Pointer as( SEXP itkImageR )
{
  const unsigned int Dim = 2;
  typedef itk::Image<double,Dim>        ImageType;

  Rcpp::S4 itkImageObject( itkImageR );

  if (!itkImageObject.is( "antsImage") ||
      (Rcpp::as<int>(itkImageObject.slot("dimension")) != Dim) ||
      (Rcpp::as<int>(itkImageObject.slot("components")) != 1) )
    {
    Rcpp::stop( "Invalid S4 object type in itk::Image<double,2>::Pointer Rcpp::as()");
    }

  if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "double" ) {
    return castSEXP<ImageType,ImageType>( itkImageR );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "float" ) {
    typedef itk::Image<float,Dim> PassedImageType;
    return castSEXP<PassedImageType,ImageType>( itkImageR );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "unsigned int" ) {
    typedef itk::Image<unsigned int,Dim> PassedImageType;
    return castSEXP<PassedImageType,ImageType>( itkImageR );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "unsigned char" ) {
    typedef itk::Image<unsigned char,Dim> PassedImageType;
    return castSEXP<PassedImageType,ImageType>( itkImageR );
  }

  // never reached
  Rcpp::Rcout << "Unsupported pixeltype: " <<
    Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) << std::endl;
  return NULL;

}

template <> inline
itk::Image<double,3>::Pointer as( SEXP itkImageR )
{

  const unsigned int Dim = 3;
  typedef itk::Image<double,Dim>        ImageType;
  Rcpp::S4 itkImageObject( itkImageR );

  if (!itkImageObject.is( "antsImage") ||
      (Rcpp::as<int>(itkImageObject.slot("dimension")) != Dim) ||
      (Rcpp::as<int>(itkImageObject.slot("components")) != 1) )
    {
    //print_antsimage_S4( itkImageR );
    Rcpp::stop( "Invalid S4 object type in itk::Image<double,3>::Pointer Rcpp::as()");
    }

  if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "double" ) {
    return( castSEXP<ImageType,ImageType>( itkImageR ) );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "float" ) {
    typedef itk::Image<float,Dim> PassedImageType;
    return( castSEXP<PassedImageType,ImageType>( itkImageR ) );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "unsigned int" ) {
    typedef itk::Image<unsigned int,Dim> PassedImageType;
    return( castSEXP<PassedImageType,ImageType>( itkImageR ) );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "unsigned char" ) {
    typedef itk::Image<unsigned char,Dim> PassedImageType;
    return( castSEXP<PassedImageType,ImageType>( itkImageR ) );
  }

  // never reached
  Rcpp::Rcout << "Unsupported pixeltype: " <<
    Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) << std::endl;
  return NULL;
}

template <> inline
itk::Image<double,4>::Pointer as( SEXP itkImageR )
{
  const unsigned int Dim = 4;
  typedef itk::Image<double,Dim>        ImageType;
  Rcpp::S4 itkImageObject( itkImageR );

  if (!itkImageObject.is( "antsImage") ||
      (Rcpp::as<int>(itkImageObject.slot("dimension")) != Dim) ||
      (Rcpp::as<int>(itkImageObject.slot("components")) != 1) )
    {
    Rcpp::stop( "Invalid S4 object type in itk::Image<double,4>::Pointer Rcpp::as()");
    }

  if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "double" ) {
    return( castSEXP<ImageType,ImageType>( itkImageR ) );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "float" ) {
    typedef itk::Image<float,Dim> PassedImageType;
    return( castSEXP<PassedImageType,ImageType>( itkImageR ) );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "unsigned int" ) {
    typedef itk::Image<unsigned int,Dim> PassedImageType;
    return( castSEXP<PassedImageType,ImageType>( itkImageR ) );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "unsigned char" ) {
    typedef itk::Image<unsigned char,Dim> PassedImageType;
    return( castSEXP<PassedImageType,ImageType>( itkImageR ) );
  }

  // never reached
  Rcpp::Rcout << "Unsupported pixeltype: " <<
    Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) << std::endl;
  return NULL;

}

template <> inline
itk::Image<float,2>::Pointer as( SEXP itkImageR )
{
  const unsigned int Dim = 2;
  typedef itk::Image<float,Dim>        ImageType;
  Rcpp::S4 itkImageObject( itkImageR );

  if (!itkImageObject.is( "antsImage") ||
      (Rcpp::as<int>(itkImageObject.slot("dimension")) != Dim) ||
      (Rcpp::as<int>(itkImageObject.slot("components")) != 1) )
    {
    Rcpp::stop( "Invalid S4 object type in itk::Image<float,2>::Pointer Rcpp::as()");
    }

  if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "float" ) {
    return( castSEXP<ImageType,ImageType>( itkImageR ) );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "double" ) {
    typedef itk::Image<double,Dim> PassedImageType;
    return( castSEXP<PassedImageType,ImageType>( itkImageR ) );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "unsigned int" ) {
    typedef itk::Image<unsigned int,Dim> PassedImageType;
    return( castSEXP<PassedImageType,ImageType>( itkImageR ) );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "unsigned char" ) {
    typedef itk::Image<unsigned char,Dim> PassedImageType;
    return( castSEXP<PassedImageType,ImageType>( itkImageR ) );
  }

  // never reached
  Rcpp::Rcout << "Unsupported pixeltype: " <<
    Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) << std::endl;
  return NULL;
}

template <> inline
itk::Image<float,3>::Pointer as( SEXP itkImageR )
{
  const unsigned int Dim = 3;
  typedef itk::Image<float,Dim>        ImageType;
  Rcpp::S4 itkImageObject( itkImageR );

  if (!itkImageObject.is( "antsImage") ||
      (Rcpp::as<int>(itkImageObject.slot("dimension")) != Dim) ||
      (Rcpp::as<int>(itkImageObject.slot("components")) != 1) )
    {
    Rcpp::stop( "Invalid S4 object type in itk::Image<float,3>::Pointer Rcpp::as()");
    }

  if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "float" ) {
    return( castSEXP<ImageType,ImageType>( itkImageR ) );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "double" ) {
    typedef itk::Image<double,Dim> PassedImageType;
    return( castSEXP<PassedImageType,ImageType>( itkImageR ) );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "unsigned int" ) {
    typedef itk::Image<unsigned int,Dim> PassedImageType;
    return( castSEXP<PassedImageType,ImageType>( itkImageR ) );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "unsigned char" ) {
    typedef itk::Image<unsigned char,Dim> PassedImageType;
    return( castSEXP<PassedImageType,ImageType>( itkImageR ) );
  }

  // never reached
  Rcpp::Rcout << "Unsupported pixeltype: " <<
    Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) << std::endl;
  return NULL;
}

template <> inline
itk::Image<float,4>::Pointer as( SEXP itkImageR )
{
  const unsigned int Dim = 4;
  typedef itk::Image<float,Dim>        ImageType;
  Rcpp::S4 itkImageObject( itkImageR );

  if (!itkImageObject.is( "antsImage") ||
      (Rcpp::as<int>(itkImageObject.slot("dimension")) != Dim) ||
      (Rcpp::as<int>(itkImageObject.slot("components")) != 1) )
    {
    Rcpp::stop( "Invalid S4 object type in itk::Image<float,4>::Pointer Rcpp::as()");
    }

  if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "float" ) {
    return( castSEXP<ImageType,ImageType>( itkImageR ) );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "double" ) {
    typedef itk::Image<double,Dim> PassedImageType;
    return( castSEXP<PassedImageType,ImageType>( itkImageR ) );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "unsigned int" ) {
    typedef itk::Image<unsigned int,Dim> PassedImageType;
    return( castSEXP<PassedImageType,ImageType>( itkImageR ) );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "unsigned char" ) {
    typedef itk::Image<unsigned char,Dim> PassedImageType;
    return( castSEXP<PassedImageType,ImageType>( itkImageR ) );
  }

  // never reached
  Rcpp::Rcout << "Unsupported pixeltype: " <<
    Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) << std::endl;
  return NULL;
}

template <> inline
itk::Image<unsigned int,2>::Pointer as( SEXP itkImageR )
{
  const unsigned int Dim = 2;
  typedef itk::Image<unsigned int,Dim>        ImageType;
  Rcpp::S4 itkImageObject( itkImageR );

  if (!itkImageObject.is( "antsImage") ||
      (Rcpp::as<int>(itkImageObject.slot("dimension")) != Dim) ||
      (Rcpp::as<int>(itkImageObject.slot("components")) != 1) )
    {
    Rcpp::stop( "Invalid S4 object type in  in itk::Image<unsigned int,2>::Pointer Rcpp::as()");
    }

  if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "unsigned int" ) {
    return( castSEXP<ImageType,ImageType>( itkImageR ) );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "double" ) {
    typedef itk::Image<double,Dim> PassedImageType;
    return( castSEXP<PassedImageType,ImageType>( itkImageR ) );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "float" ) {
    typedef itk::Image<float,Dim> PassedImageType;
    return( castSEXP<PassedImageType,ImageType>( itkImageR ) );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "unsigned char" ) {
    typedef itk::Image<unsigned char,Dim> PassedImageType;
    return( castSEXP<PassedImageType,ImageType>( itkImageR ) );
  }

  // never reached
  Rcpp::Rcout << "Unsupported pixeltype: " <<
    Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) << std::endl;
  return NULL;
}

template <> inline
itk::Image<unsigned int,3>::Pointer as( SEXP itkImageR )
{
  const unsigned int Dim = 3;
  typedef itk::Image<unsigned int,Dim>        ImageType;
  Rcpp::S4 itkImageObject( itkImageR );

  if (!itkImageObject.is( "antsImage") ||
      (Rcpp::as<int>(itkImageObject.slot("dimension")) != Dim) ||
      (Rcpp::as<int>(itkImageObject.slot("components")) != 1) )
    {
    Rcpp::stop( "Invalid S4 object type in itk::Image<unsigned int,3>::Pointer Rcpp::as()");
    }

  if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "unsigned int" ) {
    return( castSEXP<ImageType,ImageType>( itkImageR ) );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "double" ) {
    typedef itk::Image<double,Dim> PassedImageType;
    return( castSEXP<PassedImageType,ImageType>( itkImageR ) );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "float" ) {
    typedef itk::Image<float,Dim> PassedImageType;
    return( castSEXP<PassedImageType,ImageType>( itkImageR ) );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "unsigned char" ) {
    typedef itk::Image<unsigned char,Dim> PassedImageType;
    return( castSEXP<PassedImageType,ImageType>( itkImageR ) );
  }

  // never reached
  Rcpp::Rcout << "Unsupported pixeltype: " <<
    Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) << std::endl;
  return NULL;
}

template <> inline
itk::Image<unsigned int,4>::Pointer as( SEXP itkImageR )
{
  const unsigned int Dim = 4;
  typedef itk::Image<unsigned int,Dim>        ImageType;
  Rcpp::S4 itkImageObject( itkImageR );

  if (!itkImageObject.is( "antsImage") ||
      (Rcpp::as<int>(itkImageObject.slot("dimension")) != Dim) ||
      (Rcpp::as<int>(itkImageObject.slot("components")) != 1) )
    {
    Rcpp::stop( "Invalid S4 object type in itk::Image<unsigned int,4>::Pointer Rcpp::as()");
    }

  if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "unsigned int" ) {
    return( castSEXP<ImageType,ImageType>( itkImageR ) );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "double" ) {
    typedef itk::Image<double,Dim> PassedImageType;
    return( castSEXP<PassedImageType,ImageType>( itkImageR ) );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "float" ) {
    typedef itk::Image<float,Dim> PassedImageType;
    return( castSEXP<PassedImageType,ImageType>( itkImageR ) );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "unsigned char" ) {
    typedef itk::Image<unsigned char,Dim> PassedImageType;
    return( castSEXP<PassedImageType,ImageType>( itkImageR ) );
  }

  // never reached
  Rcpp::Rcout << "Unsupported pixeltype: " <<
    Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) << std::endl;
  return NULL;
}

template <> inline
itk::Image<unsigned char,2>::Pointer as( SEXP itkImageR )
{
  const unsigned int Dim = 2;
  typedef itk::Image<unsigned char,Dim>        ImageType;
  Rcpp::S4 itkImageObject( itkImageR );

  if (!itkImageObject.is( "antsImage") ||
      (Rcpp::as<int>(itkImageObject.slot("dimension")) != Dim) ||
      (Rcpp::as<int>(itkImageObject.slot("components")) != 1) )
    {
    Rcpp::stop( "Invalid S4 object type in itk::Image<unsigned char,2>::Pointer Rcpp::as()");
    }

  if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "unsigned char" ) {
    return( castSEXP<ImageType,ImageType>( itkImageR ) );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "double" ) {
    typedef itk::Image<double,Dim> PassedImageType;
    return( castSEXP<PassedImageType,ImageType>( itkImageR ) );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "float" ) {
    typedef itk::Image<float,Dim> PassedImageType;
    return( castSEXP<PassedImageType,ImageType>( itkImageR ) );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "unsigned ing" ) {
    typedef itk::Image<unsigned int,Dim> PassedImageType;
    return( castSEXP<PassedImageType,ImageType>( itkImageR ) );
  }

  // never reached
  Rcpp::Rcout << "Unsupported pixeltype: " <<
    Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) << std::endl;
  return NULL;
}

template <> inline
itk::Image<unsigned char,3>::Pointer as( SEXP itkImageR )
{
  const unsigned int Dim = 3;
  typedef itk::Image<unsigned char,Dim>        ImageType;
  Rcpp::S4 itkImageObject( itkImageR );

  if (!itkImageObject.is( "antsImage") ||
      (Rcpp::as<int>(itkImageObject.slot("dimension")) != Dim) ||
      (Rcpp::as<int>(itkImageObject.slot("components")) != 1) )
    {
    Rcpp::stop( "Invalid S4 object type in itk::Image<unsigned char,3>::Pointer Rcpp::as()");
    }

  if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "unsigned char" ) {
    return( castSEXP<ImageType,ImageType>( itkImageR ) );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "double" ) {
    typedef itk::Image<double,Dim> PassedImageType;
    return( castSEXP<PassedImageType,ImageType>( itkImageR ) );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "float" ) {
    typedef itk::Image<float,Dim> PassedImageType;
    return( castSEXP<PassedImageType,ImageType>( itkImageR ) );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "unsigned ing" ) {
    typedef itk::Image<unsigned int,Dim> PassedImageType;
    return( castSEXP<PassedImageType,ImageType>( itkImageR ) );
  }

  // never reached
  Rcpp::Rcout << "Unsupported pixeltype: " <<
    Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) << std::endl;
  return NULL;
}

template <> inline
itk::Image<unsigned char,4>::Pointer as( SEXP itkImageR )
{
  const unsigned int Dim = 4;
  typedef itk::Image<unsigned char,Dim>        ImageType;

  Rcpp::S4 itkImageObject( itkImageR );

  if (!itkImageObject.is( "antsImage") ||
      (Rcpp::as<int>(itkImageObject.slot("dimension")) != Dim) ||
      (Rcpp::as<int>(itkImageObject.slot("components")) != 1) )
    {
    Rcpp::stop( "Invalid S4 object type in itk::Image<unsigned char,4>::Pointer Rcpp::as()");
    }

  if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "unsigned char" ) {
    return( castSEXP<ImageType,ImageType>( itkImageR ) );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "double" ) {
    typedef itk::Image<double,Dim> PassedImageType;
    return( castSEXP<PassedImageType,ImageType>( itkImageR ) );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "float" ) {
    typedef itk::Image<float,Dim> PassedImageType;
    return( castSEXP<PassedImageType,ImageType>( itkImageR ) );
  }
  else if ( Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) == "unsigned ing" ) {
    typedef itk::Image<unsigned int,Dim> PassedImageType;
    return( castSEXP<PassedImageType,ImageType>( itkImageR ) );
  }

  // never reached
  Rcpp::Rcout << "Unsupported pixeltype: " <<
    Rcpp::as<std::string>(itkImageObject.slot("pixeltype")) << std::endl;
  return NULL;
}

}

#endif
