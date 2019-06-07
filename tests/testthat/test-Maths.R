context("Testing Math operations")
img <- makeImage(c(10, 10, 3), rpois(n = 100*3, lambda = 5)) 
#normalize 0/1
norm_img = (img - min(img))/(max(img) - min(img))
norm_img[norm_img == 0] = 1e-5


test_that("Maths", {
  run_func = function(fun_name, img) {
    if (fun_name %in% c("acosh", "asinh", "atanh")) {
      img = img + 1
      img[img > pi] = pi
    }
    arr = as.array(img)
    arr_result = do.call(fun_name, args = list(arr))
    img_result = as.array(do.call(fun_name, args = list(img)))
    res = testthat::expect_equal(
      arr_result, img_result, 
      tolerance = 1e-7,
      info = paste0("Running function: ", fun_name))
    return(NULL)
  }
  
  math_funcs = c("abs",
                 "sign",
                 "sqrt",
                 "ceiling",
                 "round",
                 "floor",
                 "trunc",
                 "log",
                 "log10",
                 "log2",
                 "acos",
                 "asin",
                 "atan",
                 "acosh",
                 "asinh",
                 "atanh",
                 "cos",
                 "sin",
                 "tan",
                 "cosh",
                 "sinh",
                 "tanh",
                 "cospi",
                 "exp",
                 "gamma",
                 "lgamma")
  sapply(math_funcs, run_func, img = img)

  sapply(math_funcs, run_func, img = norm_img)
  
  math_funcs = c("sinpi", "tanpi")
  sapply(math_funcs, run_func, img = img)
  sapply(math_funcs, run_func, img = norm_img)
  
})
