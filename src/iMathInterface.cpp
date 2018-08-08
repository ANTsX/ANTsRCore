#include <RcppANTsR.h>
#include "iMathFunctions.h"

template <class ImageType>
SEXP iMathCanny( Rcpp::List args )
{
  typedef typename ImageType::Pointer ImagePointerType;

  ImagePointerType input = Rcpp::as<ImagePointerType>( args[0] );
  double sigma = Rcpp::as<double>( args[2] );
  double lower = Rcpp::as<double>( args[3] );
  double upper = Rcpp::as<double>( args[4] );

  ImagePointerType output = ants::iMathCanny<ImageType>( input, sigma, lower, upper );

  return Rcpp::wrap(output);
 }

template <class ImageType>
SEXP iMathDistanceMap( Rcpp::List args )
{
  typedef typename ImageType::Pointer ImagePointerType;

  ImagePointerType input = Rcpp::as<ImagePointerType>( args[0] );
  bool useSpacing = Rcpp::as<bool>( args[2] );

  ImagePointerType output = ants::iMathDistanceMap<ImageType>( input, useSpacing );

  return Rcpp::wrap(output);
}

template <class ImageType>
SEXP iMathFillHoles( Rcpp::List args )
{
  typedef typename ImageType::Pointer ImagePointerType;

  ImagePointerType input = Rcpp::as<ImagePointerType>( args[0] );
  double holeParam = Rcpp::as<double>( args[2] );

  ImagePointerType output = ants::iMathFillHoles<ImageType>( input, holeParam );

  return Rcpp::wrap(output);
}

