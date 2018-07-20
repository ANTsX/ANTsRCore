context("pixeltype")

test_that({
  img01 <- as.antsImage(array(1:64, c(4, 4, 4, 1)))
  stopifnot(is.character(pixeltype(img01)))
  pixeltype(img01) = "float"
  testthat::expect_error({
    pixeltype(img01) = 1.5
  })
}, "pixeltype")

test_that({
  img01 <- as.antsImage(array(1:64, c(4, 4, 4, 1)))
  stopifnot(components(img01) == 1)
  components(img01) = 1L
  testthat::expect_error({
    components(img01) = 1.5
  })
}, "pixeltypes and components and origin are wrong")

test_that({
  img01 <- as.antsImage(array(1:64, c(4, 4, 4, 1)))
  testthat::expect_true(spacing(img01) == rep(1, 4))
  spacing(img01) = rep(1, 4)
  img01 <- as.antsImage(array(1:64, c(4, 4, 4, 1)))
  testthat::expect_true(is.matrix(direction(img01)))
  direction(img01) = diag(4)
  img01 <- as.antsImage(array(1:64, c(4, 4, 4, 1)))
  testthat::expect_true(all(origin(img01) == rep(0, 4)))
  
}, "origin and spacing")
