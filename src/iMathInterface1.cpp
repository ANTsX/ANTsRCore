#include <RcppANTsR.h>
#include <iMathFunctions1.h>


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

  ImagePointerType output = ants::iMathTruncateIntensity<ImageType>( input, lowerQ, upperQ, nBins, mask );

  return Rcpp::wrap(output);
}

RcppExport SEXP iMathInterface1( SEXP r_args )
{
try
{
  Rcpp::List args(r_args);
  std::string operation = Rcpp::as< std::string >( args[1] );

  unsigned int dim = 0;
  unsigned int components = 0;
  std::string pixeltype = "";

  if ( operation == "Laplacian" )
    {
    Rcpp::S4 image( args[0] );
    dim = Rcpp::as< int >( image.slot( "dimension" ) );
    components = Rcpp::as< int >( image.slot( "components" ) );
    pixeltype = Rcpp::as<std::string>( image.slot( "pixeltype") );

    // Optional parameters with default values
    if ( args.size() < 3 )
      {
      double sigma = iMathLaplacianSigma;
      args.push_back( Rcpp::wrap(sigma) );  // radius
      }
    if ( args.size() < 4 )
      {
      bool normalize = iMathLaplacianNormalize;
      args.push_back( Rcpp::wrap(normalize) );  // radius
      }

    if ( pixeltype == "double" )
      {
      typedef double ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathLaplacian<ImageType>( args );
        }
      else if ( dim == 3 )
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathLaplacian<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathLaplacian<ImageType>( args );
        }
      }
    else if ( pixeltype == "float" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathLaplacian<ImageType>( args );
        }
      else if ( dim == 3 )
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathLaplacian<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathLaplacian<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned int" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathLaplacian<ImageType>( args );
        }
      else if ( dim == 3 )
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathLaplacian<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathLaplacian<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned char" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathLaplacian<ImageType>( args );
        }
      else if ( dim == 3 )
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathLaplacian<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathLaplacian<ImageType>( args );
        }
      }
    }
  else if ( operation == "MC" )
    {
    Rcpp::S4 image( args[0] );
    dim = Rcpp::as< int >( image.slot( "dimension" ) );
    components = Rcpp::as< int >( image.slot( "components" ) );
    pixeltype = Rcpp::as<std::string>( image.slot( "pixeltype") );

    if ( components > 1 )
      {
      Rcpp::stop("MC only supports scalar images");
      }

    // Optional parameters with default values
    unsigned int shape = iMathGetFlatStructuringElementShape;
    if ( args.size() < 3 )
      {
      unsigned long radius = iMathMCRadius;
      args.push_back( Rcpp::wrap(radius) );  // radius
      }
    if ( args.size() < 4)
      {
      double value = iMathMCValue;
      args.push_back( Rcpp::wrap(value));
      }
    if ( args.size() < 5)
      {
      args.push_back( Rcpp::wrap(shape));
      }
    else
      {
      shape = Rcpp::as<unsigned int>( args[5] );
      }
    if ( args.size() < 6)
      {
      if ( shape==5 )
        {
        unsigned int lines = iMathGetFlatStructuringElementLines;
        args.push_back( Rcpp::wrap(lines));
        }
      else
        {
        bool parametric = iMathGetFlatStructuringElementRadiusIsParametric;
        args.push_back(Rcpp::wrap(parametric));
        }
      }
    if ( args.size() < 7)
      {
      unsigned int thickness = iMathGetFlatStructuringElementThickness;
      args.push_back( Rcpp::wrap(thickness));
      }
    if ( args.size() < 8)
      {
      bool center = iMathGetFlatStructuringElementIncludeCenter;
      args.push_back( Rcpp::wrap(center));
      }

    if ( pixeltype == "double" )
      {
      typedef double ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathMC<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathMC<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathMC<ImageType>( args );
        }
      }
    else if ( pixeltype == "float" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathMC<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathMC<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathMC<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned int" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathMC<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathMC<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathMC<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned char" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathMC<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathMC<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathMC<ImageType>( args );
        }
      }
    }
  else if ( operation == "MD" )
    {
    Rcpp::S4 image( args[0] );
    dim = Rcpp::as< int >( image.slot( "dimension" ) );
    components = Rcpp::as< int >( image.slot( "components" ) );
    pixeltype = Rcpp::as<std::string>( image.slot( "pixeltype") );

    if ( components > 1 )
      {
      Rcpp::stop("MD only supports scalar images");
      }

    // Optional parameters with default values
    unsigned int shape = iMathGetFlatStructuringElementShape;
    if ( args.size() < 3 )
      {
      unsigned long radius = iMathMDRadius;
      args.push_back( Rcpp::wrap(radius) );  // radius
      }
    if ( args.size() < 4)
      {
      double value = iMathMDValue;
      args.push_back( Rcpp::wrap(value));
      }
    if ( args.size() < 5)
      {
      args.push_back( Rcpp::wrap(shape));
      }
    else
      {
      shape = Rcpp::as<unsigned int>( args[5] );
      }
    if ( args.size() < 6)
      {
      if ( shape==5 )
        {
        unsigned int lines = iMathGetFlatStructuringElementLines;
        args.push_back( Rcpp::wrap(lines));
        }
      else
        {
        bool parametric = iMathGetFlatStructuringElementRadiusIsParametric;
        args.push_back(Rcpp::wrap(parametric));
        }
      }
    if ( args.size() < 7)
      {
      unsigned int thickness = iMathGetFlatStructuringElementThickness;
      args.push_back( Rcpp::wrap(thickness));
      }
    if ( args.size() < 8)
      {
      bool center = iMathGetFlatStructuringElementIncludeCenter;
      args.push_back( Rcpp::wrap(center));
      }

    if ( pixeltype == "double" )
      {
      typedef double ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathMD<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathMD<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathMD<ImageType>( args );
        }
      }
    else if ( pixeltype == "float" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathMD<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathMD<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathMD<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned int" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathMD<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathMD<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathMD<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned char" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathMD<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathMD<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathMD<ImageType>( args );
        }
      }
    }
  else if ( operation == "ME" )
    {
    Rcpp::S4 image( args[0] );
    dim = Rcpp::as< int >( image.slot( "dimension" ) );
    components = Rcpp::as< int >( image.slot( "components" ) );
    pixeltype = Rcpp::as<std::string>( image.slot( "pixeltype") );

    if ( components > 1 )
      {
      Rcpp::stop("ME only supports scalar images");
      }

    // Optional parameters with default values
    unsigned int shape = iMathGetFlatStructuringElementShape;
    if ( args.size() < 3 )
      {
      unsigned long radius = iMathMERadius;
      args.push_back( Rcpp::wrap(radius) );  // radius
      }
    if ( args.size() < 4)
      {
      double value = iMathMDValue;
      args.push_back( Rcpp::wrap(value));
      }
    if ( args.size() < 5)
      {
      args.push_back( Rcpp::wrap(shape) );
      }
    else
      {
      shape = Rcpp::as<unsigned int>( args[4] );
      }
    if ( args.size() < 6)
      {
      if ( shape==5 )
        {
        unsigned int lines = iMathGetFlatStructuringElementLines;
        args.push_back( Rcpp::wrap(lines));
        }
      else
        {
        bool parametric = iMathGetFlatStructuringElementRadiusIsParametric;
        args.push_back(Rcpp::wrap(parametric));
        }
      }
    if ( args.size() < 7)
      {
      unsigned int thickness = iMathGetFlatStructuringElementThickness;
      args.push_back( Rcpp::wrap(thickness));
      }
    if ( args.size() < 8)
      {
      bool center = iMathGetFlatStructuringElementIncludeCenter;
      args.push_back( Rcpp::wrap(center));
      }

    if ( pixeltype == "double" )
      {
      typedef double ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathME<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathME<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathME<ImageType>( args );
        }
      }
    else if ( pixeltype == "float" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathME<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathME<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathME<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned int" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathME<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathME<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathME<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned char" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathME<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathME<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathME<ImageType>( args );
        }
      }
    }
  else if ( operation == "MO" )
    {
    Rcpp::S4 image( args[0] );
    dim = Rcpp::as< int >( image.slot( "dimension" ) );
    components = Rcpp::as< int >( image.slot( "components" ) );
    pixeltype = Rcpp::as<std::string>( image.slot( "pixeltype") );

    if ( components > 1 )
      {
      Rcpp::stop("MO only supports scalar images");
      }

    // Optional parameters with default values
    unsigned int shape = iMathGetFlatStructuringElementShape;
    if ( args.size() < 3 )
      {
      unsigned long radius = iMathMORadius;
      args.push_back( Rcpp::wrap(radius) );  // radius
      }
    if ( args.size() < 4)
      {
      double value = iMathMDValue;
      args.push_back( Rcpp::wrap(value));
      }
    if ( args.size() < 5)
      {
      args.push_back( Rcpp::wrap(shape));
      }
    else
      {
      shape = Rcpp::as<unsigned int>( args[5] );
      }
    if ( args.size() < 6)
      {
      if ( shape==5 )
        {
        unsigned int lines = iMathGetFlatStructuringElementLines;
        args.push_back( Rcpp::wrap(lines));
        }
      else
        {
        bool parametric = iMathGetFlatStructuringElementRadiusIsParametric;
        args.push_back(Rcpp::wrap(parametric));
        }
      }
    if ( args.size() < 7)
      {
      unsigned int thickness = iMathGetFlatStructuringElementThickness;
      args.push_back( Rcpp::wrap(thickness));
      }
    if ( args.size() < 8)
      {
      bool center = iMathGetFlatStructuringElementIncludeCenter;
      args.push_back( Rcpp::wrap(center));
      }

    if ( pixeltype == "double" )
      {
      typedef double ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathMO<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathMO<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathMO<ImageType>( args );
        }
      }
    else if ( pixeltype == "float" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathMO<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathMO<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathMO<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned int" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathMO<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathMO<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathMO<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned char" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathMO<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathMO<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathMO<ImageType>( args );
        }
      }
    }
  else if ( operation == "MaurerDistance" )
    {
    Rcpp::S4 image( args[0] );
    dim = Rcpp::as< int >( image.slot( "dimension" ) );
    components = Rcpp::as< int >( image.slot( "components" ) );
    pixeltype = Rcpp::as<std::string>( image.slot( "pixeltype") );

    if ( components > 1 )
      {
      Rcpp::stop("MaurerDistance only supports scalar images");
      }

    // Optional parameters with default values
    if ( args.size() < 3 )
      {
      double foreground = iMathMaurerDistanceForeground;
      args.push_back( Rcpp::wrap(foreground) );  // radius
      }

    if ( pixeltype == "double" )
      {
      typedef double ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathMaurerDistance<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathMaurerDistance<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathMaurerDistance<ImageType>( args );
        }
      }
    else if ( pixeltype == "float" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathMaurerDistance<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathMaurerDistance<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathMaurerDistance<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned int" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathMaurerDistance<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathMaurerDistance<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathMaurerDistance<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned char" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathMaurerDistance<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathMaurerDistance<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathMaurerDistance<ImageType>( args );
        }
      }
    }
  else if ( operation == "Normalize" )
    {
    Rcpp::S4 image( args[0] );
    dim = Rcpp::as< int >( image.slot( "dimension" ) );
    components = Rcpp::as< int >( image.slot( "components" ) );
    pixeltype = Rcpp::as<std::string>( image.slot( "pixeltype") );

    if ( components > 1 )
      {
      Rcpp::stop("Normalize only supports scalar images");
      }

    if ( pixeltype == "double" )
      {
      typedef double ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathNormalize<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathNormalize<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathNormalize<ImageType>( args );
        }
      }
    else if ( pixeltype == "float" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathNormalize<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathNormalize<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathNormalize<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned int" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathNormalize<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathNormalize<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathNormalize<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned char" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathNormalize<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathNormalize<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathNormalize<ImageType>( args );
        }
      }
    }
  else if ( operation == "PadImage" )
    {
    Rcpp::S4 image( args[0] );
    dim = Rcpp::as< int >( image.slot( "dimension" ) );
    components = Rcpp::as< int >( image.slot( "components" ) );
    pixeltype = Rcpp::as<std::string>( image.slot( "pixeltype") );

    // Optional parameters with default values
    if ( args.size() < 3 )
      {
      Rcpp::stop( "Pad: requires a padding value");
      }

    if ( pixeltype == "double" )
      {
      typedef double ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathPad<ImageType>( args );
        }
      else if ( dim == 3 )
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathPad<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathPad<ImageType>( args );
        }
      }
    else if ( pixeltype == "float" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathPad<ImageType>( args );
        }
      else if ( dim == 3 )
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathPad<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathPad<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned int" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathPad<ImageType>( args );
        }
      else if ( dim == 3 )
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathPad<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathPad<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned char" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathPad<ImageType>( args );
        }
      else if ( dim == 3 )
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathPad<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathPad<ImageType>( args );
        }
      }
    }
  else if ( operation == "PeronaMalik" )
    {
    Rcpp::S4 image( args[0] );
    dim = Rcpp::as< int >( image.slot( "dimension" ) );
    components = Rcpp::as< int >( image.slot( "components" ) );
    pixeltype = Rcpp::as<std::string>( image.slot( "pixeltype") );

    if ( components > 1 )
      {
      Rcpp::stop("PeronaMalik only supports scalar images");
      }

    // Optional parameters with default values
     if ( args.size() < 3 )
       {
       unsigned long nIterations = iMathPeronaMalikNIterations;
       args.push_back( Rcpp::wrap(nIterations) );
       }
    if ( args.size() < 4 )
      {
      double conductance = iMathPeronaMalikConductance;
      args.push_back( Rcpp::wrap(conductance) );
     }

    if ( pixeltype == "double" )
      {
      typedef double ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathPeronaMalik<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathPeronaMalik<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathPeronaMalik<ImageType>( args );
        }
      }
    else if ( pixeltype == "float" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathPeronaMalik<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathPeronaMalik<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathPeronaMalik<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned int" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathPeronaMalik<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathPeronaMalik<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathPeronaMalik<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned char" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathPeronaMalik<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathPeronaMalik<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathPeronaMalik<ImageType>( args );
        }
      }
    }
  else if ( operation == "PropagateLabelsThroughMask" )
    {
    Rcpp::S4 image( args[0] );
    dim = Rcpp::as< int >( image.slot( "dimension" ) );
    components = Rcpp::as< int >( image.slot( "components" ) );
    pixeltype = Rcpp::as<std::string>( image.slot( "pixeltype") );

    if ( components > 1 )
      {
      Rcpp::stop("PropagateLabelsThroughMask only supports scalar images");
      }

    // Optional parameters with default values
     if ( args.size() < 4 )
       {
       double stoppingValue = iMathPropagateLabelsThroughMaskStoppingValue;
       args.push_back( Rcpp::wrap(stoppingValue) );
       }
    if ( args.size() < 5 )
       {
       unsigned int method = iMathPropagateLabelsThroughMaskMethod;
       args.push_back( Rcpp::wrap(method) );
       }

    if ( pixeltype == "double" )
      {
      typedef double ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathPropagateLabelsThroughMask<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathPropagateLabelsThroughMask<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathPropagateLabelsThroughMask<ImageType>( args );
        }
      }
    else if ( pixeltype == "float" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathPropagateLabelsThroughMask<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathPropagateLabelsThroughMask<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathPropagateLabelsThroughMask<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned int" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathPropagateLabelsThroughMask<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathPropagateLabelsThroughMask<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathPropagateLabelsThroughMask<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned char" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathPropagateLabelsThroughMask<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathPropagateLabelsThroughMask<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathPropagateLabelsThroughMask<ImageType>( args );
        }
      }
    }
  else if ( operation == "Sharpen" )
    {
    Rcpp::S4 image( args[0] );
    dim = Rcpp::as< int >( image.slot( "dimension" ) );
    components = Rcpp::as< int >( image.slot( "components" ) );
    pixeltype = Rcpp::as<std::string>( image.slot( "pixeltype") );

    if ( components > 1 )
      {
      Rcpp::stop("Sharpen only supports scalar images");
      }

    if ( pixeltype == "double" )
      {
      typedef double ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathSharpen<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathSharpen<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathSharpen<ImageType>( args );
        }
      }
    else if ( pixeltype == "float" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathSharpen<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathSharpen<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathSharpen<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned int" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathSharpen<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathSharpen<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathSharpen<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned char" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathSharpen<ImageType>( args );
        }
      else if ( dim == 3)
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathSharpen<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathSharpen<ImageType>( args );
        }
      }
    }
  else if ( operation == "TruncateIntensity" )
    {
    Rcpp::S4 image( args[0] );
    dim = Rcpp::as< int >( image.slot( "dimension" ) );
    components = Rcpp::as< int >( image.slot( "components" ) );
    pixeltype = Rcpp::as<std::string>( image.slot( "pixeltype") );

    // Optional parameters with default values
    if ( args.size() < 4 )
      {
      Rcpp::stop("TruncateIntensity: requires lowerQ and upperQ values");
      }
    if ( args.size() < 5 )
      {
      int nBins = iMathTruncateIntensityNBins;
      args.push_back( Rcpp::wrap(nBins) );
      }

    if ( pixeltype == "double" )
      {
      typedef double ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathTruncateIntensity<ImageType>( args );
        }
      else if ( dim == 3 )
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathTruncateIntensity<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathTruncateIntensity<ImageType>( args );
        }
      }
    else if ( pixeltype == "float" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathTruncateIntensity<ImageType>( args );
        }
      else if ( dim == 3 )
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathTruncateIntensity<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathTruncateIntensity<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned int" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathTruncateIntensity<ImageType>( args );
        }
      else if ( dim == 3 )
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathTruncateIntensity<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathTruncateIntensity<ImageType>( args );
        }
      }
    else if ( pixeltype == "unsigned char" )
      {
      typedef float ValueType;

      if ( dim == 2 )
        {
        typedef itk::Image<ValueType,2>       ImageType;
        return iMathTruncateIntensity<ImageType>( args );
        }
      else if ( dim == 3 )
        {
        typedef itk::Image<ValueType,3>       ImageType;
        return iMathTruncateIntensity<ImageType>( args );
        }
      else if ( dim == 4 )
        {
        typedef itk::Image<ValueType,4>       ImageType;
        return iMathTruncateIntensity<ImageType>( args );
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
