# The antsImage (and related) S4 classes are defined in ANTsR, so any test
# that creates an image needs ANTsR attached for the classes and operators.
skip_without_antsr <- function() {
  skip_if_not_installed("ANTsR")
  suppressPackageStartupMessages(library(ANTsR))
}

# Tests for open bugs assert the correct behaviour and are skipped by default
# so R CMD check stays green. Run them with ANTSRCORE_TEST_KNOWN_BUGS=true;
# remove the skip_known_bug() call when the issue is fixed.
skip_known_bug <- function(issue) {
  if (!identical(Sys.getenv("ANTSRCORE_TEST_KNOWN_BUGS"), "true")) {
    skip(paste0(
      "known bug ANTsX/ANTsRCore#", issue,
      " (set ANTSRCORE_TEST_KNOWN_BUGS=true to run)"
    ))
  }
}

img_values <- function(x) unique(as.vector(as.array(x)))
