context("antsApplyTransforms works")

# Use pixeltype=="double" for tests, if using the default pixeltype=="float"
# then all test will fail due loss of precision
fixed <- antsImageRead(getANTsRData("r16") , 2)
moving <- antsImageRead(getANTsRData("r64") , 2)
fixed <- resampleImage(fixed, c(64, 64), 1, 0)
moving <- resampleImage(moving, c(68, 68), 1, 0)
mytx <- antsRegistration(fixed = fixed ,
                         moving = moving ,
                         typeofTransform = c("SyN"))

mywarpedimage <- antsApplyTransforms(
  fixed = fixed,
  moving = moving,
  transformlist = mytx$fwdtransforms
)

test_that("antsApplyTransforms will give consistent out space", {
  
  testthat::expect_true(antsImagePhysicalSpaceConsistency(mywarpedimage, fixed))
})

test_that("inverse antsApplyTransforms will give consistent out space", {
  invwarped_image <- antsApplyTransforms(
    fixed = moving,
    moving = fixed,
    transformlist = mytx$invtransforms
  )
  testthat::expect_true(antsImagePhysicalSpaceConsistency(invwarped_image, moving))
  
})

test_that("compose transformation will work", {
  tfile = tempfile()
  out_composed_transform <- antsApplyTransforms(
    fixed = fixed,
    moving = moving,
    transformlist = mytx$invtransforms,
    compose = tfile
  )
  outfile = paste0(tfile, "comptx.nii.gz")
  testthat::expect_equal(out_composed_transform, outfile)
  
  warped_from_composed <- antsApplyTransforms(
    fixed = fixed,
    moving = moving,
    transformlist = outfile
  )  
  testthat::expect_equal(warped_from_composed, mywarpedimage)
  
  aimg = antsImageRead(outfile)
  testthat::expect_warning({
    warped_with_aimg <- antsApplyTransforms(
      fixed = fixed,
      moving = moving,
      transformlist = aimg
    )  
  }, "creating a temporary")
  testthat::expect_equal(warped_with_aimg, mywarpedimage)  
  
})


