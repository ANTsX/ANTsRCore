#include <RcppANTsR.h>
#include "iMathFunctions3.h"

template <class ImageType>
SEXP iMathGE( Rcpp::List args )
{
  typedef typename ImageType::Pointer   ImagePointerType;

  ImagePointerType input = Rcpp::as<ImagePointerType>( args[0] );
  unsigned long radius = Rcpp::as<unsigned long>( args[2] );

  ImagePointerType output = ants::iMathGE<ImageType>( input, radius );

  return Rcpp::wrap(output);
}

template <class ImageType>
SEXP iMathGO( Rcpp::List args )
{
  typedef typename ImageType::Pointer   ImagePointerType;

  ImagePointerType input = Rcpp::as<ImagePointerType>( args[0] );
  unsigned long radius = Rcpp::as<unsigned long>( args[2] );

  ImagePointerType output = ants::iMathGO<ImageType>( input, radius );

  return Rcpp::wrap(output);
}


template <class ImageType>
SEXP iMathGetLargestComponent( Rcpp::List args )
{
  typedef typename ImageType::Pointer ImagePointerType;

  ImagePointerType input = Rcpp::as<ImagePointerType>( args[0] );
  unsigned int minSize = Rcpp::as<unsigned int>( args[2] );

  ImagePointerType output = ants::iMathGetLargestComponent<ImageType>( input, minSize );

  return Rcpp::wrap(output);
 }

template <class ImageType>
SEXP iMathGrad( Rcpp::List args )
{
  typedef typename ImageType::Pointer ImagePointerType;

  ImagePointerType input = Rcpp::as<ImagePointerType>( args[0] );
  double sigma = Rcpp::as<double>( args[2] );
  bool normalize = Rcpp::as<bool>( args[3] );

  ImagePointerType output = ants::iMathGrad<ImageType>( input, sigma, normalize );

  return Rcpp::wrap(output);
 }

 template <class ImageType>
 SEXP iMathHistogramEqualization( Rcpp::List args )
 {
   typedef typename ImageType::Pointer ImagePointerType;

   ImagePointerType input = Rcpp::as<ImagePointerType>( args[0] );
   double alpha = Rcpp::as<double>( args[2] );
   double beta = Rcpp::as<double>( args[3] );
   unsigned int r = Rcpp::as<unsigned int>( args[4] );
   ImagePointerType output = ants::iMathHistogramEqualization<ImageType>( input, alpha, beta, r );

   return Rcpp::wrap( output );
 }

template <class ImageType>
SEXP iMathGD( Rcpp::List args )
{
  typedef typename ImageType::Pointer   ImagePointerType;

  ImagePointerType input = Rcpp::as<ImagePointerType>( args[0] );
  unsigned long radius = Rcpp::as<unsigned long>( args[2] );

  ImagePointerType output = ants::iMathGD<ImageType>( input, radius );

  return Rcpp::wrap(output);
}
 
