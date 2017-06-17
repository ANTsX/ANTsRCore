#' @rdname antsImageops
#' @aliases OPERATOR,antsImage,antsImage-method
setMethod("OPERATOR", signature(e1 = "antsImage", e2 = "antsImage"),
          function(e1, e2) {
            operator = "OPERATOR"
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
#' @aliases OPERATOR,antsImage,list-method
setMethod("OPERATOR", signature(e1 = "antsImage", e2 = "list"),
          function(e1, e2) {
            stop("antsRegions not done yet!")
          })

#' @rdname antsImageops
#' @aliases OPERATOR,antsImage,array-method
setMethod("OPERATOR", signature(e1 = "antsImage", e2 = "array"),
          function(e1, e2) {
            e2 = as.antsImage(e2, reference = e1)
            res = e1 OPERATOR e2
            return(res)
          })

#' @rdname antsImageops
#' @aliases OPERATOR,array,antsImage-method
setMethod("OPERATOR", signature(e1 = "array", e2 = "antsImage"),
          function(e1, e2) {
            i1 = as.antsImage(e1, reference = e2)
            return(i1 OPERATOR e2)
          })

#' @rdname antsImageops
#' @aliases OPERATOR,antsImage,ANY-method
setMethod("OPERATOR", signature(e1 = "antsImage", e2 = "ANY"),
          function(e1, e2) {
            operator = "OPERATOR"
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
#' @aliases OPERATOR,ANY,antsImage-method
setMethod("OPERATOR", signature(e1 = "ANY", e2 = "antsImage"),
          function(e1, e2) {
            a2 = as.array(e2)
            res = callGeneric(e1, a2)
            return(res) # DOES NOT RETURN ANTsImage
          })

