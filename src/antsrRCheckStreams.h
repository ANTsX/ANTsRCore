#ifndef ANTSR_R_CHECK_STREAMS_H
#define ANTSR_R_CHECK_STREAMS_H

#include <iostream>

// Avoid direct std::cout/std::cerr references from ITK/ANTs header templates
// in R package builds.  Rcpp::Rcout/Rcpp::Rcerr are unaffected.
#define cout clog
#define cerr clog

#endif
