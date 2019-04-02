
#include <algorithm>
#include <vector>
#include <string>
#include <RcppANTsR.h>

#include "antsUtilities.h"
#include "itkAffineTransform.h"
#include "itkCenteredAffineTransform.h"
#include "itkEuler2DTransform.h"
#include "itkEuler3DTransform.h"
#include "itkRigid2DTransform.h"
#include "itkRigid3DTransform.h"
#include "itkCenteredRigid2DTransform.h"
#include "itkCenteredEuler3DTransform.h"
#include "itkSimilarity2DTransform.h"
#include "itkCenteredSimilarity2DTransform.h"
#include "itkSimilarity3DTransform.h"
#include "itkQuaternionRigidTransform.h"
#include "itkTranslationTransform.h"
#include "itkResampleImageFilter.h"
#include "itkTransformFileReader.h"
#include "itkCompositeTransform.h"
#include "itkMatrixOffsetTransformBase.h"
#include "itkDisplacementFieldTransform.h"
#include "itkConstantBoundaryCondition.h"

#include "itkBSplineInterpolateImageFunction.h"
#include "itkLinearInterpolateImageFunction.h"
#include "itkGaussianInterpolateImageFunction.h"
#include "itkInterpolateImageFunction.h"
#include "itkNearestNeighborInterpolateImageFunction.h"
#include "itkWindowedSincInterpolateImageFunction.h"
#include "itkLabelImageGaussianInterpolateImageFunction.h"
#include "itkTransformFileWriter.h"


/*
template< class TransformType >
Rcpp::XPtr<typename TransformType::Pointer> antsrTransformGetXPtr()
{
  using TransformPointerType = typename TransformType::Pointer;
  TransformPointerType transformPtr = TransformType::New();

  TransformPointerType * rawPointer = new TransformPointerType( transformPtr );
  Rcpp::XPtr<TransformPointerType> xptr( rawPointer, true );
  return xptr;
}*/

template< class PrecisionType, unsigned int Dimension >
SEXP antsrTransform( SEXP r_precision, SEXP r_dimension, SEXP r_type )
{

  std::string type = Rcpp::as<std::string>( r_type );

  if ( type == "AffineTransform" )
    {
    using TransformType = itk::AffineTransform<PrecisionType,Dimension>;
    using TransformBaseType = itk::Transform<PrecisionType,Dimension,Dimension>;
    using TransformBasePointerType = typename TransformBaseType::Pointer;

    typename TransformType::Pointer transformPointer = TransformType::New();
    TransformBasePointerType basePointer
      = dynamic_cast<TransformBaseType *>( transformPointer.GetPointer() );

    return Rcpp::wrap( basePointer );
    }
  else
    {
    Rcpp::Rcout << "Passed transform type: " << type << std::endl;
    Rcpp::stop( "Transform type not supported" );
    }

  return Rcpp::wrap(NA_REAL);
}

RcppExport SEXP antsrTransform( SEXP r_precision, SEXP r_dimension, SEXP r_type )
{
try
{
  std::string precision = Rcpp::as< std::string >( r_precision );
  unsigned int dimension = Rcpp::as< int >( r_dimension );

  if ( (dimension < 1) || (dimension > 4) )
    {
    Rcpp::stop("Unsupported image dimension");
    }

  if ( (precision != "float") && (precision != "double"))
    {
    Rcpp::stop( "Precision must be 'float' or 'double'");
    }

  if( precision == "double" )
    {
    using PrecisionType = double;
    if( dimension == 4 )
	    {
      return antsrTransform<PrecisionType,4>( r_precision, r_dimension, r_type  );
      }
    else if( dimension == 3 )
	    {
      return antsrTransform<PrecisionType,3>( r_precision, r_dimension, r_type  );
	    }
    else if( dimension == 2 )
	    {
      return antsrTransform<PrecisionType,2>( r_precision, r_dimension, r_type  );
	    }
	  }
  else if( precision == "float" )
    {
    using PrecisionType = float;
    if( dimension == 4 )
	    {
      return antsrTransform<PrecisionType,4>( r_precision, r_dimension, r_type  );
      }
    else if( dimension == 3 )
	    {
      return antsrTransform<PrecisionType,3>( r_precision, r_dimension, r_type  );
	    }
    else if( dimension == 2 )
	    {
      return antsrTransform<PrecisionType,2>( r_precision, r_dimension, r_type  );
	    }
    }

  return( Rcpp::wrap(NA_REAL) );

}
catch( itk::ExceptionObject & err )
  {
  Rcpp::Rcout << "ITK ExceptionObject caught !" << std::endl;
  Rcpp::Rcout << err << std::endl;
  Rcpp::stop("ITK exception caught");
  }
catch( const std::exception& exc )
  {
  forward_exception_to_r( exc ) ;
  }
catch(...)
  {
	Rcpp::stop("c++ exception (unknown reason)");
  }
return Rcpp::wrap(NA_REAL); //not reached
}

