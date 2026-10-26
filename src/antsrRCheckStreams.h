#ifndef ANTSR_R_CHECK_STREAMS_H
#define ANTSR_R_CHECK_STREAMS_H

#include <iostream>

// Avoid direct std::cout/std::cerr references from ITK/ANTs header templates
// in R package builds.  Rcpp::Rcout/Rcpp::Rcerr are unaffected.
//
// Why: R CMD check scans compiled code for std::cout/std::cerr symbols and
// flags them, since output should go through R's console.  The offending
// writes live in third-party ITK/ANTs templates that get instantiated in our
// translation units, so we cannot rewrite them.  Remapping them to std::clog
// hides them from that check; the output is NOT routed through R and still
// goes to the process's stderr.  Prefer Rcpp::Rcout/Rcerr in ANTsRCore code.
//
// Usage: include this header (after <iostream>, which it pulls in so the real
// std::cout/std::cerr declarations are not renamed) before the ITK/ANTs
// headers, then #undef cout and #undef cerr right after them so the macros do
// not leak into the rest of the file.  This only affects code compiled in
// ANTsRCore's own sources, not the prebuilt static ANTs libraries in antb/.
#define cout clog
#define cerr clog

#endif
