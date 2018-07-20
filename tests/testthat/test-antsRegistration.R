context("antsRegistration from Examples")

test_that("read in trans", {
  #print help
  fi <- antsImageRead(getANTsRData("r16"))
  mi <- antsImageRead(getANTsRData("r64"))  
  rig <- antsRegistration(
    fixed = fi,
    moving = mi,
    typeofTransform = 'Rigid')
  trans = readAntsrTransform(rig$fwdtransforms, 2)
  testthat::expect_is(trans, "antsrTransform")
  rm(rig)
  rm(trans)
  
})
# "TVMSQC",




test_that("all the regs", {
  #print help
  fi <- antsImageRead(getANTsRData("r16"))
  mi <- antsImageRead(getANTsRData("r64"))  
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
    "ElasticSyN"
  )) {
    print(itype)
    mytx2 <- antsRegistration(fixed = fi,
                              moving = mi,
                              typeofTransform = itype)
    testthat::expect_true(all(file.exists(mytx2$fwdtransforms)))
    rm(mytx2)
  }
  
})


test_that( "multivariateExtras", {
  
  #print help
  fi <- antsImageRead(getANTsRData("r16"))
  mi <- antsImageRead(getANTsRData("r64"))
  mytx2 <- antsRegistration(
    fixed = fi,
    moving = mi,
    typeofTransform = "SyNOnly",
    multivariateExtras = list(list("MeanSquares", fi, mi, 0.5, 0))
  )
  
  
  testthat::expect_true(all(file.exists(mytx2$fwdtransforms)))
  rm(mytx2)
  
})


test_that("bad type of Transform", {
  #print help
  fi <- antsImageRead(getANTsRData("r16"))
  mi <- antsImageRead(getANTsRData("r64"))
  
  
  testthat::expect_error({
    res = antsRegistration(
      fixed = fi,
      moving = mi,
      typeofTransform = "sdf"
    )
  })
  rm(res)
  
})


test_that( "regIterations", {
  fi <- antsImageRead(getANTsRData("r16"))
  mi <- antsImageRead(getANTsRData("r64"))
  
  bad <- antsRegistration(fixed = fi,
                          moving = mi,
                          regIterations = 40)  
  testthat::expect_true(all(file.exists(bad$fwdtransforms)))
  rm(bad)
  
})  


test_that("affIterations",{
  fi <- antsImageRead(getANTsRData("r16"))
  mi <- antsImageRead(getANTsRData("r64"))  
  affIterations = c(3, 2, 1, 0)
  mytx2 <- antsRegistration(fixed = fi,
                            moving = mi,
                            affIterations = affIterations)
  testthat::expect_true(all(file.exists(mytx2$fwdtransforms)))
  rm(mytx2)
})    






