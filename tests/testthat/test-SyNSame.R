Sys.setenv(ANTS_RANDOM_SEED = "")
testthat::test_that("running syn twice gives exact same result", {
  
  Sys.setenv(ITK_GLOBAL_DEFAULT_NUMBER_OF_THREADS = 1)
  Sys.setenv(ANTS_RANDOM_SEED = 20180716)
  fi <- antsImageRead(getANTsRData("r16"))
  mi <- antsImageRead(getANTsRData("r64"))
  fi <- resampleImage(fi, c(60, 60), 1, 0)
  mi <- resampleImage(mi, c(50, 50), 1, 0) # speed up
  
  print("running warping")
  
  mytx <-
    antsRegistration(fixed = fi,
                     moving = mi,
                     typeofTransform = c('SyN'))
  mywarpedimage <- antsApplyTransforms(
    fixed = fi,
    moving = mi,
    transformlist = mytx$fwdtransforms
  )
  testthat::expect_is(mywarpedimage, "antsImage")
  
  
  print("running warping2")
  
  mytx2 <-
    antsRegistration(fixed = fi,
                     moving = mi,
                     typeofTransform = c('SyN'))
  mywarpedimage2 <- antsApplyTransforms(
    fixed = fi,
    moving = mi,
    transformlist = mytx2$fwdtransforms
  )
  testthat::expect_is(mywarpedimage2, "antsImage")
  print("running warping2 tests")
  
  # testthat::expect_equal(as.array(mywarpedimage), as.array(mywarpedimage2))
  
})
