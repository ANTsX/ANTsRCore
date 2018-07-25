context("Getting Neighborhoods")
img <- makeImage(c(10, 10), rnorm(100))
center <- dim(img) / 2
radius <- rep(3, 2)

test_that("getNeighborhoodAtVoxel", {
  nhlist <- getNeighborhoodAtVoxel(img, center, radius)
  kernel <- 1 * (rnorm(49) > 0)
  dim(kernel) <- c(7, 7)
  randlist <- getNeighborhoodAtVoxel(img, center, kernel)
  randlist <- getNeighborhoodAtVoxel(img, center, kernel,
                                     physical.coordinates = TRUE)
  arr = as.array(img)
  testthat::expect_error(getNeighborhoodAtVoxel(arr, center, kernel), "class")
  testthat::expect_error(getNeighborhoodAtVoxel(img, as.character(center), kernel),
                         "center must be")
  testthat::expect_error(getNeighborhoodAtVoxel(img, center, c(radius, 3)),
                         "kernel must have same")
})


r16 <- getANTsRData("r16")
r16 <- antsImageRead(r16, 2)
mask <- getMask(r16, lowThresh = mean(r16), cleanup = 1)
radius <- rep(2, 2)

test_that("getNeighborhoodInMask", {
  mat <- getNeighborhoodInMask(r16, mask, radius)
  mat <- getNeighborhoodInMask(r16, mask, radius,
                               boundary.condition = "image")
  mat <- getNeighborhoodInMask(r16, mask, radius,
                               boundary.condition = "mean")
  randlist <- getNeighborhoodInMask(r16, mask, radius,
                                    physical.coordinates = TRUE)
  arr = as.array(r16)
  testthat::expect_error(getNeighborhoodInMask(arr, mask, radius), "antsImage")
  testthat::expect_error(getNeighborhoodInMask(r16, as.numeric(mask), radius),
                         "mask must be")
  testthat::expect_error(getNeighborhoodInMask(r16, mask, as.character(radius)),
                         "radius must be")
})

