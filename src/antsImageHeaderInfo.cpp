#include <exception>
#include <vector>
#include <string>
#include <Rcpp.h>
#include "itkImage.h"
#include "itkImageFileReader.h"

RcppExport SEXP antsImageHeaderInfo( SEXP r_filename )
try
{
  std::string fname = Rcpp::as<std::string>(r_filename);

  itk::ImageIOBase::Pointer imageIO =
      itk::ImageIOFactory::CreateImageIO(
          fname.c_str(), itk::ImageIOFactory::ReadMode);

  if ( !imageIO->CanReadFile(fname.c_str()) )
  {
    Rcpp::stop("Can't read this file format");
  }

  imageIO->SetFileName(fname);
  imageIO->ReadImageInformation();

  const size_t numDimensions =  imageIO->GetNumberOfDimensions();
  const size_t numComponents = imageIO->GetNumberOfComponents();
  const std::string pixelClass( imageIO->GetPixelTypeAsString(imageIO->GetPixelType()) );
  const unsigned int pixelCode = imageIO->GetComponentType();

  Rcpp::NumericVector dimensions( numDimensions );
  Rcpp::NumericVector spacing( numDimensions );
  Rcpp::NumericVector origin( numDimensions );
  Rcpp::NumericMatrix direction( numDimensions, numDimensions );

  for (unsigned int i=0; i<numDimensions; i++)
    {

    dimensions[i] = imageIO->GetDimensions(i);
    spacing[i] = imageIO->GetSpacing(i);
    origin[i] = imageIO->GetOrigin(i);
    for (unsigned int j=0; j<numDimensions; j++)
      {
      direction(i,j) = imageIO->GetDirection(i)[j];
      }
    }

  std::string pixeltype = "unknown";

  switch( pixelCode )
    {
    case itk::ImageIOBase::IOComponentType::UNKNOWNCOMPONENTTYPE: // UNKNOWNCOMPONENTTYPE - exception here?
      pixeltype = "unknown";
      break;
    case itk::ImageIOBase::IOComponentType::UCHAR: // UCHAR
      pixeltype = "unsigned char";
      break;
    case itk::ImageIOBase::IOComponentType::CHAR: // CHAR
      pixeltype = "char";
      break;
    case itk::ImageIOBase::IOComponentType::USHORT: // USHORT
      pixeltype = "unsigned short";
      break;
    case itk::ImageIOBase::IOComponentType::SHORT: // SHORT
      pixeltype = "short";
      break;
    case itk::ImageIOBase::IOComponentType::UINT: // UINT
      pixeltype = "unsigned int";
      break;
    case itk::ImageIOBase::IOComponentType::INT: // INT
      pixeltype = "int";
      break;
    case itk::ImageIOBase::IOComponentType::ULONG: // ULONG
      pixeltype = "unsigned long";
      break;
    case itk::ImageIOBase::IOComponentType::LONG: // LONG
      pixeltype = "long";
      break;
    case itk::ImageIOBase::IOComponentType::ULONGLONG: // LONGLONG
      pixeltype = "ulonglong";
      break;
    case itk::ImageIOBase::IOComponentType::LONGLONG: // LONGLONG
      pixeltype = "longlong";
      break;
    case itk::ImageIOBase::IOComponentType::FLOAT: // FLOAT
      pixeltype = "float";
      break;
    case itk::ImageIOBase::IOComponentType::DOUBLE: // DOUBLE
      pixeltype = "double";
      break;
    default:
      Rcpp::stop("Invalid pixel type in image header");
    }

  return Rcpp::List::create( Rcpp::Named("pixelclass", Rcpp::wrap(pixelClass)),
                             Rcpp::Named("pixeltype", Rcpp::wrap(pixeltype)),
                             Rcpp::Named("nDimensions", Rcpp::wrap(numDimensions)),
                             Rcpp::Named("nComponents", Rcpp::wrap(numComponents)),
                             Rcpp::Named("dimensions", dimensions),
                             Rcpp::Named("spacing", spacing),
                             Rcpp::Named("origin", origin),
                             Rcpp::Named("direction", direction) );
}
catch( itk::ExceptionObject & err )
{
  Rcpp::Rcout << "ExceptionObject caught !" << std::endl;
  Rcpp::Rcout << err << std::endl;

  // Since the goal of the example is to catch the exception,
  // we declare this a success.
  Rcpp::stop("ITK exception caught");
  return Rcpp::wrap( NA_REAL ) ;
}
