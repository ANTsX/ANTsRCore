#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <RcppANTsR.h>

#include "itkUnaryFunctorImageFilter.h"
#include "itkCastImageFilter.h"
#include "itkDefaultConvertPixelTraits.h"
#include "itkImage.h"

/*
  Define S4 generics for group Math: "abs","sign","sqrt","ceiling","floor","trunc","log","log10","log2","acos","asin","atan","acosh", asinh", "atanh","cos","sin","tan","cosh","sinh","tanh","cospi", "sinpi", "tanpi","exp","gamma","lgamma"

  Unimplemented:  "digamma", "trigamma", "expm1", "log1p", "cummax", "cummin", "cumprod", "cumsum"
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
     class ANTsR_Abs
     {
     public:
       ANTsR_Abs() {}
       ~ANTsR_Abs() {}

       typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
       typedef itk::NumericTraits<DataType>             TraitsType;
       typedef typename TraitsType::ValueType           ValueType;
       typedef ANTsR_GetDataValue<DataType>             GetValueType;

       bool operator!=(const ANTsR_Abs &) const
       {
         return false;
       }

      bool operator==(const ANTsR_Abs & other) const
       {
         return !( *this != other );
       }

      inline DataType operator()(const DataType & A ) const
       {
         DataType output;
         unsigned int nComponents = TraitsType::GetLength(A);
         TraitsType::SetLength(output,nComponents);

         for ( unsigned int i=0; i<nComponents; i++) {
           ConvertType::SetNthComponent(i, output,
              static_cast<ValueType>( itk::Math::abs(GetValueType::NthValue(i,A)) ));
         }
         return output;
       }
     };

     template< typename DataType >
     class ANTsR_Sign
     {
     public:
       ANTsR_Sign() {}
       ~ANTsR_Sign() {}

       typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
       typedef itk::NumericTraits<DataType>             TraitsType;
       typedef typename TraitsType::ValueType           ValueType;
       typedef ANTsR_GetDataValue<DataType>             GetValueType;

       bool operator!=(const ANTsR_Sign &) const
       {
         return false;
       }

      bool operator==(const ANTsR_Sign & other) const
       {
         return !( *this != other );
       }

      inline DataType operator()(const DataType & A ) const
       {
         DataType output;
         unsigned int nComponents = TraitsType::GetLength(A);
         TraitsType::SetLength(output,nComponents);

         for ( unsigned int i=0; i<nComponents; i++) {
           if ( GetValueType::NthValue(i,A) == 0 ) {
             ConvertType::SetNthComponent(i, output, 0);
           }
           else {
             ConvertType::SetNthComponent(i, output,
               static_cast<ValueType>( GetValueType::NthValue(i,A)>0 ? 1 : -1 ));
            }
         }
         return output;
       }
     };

     template< typename DataType >
     class ANTsR_Sqrt
     {
     public:
       ANTsR_Sqrt() {}
       ~ANTsR_Sqrt() {}

       typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
       typedef itk::NumericTraits<DataType>             TraitsType;
       typedef typename TraitsType::ValueType           ValueType;
       typedef ANTsR_GetDataValue<DataType>             GetValueType;

       bool operator!=(const ANTsR_Sqrt &) const
       {
         return false;
       }

      bool operator==(const ANTsR_Sqrt & other) const
       {
         return !( *this != other );
       }

      inline DataType operator()(const DataType & A ) const
       {
         DataType output;
         unsigned int nComponents = TraitsType::GetLength(A);
         TraitsType::SetLength(output,nComponents);

         for ( unsigned int i=0; i<nComponents; i++) {
           ConvertType::SetNthComponent(i, output,
              static_cast<ValueType>( sqrt(GetValueType::NthValue(i,A)) ));
         }
         return output;
       }
     };

     template< typename DataType >
     class ANTsR_Ceiling
     {
     public:
       ANTsR_Ceiling() {}
       ~ANTsR_Ceiling() {}

       typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
       typedef itk::NumericTraits<DataType>             TraitsType;
       typedef typename TraitsType::ValueType           ValueType;
       typedef ANTsR_GetDataValue<DataType>             GetValueType;

       bool operator!=(const ANTsR_Ceiling &) const
       {
         return false;
       }

      bool operator==(const ANTsR_Ceiling & other) const
       {
         return !( *this != other );
       }

      inline DataType operator()(const DataType & A ) const
       {
         DataType output;
         unsigned int nComponents = TraitsType::GetLength(A);
         TraitsType::SetLength(output,nComponents);

         for ( unsigned int i=0; i<nComponents; i++) {
           ConvertType::SetNthComponent(i, output,
              static_cast<ValueType>( ceil(GetValueType::NthValue(i,A)) ));
         }
         return output;
       }
     };

     template< typename DataType >
     class ANTsR_Floor
     {
     public:
       ANTsR_Floor() {}
       ~ANTsR_Floor() {}

       typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
       typedef itk::NumericTraits<DataType>             TraitsType;
       typedef typename TraitsType::ValueType           ValueType;
       typedef ANTsR_GetDataValue<DataType>             GetValueType;

       bool operator!=(const ANTsR_Floor &) const
       {
         return false;
       }

      bool operator==(const ANTsR_Floor & other) const
       {
         return !( *this != other );
       }

      inline DataType operator()(const DataType & A ) const
       {
         DataType output;
         unsigned int nComponents = TraitsType::GetLength(A);
         TraitsType::SetLength(output,nComponents);

         for ( unsigned int i=0; i<nComponents; i++) {
           ConvertType::SetNthComponent(i, output,
              static_cast<ValueType>( floor(GetValueType::NthValue(i,A)) ));
         }
         return output;
       }
     };

     template< typename DataType >
     class ANTsR_Trunc
     {
     public:
       ANTsR_Trunc() {}
       ~ANTsR_Trunc() {}

       typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
       typedef itk::NumericTraits<DataType>             TraitsType;
       typedef typename TraitsType::ValueType           ValueType;
       typedef ANTsR_GetDataValue<DataType>             GetValueType;

       bool operator!=(const ANTsR_Trunc &) const
       {
         return false;
       }

      bool operator==(const ANTsR_Trunc & other) const
       {
         return !( *this != other );
       }

      inline DataType operator()(const DataType & A ) const
       {
         DataType output;
         unsigned int nComponents = TraitsType::GetLength(A);
         TraitsType::SetLength(output,nComponents);

         for ( unsigned int i=0; i<nComponents; i++) {
           ConvertType::SetNthComponent(i, output,
              static_cast<ValueType>( trunc(GetValueType::NthValue(i,A)) ));
         }
         return output;
       }
     };

     template< typename DataType >
     class ANTsR_Log
     {
     public:
       ANTsR_Log() {}
       ~ANTsR_Log() {}

       typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
       typedef itk::NumericTraits<DataType>             TraitsType;
       typedef typename TraitsType::ValueType           ValueType;
       typedef ANTsR_GetDataValue<DataType>             GetValueType;

       bool operator!=(const ANTsR_Log &) const
       {
         return false;
       }

      bool operator==(const ANTsR_Log & other) const
       {
         return !( *this != other );
       }

      inline DataType operator()(const DataType & A ) const
       {
         DataType output;
         unsigned int nComponents = TraitsType::GetLength(A);
         TraitsType::SetLength(output,nComponents);

         for ( unsigned int i=0; i<nComponents; i++) {
           ConvertType::SetNthComponent(i, output,
              static_cast<ValueType>( log(GetValueType::NthValue(i,A)) ));
         }
         return output;
       }
     };

     template< typename DataType >
     class ANTsR_Log10
     {
     public:
       ANTsR_Log10() {}
       ~ANTsR_Log10() {}

       typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
       typedef itk::NumericTraits<DataType>             TraitsType;
       typedef typename TraitsType::ValueType           ValueType;
       typedef ANTsR_GetDataValue<DataType>             GetValueType;

       bool operator!=(const ANTsR_Log10 &) const
       {
         return false;
       }

      bool operator==(const ANTsR_Log10 & other) const
       {
         return !( *this != other );
       }

      inline DataType operator()(const DataType & A ) const
       {
         DataType output;
         unsigned int nComponents = TraitsType::GetLength(A);
         TraitsType::SetLength(output,nComponents);

         for ( unsigned int i=0; i<nComponents; i++) {
           ConvertType::SetNthComponent(i, output,
              static_cast<ValueType>( log10(GetValueType::NthValue(i,A)) ));
         }
         return output;
       }
     };

     template< typename DataType >
     class ANTsR_Log2
     {
     public:
       ANTsR_Log2() {}
       ~ANTsR_Log2() {}

       typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
       typedef itk::NumericTraits<DataType>             TraitsType;
       typedef typename TraitsType::ValueType           ValueType;
       typedef ANTsR_GetDataValue<DataType>             GetValueType;

       bool operator!=(const ANTsR_Log2 &) const
       {
         return false;
       }

      bool operator==(const ANTsR_Log2 & other) const
       {
         return !( *this != other );
       }

      inline DataType operator()(const DataType & A ) const
       {
         DataType output;
         unsigned int nComponents = TraitsType::GetLength(A);
         TraitsType::SetLength(output,nComponents);

         for ( unsigned int i=0; i<nComponents; i++) {
           ConvertType::SetNthComponent(i, output,
              static_cast<ValueType>( log2(GetValueType::NthValue(i,A)) ));
         }
         return output;
       }
     };

     template< typename DataType >
     class ANTsR_Acos
     {
     public:
       ANTsR_Acos() {}
       ~ANTsR_Acos() {}

       typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
       typedef itk::NumericTraits<DataType>             TraitsType;
       typedef typename TraitsType::ValueType           ValueType;
       typedef ANTsR_GetDataValue<DataType>             GetValueType;

       bool operator!=(const ANTsR_Acos &) const
       {
         return false;
       }

      bool operator==(const ANTsR_Acos & other) const
       {
         return !( *this != other );
       }

      inline DataType operator()(const DataType & A ) const
       {
         DataType output;
         unsigned int nComponents = TraitsType::GetLength(A);
         TraitsType::SetLength(output,nComponents);

         for ( unsigned int i=0; i<nComponents; i++) {
           ConvertType::SetNthComponent(i, output,
              static_cast<ValueType>( acos(GetValueType::NthValue(i,A)) ));
         }
         return output;
       }
     };

     template< typename DataType >
     class ANTsR_Asin
     {
     public:
       ANTsR_Asin() {}
       ~ANTsR_Asin() {}

       typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
       typedef itk::NumericTraits<DataType>             TraitsType;
       typedef typename TraitsType::ValueType           ValueType;
       typedef ANTsR_GetDataValue<DataType>             GetValueType;

       bool operator!=(const ANTsR_Asin &) const
       {
         return false;
       }

      bool operator==(const ANTsR_Asin & other) const
       {
         return !( *this != other );
       }

      inline DataType operator()(const DataType & A ) const
       {
         DataType output;
         unsigned int nComponents = TraitsType::GetLength(A);
         TraitsType::SetLength(output,nComponents);

         for ( unsigned int i=0; i<nComponents; i++) {
           ConvertType::SetNthComponent(i, output,
              static_cast<ValueType>( asin(GetValueType::NthValue(i,A)) ));
         }
         return output;
       }
     };

     template< typename DataType >
     class ANTsR_Atan
     {
     public:
       ANTsR_Atan() {}
       ~ANTsR_Atan() {}

       typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
       typedef itk::NumericTraits<DataType>             TraitsType;
       typedef typename TraitsType::ValueType           ValueType;
       typedef ANTsR_GetDataValue<DataType>             GetValueType;

       bool operator!=(const ANTsR_Atan &) const
       {
         return false;
       }

      bool operator==(const ANTsR_Atan & other) const
       {
         return !( *this != other );
       }

      inline DataType operator()(const DataType & A ) const
       {
         DataType output;
         unsigned int nComponents = TraitsType::GetLength(A);
         TraitsType::SetLength(output,nComponents);

         for ( unsigned int i=0; i<nComponents; i++) {
           ConvertType::SetNthComponent(i, output,
              static_cast<ValueType>( atan(GetValueType::NthValue(i,A)) ));
         }
         return output;
       }
     };

     template< typename DataType >
     class ANTsR_Acosh
     {
     public:
       ANTsR_Acosh() {}
       ~ANTsR_Acosh() {}

       typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
       typedef itk::NumericTraits<DataType>             TraitsType;
       typedef typename TraitsType::ValueType           ValueType;
       typedef ANTsR_GetDataValue<DataType>             GetValueType;

       bool operator!=(const ANTsR_Acosh &) const
       {
         return false;
       }

      bool operator==(const ANTsR_Acosh & other) const
       {
         return !( *this != other );
       }

      inline DataType operator()(const DataType & A ) const
       {
         DataType output;
         unsigned int nComponents = TraitsType::GetLength(A);
         TraitsType::SetLength(output,nComponents);

         for ( unsigned int i=0; i<nComponents; i++) {
           ConvertType::SetNthComponent(i, output,
              static_cast<ValueType>( acosh(GetValueType::NthValue(i,A)) ));
         }
         return output;
       }
     };

     template< typename DataType >
     class ANTsR_Asinh
     {
     public:
       ANTsR_Asinh() {}
       ~ANTsR_Asinh() {}

       typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
       typedef itk::NumericTraits<DataType>             TraitsType;
       typedef typename TraitsType::ValueType           ValueType;
       typedef ANTsR_GetDataValue<DataType>             GetValueType;

       bool operator!=(const ANTsR_Asinh &) const
       {
         return false;
       }

      bool operator==(const ANTsR_Asinh & other) const
       {
         return !( *this != other );
       }

      inline DataType operator()(const DataType & A ) const
       {
         DataType output;
         unsigned int nComponents = TraitsType::GetLength(A);
         TraitsType::SetLength(output,nComponents);

         for ( unsigned int i=0; i<nComponents; i++) {
           ConvertType::SetNthComponent(i, output,
              static_cast<ValueType>( asinh(GetValueType::NthValue(i,A)) ));
         }
         return output;
       }
     };

     template< typename DataType >
     class ANTsR_Atanh
     {
     public:
       ANTsR_Atanh() {}
       ~ANTsR_Atanh() {}

       typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
       typedef itk::NumericTraits<DataType>             TraitsType;
       typedef typename TraitsType::ValueType           ValueType;
       typedef ANTsR_GetDataValue<DataType>             GetValueType;

       bool operator!=(const ANTsR_Atanh &) const
       {
         return false;
       }

      bool operator==(const ANTsR_Atanh & other) const
       {
         return !( *this != other );
       }

      inline DataType operator()(const DataType & A ) const
       {
         DataType output;
         unsigned int nComponents = TraitsType::GetLength(A);
         TraitsType::SetLength(output,nComponents);

         for ( unsigned int i=0; i<nComponents; i++) {
           ConvertType::SetNthComponent(i, output,
              static_cast<ValueType>( atanh(GetValueType::NthValue(i,A)) ));
         }
         return output;
       }
     };

     template< typename DataType >
     class ANTsR_Cos
     {
     public:
       ANTsR_Cos() {}
       ~ANTsR_Cos() {}

       typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
       typedef itk::NumericTraits<DataType>             TraitsType;
       typedef typename TraitsType::ValueType           ValueType;
       typedef ANTsR_GetDataValue<DataType>             GetValueType;

       bool operator!=(const ANTsR_Cos &) const
       {
         return false;
       }

      bool operator==(const ANTsR_Cos & other) const
       {
         return !( *this != other );
       }

      inline DataType operator()(const DataType & A ) const
       {
         DataType output;
         unsigned int nComponents = TraitsType::GetLength(A);
         TraitsType::SetLength(output,nComponents);

         for ( unsigned int i=0; i<nComponents; i++) {
           ConvertType::SetNthComponent(i, output,
              static_cast<ValueType>( cos(GetValueType::NthValue(i,A)) ));
         }
         return output;
       }
     };

     template< typename DataType >
     class ANTsR_Sin
     {
     public:
       ANTsR_Sin() {}
       ~ANTsR_Sin() {}

       typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
       typedef itk::NumericTraits<DataType>             TraitsType;
       typedef typename TraitsType::ValueType           ValueType;
       typedef ANTsR_GetDataValue<DataType>             GetValueType;

       bool operator!=(const ANTsR_Sin &) const
       {
         return false;
       }

      bool operator==(const ANTsR_Sin & other) const
       {
         return !( *this != other );
       }

      inline DataType operator()(const DataType & A ) const
       {
         DataType output;
         unsigned int nComponents = TraitsType::GetLength(A);
         TraitsType::SetLength(output,nComponents);

         for ( unsigned int i=0; i<nComponents; i++) {
           ConvertType::SetNthComponent(i, output,
              static_cast<ValueType>( sin(GetValueType::NthValue(i,A)) ));
         }
         return output;
       }
     };

     template< typename DataType >
     class ANTsR_Tan
     {
     public:
       ANTsR_Tan() {}
       ~ANTsR_Tan() {}

       typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
       typedef itk::NumericTraits<DataType>             TraitsType;
       typedef typename TraitsType::ValueType           ValueType;
       typedef ANTsR_GetDataValue<DataType>             GetValueType;

       bool operator!=(const ANTsR_Tan &) const
       {
         return false;
       }

      bool operator==(const ANTsR_Tan & other) const
       {
         return !( *this != other );
       }

      inline DataType operator()(const DataType & A ) const
       {
         DataType output;
         unsigned int nComponents = TraitsType::GetLength(A);
         TraitsType::SetLength(output,nComponents);

         for ( unsigned int i=0; i<nComponents; i++) {
           ConvertType::SetNthComponent(i, output,
              static_cast<ValueType>( tan(GetValueType::NthValue(i,A)) ));
         }
         return output;
       }
     };

     template< typename DataType >
     class ANTsR_Cosh
     {
     public:
       ANTsR_Cosh() {}
       ~ANTsR_Cosh() {}

       typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
       typedef itk::NumericTraits<DataType>             TraitsType;
       typedef typename TraitsType::ValueType           ValueType;
       typedef ANTsR_GetDataValue<DataType>             GetValueType;

       bool operator!=(const ANTsR_Cosh &) const
       {
         return false;
       }

      bool operator==(const ANTsR_Cosh & other) const
       {
         return !( *this != other );
       }

      inline DataType operator()(const DataType & A ) const
       {
         DataType output;
         unsigned int nComponents = TraitsType::GetLength(A);
         TraitsType::SetLength(output,nComponents);

         for ( unsigned int i=0; i<nComponents; i++) {
           ConvertType::SetNthComponent(i, output,
              static_cast<ValueType>( cosh(GetValueType::NthValue(i,A)) ));
         }
         return output;
       }
     };

     template< typename DataType >
     class ANTsR_Sinh
     {
     public:
       ANTsR_Sinh() {}
       ~ANTsR_Sinh() {}

       typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
       typedef itk::NumericTraits<DataType>             TraitsType;
       typedef typename TraitsType::ValueType           ValueType;
       typedef ANTsR_GetDataValue<DataType>             GetValueType;

       bool operator!=(const ANTsR_Sinh &) const
       {
         return false;
       }

      bool operator==(const ANTsR_Sinh & other) const
       {
         return !( *this != other );
       }

      inline DataType operator()(const DataType & A ) const
       {
         DataType output;
         unsigned int nComponents = TraitsType::GetLength(A);
         TraitsType::SetLength(output,nComponents);

         for ( unsigned int i=0; i<nComponents; i++) {
           ConvertType::SetNthComponent(i, output,
              static_cast<ValueType>( sinh(GetValueType::NthValue(i,A)) ));
         }
         return output;
       }
     };

     template< typename DataType >
     class ANTsR_Tanh
     {
     public:
       ANTsR_Tanh() {}
       ~ANTsR_Tanh() {}

       typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
       typedef itk::NumericTraits<DataType>             TraitsType;
       typedef typename TraitsType::ValueType           ValueType;
       typedef ANTsR_GetDataValue<DataType>             GetValueType;

       bool operator!=(const ANTsR_Tanh &) const
       {
         return false;
       }

      bool operator==(const ANTsR_Tanh & other) const
       {
         return !( *this != other );
       }

      inline DataType operator()(const DataType & A ) const
       {
         DataType output;
         unsigned int nComponents = TraitsType::GetLength(A);
         TraitsType::SetLength(output,nComponents);

         for ( unsigned int i=0; i<nComponents; i++) {
           ConvertType::SetNthComponent(i, output,
              static_cast<ValueType>( tanh(GetValueType::NthValue(i,A)) ));
         }
         return output;
       }
     };
   template< typename DataType >
   class ANTsR_Cospi
   {
   public:
     ANTsR_Cospi() {}
     ~ANTsR_Cospi() {}

     typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
     typedef itk::NumericTraits<DataType>             TraitsType;
     typedef typename TraitsType::ValueType           ValueType;
     typedef ANTsR_GetDataValue<DataType>             GetValueType;

     bool operator!=(const ANTsR_Cospi &) const
     {
       return false;
     }

    bool operator==(const ANTsR_Cospi & other) const
     {
       return !( *this != other );
     }

    inline DataType operator()(const DataType & A ) const
     {
       DataType output;
       unsigned int nComponents = TraitsType::GetLength(A);
       TraitsType::SetLength(output,nComponents);

       for ( unsigned int i=0; i<nComponents; i++) {
         ConvertType::SetNthComponent(i, output,
            static_cast<ValueType>( cos(itk::Math::pi * GetValueType::NthValue(i,A)) ));
       }
       return output;
     }
   };

   template< typename DataType >
   class ANTsR_Sinpi
   {
   public:
     ANTsR_Sinpi() {}
     ~ANTsR_Sinpi() {}

     typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
     typedef itk::NumericTraits<DataType>             TraitsType;
     typedef typename TraitsType::ValueType           ValueType;
     typedef ANTsR_GetDataValue<DataType>             GetValueType;

     bool operator!=(const ANTsR_Sinpi &) const
     {
       return false;
     }

    bool operator==(const ANTsR_Sinpi & other) const
     {
       return !( *this != other );
     }

    inline DataType operator()(const DataType & A ) const
     {
       DataType output;
       unsigned int nComponents = TraitsType::GetLength(A);
       TraitsType::SetLength(output,nComponents);

       for ( unsigned int i=0; i<nComponents; i++) {
         ConvertType::SetNthComponent(i, output,
            static_cast<ValueType>( itk::Math::pi * sin(GetValueType::NthValue(i,A)) ));
       }
       return output;
     }
   };

   template< typename DataType >
   class ANTsR_Tanpi
   {
   public:
     ANTsR_Tanpi() {}
     ~ANTsR_Tanpi() {}

     typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
     typedef itk::NumericTraits<DataType>             TraitsType;
     typedef typename TraitsType::ValueType           ValueType;
     typedef ANTsR_GetDataValue<DataType>             GetValueType;

     bool operator!=(const ANTsR_Tanpi &) const
     {
       return false;
     }

    bool operator==(const ANTsR_Tanpi & other) const
     {
       return !( *this != other );
     }

    inline DataType operator()(const DataType & A ) const
     {
       DataType output;
       unsigned int nComponents = TraitsType::GetLength(A);
       TraitsType::SetLength(output,nComponents);

       for ( unsigned int i=0; i<nComponents; i++) {
         ConvertType::SetNthComponent(i, output,
            static_cast<ValueType>( itk::Math::pi * tan(GetValueType::NthValue(i,A)) ));
       }
       return output;
     }
   };

   template< typename DataType >
   class ANTsR_Exp
   {
   public:
     ANTsR_Exp() {}
     ~ANTsR_Exp() {}

     typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
     typedef itk::NumericTraits<DataType>             TraitsType;
     typedef typename TraitsType::ValueType           ValueType;
     typedef ANTsR_GetDataValue<DataType>             GetValueType;

     bool operator!=(const ANTsR_Exp &) const
     {
       return false;
     }

    bool operator==(const ANTsR_Exp & other) const
     {
       return !( *this != other );
     }

    inline DataType operator()(const DataType & A ) const
     {
       DataType output;
       unsigned int nComponents = TraitsType::GetLength(A);
       TraitsType::SetLength(output,nComponents);

       for ( unsigned int i=0; i<nComponents; i++) {
         ConvertType::SetNthComponent(i, output,
            static_cast<ValueType>( exp(GetValueType::NthValue(i,A)) ));
       }
       return output;
     }
   };

   template< typename DataType >
   class ANTsR_Gamma
   {
   public:
     ANTsR_Gamma() {}
     ~ANTsR_Gamma() {}

     typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
     typedef itk::NumericTraits<DataType>             TraitsType;
     typedef typename TraitsType::ValueType           ValueType;
     typedef ANTsR_GetDataValue<DataType>             GetValueType;

     bool operator!=(const ANTsR_Gamma &) const
     {
       return false;
     }

    bool operator==(const ANTsR_Gamma & other) const
     {
       return !( *this != other );
     }

    inline DataType operator()(const DataType & A ) const
     {
       DataType output;
       unsigned int nComponents = TraitsType::GetLength(A);
       TraitsType::SetLength(output,nComponents);

       for ( unsigned int i=0; i<nComponents; i++) {
         ConvertType::SetNthComponent(i, output,
            static_cast<ValueType>( tgamma(GetValueType::NthValue(i,A)) ));
       }
       return output;
     }
   };

   template< typename DataType >
   class ANTsR_Lgamma
   {
   public:
     ANTsR_Lgamma() {}
     ~ANTsR_Lgamma() {}

     typedef itk::DefaultConvertPixelTraits<DataType> ConvertType;
     typedef itk::NumericTraits<DataType>             TraitsType;
     typedef typename TraitsType::ValueType           ValueType;
     typedef ANTsR_GetDataValue<DataType>             GetValueType;

     bool operator!=(const ANTsR_Lgamma &) const
     {
       return false;
     }

    bool operator==(const ANTsR_Lgamma & other) const
     {
       return !( *this != other );
     }

    inline DataType operator()(const DataType & A ) const
     {
       DataType output;
       unsigned int nComponents = TraitsType::GetLength(A);
       TraitsType::SetLength(output,nComponents);

       for ( unsigned int i=0; i<nComponents; i++) {
         ConvertType::SetNthComponent(i, output,
            static_cast<ValueType>( lgamma(GetValueType::NthValue(i,A)) ));
       }
       return output;
     }
   };

  }
  }

template< class ImageType >
SEXP antsImageMath( SEXP r_antsimage, SEXP r_operator )
{
  //Rcpp::Rcout << "antsImageMath " << Rcpp::as< std::string >( r_operator ) << std::endl;

  typedef typename ImageType::PixelType PixelType;
  typedef typename ImageType::Pointer ImagePointerType;

  ImagePointerType image = Rcpp::as<ImagePointerType>(r_antsimage);
  Rcpp::S4 antsimage(r_antsimage);

  if ( Rcpp::as< std::string >( r_operator ) == "abs" )
  {
    typedef itk::UnaryFunctorImageFilter<ImageType, ImageType,
      itk::Functor::ANTsR_Abs<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "sign" )
  {
    typedef itk::UnaryFunctorImageFilter<ImageType, ImageType,
      itk::Functor::ANTsR_Sign<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "sqrt" )
  {
    typedef itk::UnaryFunctorImageFilter<ImageType, ImageType,
      itk::Functor::ANTsR_Sqrt<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "ceiling" )
  {
    typedef itk::UnaryFunctorImageFilter<ImageType, ImageType,
      itk::Functor::ANTsR_Ceiling<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "floor" )
  {
    typedef itk::UnaryFunctorImageFilter<ImageType, ImageType,
      itk::Functor::ANTsR_Floor<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "trunc" )
  {
    typedef itk::UnaryFunctorImageFilter<ImageType, ImageType,
      itk::Functor::ANTsR_Trunc<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "log" )
  {
    typedef itk::UnaryFunctorImageFilter<ImageType, ImageType,
      itk::Functor::ANTsR_Log<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "log10" )
  {
    typedef itk::UnaryFunctorImageFilter<ImageType, ImageType,
      itk::Functor::ANTsR_Log10<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "log2" )
  {
    typedef itk::UnaryFunctorImageFilter<ImageType, ImageType,
      itk::Functor::ANTsR_Log2<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "acos" )
  {
    typedef itk::UnaryFunctorImageFilter<ImageType, ImageType,
      itk::Functor::ANTsR_Acos<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "asin" )
  {
    typedef itk::UnaryFunctorImageFilter<ImageType, ImageType,
      itk::Functor::ANTsR_Asin<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "atan" )
  {
    typedef itk::UnaryFunctorImageFilter<ImageType, ImageType,
      itk::Functor::ANTsR_Atan<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "acosh" )
  {
    typedef itk::UnaryFunctorImageFilter<ImageType, ImageType,
      itk::Functor::ANTsR_Acosh<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "asinh" )
  {
    typedef itk::UnaryFunctorImageFilter<ImageType, ImageType,
      itk::Functor::ANTsR_Asinh<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "atanh" )
  {
    typedef itk::UnaryFunctorImageFilter<ImageType, ImageType,
      itk::Functor::ANTsR_Atanh<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "cos" )
  {
    typedef itk::UnaryFunctorImageFilter<ImageType, ImageType,
      itk::Functor::ANTsR_Cos<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "sin" )
  {
    typedef itk::UnaryFunctorImageFilter<ImageType, ImageType,
      itk::Functor::ANTsR_Sin<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "tan" )
  {
    typedef itk::UnaryFunctorImageFilter<ImageType, ImageType,
      itk::Functor::ANTsR_Tan<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "cosh" )
  {
    typedef itk::UnaryFunctorImageFilter<ImageType, ImageType,
      itk::Functor::ANTsR_Cosh<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "sinh" )
  {
    typedef itk::UnaryFunctorImageFilter<ImageType, ImageType,
      itk::Functor::ANTsR_Sinh<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "tanh" )
  {
    typedef itk::UnaryFunctorImageFilter<ImageType, ImageType,
      itk::Functor::ANTsR_Tanh<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "cospi" )
  {
    typedef itk::UnaryFunctorImageFilter<ImageType, ImageType,
      itk::Functor::ANTsR_Cospi<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "sinpi" )
  {
    typedef itk::UnaryFunctorImageFilter<ImageType, ImageType,
      itk::Functor::ANTsR_Sinpi<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "tanpi" )
  {
    typedef itk::UnaryFunctorImageFilter<ImageType, ImageType,
      itk::Functor::ANTsR_Tanpi<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "exp" )
  {
    typedef itk::UnaryFunctorImageFilter<ImageType, ImageType,
      itk::Functor::ANTsR_Exp<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "gamma" )
  {
    typedef itk::UnaryFunctorImageFilter<ImageType, ImageType,
      itk::Functor::ANTsR_Gamma<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }
  else if ( Rcpp::as< std::string >( r_operator ) == "lgamma" )
  {
    typedef itk::UnaryFunctorImageFilter<ImageType, ImageType,
      itk::Functor::ANTsR_Lgamma<PixelType>  > FilterType;

    typename FilterType::Pointer filter = FilterType::New();
    filter->SetInput( image );
    filter->Update();
    typename ImageType::Pointer outImage = filter->GetOutput();

    return Rcpp::wrap(outImage);
  }

  Rcpp::Rcout << "Unsupported operator: " << Rcpp::as< std::string >( r_operator ) << std::endl;
  return Rcpp::wrap(NA_REAL);
}


RcppExport SEXP antsImageMath( SEXP r_antsimage, SEXP r_operator ) {
try
  {
  if( r_antsimage == NULL || r_operator == NULL )
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
          antsImageMath< ImageType >( r_antsimage, r_operator ) :
          antsImageMath< VectorImageType >( r_antsimage, r_operator );
        }
      else if( dimension == 3 )
        {
        const int ImageDimension = 3;
        typedef itk::Image< PixelType , ImageDimension >      ImageType;
        typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;
        return ( !isVector ) ?
          antsImageMath< ImageType >( r_antsimage, r_operator ) :
          antsImageMath< VectorImageType >( r_antsimage, r_operator );
        }
      else if( dimension == 2 )
        {
        const int ImageDimension = 2;
        typedef itk::Image< PixelType , ImageDimension >      ImageType;
        typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;
        return ( !isVector ) ?
          antsImageMath< ImageType >( r_antsimage, r_operator ) :
          antsImageMath< VectorImageType >( r_antsimage, r_operator );
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
          antsImageMath< ImageType >( r_antsimage, r_operator ) :
          antsImageMath< VectorImageType >( r_antsimage, r_operator );
        }
      else if( dimension == 3 )
        {
        const int ImageDimension = 3;
        typedef itk::Image< PixelType , ImageDimension >      ImageType;
        typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;
        return ( !isVector ) ?
          antsImageMath< ImageType >( r_antsimage, r_operator ) :
          antsImageMath< VectorImageType >( r_antsimage, r_operator );
        }
      else if( dimension == 2 )
        {
        const int ImageDimension = 2;
        typedef itk::Image< PixelType , ImageDimension >      ImageType;
        typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;
        return ( !isVector ) ?
          antsImageMath< ImageType >( r_antsimage, r_operator ) :
          antsImageMath< VectorImageType >( r_antsimage, r_operator );
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
          antsImageMath< ImageType >( r_antsimage, r_operator ) :
          antsImageMath< VectorImageType >( r_antsimage, r_operator );
      }
    else if( dimension == 3 )
      {
      const int ImageDimension = 3;
        typedef itk::Image< PixelType , ImageDimension >      ImageType;
        typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;
        return ( !isVector ) ?
          antsImageMath< ImageType >( r_antsimage, r_operator ) :
          antsImageMath< VectorImageType >( r_antsimage, r_operator );
      }
    else if( dimension == 2 )
      {
      const int ImageDimension = 2;
        typedef itk::Image< PixelType , ImageDimension >      ImageType;
        typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;
        return ( !isVector ) ?
          antsImageMath< ImageType >( r_antsimage, r_operator ) :
          antsImageMath< VectorImageType >( r_antsimage, r_operator );
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
          antsImageMath< ImageType >( r_antsimage, r_operator ) :
          antsImageMath< VectorImageType >( r_antsimage, r_operator );
      }
    else if( dimension == 3 )
      {
      const int ImageDimension = 3;
        typedef itk::Image< PixelType , ImageDimension >      ImageType;
        typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;
        return ( !isVector ) ?
          antsImageMath< ImageType >( r_antsimage, r_operator ) :
          antsImageMath< VectorImageType >( r_antsimage, r_operator );
      }
    else if( dimension == 2 )
      {
      const int ImageDimension = 2;
        typedef itk::Image< PixelType , ImageDimension >      ImageType;
        typedef itk::VectorImage< PixelType, ImageDimension > VectorImageType;
        return ( !isVector ) ?
          antsImageMath< ImageType >( r_antsimage, r_operator ) :
          antsImageMath< VectorImageType >( r_antsimage, r_operator );
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
