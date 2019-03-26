
#include <exception>
#include <vector>
#include <string>
#include <RcppANTsR.h>

#include "itkImageFileWriter.h"
#include "itkCastImageFilter.h"
#include "itkImage.h"
#include "itkVectorImage.h"
#include "itkDiffusionTensor3D.h"
#include "itkDefaultConvertPixelTraits.h"

namespace ants
{

  template< class ImageType >
  int antsImageWrite( SEXP r_image , // image to write
                      std::string filename, bool asTensor )
  {
    typedef typename ImageType::Pointer ImagePointerType;
    ImagePointerType image = Rcpp::as<ImagePointerType>( r_image );

    if ( !asTensor ) {
      typedef itk::ImageFileWriter< ImageType > ImageWriterType ;
      typename ImageWriterType::Pointer image_writer = ImageWriterType::New() ;
      image_writer->SetFileName( filename.c_str() ) ;
      image_writer->SetInput( image );
      image_writer->Update();
    }
    else {
      typedef typename ImageType::PixelType         PixelType;
      typedef typename ImageType::InternalPixelType ValueType;
      typedef typename itk::DiffusionTensor3D< ValueType > TensorType;
      typedef itk::Image< TensorType, ImageType::ImageDimension> TensorImageType;
      typedef itk::ImageFileWriter<TensorImageType> ImageWriterType;

      typename TensorImageType::Pointer out_image = TensorImageType::New() ;
      out_image->SetRegions( image->GetLargestPossibleRegion() ) ;
      out_image->SetSpacing( image->GetSpacing() ) ;
      out_image->SetOrigin( image->GetOrigin() ) ;
      out_image->SetDirection( image->GetDirection() );
      out_image->Allocate() ;

      itk::ImageRegionConstIterator< ImageType > in_iterator( image , image->GetLargestPossibleRegion() ) ;
      itk::ImageRegionIterator< TensorImageType > out_iterator( out_image , out_image->GetLargestPossibleRegion() ) ;
      for( in_iterator.GoToBegin() , out_iterator.GoToBegin() ; !in_iterator.IsAtEnd() ; ++in_iterator , ++out_iterator )
        {
        PixelType pix = in_iterator.Get();
        TensorType ten;
        for (unsigned int i=0; i<image->GetNumberOfComponentsPerPixel(); i++ )
          {
          ValueType v = itk::DefaultConvertPixelTraits<PixelType>::GetNthComponent(i, pix);
          itk::DefaultConvertPixelTraits<TensorType>::SetNthComponent(i, ten, v);
          }
  	    out_iterator.Set(ten);
        }

      typename ImageWriterType::Pointer image_writer = ImageWriterType::New();
      image_writer->SetInput( out_image );
      image_writer->SetFileName( filename.c_str() );
      image_writer->Update();

    }
    return 0;
  }

} // namespace ants