template< class PrecisionType, unsigned int Dimension >
SEXP antsrTransform_MatrixOffset( SEXP r_type, SEXP r_precision, SEXP r_dimension,
    SEXP r_matrix, SEXP r_offset, SEXP r_center, SEXP r_translation,
    SEXP r_parameters, SEXP r_fixedparameters )
  {
  using MatrixOffsetBaseType = itk::MatrixOffsetTransformBase< PrecisionType, Dimension, Dimension>;
  using MatrixOffsetBasePointerType = typename MatrixOffsetBaseType::Pointer;
  using TransformBaseType = itk::Transform<PrecisionType,Dimension,Dimension>;
  using TransformBasePointerType = typename TransformBaseType::Pointer;

  std::string type = Rcpp::as<std::string>( r_type );
  unsigned int dimension = Rcpp::as< unsigned int >( r_dimension );

  MatrixOffsetBasePointerType matrixOffset = nullptr;

  // Initialize transform by type
  if ( type == "AffineTransform" )
    {
    using TransformType = itk::AffineTransform<PrecisionType,Dimension>;
    typename TransformType::Pointer transformPointer = TransformType::New();
    matrixOffset = dynamic_cast<MatrixOffsetBaseType*>( transformPointer.GetPointer() );
    }
  else if ( type == "CenteredAffineTransform" )
    {
    using TransformType = itk::CenteredAffineTransform<PrecisionType,Dimension>;
    typename TransformType::Pointer transformPointer = TransformType::New();
    matrixOffset = dynamic_cast<MatrixOffsetBaseType*>( transformPointer.GetPointer() );
    }
  else if ( type == "Euler3DTransform" )
    {
    using TransformType = itk::Euler3DTransform<PrecisionType>;
    typename TransformType::Pointer transformPointer = TransformType::New();
    matrixOffset = dynamic_cast<MatrixOffsetBaseType*>( transformPointer.GetPointer() );
    }
  else if ( type == "Euler2DTransform" )
    {
    using TransformType = itk::Euler2DTransform<PrecisionType>;
    typename TransformType::Pointer transformPointer = TransformType::New();
    matrixOffset = dynamic_cast<MatrixOffsetBaseType*>( transformPointer.GetPointer() );
    }
  else if ( type == "QuaternionRigidTransform" )
    {
    using TransformType = itk::QuaternionRigidTransform<PrecisionType>;
    typename TransformType::Pointer transformPointer = TransformType::New();
    matrixOffset = dynamic_cast<MatrixOffsetBaseType*>( transformPointer.GetPointer() );
    }
  else if ( type == "Rigid2DTransform" )
    {
    using TransformType = itk::Rigid2DTransform<PrecisionType>;
    typename TransformType::Pointer transformPointer = TransformType::New();
    matrixOffset = dynamic_cast<MatrixOffsetBaseType*>( transformPointer.GetPointer() );
    }
  else if ( type == "CenteredEuler3DTransform" )
    {
    using TransformType = itk::CenteredEuler3DTransform<PrecisionType>;
    typename TransformType::Pointer transformPointer = TransformType::New();
    matrixOffset = dynamic_cast<MatrixOffsetBaseType*>( transformPointer.GetPointer() );
    }
  else if ( type == "CenteredRigid2DTransform" )
    {
    using TransformType = itk::CenteredRigid2DTransform<PrecisionType>;
    typename TransformType::Pointer transformPointer = TransformType::New();
    matrixOffset = dynamic_cast<MatrixOffsetBaseType*>( transformPointer.GetPointer() );
    }
  else if ( type == "Similarity3DTransform" )
    {
    using TransformType = itk::Similarity3DTransform<PrecisionType> ;
    typename TransformType::Pointer transformPointer = TransformType::New();
    matrixOffset = dynamic_cast<MatrixOffsetBaseType*>( transformPointer.GetPointer() );
    }
  else if ( type == "Similarity2DTransform" )
    {
    using TransformType = itk::Similarity2DTransform<PrecisionType>;
    typename TransformType::Pointer transformPointer = TransformType::New();
    matrixOffset = dynamic_cast<MatrixOffsetBaseType*>( transformPointer.GetPointer() );
    }
  else if ( type == "CenteredSimilarity2DTransform" )
    {
    using TransformType = itk::CenteredSimilarity2DTransform<PrecisionType>;
    typename TransformType::Pointer transformPointer = TransformType::New();
    matrixOffset = dynamic_cast<MatrixOffsetBaseType*>( transformPointer.GetPointer() );
    }
  else
    {
    Rcpp::Rcout << "Passed transform type: " << type << std::endl;
    Rcpp::stop( "Transform type not supported" );
    }

  matrixOffset->SetIdentity();

  // Set parameters
  Rcpp::NumericVector testvec( r_matrix );
  if ( testvec[0] == testvec[0])
    {
    Rcpp::NumericMatrix matrix( r_matrix );
    if ( (matrix.nrow() != dimension) || (matrix.ncol() != dimension) )
      {
      Rcpp::stop( "Matrix must of size dimension*dimension");
      }

    typename MatrixOffsetBaseType::MatrixType itkMatrix;
    for ( unsigned int i=0; i<dimension; i++)
      for ( unsigned int j=0; j<dimension; j++)
      {
        itkMatrix(i,j) = matrix(i,j);
      }

    matrixOffset->SetMatrix( itkMatrix );
    }

  Rcpp::NumericVector translation( r_translation );
  if ( translation[0] == translation[0] )
  {
    if ( translation.length() != dimension )
      {
      Rcpp::stop("Translation must be of length: dimension");
      }

    typename MatrixOffsetBaseType::OutputVectorType itkTranslation;
    for ( unsigned int i=0; i<dimension; i++)
      {
      itkTranslation[i] = translation[i];
      }

    matrixOffset->SetTranslation( itkTranslation );
  }

  Rcpp::NumericVector offset( r_offset );
  if ( offset[0] == offset[0] )
  {
    if ( offset.length() != dimension )
      {
      Rcpp::stop("Offset must be of length: dimension");
      }

    typename MatrixOffsetBaseType::OutputVectorType itkOffset;
    for ( unsigned int i=0; i<dimension; i++)
      {
      itkOffset[i] = offset[i];
      }

    matrixOffset->SetOffset( itkOffset );
  }

  Rcpp::NumericVector center( r_center );
  if ( center[0] == center[0] )
  {
    if ( center.length() != dimension )
      {
      Rcpp::stop("Center must be of length: dimension");
      }

    typename MatrixOffsetBaseType::InputPointType itkCenter;
    for ( unsigned int i=0; i<dimension; i++)
      {
      itkCenter[i] = center[i];
      }

    matrixOffset->SetCenter( itkCenter );
  }

  Rcpp::NumericVector parameters( r_parameters );
  if ( parameters[0] == parameters[0] )
  {
    if ( parameters.length() != matrixOffset->GetNumberOfParameters() )
      {
      Rcpp::stop("Parameters has incorrect length");
      }

    typename MatrixOffsetBaseType::ParametersType itkParameters;
    itkParameters.SetSize( matrixOffset->GetNumberOfParameters() );
    for ( unsigned int i=0; i<matrixOffset->GetNumberOfParameters(); i++)
      {
      itkParameters[i] = parameters[i];
      }

    matrixOffset->SetParameters( itkParameters );
  }

  Rcpp::NumericVector fixedparameters( r_fixedparameters );
  if ( fixedparameters[0] == fixedparameters[0] )
  {
    if ( fixedparameters.length() != matrixOffset->GetNumberOfFixedParameters() )
      {
      Rcpp::stop("fixed.parameters has incorrect length");
      }

    typename MatrixOffsetBaseType::FixedParametersType itkFixedParameters;
    itkFixedParameters.SetSize( matrixOffset->GetNumberOfFixedParameters() );
    for ( unsigned int i=0; i<matrixOffset->GetNumberOfFixedParameters(); i++)
      {
      itkFixedParameters[i] = fixedparameters[i];
      }

    matrixOffset->SetFixedParameters( itkFixedParameters );
  }


  TransformBasePointerType itkTransform = dynamic_cast<TransformBaseType*>( matrixOffset.GetPointer() );
  return Rcpp::wrap( itkTransform );
}

