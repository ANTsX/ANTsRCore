#' @rdname antsImageops
#' @aliases ==,antsImage,antsImage-method
#' @examples
#' img01 <- as.antsImage(array(1:64, c(4,4,4,1)))
#' et = function(x) {
#' testthat::expect_true(x)
#' }
#' x <- is.antsImage(img01 == img01)
#' et(x)
#' x <- is.antsImage(img01 == as.array(img01))
#' et(x)
#' x <- is.antsImage(img01 == 1)
#' et(x)
#' x <- is.antsImage(1 == img01)
#' et(x)
#' x <- is.antsImage(as.array(img01) == img01)
#' et(x)
#' 
#' x <- is.antsImage(img01 >= img01)
#' et(x)
#' x <- is.antsImage(img01 >= as.array(img01))
#' et(x)
#' x <- is.antsImage(img01 >= 1)
#' et(x)
#' x <- is.antsImage(1 >= img01)
#' et(x)
#' x <- is.antsImage(as.array(img01) >= img01) 
#' et(x)
#' 
#' x <- is.antsImage(img01 > img01)
#' et(x)
#' x <- is.antsImage(img01 > as.array(img01))
#' et(x)
#' x <- is.antsImage(img01 > 1)
#' et(x)
#' x <- is.antsImage(1 > img01)
#' et(x)
#' x <- is.antsImage(as.array(img01) > img01) 
#' et(x)
#' 
#' x <- is.antsImage(img01 < img01)
#' et(x)
#' x <- is.antsImage(img01 < as.array(img01))
#' et(x)
#' x <- is.antsImage(img01 < 1)
#' et(x)
#' x <- is.antsImage(1 < img01)
#' et(x)
#' x <- is.antsImage(as.array(img01) < img01) 
#' et(x) 
#' 
#' 
#' x <- is.antsImage(img01 <= img01)
#' et(x)
#' x <- is.antsImage(img01 <= as.array(img01))
#' et(x)
#' x <- is.antsImage(1 <= img01)
#' et(x) 
#' x <- is.antsImage(img01 <= 1)
#' et(x)
#' x <- is.antsImage(as.array(img01) <= img01)  
#' et(x)
#' 
#' x <- is.antsImage(img01 != img01)
#' et(x)
#' x <- is.antsImage(img01 != as.array(img01))
#' et(x)
#' x <- is.antsImage(1 != img01)
#' et(x)  
#' x <- is.antsImage(img01 != 1)
#' et(x)
#' x <- is.antsImage(as.array(img01) != img01) 
#' et(x)
#' 
setMethod("==", signature(e1 = "antsImage", e2 = "antsImage"),
          function(e1, e2) {
            operator = "=="
            ## either use drop_img_dim and validObject or take out both
            if (!antsImagePhysicalSpaceConsistency(e1, e2)) {
              stop("Images do not occupy the same physical space")
            }
            res = .Call("antsImageComparisonImageImage", 
                        e1, e2, 
                        operator, PACKAGE = "ANTsRCore")
            return(res)

          })

#' @rdname antsImageops
#' @aliases ==,antsImage,list-method
#' @examples
#' img01 <- as.antsImage(array(1:64, c(4,4,4,1)))
#' testthat::expect_error(img01 == list())  
setMethod("==", signature(e1 = "antsImage", e2 = "list"),
          function(e1, e2) {
            stop("antsRegions not done yet!")
          })

#' @rdname antsImageops
#' @aliases ==,antsImage,array-method
setMethod("==", signature(e1 = "antsImage", e2 = "array"),
          function(e1, e2) {
            e2 = as.antsImage(e2, reference = e1)
            res = e1 == e2
            return(res)
          })

#' @rdname antsImageops
#' @aliases ==,array,antsImage-method
setMethod("==", signature(e1 = "array", e2 = "antsImage"),
          function(e1, e2) {
            i1 = as.antsImage(e1, reference = e2)
            return(i1 == e2)
          })

#' @rdname antsImageops
#' @aliases ==,antsImage,ANY-method
setMethod("==", signature(e1 = "antsImage", e2 = "ANY"),
          function(e1, e2) {
            operator = "=="
            if (length(e2) == 1) {
              e2 = as.numeric(e2)
              res = .Call("antsImageComparisonImageNumeric", 
                          e1, e2, 
                          operator, PACKAGE = "ANTsRCore")  
              return(res)
            }
            a1 = as.array(e1)
            res = callGeneric(a1, e2)
            res = as.antsImage(res, reference = e1)            
            return(res)
          })

