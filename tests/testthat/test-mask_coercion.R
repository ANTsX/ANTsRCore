context("Mask coercion")
img = makeImage(c(10, 10), rnorm(100))

test_that("mask coercion errors when it should", {
  mask = img > 0
  coerce_mask(mask, error = TRUE)
  coerce_mask(mask + 1, error = FALSE)
  testthat::expect_error(coerce_mask(mask + 1, error = TRUE))
  testthat::expect_silent(coerce_mask(as.array(mask) > 0, error = FALSE))

})