RcppExport SEXP antsrTransform_MatrixOffset( SEXP r_type, SEXP r_precision, SEXP r_dimension,
  SEXP r_matrix, SEXP r_offset, SEXP r_center, SEXP r_translation,
  SEXP r_parameters, SEXP r_fixedparameters )
{
try
{

  std::string precision = Rcpp::as< std::string >( r_precision );
  unsigned int dimension = Rcpp::as< int >( r_dimension );

  if ( (dimension < 2) || (dimension > 4) )
    {
    Rcpp::stop("Unsupported image dimension");
    }

  if ( (precision != "float") && (precision != "double"))
    {
    Rcpp::stop( "Precision must be 'float' or 'double'");
    }

  if( precision == "double" )
    {
    using PrecisionType = double;
    if( dimension == 4 )
	    {
      return antsrTransform_MatrixOffset<PrecisionType,4>( r_type, r_precision, r_dimension, r_matrix,
          r_offset, r_center, r_translation, r_parameters, r_fixedparameters );
      }
    else if( dimension == 3 )
	    {
      return antsrTransform_MatrixOffset<PrecisionType,3>( r_type, r_precision, r_dimension, r_matrix,
          r_offset, r_center, r_translation, r_parameters, r_fixedparameters );
	    }
    else if( dimension == 2 )
	    {
      return antsrTransform_MatrixOffset<PrecisionType,2>( r_type, r_precision, r_dimension, r_matrix,
          r_offset, r_center, r_translation, r_parameters, r_fixedparameters );
	    }
	  }
  else if( precision == "float" )
    {
    using PrecisionType = float;
    if( dimension == 4 )
	    {
      return antsrTransform_MatrixOffset<PrecisionType,4>( r_type, r_precision, r_dimension, r_matrix,
          r_offset, r_center, r_translation, r_parameters, r_fixedparameters );
      }
    else if( dimension == 3 )
	    {
      return antsrTransform_MatrixOffset<PrecisionType,3>( r_type, r_precision, r_dimension, r_matrix,
          r_offset, r_center, r_translation, r_parameters, r_fixedparameters );
	    }
    else if( dimension == 2 )
	    {
      return antsrTransform_MatrixOffset<PrecisionType,2>( r_type, r_precision, r_dimension, r_matrix,
          r_offset, r_center, r_translation, r_parameters, r_fixedparameters );
	    }
    }

  return( Rcpp::wrap(NA_REAL) );

}
catch( itk::ExceptionObject & err )
  {
  Rcpp::Rcout << "ITK ExceptionObject caught !" << std::endl;
  Rcpp::Rcout << err << std::endl;
  Rcpp::stop("ITK exception caught");
  }
catch( const std::exception& exc )
  {
  forward_exception_to_r( exc ) ;
  }
catch(...)
  {
	Rcpp::stop("c++ exception (unknown reason)");
  }
return Rcpp::wrap(NA_REAL); //not reached
}