template <class ImageType>
SEXP iMathGC( Rcpp::List args )
{
  typedef typename ImageType::Pointer   ImagePointerType;

  ImagePointerType input = Rcpp::as<ImagePointerType>( args[0] );
  unsigned long radius = Rcpp::as<unsigned long>( args[2] );

  ImagePointerType output = ants::iMathGC<ImageType>( input, radius );

  return Rcpp::wrap(output);
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

<<<<<<< HEAD
=======
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
SEXP iMathLaplacian( Rcpp::List args )
{
  typedef typename ImageType::Pointer ImagePointerType;

  ImagePointerType input = Rcpp::as<ImagePointerType>( args[0] );
  double sigma = Rcpp::as<double>( args[2] );
  bool normalize = Rcpp::as<bool>( args[3] );

  ImagePointerType output = ants::iMathLaplacian<ImageType>( input, sigma, normalize );

  return Rcpp::wrap(output);
 }

template <class ImageType>
SEXP iMathMC( Rcpp::List args )
{
  typedef typename ImageType::Pointer   ImagePointerType;
  typedef typename ImageType::PixelType PixelType;

  ImagePointerType input = Rcpp::as<ImagePointerType>( args[0] );
  unsigned long radius = Rcpp::as<unsigned long>( args[2] );
  PixelType value = (PixelType) Rcpp::as<double>( args[3] );
  unsigned int shape = Rcpp::as<unsigned int>( args[4] );
  bool parametric = iMathGetFlatStructuringElementRadiusIsParametric;
  unsigned int lines = iMathGetFlatStructuringElementLines;
  if (shape == 5)
    {
    lines = Rcpp::as<unsigned int>( args[5] );
    }
  else
    {
    parametric = Rcpp::as<bool>( args[5] );
    }
  unsigned int thickness = Rcpp::as<unsigned int>( args[6] );
  bool center = Rcpp::as<bool>( args[7] );

  ImagePointerType output = ants::iMathMC<ImageType>( input, radius, value, shape,
                                                      parametric, lines, thickness, center );

  return Rcpp::wrap(output);
}

template <class ImageType>
SEXP iMathMD( Rcpp::List args )
{
  typedef typename ImageType::Pointer   ImagePointerType;
  typedef typename ImageType::PixelType PixelType;

  ImagePointerType input = Rcpp::as<ImagePointerType>( args[0] );
  unsigned long radius = Rcpp::as<unsigned long>( args[2] );
  PixelType value = (PixelType) Rcpp::as<double>( args[3] );
  unsigned int shape = Rcpp::as<unsigned int>( args[4] );
  bool parametric = iMathGetFlatStructuringElementRadiusIsParametric;
  unsigned int lines = iMathGetFlatStructuringElementLines;
  if (shape == 5)
    {
    lines = Rcpp::as<unsigned int>( args[5] );
    }
  else
    {
    parametric = Rcpp::as<bool>( args[5] );
    }
  unsigned int thickness = Rcpp::as<unsigned int>( args[6] );
  bool center = Rcpp::as<bool>( args[7] );

  ImagePointerType output = ants::iMathMD<ImageType>( input, radius, value, shape,
                                                      parametric, lines, thickness, center );

  return Rcpp::wrap(output);
 }

template <class ImageType>
SEXP iMathME( Rcpp::List args )
{
  typedef typename ImageType::Pointer   ImagePointerType;
  typedef typename ImageType::PixelType PixelType;

  ImagePointerType input = Rcpp::as<ImagePointerType>( args[0] );
  unsigned long radius = Rcpp::as<unsigned long>( args[2] );
  PixelType value = (PixelType) Rcpp::as<double>( args[3] );
  unsigned int shape = Rcpp::as<unsigned int>( args[4] );
  bool parametric = iMathGetFlatStructuringElementRadiusIsParametric;
  unsigned int lines = iMathGetFlatStructuringElementLines;
  if (shape == 5)
    {
    lines = Rcpp::as<unsigned int>( args[5] );
    }
  else
    {
    parametric = Rcpp::as<bool>( args[5] );
    }
  unsigned int thickness = Rcpp::as<unsigned int>( args[6] );
  bool center = Rcpp::as<bool>( args[7] );

  ImagePointerType output = ants::iMathME<ImageType>( input, radius, value, shape,
                                                      parametric, lines, thickness, center );

  return Rcpp::wrap(output);
 }

template <class ImageType>
SEXP iMathMO( Rcpp::List args )
{
  typedef typename ImageType::Pointer   ImagePointerType;
  typedef typename ImageType::PixelType PixelType;

  ImagePointerType input = Rcpp::as<ImagePointerType>( args[0] );
  unsigned long radius = Rcpp::as<unsigned long>( args[2] );
  PixelType value = (PixelType) Rcpp::as<double>( args[3] );
  unsigned int shape = Rcpp::as<unsigned int>( args[4] );
  bool parametric = iMathGetFlatStructuringElementRadiusIsParametric;
  unsigned int lines = iMathGetFlatStructuringElementLines;
  if (shape == 5)
    {
    lines = Rcpp::as<unsigned int>( args[5] );
    }
  else
    {
    parametric = Rcpp::as<bool>( args[5] );
    }
  unsigned int thickness = Rcpp::as<unsigned int>( args[6] );
  bool center = Rcpp::as<bool>( args[7] );

  ImagePointerType output = ants::iMathMO<ImageType>( input, radius, value, shape,
                                                      parametric, lines, thickness, center );

  return Rcpp::wrap(output);
 }

template <class ImageType>
SEXP iMathMaurerDistance( Rcpp::List args )
{
  typedef typename ImageType::Pointer   ImagePointerType;
  typedef typename ImageType::PixelType PixelType;

  ImagePointerType input = Rcpp::as<ImagePointerType>( args[0] );
  PixelType foreground = (PixelType) Rcpp::as<double>( args[2] );

  ImagePointerType output = ants::iMathMaurerDistance<ImageType>( input, foreground );

  return Rcpp::wrap(output);
}

template <class ImageType>
SEXP iMathNormalize( Rcpp::List args )
{
  typedef typename ImageType::Pointer ImagePointerType;

  ImagePointerType input = Rcpp::as<ImagePointerType>( args[0] );

  ImagePointerType output = ants::iMathNormalize<ImageType>( input );

  return Rcpp::wrap(output);
}

template <class ImageType>
SEXP iMathPad( Rcpp::List args )
{
  typedef typename ImageType::Pointer   ImagePointerType;

  ImagePointerType input = Rcpp::as<ImagePointerType>( args[0] );
  int padding = Rcpp::as<int>( args[2] );

  ImagePointerType output = ants::iMathPad<ImageType>( input, padding );

  return Rcpp::wrap(output);
}

template <class ImageType>
SEXP iMathPeronaMalik( Rcpp::List args )
{
  typedef typename ImageType::Pointer ImagePointerType;

  ImagePointerType input = Rcpp::as<ImagePointerType>( args[0] );
  unsigned long nIterations = Rcpp::as<unsigned long>( args[2] );
  double conductance = Rcpp::as<double>( args[3] );


  ImagePointerType output = ants::iMathPeronaMalik<ImageType>( input, nIterations, conductance );

  return Rcpp::wrap(output);
}

template <class ImageType>
SEXP iMathPropagateLabelsThroughMask( Rcpp::List args )
{
  typedef typename ImageType::Pointer ImagePointerType;

  ImagePointerType mask = Rcpp::as<ImagePointerType>( args[0] );
  ImagePointerType labels = Rcpp::as<ImagePointerType>( args[2] );
  double stoppingValue = Rcpp::as<double>( args[3] );
  unsigned int propagationMethod = Rcpp::as<unsigned int>( args[4] );

  ImagePointerType output = ants::iMathPropagateLabelsThroughMask<ImageType>( mask, labels, stoppingValue, propagationMethod );
  return Rcpp::wrap(output);
}

template <class ImageType>
SEXP iMathSharpen( Rcpp::List args )
{
  typedef typename ImageType::Pointer ImagePointerType;

  ImagePointerType input = Rcpp::as<ImagePointerType>( args[0] );

  ImagePointerType output = ants::iMathSharpen<ImageType>( input );

  return Rcpp::wrap(output);
}

template <class ImageType>
SEXP iMathTruncateIntensity( Rcpp::List args )
{
  const unsigned int ImageDimension = ImageType::ImageDimension;
  typedef typename ImageType::Pointer   ImagePointerType;
  typedef typename ImageType::PixelType PixelType;

  typedef itk::Image<unsigned int, ImageDimension>   MaskImageType;
  typedef typename MaskImageType::Pointer   MaskImagePointerType;

  ImagePointerType input = Rcpp::as<ImagePointerType>( args[0] );
  double lowerQ = (PixelType) Rcpp::as<double>( args[2] );
  double upperQ = (PixelType) Rcpp::as<double>( args[3] );
  int nBins = (PixelType) Rcpp::as<int>( args[4] );

  MaskImagePointerType mask = nullptr;

  if ( args.size() > 5 )
    {
    mask = Rcpp::as<MaskImagePointerType>( args[5] );
    }
  else
    {
    mask = MaskImageType::New();
    mask->SetSpacing( input->GetSpacing() );
    mask->SetOrigin( input->GetOrigin() );
    mask->SetDirection( input->GetDirection() );
    mask->SetRegions( input->GetLargestPossibleRegion() );
    mask->Allocate();
    mask->FillBuffer(1);
    }
>>>>>>> muschellij2/master


RcppExport SEXP iMathInterface( SEXP r_args )
{
try
{
  Rcpp::List args(r_args);
  std::string operation = Rcpp::as< std::string >( args[1] );

  unsigned int dim = 0;
  unsigned int components = 0;
  std::string pixeltype = "";

  if ( operation == "Canny" )
    {
    Rcpp::S4 image( args[0] );
    dim = Rcpp::as< int >( image.slot( "dimension" ) );
    components = Rcpp::as< int >( image.slot( "components" ) );
    pixeltype = Rcpp::as<std::string>( image.slot( "pixeltype") );

    if ( args.size() < 5 )
      {
      Rcpp::stop("To few input parameters");
      }

    if ( pixeltype == "double" )
      {
      typedef double ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathCanny<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathCanny<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathCanny<ImageType>( args );
        }
      }
    else if ( pixeltype == "float" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathCanny<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathCanny<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathCanny<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned int" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathCanny<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathCanny<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathCanny<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned char" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathCanny<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathCanny<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathCanny<ImageType>( args );
        }
      }

    }
  //else if ( operation == "DistanceMap" )
  else if ( operation == "D" )
    {
    Rcpp::S4 image( args[0] );
    dim = Rcpp::as< int >( image.slot( "dimension" ) );
    components = Rcpp::as< int >( image.slot( "components" ) );
    pixeltype = Rcpp::as<std::string>( image.slot( "pixeltype") );

    // Optional parameters with default values
    if ( args.size() < 3 )
      {
      bool useSpacing = iMathDistanceMapUseSpacing;
      args.push_back( Rcpp::wrap(useSpacing) );  // radius
      }

    if ( pixeltype == "double" )
      {
      typedef double ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathDistanceMap<ImageType>( args );
        }
      else if ( dim == 3 )
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathDistanceMap<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathDistanceMap<ImageType>( args );
        }
      }
    else if ( pixeltype == "float" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathDistanceMap<ImageType>( args );
        }
      else if ( dim == 3 )
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathDistanceMap<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathDistanceMap<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned int" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathDistanceMap<ImageType>( args );
        }
      else if ( dim == 3 )
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathDistanceMap<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathDistanceMap<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned char" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathDistanceMap<ImageType>( args );
        }
      else if ( dim == 3 )
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathDistanceMap<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathDistanceMap<ImageType>( args );
        }
      }
    }
  else if ( operation == "FillHoles" )
    {
    Rcpp::S4 image( args[0] );
    dim = Rcpp::as< int >( image.slot( "dimension" ) );
    components = Rcpp::as< int >( image.slot( "components" ) );
    pixeltype = Rcpp::as<std::string>( image.slot( "pixeltype") );

    // Optional parameters with default values
    if ( args.size() < 3 )
      {
      double holeParam = iMathFillHolesHoleParam;
      args.push_back( Rcpp::wrap(holeParam) );  // radius
      }

    if ( pixeltype == "double" )
      {
      typedef double ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathFillHoles<ImageType>( args );
        }
      else if ( dim == 3 )
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathFillHoles<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathFillHoles<ImageType>( args );
        }
      }
    else if ( pixeltype == "float" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathFillHoles<ImageType>( args );
        }
      else if ( dim == 3 )
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathFillHoles<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathFillHoles<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned int" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathFillHoles<ImageType>( args );
        }
      else if ( dim == 3 )
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathFillHoles<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathFillHoles<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned char" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathFillHoles<ImageType>( args );
        }
      else if ( dim == 3 )
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathFillHoles<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathFillHoles<ImageType>( args );
        }
      }
    }
  else if ( operation == "GC" )
    {
    Rcpp::S4 image( args[0] );
    dim = Rcpp::as< int >( image.slot( "dimension" ) );
    components = Rcpp::as< int >( image.slot( "components" ) );
    pixeltype = Rcpp::as<std::string>( image.slot( "pixeltype") );

    if ( components > 1 )
      {
      Rcpp::stop("GC only supports scalar images");
      }

    // Optional parameters with default values
    if ( args.size() < 3 )
      {
      unsigned long radius = iMathGCRadius;
      args.push_back( Rcpp::wrap(radius) );  // radius
      }

    if ( pixeltype == "double" )
      {
      typedef double ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathGC<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathGC<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathGC<ImageType>( args );
        }
      }
    else if ( pixeltype == "float" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathGC<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathGC<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathGC<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned int" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathGC<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathGC<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathGC<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned char" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathGC<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathGC<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathGC<ImageType>( args );
        }
      }
    }
  else if ( operation == "GD" )
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