#' @rdname antsImageops
#' @aliases ==,ANY,antsImage-method
setMethod("==", signature(e1 = "ANY", e2 = "antsImage"),
          function(e1, e2) {
            a2 = as.array(e2)
            res = callGeneric(e1, a2)
            res = as.antsImage(res, reference = e2)            
            return(res) # Now returns antsImage
          })






#' @rdname antsImageops
#' @aliases >,antsImage,antsImage-method
setMethod(">", signature(e1 = "antsImage", e2 = "antsImage"),
          function(e1, e2) {
            operator = ">"
            ## either use drop_img_dim and validObject or take out both
            if (!antsImagePhysicalSpaceConsistency(e1, e2)) {
              stop("Images do not occupy the same physical space")
            }
            res = .Call("antsImageComparisonImageImage", 
                        e1, e2, 
                        operator, PACKAGE = "ANTsRCore")
            return(res)

          })

#' @rdname antsImageops
#' @aliases >,antsImage,list-method
#' @examples
#' img01 <- as.antsImage(array(1:64, c(4,4,4,1)))
#' testthat::expect_error(img01 > list())  
setMethod(">", signature(e1 = "antsImage", e2 = "list"),
          function(e1, e2) {
            stop("antsRegions not done yet!")
          })

#' @rdname antsImageops
#' @aliases >,antsImage,array-method
setMethod(">", signature(e1 = "antsImage", e2 = "array"),
          function(e1, e2) {
            e2 = as.antsImage(e2, reference = e1)
            res = e1 > e2
            return(res)
          })

#' @rdname antsImageops
#' @aliases >,array,antsImage-method
setMethod(">", signature(e1 = "array", e2 = "antsImage"),
          function(e1, e2) {
            i1 = as.antsImage(e1, reference = e2)
            return(i1 > e2)
          })

#' @rdname antsImageops
#' @aliases >,antsImage,ANY-method
setMethod(">", signature(e1 = "antsImage", e2 = "ANY"),
          function(e1, e2) {
            operator = ">"
            if (length(e2) == 1) {
              e2 = as.numeric(e2)
              res = .Call("antsImageComparisonImageNumeric", 
                          e1, e2, 
                          operator, PACKAGE = "ANTsRCore")  
              return(res)
            }
            a1 = as.array(e1)
            res = callGeneric(a1, e2)
            res = as.antsImage(res, reference = e1)            
            return(res)
          })

#' @rdname antsImageops
#' @aliases >,ANY,antsImage-method
setMethod(">", signature(e1 = "ANY", e2 = "antsImage"),
          function(e1, e2) {
            a2 = as.array(e2)
            res = callGeneric(e1, a2)
            res = as.antsImage(res, reference = e2)            
            return(res) # Now returns antsImage
          })






#' @rdname antsImageops
#' @aliases <,antsImage,antsImage-method
setMethod("<", signature(e1 = "antsImage", e2 = "antsImage"),
          function(e1, e2) {
            operator = "<"
            ## either use drop_img_dim and validObject or take out both
            if (!antsImagePhysicalSpaceConsistency(e1, e2)) {
              stop("Images do not occupy the same physical space")
            }
            res = .Call("antsImageComparisonImageImage", 
                        e1, e2, 
                        operator, PACKAGE = "ANTsRCore")
            return(res)

          })

#' @rdname antsImageops
#' @aliases <,antsImage,list-method
#' @examples
#' img01 <- as.antsImage(array(1:64, c(4,4,4,1)))
#' testthat::expect_error(img01 < list())   
setMethod("<", signature(e1 = "antsImage", e2 = "list"),
          function(e1, e2) {
            stop("antsRegions not done yet!")
          })

#' @rdname antsImageops
#' @aliases <,antsImage,array-method
setMethod("<", signature(e1 = "antsImage", e2 = "array"),
          function(e1, e2) {
            e2 = as.antsImage(e2, reference = e1)
            res = e1 < e2
            return(res)
          })