template< class PrecisionType, unsigned int Dimension >
SEXP antsrTransform_GetParameters( SEXP r_transform )
{
  using TransformType = itk::Transform<PrecisionType,Dimension,Dimension>;
  using TransformPointerType = typename TransformType::Pointer;

  TransformPointerType itkTransform = Rcpp::as<TransformPointerType>( r_transform );
  Rcpp::NumericVector parameters( itkTransform->GetNumberOfParameters() );

  for (unsigned int i=0; i<itkTransform->GetNumberOfParameters(); i++ )
  {
    parameters[i] = itkTransform->GetParameters()[i];
  }

  return parameters;
}


RcppExport SEXP antsrTransform_GetParameters( SEXP r_transform )
{
try
{
  Rcpp::S4 transform( r_transform );

  std::string precision = Rcpp::as<std::string>( transform.slot("precision") );
  unsigned int dimension = Rcpp::as<int>( transform.slot("dimension") );

  if ( (dimension < 1) || (dimension > 4) )
    {
    Rcpp::stop("Unsupported image dimension");
    }

  if ( (precision != "float") && (precision != "double"))
    {
    Rcpp::stop( "Precision must be 'float' or 'double'");
    }

  if( precision == "double" )
    {
    using PrecisionType = double;
    if( dimension == 4 )
	    {
      return antsrTransform_GetParameters<PrecisionType,4>( r_transform  );
      }
    else if( dimension == 3 )
	    {
      return antsrTransform_GetParameters<PrecisionType,3>( r_transform  );
	    }
    else if( dimension == 2 )
	    {
      return antsrTransform_GetParameters<PrecisionType,2>( r_transform );
	    }
	  }
  else if( precision == "float" )
    {
    using PrecisionType = float;
    if( dimension == 4 )
	    {
      return antsrTransform_GetParameters<PrecisionType,4>( r_transform );
      }
    else if( dimension == 3 )
	    {
      return antsrTransform_GetParameters<PrecisionType,3>( r_transform );
	    }
    else if( dimension == 2 )
	    {
      return antsrTransform_GetParameters<PrecisionType,2>( r_transform );
	    }
    }

  return( Rcpp::wrap(NA_REAL) );

}
catch( itk::ExceptionObject & err )
  {
  Rcpp::Rcout << "ITK ExceptionObject caught !" << std::endl;
  Rcpp::Rcout << err << std::endl;
  Rcpp::stop("ITK exception caught");
  }
catch( const std::exception& exc )
  {
  forward_exception_to_r( exc ) ;
  }
catch(...)
  {
	Rcpp::stop("c++ exception (unknown reason)");
  }
return Rcpp::wrap(NA_REAL); //not reached
}


