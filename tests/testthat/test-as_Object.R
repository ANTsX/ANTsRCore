context("as.OBJECT works for antsImages")

outimg <- makeImage(c(2, 10) , 1)
is.na(outimg)
outimg <- makeImage(c(2, 10) , rnorm(20))
as.numeric(outimg)
as.numeric(outimg, mask = outimg > 1)

test_that("all the conversions work", {

  testthat::expect_error(as.numeric(outimg, mask = outimg))
  
  outimg <- makeImage(c(2, 10) , rnorm(20))
  as.matrix(outimg)
  as.matrix(outimg, mask = outimg > 1)
  testthat::expect_error(as.matrix(outimg, mask = outimg))
  outimg <- makeImage(c(2, 10, 2) , rnorm(40))
  testthat::expect_error(as.matrix(outimg))
  outimg <- makeImage(c(2, 10) , rnorm(20))
  as.matrix(outimg)
  as.matrix(outimg, mask = outimg > 1)
  outimg <- makeImage(c(2, 10, 2) , rnorm(40))
  testthat::expect_error(as.matrix(outimg))

})

img <- antsImageRead(getANTsRData("r16"))
img[img > 5] = 0
sort(unique(as.character(img)))
factor(img)
table(img, img)
