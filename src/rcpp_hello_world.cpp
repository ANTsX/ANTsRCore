
#include <Rcpp.h>

#include "itkImage.h"
#include "itkAdditiveGaussianNoiseImageFilter.h"
#include "itkSaltAndPepperNoiseImageFilter.h"
#include "itkShotNoiseImageFilter.h"
#include "itkSpeckleNoiseImageFilter.h"

using namespace Rcpp;

// [[Rcpp::export]]
List rcpp_hello_world22() {

    CharacterVector x = CharacterVector::create( "foo", "bar" )  ;
    NumericVector y   = NumericVector::create( 0.0, 1.0 ) ;
    List z            = List::create( x, y ) ;

    return z ;
}

// [[Rcpp::export]]
List rcpp_hello_world33() {

  CharacterVector x = CharacterVector::create( "bar", "foo" )  ;
  NumericVector y   = NumericVector::create( 1.0, 0.0 ) ;
  List z            = List::create( x, y ) ;

  return z ;
}

