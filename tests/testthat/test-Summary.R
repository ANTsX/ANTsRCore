testthat::context("Testing Summary operations")
img <- makeImage(c(10, 100, 3), rpois(n = 1000*3, lambda = 5)) 
img[1,1,1] = 0

mask = abs(img) <= 1

testthat::test_that("Summaries", {
  run_func = function(fun_name, img) {
    arr = as.array(img)
    arr_result = do.call(fun_name, args = list(arr))
    img_result = as.array(do.call(fun_name, args = list(img)))
    res = testthat::expect_equal(
      arr_result, img_result, 
      tolerance = 1e-6,
      info = paste0("Running function: ", fun_name))
    return(NULL)
  }
  
  
  sumofsquares = function(x) {
    sum(x^2)
  }
  
  math_funcs = c("mean",
                 "min",
                 "max",
                 "sd",
                 "var",
                 "sum",
                 "sumofsquares")
  sapply(math_funcs, run_func, img = img)
  
  sapply(math_funcs, run_func, img = norm_img)
  
  
  math_funcs = c("gamma", "sinpi", "tanpi")
  # expect_error(
  sapply(math_funcs, run_func, img = img)
  # )
  # expect_error(
  sapply(math_funcs, run_func, img = norm_img)
  # )
  
})
