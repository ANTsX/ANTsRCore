testthat::context("Testing Finite operations")
img <- makeImage(c(10, 100, 3), rpois(n = 1000*3, lambda = 5)) 
img[1,1,1] = NA_real_
img[1,1,2] = Inf
img[1,1,3] = NaN
img[1,2,3] = -Inf
as.array(img)[1,1,]

testthat::test_that("Finite", {
  
  testthat::expect_true(anyNA(img))
  testthat::expect_is(is.na(img), "antsImage")
  testthat::expect_equal(sum(is.na(img)), 2)
  testthat::expect_equal(sum(is.na(img)), sum(is.na(as.array(img))))  
  
  # this is because coercion of NA to NaN in antsImage Object
  testthat::expect_is(is.nan(img), "antsImage")
  testthat::expect_equal(sum(is.nan(img)), 2)  
  testthat::expect_equal(sum(is.nan(img)), sum(is.nan(as.array(img))))  
  
  fin_img = is.finite(img)
  testthat::expect_is(fin_img, "antsImage")
  testthat::expect_equal(sum(fin_img), length(as.array(img)) - 4)
  testthat::expect_equal(sum(coerce_mask(fin_img)), 
                         sum(fin_img))
  
  not_fin_img = fin_img == 0
  testthat::expect_is(fin_img, "antsImage")
  testthat::expect_equal(sum(not_fin_img), 4)
  testthat::expect_equal(sum(coerce_mask(not_fin_img)), sum(not_fin_img))
  

  inf_img = is.infinite(img)
  testthat::expect_is(inf_img, "antsImage")
  testthat::expect_equal(sum(inf_img), 2)
  testthat::expect_equal(sum(coerce_mask(inf_img)), 
                         sum(inf_img))
  
})
