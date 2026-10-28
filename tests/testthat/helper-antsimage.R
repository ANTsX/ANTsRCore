# ANTsR depends on ANTsRCore, so these tests cannot use ANTsR (that would be a
# circular dependency). The C++ code only needs the S4 classes to exist, so
# define minimal copies of ANTsR's antsImage, antsRegion and antsImageIterator
# classes and call the ANTsRCore functions directly.
if (!methods::isClass("antsImage")) {
  methods::setClass("antsImage", methods::representation(
    pixeltype = "character", dimension = "integer",
    components = "integer", pointer = "externalptr",
    isVector = "logical", filename = "character"
  ), prototype = list(isVector = FALSE, filename = ""))
}
if (!methods::isClass("antsRegion")) {
  methods::setClass("antsRegion", methods::representation(
    index = "numeric", size = "numeric"
  ))
}
if (!methods::isClass("antsImageIterator")) {
  methods::setClass("antsImageIterator", methods::representation(
    pixeltype = "character", dimension = "integer",
    components = "integer", pointer = "externalptr"
  ))
}

# A constant image of size `dims` with the given pixel type.
make_test_image <- function(dims, value, pixeltype = "float") {
  d <- length(dims)
  img <- antsImage_asantsImage(
    array(value, dim = dims), "float",
    rep(1, d), rep(0, d), diag(d), FALSE
  )
  if (pixeltype != "float") img <- AntsImageClone(img, pixeltype)
  img
}

img_values <- function(x) {
  region <- methods::new("antsRegion", index = integer(), size = integer())
  unique(as.vector(antsImage_asVector(x, logical(), region)))
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
