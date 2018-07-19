context("antsTransformIndexToPhysicalPoint")


img <- makeImage(c(10, 10), rnorm(100))

test_that({
  pt <- antsTransformIndexToPhysicalPoint(img, c(2, 2))
  arr = as.array(img)
  testthat::expect_error(antsTransformIndexToPhysicalPoint(arr, c(2, 2)),
                         "antsImage")
  testthat::expect_error(antsTransformIndexToPhysicalPoint(img, c("2", 2)),
                         "index must be")
  testthat::expect_error(antsTransformIndexToPhysicalPoint(img, c(2, 2, 2)),
                         "matrix must be of")
  
}, "making sure antsTransformIndexToPhysicalPoint failures consistent")

img <- makeImage(c(10, 10), rnorm(100))

test_that({
  pt <- antsTransformPhysicalPointToIndex(img, c(2, 2))
  arr = as.array(img)
  testthat::expect_error(antsTransformPhysicalPointToIndex(arr, c(2, 2)), 
                         "antsImage")
  testthat::expect_error(antsTransformPhysicalPointToIndex(img, c("2", 2)), 
                         "point must be")
  testthat::expect_error(antsTransformPhysicalPointToIndex(img, c(2, 2, 2)),
                         "matrix must be of")
  
  
}, "making sure antsTransformPhysicalPointToIndex failures consistent")