template< class PrecisionType, unsigned int Dimension >
SEXP antsrTransform_SetParameters( SEXP r_transform, SEXP r_parameters )
{
  using TransformType = itk::Transform<PrecisionType,Dimension,Dimension>;
  using TransformPointerType = typename TransformType::Pointer;

  TransformPointerType itkTransform = Rcpp::as<TransformPointerType>( r_transform );
  Rcpp::NumericVector parameters( r_parameters );

  if ( parameters.size() != itkTransform->GetNumberOfParameters() )
  {
    Rcpp::stop("Incorrect number of parameters passed");
  }

  typename TransformType::ParametersType itkParameters;
  itkParameters.SetSize( itkTransform->GetNumberOfParameters() );
  for (unsigned int i=0; i < itkTransform->GetNumberOfParameters(); i++)
  {
    itkParameters[i] = parameters[i];
  }

  itkTransform->SetParameters( itkParameters );

  return(Rcpp::wrap(true));
}

RcppExport SEXP antsrTransform_SetParameters( SEXP r_transform, SEXP r_parameters )
{
try
{
  Rcpp::S4 transform( r_transform );

  std::string precision = Rcpp::as<std::string>( transform.slot("precision") );
  unsigned int dimension = Rcpp::as<int>( transform.slot("dimension") );

  if ( (dimension < 1) || (dimension > 4) )
    {
    Rcpp::stop("Unsupported image dimension");
    }

  if ( (precision != "float") && (precision != "double"))
    {
    Rcpp::stop( "Precision must be 'float' or 'double'");
    }

  if( precision == "double" )
    {
    using PrecisionType = double;
    if( dimension == 4 )
	    {
      return antsrTransform_SetParameters<PrecisionType,4>( r_transform, r_parameters  );
      }
    else if( dimension == 3 )
	    {
      return antsrTransform_SetParameters<PrecisionType,3>( r_transform, r_parameters  );
	    }
    else if( dimension == 2 )
	    {
      return antsrTransform_SetParameters<PrecisionType,2>( r_transform, r_parameters );
	    }
	  }
  else if( precision == "float" )
    {
    using PrecisionType = float;
    if( dimension == 4 )
	    {
      return antsrTransform_SetParameters<PrecisionType,4>( r_transform, r_parameters );
      }
    else if( dimension == 3 )
	    {
      return antsrTransform_SetParameters<PrecisionType,3>( r_transform, r_parameters );
	    }
    else if( dimension == 2 )
	    {
      return antsrTransform_SetParameters<PrecisionType,2>( r_transform, r_parameters );
	    }
    }

  return( Rcpp::wrap(NA_REAL) );

}
catch( itk::ExceptionObject & err )
  {
  Rcpp::Rcout << "ITK ExceptionObject caught !" << std::endl;
  Rcpp::Rcout << err << std::endl;
  Rcpp::stop("ITK exception caught");
  }
catch( const std::exception& exc )
  {
  forward_exception_to_r( exc ) ;
  }
catch(...)
  {
	Rcpp::stop("c++ exception (unknown reason)");
  }
return Rcpp::wrap(NA_REAL); //not reached
}

