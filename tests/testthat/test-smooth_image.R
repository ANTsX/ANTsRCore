context("Smoothing image")

set.seed(1234)
img <- makeImage(c(5, 5), rnorm(25))
test_that("smooth gives exact results", {
  simg <- smoothImage(img, c(1.2, 1.5))
  testthat::expect_equal(sum(simg),-5.59352651424706)
  testthat::expect_error(
    smoothImage(img, c(1.2, 1.5, 3))
    )
  simg2 <- smoothImage(img, c(1.2, 1.5), FWHM = TRUE)
  
  multi = antsImageRead(getANTsRData("multi_component_image"))
  smulti <- smoothImage(multi, c(1.2, 1.5))
  means = sapply(splitChannels(smulti), mean)
  testthat::expect_equal(means, c(86.0794883092244, 81.913664855957, 85.519760093689))

})
