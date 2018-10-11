context("iMath Operations")


# Grayscale morphological operations
test_that("iMath GD", {
  img<-antsImageRead( getANTsRData("r16") )
  img<-iMath(img, "GD", 10)
  expect_true(sum(img) == 5328430)
})

test_that("iMath GE", {
  img<-antsImageRead( getANTsRData("r16") )
  img<-iMath(img, "GE", 10)
  expect_true(sum(img) == 1094198)
})

test_that("iMath GO", {
  img<-antsImageRead( getANTsRData("r16") )
  img<-iMath(img, "GO", 10)
  expect_true(sum(img) == 2412733)
})

test_that("iMath GC", {
  img<-antsImageRead( getANTsRData("r16") )
  img<-iMath(img, "GC", 10)
  expect_true(sum(img) == 3913893)
})
