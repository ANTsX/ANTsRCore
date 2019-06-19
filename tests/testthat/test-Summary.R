testthat::context("Testing Summary operations")
img <- makeImage(c(100, 100, 3), rpois(n = 1000*3, lambda = 5)) 
img[1,1,1] = 0
mask = img > 1

mask = abs(img) <= 1

testthat::test_that("Summaries", {
  run_func = function(fun_name, mask = NULL, img) {
    print(fun_name)
    arr = as.array(img)
    if (!is.null(mask)) {
      arr = arr[ as.array(mask) > 0 ]
    }
    arr_result = do.call(fun_name, args = list(arr))
    L = list(img)
    L$mask = mask
    img_result = do.call(fun_name, args = L)
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
                 "sum")
  fun_name = math_funcs[1]
  sapply(math_funcs, run_func, img = img)
  sapply(math_funcs, run_func, img = mask)
  
  sapply(math_funcs, run_func, img = img, mask = mask)
  
})