RcppExport SEXP antsImageWrite( SEXP r_img , SEXP r_filename, SEXP r_asTensor )
{
try
{
  // check and set the filename
  if( r_img == NULL || r_filename == NULL || r_asTensor == NULL)
    {
    Rcpp::stop("Unspecified Arguments");
    }

  bool verbose = false;
  std::string filename = Rcpp::as< std::string >( r_filename );
  Rcpp::S4 r_image( r_img ) ;
  bool asTensor = Rcpp::as<bool>( r_asTensor );
  std::string pixeltype = Rcpp::as< std::string >( r_image.slot( "pixeltype" ));
  unsigned int dimension = Rcpp::as< unsigned int >( r_image.slot( "dimension" ));
  unsigned int components = Rcpp::as< unsigned int >( r_image.slot( "components"));

  if ( components != 6 ) {
    asTensor = false;
  }

  if ( (dimension < 2) || (dimension > 4) )
    {
    Rcpp::stop( "Unsupported image dimension");
    }
  if ( (pixeltype != "double") &&
       (pixeltype != "float") &&
       (pixeltype != "unsigned int") &&
       (pixeltype != "unsigned char") )
    {
    Rcpp::stop( "Unsupported pixeltype");
    }

  // write the image
  if ( pixeltype == "double" )
    {
    typedef double PixelType;

    if( dimension == 4 )
      {
      const int ImageDimension = 4;
      typedef itk::Image< PixelType , ImageDimension >      ImageType;
      typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;

      (components == 1) ?
        ants::antsImageWrite< ImageType >( r_img, filename, asTensor ) :
        ants::antsImageWrite< VectorImageType >( r_img, filename, asTensor );

      if ( verbose ) Rcpp::Rcout << "Done writing image. PixelType: 'double' | Dimension: '4'." << std::endl ;
      return Rcpp::wrap( 0 );
      }
    else if( dimension == 3 )
      {
      const int ImageDimension = 3 ;
      typedef itk::Image< PixelType , ImageDimension >      ImageType;
      typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;

      (components == 1) ?
        ants::antsImageWrite< ImageType >( r_img, filename, asTensor ) :
        ants::antsImageWrite< VectorImageType >( r_img, filename, asTensor );

      if ( verbose ) Rcpp::Rcout << "Done writing image. PixelType: 'double' | Dimension: '4'." << std::endl;
      return Rcpp::wrap( 0 ) ;
      }
    else if( dimension == 2 )
      {
      const int ImageDimension = 2 ;
      typedef itk::Image< PixelType , ImageDimension >      ImageType;
      typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;

      (components == 1) ?
        ants::antsImageWrite< ImageType >( r_img, filename, asTensor ) :
        ants::antsImageWrite< VectorImageType >( r_img, filename, asTensor );

      if ( verbose ) Rcpp::Rcout << "Done writing image. PixelType: 'double' | Dimension: '4'." << std::endl;
      return Rcpp::wrap( 0 );
      }
    }
  else if ( pixeltype == "float" )
    {
    typedef float PixelType;

    if( dimension == 4 )
      {
      const int ImageDimension = 4;
      typedef itk::Image< PixelType , ImageDimension >      ImageType;
      typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;

      (components == 1) ?
        ants::antsImageWrite< ImageType >( r_img, filename, asTensor ) :
        ants::antsImageWrite< VectorImageType >( r_img, filename, asTensor );

      if ( verbose ) Rcpp::Rcout << "Done writing image. PixelType: 'double' | Dimension: '4'." << std::endl ;
      return Rcpp::wrap( 0 );
      }
    else if( dimension == 3 )
      {
      const int ImageDimension = 3 ;
      typedef itk::Image< PixelType , ImageDimension >      ImageType;
      typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;

      (components == 1) ?
        ants::antsImageWrite< ImageType >( r_img, filename, asTensor ) :
        ants::antsImageWrite< VectorImageType >( r_img, filename, asTensor );

      if ( verbose ) Rcpp::Rcout << "Done writing image. PixelType: 'double' | Dimension: '4'." << std::endl ;
      return Rcpp::wrap( 0 ) ;
      }
    else if( dimension == 2 )
      {
      const int ImageDimension = 2 ;
      typedef itk::Image< PixelType , ImageDimension >      ImageType;
      typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;

      (components == 1) ?
        ants::antsImageWrite< ImageType >( r_img, filename, asTensor ) :
        ants::antsImageWrite< VectorImageType >( r_img, filename, asTensor );

      if ( verbose ) Rcpp::Rcout << "Done writing image. PixelType: 'double' | Dimension: '4'." << std::endl ;
      return Rcpp::wrap( 0 ) ;
      }
    }
  else if ( pixeltype == "unsigned int" )
    {
    typedef unsigned int PixelType;

    if( dimension == 4 )
      {
      const int ImageDimension = 4;
      typedef itk::Image< PixelType , ImageDimension >      ImageType;
      typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;

      (components == 1) ?
        ants::antsImageWrite< ImageType >( r_img, filename, asTensor ) :
        ants::antsImageWrite< VectorImageType >( r_img, filename, asTensor );

      if ( verbose ) Rcpp::Rcout << "Done writing image. PixelType: 'double' | Dimension: '4'." << std::endl ;
      return Rcpp::wrap( 0 );
      }
    else if( dimension == 3 )
      {
      const int ImageDimension = 3 ;
      typedef itk::Image< PixelType , ImageDimension >      ImageType;
      typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;

      (components == 1) ?
        ants::antsImageWrite< ImageType >( r_img, filename, asTensor ) :
        ants::antsImageWrite< VectorImageType >( r_img, filename, asTensor );

      if ( verbose ) Rcpp::Rcout << "Done writing image. PixelType: 'double' | Dimension: '4'." << std::endl ;
      return Rcpp::wrap( 0 ) ;
      }
    else if( dimension == 2 )
      {
      const int ImageDimension = 2 ;
      typedef itk::Image< PixelType , ImageDimension >      ImageType;
      typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;

      (components == 1) ?
        ants::antsImageWrite< ImageType >( r_img, filename, asTensor ) :
        ants::antsImageWrite< VectorImageType >( r_img, filename, asTensor );

      if ( verbose ) Rcpp::Rcout << "Done writing image. PixelType: 'double' | Dimension: '4'." << std::endl ;
      return Rcpp::wrap( 0 ) ;
      }
    }
  else if ( pixeltype == "unsigned char" )
    {
    typedef unsigned char PixelType;

    if( dimension == 4 )
      {
      const int ImageDimension = 4;
      typedef itk::Image< PixelType , ImageDimension >      ImageType;
      typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;

      (components == 1) ?
        ants::antsImageWrite< ImageType >( r_img, filename, asTensor ) :
        ants::antsImageWrite< VectorImageType >( r_img, filename, asTensor );

      if ( verbose ) Rcpp::Rcout << "Done writing image. PixelType: 'double' | Dimension: '4'." << std::endl ;
      return Rcpp::wrap( 0 );
      }
    else if( dimension == 3 )
      {
      const int ImageDimension = 3 ;
      typedef itk::Image< PixelType , ImageDimension >      ImageType;
      typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;

      (components == 1) ?
        ants::antsImageWrite< ImageType >( r_img, filename, asTensor ) :
        ants::antsImageWrite< VectorImageType >( r_img, filename, asTensor );

      if ( verbose ) Rcpp::Rcout << "Done writing image. PixelType: 'double' | Dimension: '4'." << std::endl ;
      return Rcpp::wrap( 0 ) ;
      }
    else if( dimension == 2 )
      {
      const int ImageDimension = 2 ;
      typedef itk::Image< PixelType , ImageDimension >      ImageType;
      typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;

      (components == 1) ?
        ants::antsImageWrite< ImageType >( r_img, filename, asTensor ) :
        ants::antsImageWrite< VectorImageType >( r_img, filename, asTensor );

      if ( verbose ) Rcpp::Rcout << "Done writing image. PixelType: 'double' | Dimension: '4'." << std::endl ;
      return Rcpp::wrap( 0 ) ;
      }
    }
}
catch( const itk::ExceptionObject& err )
  {
  forward_exception_to_r( err );
  }
catch( const std::exception& exc )
  {
  forward_exception_to_r( exc );
  }
catch(...)
  {
	Rcpp::stop("c++ exception (unknown reason)");
  }
return Rcpp::wrap(NA_REAL); //not reached
}
