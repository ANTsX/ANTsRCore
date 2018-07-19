context("antsRegistration from Exmaples")
#print help
antsRegistration()
fi <- antsImageRead(getANTsRData("r16"))
mi <- antsImageRead(getANTsRData("r64"))


test_that({
  mytx2 <- antsRegistration(fixed = fi,  typeofTransform = '')
  rig <- antsRegistration(
    fixed = fi,
    moving = mi,
    typeofTransform = 'Rigid',
    verbose = TRUE
  )
  trans = readAntsrTransform(rig$fwdtransforms, 2)
  postrig <- antsRegistration(
    fixed = fi,
    moving = mi,
    typeofTransform = "Affine",
    initialTransform = trans
  )
  for (itype in c(
    "AffineFast",
    "BOLDAffine",
    "QuickRigid",
    "DenseRigid",
    "BOLDRigid",
    "Translation",
    "Rigid",
    "Similarity",
    "Affine",
    "TRSAA",
    "SyN",
    "SyNRA",
    "SyNOnly",
    "SyNCC",
    "SyNabp",
    "SyNBold",
    "SyNBoldAff",
    "SyNAggro",
    "SyNLessAggro",
    "TVMSQ",
    "TVMSQC",
    "ElasticSyN"
  )) {
    print(itype)
    mytx2 <- antsRegistration(fixed = fi,
                              moving = mi,
                              typeofTransform = itype)
  }
  mytx2 <- antsRegistration(
    fixed = fi,
    moving = mi,
    typeofTransform = "SyNOnly",
    multivariateExtras = list(list("MeanSquares", fi, mi, 0.5, 0))
  )
  testthat::expect_error(antsRegistration(
    fixed = fi,
    moving = mi,
    typeofTransform = "sdf"
  ))
  bad <- antsRegistration(fixed = fi,
                          moving = mi,
                          regIterations = 40)
  affIterations = c(3, 2, 1, 0)
  mytx2 <- antsRegistration(fixed = fi,
                            moving = mi,
                            affIterations = affIterations)
  
  
  fi <- resampleImage(fi, c(60, 60), 1, 0)
  mi <- resampleImage(mi, c(50, 50), 1, 0) # speed up
  mytx <-
    antsRegistration(fixed = fi,
                     moving = mi,
                     typeofTransform = c('SyN'))
  mywarpedimage <- antsApplyTransforms(
    fixed = fi,
    moving = mi,
    transformlist = mytx$fwdtransforms
  )
  mytx2 <-
    antsRegistration(fixed = fi,
                     moving = mi,
                     typeofTransform = c('SyN'))
  mywarpedimage2 <- antsApplyTransforms(
    fixed = fi,
    moving = mi,
    transformlist = mytx2$fwdtransforms
  )
  testthat::expect_equal(mywarpedimage, mywarpedimage2)
}, "all registrations work")