RcppExport SEXP iMathInterface3( SEXP r_args )
{
try
{
  Rcpp::List args(r_args);
  std::string operation = Rcpp::as< std::string >( args[1] );

  unsigned int dim = 0;
  unsigned int components = 0;
  std::string pixeltype = "";

    
  if ( operation == "GD" )
    {
    Rcpp::S4 image( args[0] );
    dim = Rcpp::as< int >( image.slot( "dimension" ) );
    components = Rcpp::as< int >( image.slot( "components" ) );
    pixeltype = Rcpp::as<std::string>( image.slot( "pixeltype") );

    if ( components > 1 )
      {
      Rcpp::stop("GD only supports scalar images");
      }

    // Optional parameters with default values
    if ( args.size() < 3 )
      {
      unsigned long radius = iMathGDRadius;
      args.push_back( Rcpp::wrap(radius) );  // radius
      }

    if ( pixeltype == "double" )
      {
      typedef double ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathGD<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathGD<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathGD<ImageType>( args );
        }
      }
    else if ( pixeltype == "float" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathGD<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathGD<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathGD<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned int" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathGD<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathGD<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathGD<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned char" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathGD<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathGD<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathGD<ImageType>( args );
        }
      }
    }
  else if ( operation == "GE" )
    {
    Rcpp::S4 image( args[0] );
    dim = Rcpp::as< int >( image.slot( "dimension" ) );
    components = Rcpp::as< int >( image.slot( "components" ) );
    pixeltype = Rcpp::as<std::string>( image.slot( "pixeltype") );

    if ( components > 1 )
      {
      Rcpp::stop("GE only supports scalar images");
      }

    // Optional parameters with default values
    if ( args.size() < 3 )
      {
      //unsigned long radius = iMathMERadius; //A_Bra
	  unsigned long radius = iMathGERadius;
      args.push_back( Rcpp::wrap(radius) );  // radius
      }

    if ( pixeltype == "double" )
      {
      typedef double ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathGE<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathGE<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathGE<ImageType>( args );
        }
      }
    else if ( pixeltype == "float" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathGE<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathGE<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathGE<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned int" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathGE<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathGE<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathGE<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned char" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathGE<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathGE<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathGE<ImageType>( args );
        }
      }
    }
  else if ( operation == "GO" )
    {
    Rcpp::S4 image( args[0] );
    dim = Rcpp::as< int >( image.slot( "dimension" ) );
    components = Rcpp::as< int >( image.slot( "components" ) );
    pixeltype = Rcpp::as<std::string>( image.slot( "pixeltype") );

    if ( components > 1 )
      {
      Rcpp::stop("GO only supports scalar images");
      }

    // Optional parameters with default values
    if ( args.size() < 3 )
      {
      unsigned long radius = iMathGORadius;
      args.push_back( Rcpp::wrap(radius) );  // radius
      }

    if ( pixeltype == "double" )
      {
      typedef double ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathGO<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathGO<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathGO<ImageType>( args );
        }
      }
    else if ( pixeltype == "float" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathGO<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathGO<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathGO<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned int" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathGO<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathGO<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathGO<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned char" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathGO<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathGO<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathGO<ImageType>( args );
        }
      }
    }
  else if ( operation == "GetLargestComponent" )
    {
    Rcpp::S4 image( args[0] );
    dim = Rcpp::as< int >( image.slot( "dimension" ) );
    components = Rcpp::as< int >( image.slot( "components" ) );
    pixeltype = Rcpp::as<std::string>( image.slot( "pixeltype") );

    if ( components > 1 )
      {
      Rcpp::stop("GetLargestComponent only supports scalar images");
      }

    // Optional parameters with defaul values
    if ( args.size() < 3 )
      {
      unsigned long minSize = iMathGetLargestComponentMinSize;
      args.push_back( Rcpp::wrap(minSize) );  // minSize
      }

    if ( pixeltype == "double" )
      {
      typedef double ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathGetLargestComponent<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathGetLargestComponent<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathGetLargestComponent<ImageType>( args );
        }
      }
    else if ( pixeltype == "float" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathGetLargestComponent<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathGetLargestComponent<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathGetLargestComponent<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned int" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathGetLargestComponent<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathGetLargestComponent<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathGetLargestComponent<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned char" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathGetLargestComponent<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathGetLargestComponent<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathGetLargestComponent<ImageType>( args );
        }
      }
    }
  else if ( operation == "Grad" )
    {
    Rcpp::S4 image( args[0] );
    dim = Rcpp::as< int >( image.slot( "dimension" ) );
    components = Rcpp::as< int >( image.slot( "components" ) );
    pixeltype = Rcpp::as<std::string>( image.slot( "pixeltype") );

    // Optional parameters with default values
    if ( args.size() < 3 )
      {
      double sigma = iMathGradSigma;
      args.push_back( Rcpp::wrap(sigma) );  // radius
      }
    if ( args.size() < 4 )
      {
      bool normalize = iMathGradNormalize;
      args.push_back( Rcpp::wrap(normalize) );  // radius
      }

    if ( pixeltype == "double" )
      {
      typedef double ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathGrad<ImageType>( args );
        }
      else if ( dim == 3 )
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathGrad<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathGrad<ImageType>( args );
        }
      }
    else if ( pixeltype == "float" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathGrad<ImageType>( args );
        }
      else if ( dim == 3 )
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathGrad<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathGrad<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned int" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathGrad<ImageType>( args );
        }
      else if ( dim == 3 )
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathGrad<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathGrad<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned char" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathGrad<ImageType>( args );
        }
      else if ( dim == 3 )
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathGrad<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathGrad<ImageType>( args );
        }
      }
    }
  else if ( operation == "HistogramEqualization" )
    {
    Rcpp::S4 image( args[0] );
    dim = Rcpp::as< int >( image.slot( "dimension" ) );
    components = Rcpp::as< int >( image.slot( "components" ) );
    pixeltype = Rcpp::as<std::string>( image.slot( "pixeltype") );

    if ( components > 1 )
      {
      Rcpp::stop("HistogramEqualization only supports scalar images");
      }

    if ( pixeltype == "double" )
      {
      typedef double ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathHistogramEqualization<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathHistogramEqualization<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathHistogramEqualization<ImageType>( args );
        }
      }
    else if ( pixeltype == "float" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathHistogramEqualization<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathHistogramEqualization<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathHistogramEqualization<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned int" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathHistogramEqualization<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathHistogramEqualization<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathHistogramEqualization<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned char" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathHistogramEqualization<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathHistogramEqualization<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathHistogramEqualization<ImageType>( args );
        }
      }
    }
 
  else
    {
    Rcpp::Rcout << "Operation = " << operation << std::endl;
    Rcpp::stop( "Unknown iMath operation");
    }

  return Rcpp::wrap(NA_REAL); // FIXME - for debugging only
}
catch( const itk::ExceptionObject& err )
  {
  Rcpp::Rcout << "ITK Exception" << std::endl;
  forward_exception_to_r( err );
  }
catch( const std::exception& exc )
  {
  Rcpp::Rcout << "STD Exception" << std::endl;
  forward_exception_to_r( exc );
  }
catch(...)
  {
	Rcpp::stop("c++ exception (unknown reason)");
  }

return Rcpp::wrap(NA_REAL); //not reached
}
