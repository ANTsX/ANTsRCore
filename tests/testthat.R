library(testthat)
library(ANTsRCore)
Sys.setenv(ITK_GLOBAL_DEFAULT_NUMBER_OF_THREADS = 1)

test_check("ANTsRCore")
