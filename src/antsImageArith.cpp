#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <RcppANTsR.h>

#include "itkBinaryFunctorImageFilter.h"
#include "itkCastImageFilter.h"
#include "itkDefaultConvertPixelTraits.h"
#include "itkImage.h"


/*
  Define S4 generics for group Arith: "+", "-", "*", "^", "%%", "%/%", "/"
*/

/*
  C++ modulus returns different results for negative inputs than R
    in C++: -5 %% 4 returns -2
    in R:   -5 %% 4 returns 3

    in R: x == (x %% y) + y * ( x %/% y )
*/


namespace itk
   {

   /* Class to return the nth element for data types with more than one component
    * and the first value for one element data type
    */
   template< typename DataType >
   class ANTsR_GetDataValue
   {
   public:
     ANTsR_GetDataValue() {}
     ~ANTsR_GetDataValue() {}

     typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
     typedef itk::NumericTraits<DataType>             TraitsType;
     typedef typename TraitsType::ValueType           ValueType;

     bool operator!=(const ANTsR_GetDataValue &) const
     {
       return false;
     }

     bool operator==(const ANTsR_GetDataValue & other) const
     {
       return !( *this != other );
     }

     static inline ValueType NthValue (unsigned long i, const DataType & A ) {
       if ( TraitsType::GetLength(A)==1 ) {
         return ConvertType::GetNthComponent(0,A);
       }
       else {
         return ConvertType::GetNthComponent(i,A);
       }

     }
   };

   namespace Functor
   {
     template< typename DataType >
     class ANTsR_IDiv
     {
     public:
       ANTsR_IDiv() {}
       ~ANTsR_IDiv() {}

       typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
       typedef itk::NumericTraits<DataType>             TraitsType;
       typedef typename TraitsType::ValueType           ValueType;
       typedef ANTsR_GetDataValue<DataType>             GetValueType;

       bool operator!=(const ANTsR_IDiv &) const
       {
         return false;
       }

      bool operator==(const ANTsR_IDiv & other) const
       {
         return !( *this != other );
       }

      inline DataType operator()(const DataType & A, const DataType & B ) const
       {
         //return static_cast<TOutput>( std::floor( static_cast<double>(A) / B ) );

         DataType output;
         unsigned int nComponents = std::max( TraitsType::GetLength(A),TraitsType::GetLength(B));
         TraitsType::SetLength(output,nComponents);


         for ( unsigned int i=0; i<nComponents; i++) {
           ValueType aVal = GetValueType::NthValue(i,A);
           ValueType bVal = GetValueType::NthValue(i,B);

           ConvertType::SetNthComponent(i, output,
              static_cast<ValueType>( std::floor( static_cast<double>(aVal) / bVal)));
         }
         return output;
       }
     };

     template< typename DataType >
     class ANTsR_Mod
     {
     public:
       ANTsR_Mod() {}
       ~ANTsR_Mod() {}

       typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
       typedef itk::NumericTraits<DataType>             TraitsType;
       typedef typename TraitsType::ValueType           ValueType;
       typedef ANTsR_GetDataValue<DataType>             GetValueType;

       bool operator!=(const ANTsR_Mod &) const
       {
         return false;
       }

      bool operator==(const ANTsR_Mod & other) const
       {
         return !( *this != other );
       }

       inline DataType operator()(const DataType & A, const DataType & B ) const
       {
         //return static_cast<TOutput>( std::floor( static_cast<double>(A) / B ) );

         DataType output;
         unsigned int nComponents = std::max( TraitsType::GetLength(A),TraitsType::GetLength(B));
         TraitsType::SetLength(output,nComponents);

         for ( unsigned int i=0; i<nComponents; i++) {

           ValueType aVal = GetValueType::NthValue(i,A);
           ValueType bVal = GetValueType::NthValue(i,B);

           ValueType val = static_cast<ValueType>( aVal - bVal*std::floor( static_cast<double>(aVal) / bVal ) );
           if ( (val < 0 ) && ( bVal > 0) )
           {
             val = static_cast<ValueType>( val + bVal );
           }

           ConvertType::SetNthComponent(i, output, val);

         }
         return output;
       }
     };

    template< typename DataType >
    class ANTsR_Add
    {
    public:
      ANTsR_Add() {}
      ~ANTsR_Add() {}

      typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
      typedef itk::NumericTraits<DataType>             TraitsType;
      typedef typename TraitsType::ValueType           ValueType;
      typedef ANTsR_GetDataValue<DataType>             GetValueType;

      bool operator!=(const ANTsR_Add &) const
      {
        return false;
      }

      bool operator==(const ANTsR_Add & other) const
      {
        return !( *this != other );
      }

      inline DataType operator()(const DataType & A, const DataType & B ) const
      {
        unsigned int nComponents = std::max( TraitsType::GetLength(A),TraitsType::GetLength(B));
        DataType output;
        TraitsType::SetLength(output, nComponents);

        for (unsigned int i=0; i<nComponents; i++)
        {
          ValueType val = GetValueType::NthValue(i,A) + GetValueType::NthValue(i,B);
          ConvertType::SetNthComponent(i,output,val);
        }
        return output;
      }
    };

    template< typename DataType >
    class ANTsR_Subtract
    {
    public:
      ANTsR_Subtract() {}
      ~ANTsR_Subtract() {}

      typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
      typedef itk::NumericTraits<DataType>             TraitsType;
      typedef typename TraitsType::ValueType           ValueType;
      typedef ANTsR_GetDataValue<DataType>             GetValueType;

      bool operator!=(const ANTsR_Subtract &) const
      {
        return false;
      }

      bool operator==(const ANTsR_Subtract & other) const
      {
        return !( *this != other );
      }

      inline DataType operator()(const DataType & A, const DataType & B ) const
      {
        unsigned int nComponents = std::max( TraitsType::GetLength(A),TraitsType::GetLength(B));
        DataType output;
        TraitsType::SetLength(output, nComponents);

        for (unsigned int i=0; i<nComponents; i++)
        {
          ValueType val = GetValueType::NthValue(i,A) - GetValueType::NthValue(i,B);
          ConvertType::SetNthComponent(i,output,val);
        }
        return output;
      }
    };

    template< typename DataType >
    class ANTsR_Multiply
    {
    public:
      ANTsR_Multiply() {}
      ~ANTsR_Multiply() {}

      typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
      typedef itk::NumericTraits<DataType>             TraitsType;
      typedef typename TraitsType::ValueType           ValueType;
      typedef ANTsR_GetDataValue<DataType>             GetValueType;

      bool operator!=(const ANTsR_Multiply &) const
      {
        return false;
      }

      bool operator==(const ANTsR_Multiply & other) const
      {
        return !( *this != other );
      }

      inline DataType operator()(const DataType & A, const DataType & B ) const
      {
        unsigned int nComponents = std::max( TraitsType::GetLength(A),TraitsType::GetLength(B));
        DataType output;
        TraitsType::SetLength(output, nComponents);

        for (unsigned int i=0; i<nComponents; i++)
        {
          ValueType val = GetValueType::NthValue(i,A) * GetValueType::NthValue(i,B);
          ConvertType::SetNthComponent(i,output,val);
        }
        return output;
      }
    };

    template< typename DataType >
    class ANTsR_Divide
    {
    public:
      ANTsR_Divide() {}
      ~ANTsR_Divide() {}

      typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
      typedef itk::NumericTraits<DataType>             TraitsType;
      typedef typename TraitsType::ValueType           ValueType;
      typedef ANTsR_GetDataValue<DataType>             GetValueType;

      bool operator!=(const ANTsR_Divide &) const
      {
        return false;
      }

      bool operator==(const ANTsR_Divide & other) const
      {
        return !( *this != other );
      }

      inline DataType operator()(const DataType & A, const DataType & B ) const
      {
        unsigned int nComponents = std::max( TraitsType::GetLength(A),TraitsType::GetLength(B));
        DataType output;
        TraitsType::SetLength(output, nComponents);

        for (unsigned int i=0; i<nComponents; i++)
        {
          ValueType val = GetValueType::NthValue(i,A) / GetValueType::NthValue(i,B);
          ConvertType::SetNthComponent(i,output,val);
        }
        return output;
      }
    };

    template< typename DataType >
    class ANTsR_Pow
    {
    public:
      ANTsR_Pow() {}
      ~ANTsR_Pow() {}

      typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
      typedef itk::NumericTraits<DataType>             TraitsType;
      typedef typename TraitsType::ValueType           ValueType;
      typedef ANTsR_GetDataValue<DataType>             GetValueType;

      bool operator!=(const ANTsR_Pow &) const
      {
        return false;
      }

      bool operator==(const ANTsR_Pow & other) const
      {
        return !( *this != other );
      }

      inline DataType operator()(const DataType & A, const DataType & B ) const
      {
        unsigned int nComponents = std::max( TraitsType::GetLength(A),TraitsType::GetLength(B));
        DataType output;
        TraitsType::SetLength(output, nComponents);

        for (unsigned int i=0; i<nComponents; i++)
        {
          ValueType val = pow( GetValueType::NthValue(i,A), GetValueType::NthValue(i,B));
          ConvertType::SetNthComponent(i,output,val);
        }
        return output;
      }
    };

  }
  }



