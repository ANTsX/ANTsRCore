# Regression tests for bugs that return wrong answers without an error.
# Bugs that crash R (#183, #185-#192) are deliberately not exercised here.

test_that("arithmetic on integer images is not truncated (#193)", {
  skip_known_bug(193)
  img <- make_test_image(c(4, 4), 4, "unsigned char")
  expect_equal(img_values(antsImageArithImageNumeric(img, 0.5, "*")), 2)
  expect_equal(img_values(antsImageArithImageNumeric(img, 0.5, "+")), 4.5)
  expect_equal(img_values(antsImageArithImageNumeric(img, 8, "/")), 0.5)
})

test_that("subtraction on integer images does not wrap around (#193)", {
  skip_known_bug(193)
  img <- make_test_image(c(4, 4), 0, "unsigned char")
  expect_equal(img_values(antsImageArithImageNumeric(img, 1, "-")), -1)
})

test_that("& and | on integer images are logical, not bitwise (#194)", {
  skip_known_bug(194)
  a <- make_test_image(c(4, 4), 2, "unsigned int")
  b <- make_test_image(c(4, 4), 1, "unsigned int")
  expect_equal(img_values(antsImageLogicImageImage(a, b, "&")), 1)
  expect_equal(img_values(antsImageLogicImageNumeric(a, TRUE, "&")), 1)
  expect_equal(img_values(antsImageLogicImageNumeric(a, FALSE, "|")), 1)
})

test_that("comparing integer images to a numeric does not truncate it (#195)", {
  skip_known_bug(195)
  img <- make_test_image(c(4, 4), 2, "unsigned char")
  expect_equal(img_values(antsImageComparisonImageNumeric(img, 2.5, "<")), 1)
  expect_equal(img_values(antsImageComparisonImageNumeric(img, 2.5, "==")), 0)
  expect_equal(img_values(antsImageComparisonImageNumeric(img, 2.5, ">=")), 0)
})

test_that("iterators work on double images (#196)", {
  skip_known_bug(196)
  img <- make_test_image(c(4, 4), 1, "double")
  it <- AntsImageIterator(img)
  expect_equal(antsImageIterator_Get(it), 1)
  it <- antsImageIterator_Next(it)
  expect_equal(antsImageIterator_Get(it), 1)
})

test_that("iterators keep working on 3D unsigned int/char images (#196)", {
  skip_known_bug(196)
  for (pt in c("unsigned int", "unsigned char")) {
    img <- make_test_image(c(4, 4, 4), 1, pt)
    it <- antsImageIterator_Next(AntsImageIterator(img))
    expect_equal(antsImageIterator_Get(it), 1, info = pt)
  }
})

test_that("antsImageHeaderInfo direction matches the image direction (#198)", {
  skip_known_bug(198)
  img <- make_test_image(c(5, 6, 7), 1)
  antsImage_SetDirection(img, matrix(c(0, 1, 0, -1, 0, 0, 0, 0, 1), 3))
  f <- tempfile(fileext = ".nii.gz")
  on.exit(unlink(f))
  AntsImageWrite(img, f, FALSE)
  expect_equal(
    AntsImageHeaderInfo(f)$direction,
    antsImage_GetDirection(AntsImageRead(f, "float", 3L, 1L))
  )
})

test_that("test images can be built without ANTsR", {
  img <- make_test_image(c(4, 4), 3, "unsigned char")
  expect_identical(img@pixeltype, "unsigned char")
  expect_equal(img_values(img), 3)
  expect_equal(antsImage_dim(img), c(4, 4))
})
