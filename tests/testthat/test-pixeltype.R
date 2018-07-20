context("pixeltype")

test_that("pixeltype", {
  img01 <- as.antsImage(array(1:64, c(4, 4, 4, 1)))
  stopifnot(is.character(pixeltype(img01)))
  pixeltype(img01) = "float"
  testthat::expect_error({
    pixeltype(img01) = 1.5
  })
})

test_that("pixeltypes and components and origin are wrong", {
  img01 <- as.antsImage(array(1:64, c(4, 4, 4, 1)))
  stopifnot(components(img01) == 1)
  components(img01) = 1L
  testthat::expect_error({
    components(img01) = 1.5
  })
})

test_that("origin and spacing", {
  img01 <- as.antsImage(array(1:64, c(4, 4, 4, 1)))
  testthat::expect_equal(spacing(img01), rep(1, 4))
  spacing(img01) = rep(1, 4)
  img01 <- as.antsImage(array(1:64, c(4, 4, 4, 1)))
  testthat::expect_true(is.matrix(direction(img01)))
  direction(img01) = diag(4)
  img01 <- as.antsImage(array(1:64, c(4, 4, 4, 1)))
  testthat::expect_true(all(origin(img01) == rep(0, 4)))
  
})
