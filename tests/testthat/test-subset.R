context("bracket subsetting works")
fi <- antsImageRead(getANTsRData("r16"))
l = prod(dim(fi))
sub = sample(c(TRUE, FALSE), size = l, replace = TRUE)

test_that( "all can do subsetting correctly", {
  fi[sub] = rnorm(sum(sub))
  fi[, 1] = array(10, dim = dim(fi[, 1]))
  
  fi <- antsImageRead(getANTsRData("ch2"))
  testthat::expect_is(fi[2, 1, 2], "array")
  fi[2, 1, 2] = 4
  testthat::expect_is(fi[, 1, 2], "array")
  
  fi[, 1, 2] = array(10, dim = dim(fi[, 1, 2]))
  testthat::expect_is(fi[2, , 2], "array")
  
  fi[2, , 2] = array(10, dim = dim(fi[2, , 2]))
  testthat::expect_is(fi[2, 1,], "array")
  # fi[2, 1, ] = array(10, dim = dim(fi[2, 1, ]))
  testthat::expect_is(fi[2, ,], "array")
  testthat::expect_is(fi[, 1,], "array")
  testthat::expect_is(fi[, , 2], "array")
  # fi[, , 2] = array(10, dim = dim(fi[, , 2]))
  # 
  # l = prod(dim(fi))
  # sub = sample(c(TRUE, FALSE), size = l, replace = TRUE)
  # sub = array(sub, dim = dim(fi))
  # fi[sub] = rnorm(sum(sub))
  # fi <- antsImageRead(getANTsRData("r16"))
  # l = prod(dim(fi))
  # sub = sample(c(TRUE, FALSE), size = l, replace = TRUE)
  # sub = array(sub, dim = dim(fi))
  # fi[sub] = rnorm(sum(sub))
  # fi <- antsImageRead(getANTsRData("r16"))
  # fi[fi > 200] = 200
  # fi <- antsImageRead(getANTsRData("r16"))
  # i = sample(seq(nrow(fi)), 5)
  # i = as.numeric(i)
  # j = i
  # fi[i, j] = 26.2
  # fi <- antsImageRead(getANTsRData("r16"))
  # fi[1, ] = array(10, dim = dim(fi[1, ]))
  # fi <- antsImageRead(getANTsRData("r16"))
  # fi[, 1] = array(10, dim = dim(fi[, 1]))
  # fi <- antsImageRead(getANTsRData("r16"))
  # fi[, 1]
  # fi[, 2:5]
  # fi <- antsImageRead(getANTsRData("r16"))
  # fi[fi > 45]
  # fi <- antsImageRead(getANTsRData("r16"))
  # arr = c(as.array(fi) > 45)
  # fi[arr]
  # fi[1:10, 2:14]
  # fi[1:10 * 1.0, 2:14 * 1.0]
  # fi <- antsImageRead(getANTsRData("ch2"))
  # fi[, , 2]
  
  
})
