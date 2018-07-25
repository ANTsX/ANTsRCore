context("Kmeans Segmentation gives same result")

test_that( "Should give same result with same seed", {
  fi <- antsImageRead(getANTsRData("r16") , 2)
  orig = antsImageClone(fi)
  fi <- n3BiasFieldCorrection(fi, 4)
  seg <- kmeansSegmentation(fi, 3)
  seg2 <- kmeansSegmentation(fi, 3)
  arr1 = as.array(seg$segmentation)
  arr2 = as.array(seg2$segmentation)
  testthat::expect_equal(arr1, arr2)
  
  set.seed(2)
  Sys.setenv(ITK_GLOBAL_DEFAULT_NUMBER_OF_THREADS = 1,
             ANTS_RANDOM_SEED = 20180716)
  orig <- antsImageRead(getANTsRData("r16") , 2)
  seg <- kmeansSegmentation(orig, 3, use_random_seed = FALSE)
  seg2 <- kmeansSegmentation(orig, 3, use_random_seed = FALSE)
  arr1 = as.array(seg$segmentation)
  arr2 = as.array(seg2$segmentation)
  testthat::expect_equal(arr1, arr2)

})

Sys.setenv(ANTS_RANDOM_SEED = "")
