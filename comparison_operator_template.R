#' @rdname antsImageops
#' @aliases OPERATOR,antsImage,antsImage-method
setMethod("OPERATOR", signature(e1 = "antsImage", e2 = "antsImage"),
          function(e1, e2) {
            operator = "OPERATOR"
            ## either use drop_img_dim and validObject or take out both
            if (!antsImagePhysicalSpaceConsistency(e1, e2)) {
              stop("Images do not occupy the same physical space")
            }
            region <- new("antsRegion", index = integer(), size = integer())
            res = .Call("antsImage_RelationalOperators", e1, e2, region,
                        operator, PACKAGE = "ANTsR")
            res = as.antsImage(
              array(res, dim = dim(res))
              , reference = res)            
            return(res)

          })

#' @rdname antsImageops
#' @aliases OPERATOR,antsImage,list-method
setMethod("OPERATOR", signature(e1 = "antsImage", e2 = "list"),
          function(e1, e2) {
            stop("antsRegions not done yet!")
          })

#' @rdname antsImageops
#' @aliases OPERATOR,antsImage,ANY-method
setMethod("OPERATOR", signature(e1 = "antsImage", e2 = "ANY"),
          function(e1, e2) {
            operator = "OPERATOR"
            region <- new("antsRegion", index = integer(), size = integer())
            res = .Call("antsImage_RelationalOperators", e1, e2, region,
                        operator, PACKAGE = "ANTsR")
            res = as.antsImage(
              array(res, dim = dim(res))
              , reference = res)     
            return(res)
            # return(.Call("antsImage_RelationalOperators", e1, e2, region,
            #              operator, PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImageops
#' @aliases OPERATOR,antsImage,logical-method
setMethod("OPERATOR", signature(e1 = "antsImage", e2 = "logical"),
          function(e1, e2) {
            operator = "OPERATOR"
            e2 = as.numeric(e2)
            region <- new("antsRegion", index = integer(), size = integer())
            res = .Call("antsImage_RelationalOperators", e1, e2, region,
                        operator, PACKAGE = "ANTsR")
            res = as.antsImage(
              array(res, dim = dim(res))
              , reference = res)     
            return(res)            
            # return(.Call("antsImage_RelationalOperators", e1, e2, region,
            #              operator, PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImageops
#' @aliases OPERATOR,ANY,antsImage-method
setMethod("OPERATOR", signature(e1 = "ANY", e2 = "antsImage"),
          function(e1, e2) {
            a2 = as.array(e2)
            res = callGeneric(e1, a2)
            # res = as.antsImage(res, reference = e1)
            return(res)
          })