#' @rdname antsImageops
#' @aliases <,array,antsImage-method
setMethod("<", signature(e1 = "array", e2 = "antsImage"),
          function(e1, e2) {
            i1 = as.antsImage(e1, reference = e2)
            return(i1 < e2)
          })

#' @rdname antsImageops
#' @aliases <,antsImage,ANY-method
setMethod("<", signature(e1 = "antsImage", e2 = "ANY"),
          function(e1, e2) {
            operator = "<"
            if (length(e2) == 1) {
              e2 = as.numeric(e2)
              res = .Call("antsImageComparisonImageNumeric", 
                          e1, e2, 
                          operator, PACKAGE = "ANTsRCore")  
              return(res)
            }
            a1 = as.array(e1)
            res = callGeneric(a1, e2)
            res = as.antsImage(res, reference = e1)            
            return(res)
          })

#' @rdname antsImageops
#' @aliases <,ANY,antsImage-method
setMethod("<", signature(e1 = "ANY", e2 = "antsImage"),
          function(e1, e2) {
            a2 = as.array(e2)
            res = callGeneric(e1, a2)
            res = as.antsImage(res, reference = e2)            
            return(res) # Now returns antsImage            
          })






#' @rdname antsImageops
#' @aliases !=,antsImage,antsImage-method
setMethod("!=", signature(e1 = "antsImage", e2 = "antsImage"),
          function(e1, e2) {
            operator = "!="
            ## either use drop_img_dim and validObject or take out both
            if (!antsImagePhysicalSpaceConsistency(e1, e2)) {
              stop("Images do not occupy the same physical space")
            }
            res = .Call("antsImageComparisonImageImage", 
                        e1, e2, 
                        operator, PACKAGE = "ANTsRCore")
            return(res)

          })

#' @rdname antsImageops
#' @aliases !=,antsImage,list-method
#' @examples
#' img01 <- as.antsImage(array(1:64, c(4,4,4,1)))
#' testthat::expect_error(img01 != list())  
setMethod("!=", signature(e1 = "antsImage", e2 = "list"),
          function(e1, e2) {
            stop("antsRegions not done yet!")
          })

#' @rdname antsImageops
#' @aliases !=,antsImage,array-method
setMethod("!=", signature(e1 = "antsImage", e2 = "array"),
          function(e1, e2) {
            e2 = as.antsImage(e2, reference = e1)
            res = e1 != e2
            return(res)
          })

#' @rdname antsImageops
#' @aliases !=,array,antsImage-method
setMethod("!=", signature(e1 = "array", e2 = "antsImage"),
          function(e1, e2) {
            i1 = as.antsImage(e1, reference = e2)
            return(i1 != e2)
          })

#' @rdname antsImageops
#' @aliases !=,antsImage,ANY-method
setMethod("!=", signature(e1 = "antsImage", e2 = "ANY"),
          function(e1, e2) {
            operator = "!="
            if (length(e2) == 1) {
              e2 = as.numeric(e2)
              res = .Call("antsImageComparisonImageNumeric", 
                          e1, e2, 
                          operator, PACKAGE = "ANTsRCore")  
              return(res)
            }
            a1 = as.array(e1)
            res = callGeneric(a1, e2)
            res = as.antsImage(res, reference = e1)            
            return(res)
          })

#' @rdname antsImageops
#' @aliases !=,ANY,antsImage-method
setMethod("!=", signature(e1 = "ANY", e2 = "antsImage"),
          function(e1, e2) {
            a2 = as.array(e2)
            res = callGeneric(e1, a2)
            res = as.antsImage(res, reference = e2)            
            return(res) # Now returns antsImage
          })






#' @rdname antsImageops
#' @aliases <=,antsImage,antsImage-method
setMethod("<=", signature(e1 = "antsImage", e2 = "antsImage"),
          function(e1, e2) {
            operator = "<="
            ## either use drop_img_dim and validObject or take out both
            if (!antsImagePhysicalSpaceConsistency(e1, e2)) {
              stop("Images do not occupy the same physical space")
            }
            res = .Call("antsImageComparisonImageImage", 
                        e1, e2, 
                        operator, PACKAGE = "ANTsRCore")
            return(res)

          })