template< class PrecisionType, unsigned int Dimension >
SEXP antsrTransform_GetFixedParameters( SEXP r_transform )
{
  using TransformType = itk::Transform<PrecisionType,Dimension,Dimension>;
  using TransformPointerType = typename TransformType::Pointer;

  TransformPointerType itkTransform = Rcpp::as<TransformPointerType>( r_transform );
  Rcpp::NumericVector parameters( itkTransform->GetNumberOfFixedParameters() );

  for (unsigned int i=0; i<itkTransform->GetNumberOfFixedParameters(); i++ )
  {
    parameters[i] = itkTransform->GetFixedParameters()[i];
  }

  return parameters;
}


RcppExport SEXP antsrTransform_GetFixedParameters( SEXP r_transform )
{
try
{
  Rcpp::S4 transform( r_transform );

  std::string precision = Rcpp::as<std::string>( transform.slot("precision") );
  unsigned int dimension = Rcpp::as<int>( transform.slot("dimension") );

  if ( (dimension < 1) || (dimension > 4) )
    {
    Rcpp::stop("Unsupported image dimension");
    }

  if ( (precision != "float") && (precision != "double"))
    {
    Rcpp::stop( "Precision must be 'float' or 'double'");
    }

  if( precision == "double" )
    {
    using PrecisionType = double;
    if( dimension == 4 )
	    {
      return antsrTransform_GetFixedParameters<PrecisionType,4>( r_transform  );
      }
    else if( dimension == 3 )
	    {
      return antsrTransform_GetFixedParameters<PrecisionType,3>( r_transform  );
	    }
    else if( dimension == 2 )
	    {
      return antsrTransform_GetFixedParameters<PrecisionType,2>( r_transform );
	    }
	  }
  else if( precision == "float" )
    {
    using PrecisionType = float;
    if( dimension == 4 )
	    {
      return antsrTransform_GetFixedParameters<PrecisionType,4>( r_transform );
      }
    else if( dimension == 3 )
	    {
      return antsrTransform_GetFixedParameters<PrecisionType,3>( r_transform );
	    }
    else if( dimension == 2 )
	    {
      return antsrTransform_GetFixedParameters<PrecisionType,2>( r_transform );
	    }
    }

  return( Rcpp::wrap(NA_REAL) );

}
catch( itk::ExceptionObject & err )
  {
  Rcpp::Rcout << "ITK ExceptionObject caught !" << std::endl;
  Rcpp::Rcout << err << std::endl;
  Rcpp::stop("ITK exception caught");
  }
catch( const std::exception& exc )
  {
  forward_exception_to_r( exc ) ;
  }
catch(...)
  {
	Rcpp::stop("c++ exception (unknown reason)");
  }
return Rcpp::wrap(NA_REAL); //not reached
}


