context("antsTransformIndexToPhysicalPoint")



print("transforming points")
test_that("making sure antsTransformIndexToPhysicalPoint failures consistent", {
  img <- makeImage(c(10, 10), rnorm(100))
  pt <- antsTransformIndexToPhysicalPoint(img, c(2, 2))
  arr = as.array(img)
  
  testthat::expect_error(antsTransformIndexToPhysicalPoint(arr, c(2, 2)),
                         "antsImage")
  testthat::expect_error(antsTransformIndexToPhysicalPoint(img, c("2", 2)),
                         "index must be")
  testthat::expect_error(antsTransformIndexToPhysicalPoint(img, c(2, 2, 2)),
                         "matrix must be of")
  
})

print("transforming index")
test_that( "making sure antsTransformPhysicalPointToIndex failures consistent",{

  img <- makeImage(c(10, 10), rnorm(100))
  pt <- antsTransformPhysicalPointToIndex(img, c(2, 2))
  arr = as.array(img)
  
  
  testthat::expect_error(antsTransformPhysicalPointToIndex(arr, c(2, 2)), 
                         "antsImage")
  testthat::expect_error(antsTransformPhysicalPointToIndex(img, c("2", 2)), 
                         "point must be")
  testthat::expect_error(antsTransformPhysicalPointToIndex(img, c(2, 2, 2)),
                         "matrix must be of")
  
  
})