#' @rdname antsImageops
#' @aliases <=,antsImage,list-method
#' @examples
#' img01 <- as.antsImage(array(1:64, c(4,4,4,1)))
#' testthat::expect_error(img01 <= list())  
setMethod("<=", signature(e1 = "antsImage", e2 = "list"),
          function(e1, e2) {
            stop("antsRegions not done yet!")
          })

#' @rdname antsImageops
#' @aliases <=,antsImage,array-method
setMethod("<=", signature(e1 = "antsImage", e2 = "array"),
          function(e1, e2) {
            e2 = as.antsImage(e2, reference = e1)
            res = e1 <= e2
            return(res)
          })

#' @rdname antsImageops
#' @aliases <=,array,antsImage-method
setMethod("<=", signature(e1 = "array", e2 = "antsImage"),
          function(e1, e2) {
            i1 = as.antsImage(e1, reference = e2)
            return(i1 <= e2)
          })

#' @rdname antsImageops
#' @aliases <=,antsImage,ANY-method
setMethod("<=", signature(e1 = "antsImage", e2 = "ANY"),
          function(e1, e2) {
            operator = "<="
            if (length(e2) == 1) {
              e2 = as.numeric(e2)
              res = .Call("antsImageComparisonImageNumeric", 
                          e1, e2, 
                          operator, PACKAGE = "ANTsRCore")  
              return(res)
            }
            a1 = as.array(e1)
            res = callGeneric(a1, e2)
            res = as.antsImage(res, reference = e1)            
            return(res)
          })

#' @rdname antsImageops
#' @aliases <=,ANY,antsImage-method
setMethod("<=", signature(e1 = "ANY", e2 = "antsImage"),
          function(e1, e2) {
            a2 = as.array(e2)
            res = callGeneric(e1, a2)
            res = as.antsImage(res, reference = e2)            
            return(res) # Now returns antsImage
          })






#' @rdname antsImageops
#' @aliases >=,antsImage,antsImage-method
setMethod(">=", signature(e1 = "antsImage", e2 = "antsImage"),
          function(e1, e2) {
            operator = ">="
            ## either use drop_img_dim and validObject or take out both
            if (!antsImagePhysicalSpaceConsistency(e1, e2)) {
              stop("Images do not occupy the same physical space")
            }
            res = .Call("antsImageComparisonImageImage", 
                        e1, e2, 
                        operator, PACKAGE = "ANTsRCore")
            return(res)

          })

#' @rdname antsImageops
#' @aliases >=,antsImage,list-method
#' @examples
#' img01 <- as.antsImage(array(1:64, c(4,4,4,1)))
#' testthat::expect_error(img01 >= list())  
setMethod(">=", signature(e1 = "antsImage", e2 = "list"),
          function(e1, e2) {
            stop("antsRegions not done yet!")
          })

#' @rdname antsImageops
#' @aliases >=,antsImage,array-method
setMethod(">=", signature(e1 = "antsImage", e2 = "array"),
          function(e1, e2) {
            e2 = as.antsImage(e2, reference = e1)
            res = e1 >= e2
            return(res)
          })

#' @rdname antsImageops
#' @aliases >=,array,antsImage-method
setMethod(">=", signature(e1 = "array", e2 = "antsImage"),
          function(e1, e2) {
            i1 = as.antsImage(e1, reference = e2)
            return(i1 >= e2)
          })

#' @rdname antsImageops
#' @aliases >=,antsImage,ANY-method
setMethod(">=", signature(e1 = "antsImage", e2 = "ANY"),
          function(e1, e2) {
            operator = ">="
            if (length(e2) == 1) {
              e2 = as.numeric(e2)
              res = .Call("antsImageComparisonImageNumeric", 
                          e1, e2, 
                          operator, PACKAGE = "ANTsRCore")  
              return(res)
            }
            a1 = as.array(e1)
            res = callGeneric(a1, e2)
            res = as.antsImage(res, reference = e1)            
            return(res)
          })

#' @rdname antsImageops
#' @aliases >=,ANY,antsImage-method
setMethod(">=", signature(e1 = "ANY", e2 = "antsImage"),
          function(e1, e2) {
            a2 = as.array(e2)
            res = callGeneric(e1, a2)
            res = as.antsImage(res, reference = e2)            
            return(res) # Now returns antsImage
          })