template< class PrecisionType, unsigned int Dimension >
SEXP antsrTransform_SetFixedParameters( SEXP r_transform, SEXP r_parameters )
{
  using TransformType = itk::Transform<PrecisionType,Dimension,Dimension>;
  using TransformPointerType = typename TransformType::Pointer;

  TransformPointerType itkTransform = Rcpp::as<TransformPointerType>( r_transform );
  Rcpp::NumericVector parameters( r_parameters );

  if ( parameters.size() != itkTransform->GetNumberOfFixedParameters() )
  {
    Rcpp::stop("Incorrect number of parameters passed, should be: ", itkTransform->GetNumberOfFixedParameters());
  }

  typename TransformType::FixedParametersType itkParameters;
  itkParameters.SetSize( itkTransform->GetNumberOfFixedParameters() );
  for (unsigned int i=0; i < itkTransform->GetNumberOfFixedParameters(); i++)
  {
    itkParameters[i] = parameters[i];
  }

  itkTransform->SetFixedParameters( itkParameters );

  return(Rcpp::wrap(true));
}

RcppExport SEXP antsrTransform_SetFixedParameters( SEXP r_transform, SEXP r_parameters )
{
try
{
  Rcpp::S4 transform( r_transform );

  std::string precision = Rcpp::as<std::string>( transform.slot("precision") );
  unsigned int dimension = Rcpp::as<int>( transform.slot("dimension") );

  if ( (dimension < 1) || (dimension > 4) )
    {
    Rcpp::stop("Unsupported image dimension");
    }

  if ( (precision != "float") && (precision != "double"))
    {
    Rcpp::stop( "Precision must be 'float' or 'double'");
    }

  if( precision == "double" )
    {
    using PrecisionType = double;
    if( dimension == 4 )
	    {
      return antsrTransform_SetFixedParameters<PrecisionType,4>( r_transform, r_parameters  );
      }
    else if( dimension == 3 )
	    {
      return antsrTransform_SetFixedParameters<PrecisionType,3>( r_transform, r_parameters  );
	    }
    else if( dimension == 2 )
	    {
      return antsrTransform_SetFixedParameters<PrecisionType,2>( r_transform, r_parameters );
	    }
	  }
  else if( precision == "float" )
    {
    using PrecisionType = float;
    if( dimension == 4 )
	    {
      return antsrTransform_SetFixedParameters<PrecisionType,4>( r_transform, r_parameters );
      }
    else if( dimension == 3 )
	    {
      return antsrTransform_SetFixedParameters<PrecisionType,3>( r_transform, r_parameters );
	    }
    else if( dimension == 2 )
	    {
      return antsrTransform_SetFixedParameters<PrecisionType,2>( r_transform, r_parameters );
	    }
    }

  return( Rcpp::wrap(NA_REAL) );

}
catch( itk::ExceptionObject & err )
  {
  Rcpp::Rcout << "ITK ExceptionObject caught !" << std::endl;
  Rcpp::Rcout << err << std::endl;
  Rcpp::stop("ITK exception caught");
  }
catch( const std::exception& exc )
  {
  forward_exception_to_r( exc ) ;
  }
catch(...)
  {
	Rcpp::stop("c++ exception (unknown reason)");
  }
return Rcpp::wrap(NA_REAL); //not reached
}