template< class ImageType >
SEXP antsImageArithImageNumeric( SEXP r_antsimage, SEXP r_numeric, SEXP r_operator )
{
  //Rcpp::Rcout << "antsImageArithImageNumeric " << Rcpp::as< std::string >( r_operator ) << std::endl;

  typedef typename ImageType::PixelType PixelType;
  typedef typename ImageType::Pointer ImagePointerType;
  typedef itk::DefaultConvertPixelTraits<PixelType> PixelConvertType;

  ImagePointerType image = Rcpp::as<ImagePointerType>(r_antsimage);
  //PixelType numeric = Rcpp::as<PixelType>( r_numeric );

  Rcpp::S4 antsimage(r_antsimage);
  unsigned int nComponents = Rcpp::as<unsigned int>( antsimage.slot("components") );

  PixelType numeric;
  Rcpp::NumericVector numVec(r_numeric);

  if ( (numVec.length() != nComponents) && (numVec.length() != 1) ) {
    Rcpp::Rcout << "Constant must have one component or the same number of components as the image" << std::endl;
    return Rcpp::wrap(NA_REAL);
  }

  itk::NumericTraits<PixelType>::SetLength(numeric, nComponents);
  if ( numVec.length() == 1)
  {
    for ( unsigned int i=0; i<nComponents; i++) {
      PixelConvertType::SetNthComponent(i, numeric, numVec[0]);
    }
  }
  else
  {
    for ( unsigned int i=0; i<nComponents; i++) {
      PixelConvertType::SetNthComponent(i, numeric, numVec[i]);
    }
  }

  if ( Rcpp::as< std::string >( r_operator ) == "+" )
  {
    typedef itk::BinaryFunctorImageFilter<ImageType, ImageType, ImageType,
      itk::Functor::ANTsR_Add<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput1( image );
    filter->SetConstant2( numeric );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "-" )
  {
    typedef itk::BinaryFunctorImageFilter<ImageType, ImageType, ImageType,
      itk::Functor::ANTsR_Subtract<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput1( image );
    filter->SetConstant2( numeric );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "*" )
  {
    typedef itk::BinaryFunctorImageFilter<ImageType, ImageType, ImageType,
      itk::Functor::ANTsR_Multiply<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput1( image );
    filter->SetConstant2( numeric );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "/" )
  {
    typedef itk::BinaryFunctorImageFilter<ImageType, ImageType, ImageType,
      itk::Functor::ANTsR_Divide<PixelType>  > FilterType;

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
      itk::Functor::ANTsR_Mod<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput1( image );
    filter->SetConstant2( numeric );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "%/%" )
  {
    typedef itk::BinaryFunctorImageFilter<ImageType, ImageType, ImageType,
      itk::Functor::ANTsR_IDiv<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput1( image );
    filter->SetConstant2( numeric );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "^" )
  {
    typedef itk::BinaryFunctorImageFilter<ImageType, ImageType, ImageType,
      itk::Functor::ANTsR_Pow<PixelType>  > FilterType;

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
          antsImageArithImageNumeric< ImageType >( r_antsimage, r_numeric, r_operator ) :
          antsImageArithImageNumeric< VectorImageType >( r_antsimage, r_numeric, r_operator );
        }
      else if( dimension == 3 )
        {
        const int ImageDimension = 3;
        typedef itk::Image< PixelType , ImageDimension >      ImageType;
        typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;
        return ( !isVector ) ?
          antsImageArithImageNumeric< ImageType >( r_antsimage, r_numeric, r_operator ) :
          antsImageArithImageNumeric< VectorImageType >( r_antsimage, r_numeric, r_operator );
        }
      else if( dimension == 2 )
        {
        const int ImageDimension = 2;
        typedef itk::Image< PixelType , ImageDimension >      ImageType;
        typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;
        return ( !isVector ) ?
          antsImageArithImageNumeric< ImageType >( r_antsimage, r_numeric, r_operator ) :
          antsImageArithImageNumeric< VectorImageType >( r_antsimage, r_numeric, r_operator );
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
          antsImageArithImageNumeric< ImageType >( r_antsimage, r_numeric, r_operator ) :
          antsImageArithImageNumeric< VectorImageType >( r_antsimage, r_numeric, r_operator );
        }
      else if( dimension == 3 )
        {
        const int ImageDimension = 3;
        typedef itk::Image< PixelType , ImageDimension >      ImageType;
        typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;
        return ( !isVector ) ?
          antsImageArithImageNumeric< ImageType >( r_antsimage, r_numeric, r_operator ) :
          antsImageArithImageNumeric< VectorImageType >( r_antsimage, r_numeric, r_operator );
        }
      else if( dimension == 2 )
        {
        const int ImageDimension = 2;
        typedef itk::Image< PixelType , ImageDimension >      ImageType;
        typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;
        return ( !isVector ) ?
          antsImageArithImageNumeric< ImageType >( r_antsimage, r_numeric, r_operator ) :
          antsImageArithImageNumeric< VectorImageType >( r_antsimage, r_numeric, r_operator );
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
          antsImageArithImageNumeric< ImageType >( r_antsimage, r_numeric, r_operator ) :
          antsImageArithImageNumeric< VectorImageType >( r_antsimage, r_numeric, r_operator );
      }
    else if( dimension == 3 )
      {
      const int ImageDimension = 3;
        typedef itk::Image< PixelType , ImageDimension >      ImageType;
        typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;
        return ( !isVector ) ?
          antsImageArithImageNumeric< ImageType >( r_antsimage, r_numeric, r_operator ) :
          antsImageArithImageNumeric< VectorImageType >( r_antsimage, r_numeric, r_operator );
      }
    else if( dimension == 2 )
      {
      const int ImageDimension = 2;
        typedef itk::Image< PixelType , ImageDimension >      ImageType;
        typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;
        return ( !isVector ) ?
          antsImageArithImageNumeric< ImageType >( r_antsimage, r_numeric, r_operator ) :
          antsImageArithImageNumeric< VectorImageType >( r_antsimage, r_numeric, r_operator );
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
          antsImageArithImageNumeric< ImageType >( r_antsimage, r_numeric, r_operator ) :
          antsImageArithImageNumeric< VectorImageType >( r_antsimage, r_numeric, r_operator );
      }
    else if( dimension == 3 )
      {
      const int ImageDimension = 3;
        typedef itk::Image< PixelType , ImageDimension >      ImageType;
        typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;
        return ( !isVector ) ?
          antsImageArithImageNumeric< ImageType >( r_antsimage, r_numeric, r_operator ) :
          antsImageArithImageNumeric< VectorImageType >( r_antsimage, r_numeric, r_operator );
      }
    else if( dimension == 2 )
      {
      const int ImageDimension = 2;
        typedef itk::Image< PixelType , ImageDimension >      ImageType;
        typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;
        return ( !isVector ) ?
          antsImageArithImageNumeric< ImageType >( r_antsimage, r_numeric, r_operator ) :
          antsImageArithImageNumeric< VectorImageType >( r_antsimage, r_numeric, r_operator );
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

template< class ImageType >
SEXP antsImageArithNumericImage( SEXP r_numeric, SEXP r_antsimage, SEXP r_operator )
{
  //Rcpp::Rcout << "antsImageArithNumericImage " << Rcpp::as< std::string >( r_operator ) << std::endl;

  typedef typename ImageType::PixelType PixelType;
  typedef typename ImageType::Pointer ImagePointerType;
  typedef itk::DefaultConvertPixelTraits<PixelType> PixelConvertType;

  ImagePointerType image = Rcpp::as<ImagePointerType>(r_antsimage);
  //PixelType numeric = Rcpp::as<PixelType>( r_numeric );

  Rcpp::S4 antsimage(r_antsimage);
  unsigned int nComponents = Rcpp::as<unsigned int>( antsimage.slot("components") );

  PixelType numeric;
  Rcpp::NumericVector numVec(r_numeric);

  if ( (numVec.length() != nComponents) && (numVec.length() != 1) ) {
    Rcpp::Rcout << "Constant must have one component or the same number of components as the image" << std::endl;
    return Rcpp::wrap(NA_REAL);
  }

  itk::NumericTraits<PixelType>::SetLength(numeric, nComponents);
  if ( numVec.length() == 1)
  {
    for ( unsigned int i=0; i<nComponents; i++) {
      PixelConvertType::SetNthComponent(i, numeric, numVec[0]);
    }
  }
  else
  {
    for ( unsigned int i=0; i<nComponents; i++) {
      PixelConvertType::SetNthComponent(i, numeric, numVec[i]);
    }
  }

  if ( Rcpp::as< std::string >( r_operator ) == "+" )
  {
    typedef itk::BinaryFunctorImageFilter<ImageType, ImageType, ImageType,
      itk::Functor::ANTsR_Add<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetConstant1( numeric );
    filter->SetInput2( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "-" )
  {
    typedef itk::BinaryFunctorImageFilter<ImageType, ImageType, ImageType,
      itk::Functor::ANTsR_Subtract<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetConstant1( numeric );
    filter->SetInput2( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "*" )
  {
    typedef itk::BinaryFunctorImageFilter<ImageType, ImageType, ImageType,
      itk::Functor::ANTsR_Multiply<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetConstant1( numeric );
    filter->SetInput2( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "/" )
  {
    typedef itk::BinaryFunctorImageFilter<ImageType, ImageType, ImageType,
      itk::Functor::ANTsR_Divide<PixelType>  > FilterType;

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
      itk::Functor::ANTsR_Mod<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetConstant1( numeric );
    filter->SetInput2( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "%/%" )
  {
    typedef itk::BinaryFunctorImageFilter<ImageType, ImageType, ImageType,
      itk::Functor::ANTsR_IDiv<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput2( image );
    filter->SetConstant1( numeric );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "^" )
  {
    typedef itk::BinaryFunctorImageFilter<ImageType, ImageType, ImageType,
      itk::Functor::ANTsR_Pow<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput2( image );
    filter->SetConstant1( numeric );
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
  bool isVector = Rcpp::as<bool>( antsimage.slot("isVector"));

  if( pixeltype == "double" )
    {
      typedef double PixelType;
      if( dimension == 4 )
        {
        const int ImageDimension = 4;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef itk::VectorImage<PixelType, ImageDimension> VectorImageType;
        return ( !isVector ) ?
          antsImageArithNumericImage<ImageType>( r_numeric, r_antsimage, r_operator) :
          antsImageArithNumericImage<VectorImageType>( r_numeric, r_antsimage, r_operator);
        }
      else if( dimension == 3 )
        {
        const int ImageDimension = 3;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef itk::VectorImage<PixelType, ImageDimension> VectorImageType;
        return ( !isVector ) ?
          antsImageArithNumericImage<ImageType>( r_numeric, r_antsimage, r_operator) :
          antsImageArithNumericImage<VectorImageType>( r_numeric, r_antsimage, r_operator);
        }
      else if( dimension == 2 )
        {
        const int ImageDimension = 2;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef itk::VectorImage<PixelType, ImageDimension> VectorImageType;
        return ( !isVector ) ?
          antsImageArithNumericImage<ImageType>( r_numeric, r_antsimage, r_operator) :
          antsImageArithNumericImage<VectorImageType>( r_numeric, r_antsimage, r_operator);
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
          typedef itk::VectorImage<PixelType, ImageDimension> VectorImageType;
        return ( !isVector ) ?
          antsImageArithNumericImage<ImageType>( r_numeric, r_antsimage, r_operator) :
          antsImageArithNumericImage<VectorImageType>( r_numeric, r_antsimage, r_operator);
        }
      else if( dimension == 3 )
        {
        const int ImageDimension = 3;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef itk::VectorImage<PixelType, ImageDimension> VectorImageType;
        return ( !isVector ) ?
          antsImageArithNumericImage<ImageType>( r_numeric, r_antsimage, r_operator) :
          antsImageArithNumericImage<VectorImageType>( r_numeric, r_antsimage, r_operator);
        }
      else if( dimension == 2 )
        {
        const int ImageDimension = 2;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef itk::VectorImage<PixelType, ImageDimension> VectorImageType;
        return ( !isVector ) ?
          antsImageArithNumericImage<ImageType>( r_numeric, r_antsimage, r_operator) :
          antsImageArithNumericImage<VectorImageType>( r_numeric, r_antsimage, r_operator);
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
        typedef itk::VectorImage<PixelType, ImageDimension> VectorImageType;
        return ( !isVector ) ?
          antsImageArithNumericImage<ImageType>( r_numeric, r_antsimage, r_operator) :
          antsImageArithNumericImage<VectorImageType>( r_numeric, r_antsimage, r_operator);
      }
    else if( dimension == 3 )
      {
      const int ImageDimension = 3;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef itk::VectorImage<PixelType, ImageDimension> VectorImageType;
        return ( !isVector ) ?
          antsImageArithNumericImage<ImageType>( r_numeric, r_antsimage, r_operator) :
          antsImageArithNumericImage<VectorImageType>( r_numeric, r_antsimage, r_operator);
      }
    else if( dimension == 2 )
      {
      const int ImageDimension = 2;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef itk::VectorImage<PixelType, ImageDimension> VectorImageType;
        return ( !isVector ) ?
          antsImageArithNumericImage<ImageType>( r_numeric, r_antsimage, r_operator) :
          antsImageArithNumericImage<VectorImageType>( r_numeric, r_antsimage, r_operator);
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
        typedef itk::VectorImage<PixelType, ImageDimension> VectorImageType;
        return ( !isVector ) ?
          antsImageArithNumericImage<ImageType>( r_numeric, r_antsimage, r_operator) :
          antsImageArithNumericImage<VectorImageType>( r_numeric, r_antsimage, r_operator);
      }
    else if( dimension == 3 )
      {
      const int ImageDimension = 3;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef itk::VectorImage<PixelType, ImageDimension> VectorImageType;
        return ( !isVector ) ?
          antsImageArithNumericImage<ImageType>( r_numeric, r_antsimage, r_operator) :
          antsImageArithNumericImage<VectorImageType>( r_numeric, r_antsimage, r_operator);
      }
    else if( dimension == 2 )
      {
      const int ImageDimension = 2;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef itk::VectorImage<PixelType, ImageDimension> VectorImageType;
        return ( !isVector ) ?
          antsImageArithNumericImage<ImageType>( r_numeric, r_antsimage, r_operator) :
          antsImageArithNumericImage<VectorImageType>( r_numeric, r_antsimage, r_operator);
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



template< class ImageType >
SEXP antsImageArithImageImage( SEXP r_antsimage1, SEXP r_antsimage2, SEXP r_operator )
{
  //Rcpp::Rcout << "antsImageArithImageImage " << Rcpp::as< std::string >( r_operator ) << std::endl;

  typedef typename ImageType::PixelType PixelType;
  typedef typename ImageType::Pointer ImagePointerType;

  ImagePointerType image1 = Rcpp::as<ImagePointerType>(r_antsimage1);
  ImagePointerType image2 = Rcpp::as<ImagePointerType>(r_antsimage2);

  if( !image1.IsNotNull() || !image2.IsNotNull() ) {
    return Rcpp::wrap(NA_REAL);
  }

  if ( Rcpp::as< std::string >( r_operator ) == "+" )
  {
    typedef itk::BinaryFunctorImageFilter<ImageType, ImageType, ImageType,
      itk::Functor::ANTsR_Add<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput1( image1 );
    filter->SetInput2( image2 );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "-" )
  {
    typedef itk::BinaryFunctorImageFilter<ImageType, ImageType, ImageType,
      itk::Functor::ANTsR_Subtract<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput1( image1 );
    filter->SetInput2( image2 );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "*" )
  {
    typedef itk::BinaryFunctorImageFilter<ImageType, ImageType, ImageType,
      itk::Functor::ANTsR_Multiply<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput1( image1 );
    filter->SetInput2( image2 );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "/" )
  {
    typedef itk::BinaryFunctorImageFilter<ImageType, ImageType, ImageType,
      itk::Functor::ANTsR_Divide<PixelType>  > FilterType;

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
      itk::Functor::ANTsR_Mod<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput1( image1 );
    filter->SetInput2( image2 );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "%/%" )
  {
    typedef itk::BinaryFunctorImageFilter<ImageType, ImageType, ImageType,
      itk::Functor::ANTsR_IDiv<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput1( image1 );
    filter->SetInput2( image2 );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "^" )
  {
    typedef itk::BinaryFunctorImageFilter<ImageType, ImageType, ImageType,
      itk::Functor::ANTsR_Pow<PixelType>  > FilterType;

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


  Rcpp::S4 antsimage1(r_antsimage1);
  unsigned int nComponents = Rcpp::as<unsigned int>( antsimage1.slot("components") );
  bool isVector = Rcpp::as<bool>( antsimage1.slot("isVector") );

  Rcpp::S4 antsimage2(r_antsimage2);
  unsigned int nComponents2 = Rcpp::as<unsigned int>( antsimage2.slot("components") );
  bool isVector2 = Rcpp::as<bool>( antsimage2.slot("isVector") );

  if ( isVector != isVector2 ) {
    Rcpp::Rcout << "Both images must of of same type (scalar or vector)" << std::endl;
    return(Rcpp::wrap(NA_REAL));
  }

  if ( nComponents > 1 ) {
    if ( (nComponents2 != nComponents) && (nComponents2 != 1)) {
      Rcpp::Rcout << "Both images must have same number of components or one component" << std::endl;
      return(Rcpp::wrap(NA_REAL));
    }
  }
  if ( nComponents2 > 1 ) {
    if ( (nComponents2 != nComponents) && (nComponents != 1)) {
      Rcpp::Rcout << "Both images must have same number of components or one component" << std::endl;
      return(Rcpp::wrap(NA_REAL));
    }
  }

  std::string pixeltype = Rcpp::as< std::string >( antsimage1.slot( "pixeltype" ) );
  unsigned int dimension = Rcpp::as< int >( antsimage1.slot( "dimension" ) );

  std::string pixeltype2 = Rcpp::as< std::string >( antsimage2.slot( "pixeltype" ) );

  pixeltype = pixeltype_highest_precision( pixeltype, pixeltype2 );
  //Rcpp::Rcout << "Arith returning pixeltype: " << pixeltype << std::endl;

if( pixeltype == "double" )
    {
      typedef double PixelType;
      if( dimension == 4 )
        {
        const int ImageDimension = 4;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef itk::VectorImage<PixelType, ImageDimension> VectorImageType;
        return ( !isVector) ?
          antsImageArithImageImage<ImageType>( r_antsimage1, r_antsimage2, r_operator ) :
          antsImageArithImageImage<VectorImageType>( r_antsimage1, r_antsimage2, r_operator );
        }
      else if( dimension == 3 )
        {
        const int ImageDimension = 3;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef itk::VectorImage<PixelType, ImageDimension> VectorImageType;
        return ( !isVector) ?
          antsImageArithImageImage<ImageType>( r_antsimage1, r_antsimage2, r_operator ) :
          antsImageArithImageImage<VectorImageType>( r_antsimage1, r_antsimage2, r_operator );
        }
      else if( dimension == 2 )
        {
        const int ImageDimension = 2;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef itk::VectorImage<PixelType, ImageDimension> VectorImageType;
        return ( !isVector) ?
          antsImageArithImageImage<ImageType>( r_antsimage1, r_antsimage2, r_operator ) :
          antsImageArithImageImage<VectorImageType>( r_antsimage1, r_antsimage2, r_operator );
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
        typedef itk::VectorImage<PixelType, ImageDimension> VectorImageType;
        return ( !isVector) ?
          antsImageArithImageImage<ImageType>( r_antsimage1, r_antsimage2, r_operator ) :
          antsImageArithImageImage<VectorImageType>( r_antsimage1, r_antsimage2, r_operator );
        }
      else if( dimension == 3 )
        {
        const int ImageDimension = 3;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef itk::VectorImage<PixelType, ImageDimension> VectorImageType;
        return ( !isVector) ?
          antsImageArithImageImage<ImageType>( r_antsimage1, r_antsimage2, r_operator ) :
          antsImageArithImageImage<VectorImageType>( r_antsimage1, r_antsimage2, r_operator );
        }
      else if( dimension == 2 )
        {
        const int ImageDimension = 2;
          typedef itk::Image< PixelType , ImageDimension > ImageType;
          typedef itk::VectorImage<PixelType, ImageDimension> VectorImageType;
          return ( !isVector) ?
            antsImageArithImageImage<ImageType>( r_antsimage1, r_antsimage2, r_operator ) :
            antsImageArithImageImage<VectorImageType>( r_antsimage1, r_antsimage2, r_operator );
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
        typedef itk::VectorImage<PixelType, ImageDimension> VectorImageType;
        return ( !isVector) ?
          antsImageArithImageImage<ImageType>( r_antsimage1, r_antsimage2, r_operator ) :
          antsImageArithImageImage<VectorImageType>( r_antsimage1, r_antsimage2, r_operator );
        }
      else if( dimension == 3 )
        {
        const int ImageDimension = 3;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef itk::VectorImage<PixelType, ImageDimension> VectorImageType;
        return ( !isVector) ?
          antsImageArithImageImage<ImageType>( r_antsimage1, r_antsimage2, r_operator ) :
          antsImageArithImageImage<VectorImageType>( r_antsimage1, r_antsimage2, r_operator );
        }
      else if( dimension == 2 )
        {
        const int ImageDimension = 2;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef itk::VectorImage<PixelType, ImageDimension> VectorImageType;
        return ( !isVector) ?
          antsImageArithImageImage<ImageType>( r_antsimage1, r_antsimage2, r_operator ) :
          antsImageArithImageImage<VectorImageType>( r_antsimage1, r_antsimage2, r_operator );
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
        typedef itk::VectorImage<PixelType, ImageDimension> VectorImageType;
        return ( !isVector) ?
          antsImageArithImageImage<ImageType>( r_antsimage1, r_antsimage2, r_operator ) :
          antsImageArithImageImage<VectorImageType>( r_antsimage1, r_antsimage2, r_operator );
        }
      else if( dimension == 3 )
        {
        const int ImageDimension = 3;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef itk::VectorImage<PixelType, ImageDimension> VectorImageType;
        return ( !isVector) ?
          antsImageArithImageImage<ImageType>( r_antsimage1, r_antsimage2, r_operator ) :
          antsImageArithImageImage<VectorImageType>( r_antsimage1, r_antsimage2, r_operator );
        }
      else if( dimension == 2 )
        {
        const int ImageDimension = 2;
        typedef itk::Image< PixelType , ImageDimension > ImageType;
        typedef itk::VectorImage<PixelType, ImageDimension> VectorImageType;
        return ( !isVector) ?
          antsImageArithImageImage<ImageType>( r_antsimage1, r_antsimage2, r_operator ) :
          antsImageArithImageImage<VectorImageType>( r_antsimage1, r_antsimage2, r_operator );
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
