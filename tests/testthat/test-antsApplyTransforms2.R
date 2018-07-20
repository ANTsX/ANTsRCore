context("antsApplyTransforms from ex")
### ** Examples

# see antsRegistration
# example 1 - simplified
fixed <- antsImageRead(getANTsRData("r16") , 2)
moving <- antsImageRead(getANTsRData("r64") , 2)
fixed <- resampleImage(fixed, c(64, 64), 1, 0)
moving <- resampleImage(moving, c(68, 68), 1, 0)

mytx <- antsRegistration(fixed = fixed ,
                         moving = moving ,
                         typeofTransform = c("SyN"))

test_that("Consistent spaces", {

  mywarpedimage <- antsApplyTransforms(
    fixed = fixed,
    moving = moving,
    transformlist = mytx$fwdtransforms
  )
  testthat::expect_true(antsImagePhysicalSpaceConsistency(mywarpedimage, fixed))

})

test_that("consistent inverse", {
  invwarped_image <- antsApplyTransforms(
    fixed = moving,
    moving = fixed,
    transformlist = mytx$invtransforms
  )
  testthat::expect_true(antsImagePhysicalSpaceConsistency(invwarped_image, moving))
})

test_that("inverse and compose", {

  res1 <- antsApplyTransforms(
    fixed = fixed,
    moving = moving,
    transformlist = mytx$fwdtransforms[2],
    whichtoinvert = 1
  )
  cfile <- antsApplyTransforms(
    fixed = fixed,
    moving = moving,
    transformlist = mytx$fwdtransforms,
    compose = tempfile()
  )
  
  testthat::expect_true(file.exists(cfile))
  cimg = antsImageRead(cfile)

  cout <- antsApplyTransforms(fixed = fixed,
                              moving = moving,
                              transformlist = cimg)
  testthat::expect_error(
    antsApplyTransforms(
      fixed = fixed,
      moving = moving,
      transformlist = cimg,
      whichtoinvert = 1
    ),
    "nnot invert transform"
  )
  testthat::expect_error(
    antsApplyTransforms(
      fixed = fixed,
      moving = moving,
      transformlist = cimg,
      whichtoinvert = c(1, 2)
    ),
    "same length"
  )
})

test_that("blank transformlist", {
  testthat::expect_error(antsApplyTransforms(
    fixed = fixed,
    moving = moving,
    transformlist = ""
  ))
})

