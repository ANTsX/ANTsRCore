#' @rdname antsImageops
#' @aliases ==,antsImage,antsImage-method
setMethod("==", signature(e1 = "antsImage", e2 = "antsImage"),
          function(e1, e2) {
            operator = "=="
            ## either use drop_img_dim and validObject or take out both
            if (!antsImagePhysicalSpaceConsistency(e1, e2)) {
              stop("Images do not occupy the same physical space")
            }
            res = .Call("antsImageOperatorsImageNumeric", 
                        e1, e2, 
                        operator, PACKAGE = "ANTsRCore")
            return(res)

          })

#' @rdname antsImageops
#' @aliases ==,antsImage,list-method
setMethod("==", signature(e1 = "antsImage", e2 = "list"),
          function(e1, e2) {
            stop("antsRegions not done yet!")
          })

#' @rdname antsImageops
#' @aliases ==,antsImage,ANY-method
setMethod("==", signature(e1 = "antsImage", e2 = "ANY"),
          function(e1, e2) {
            operator = "=="
            res = .Call("antsImageOperatorsImageNumeric", 
                        e1, e2, 
                        operator, PACKAGE = "ANTsRCore")  
            return(res)
            # return(.Call("antsImage_RelationalOperators", e1, e2, region,
            #              operator, PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImageops
#' @aliases ==,antsImage,logical-method
setMethod("==", signature(e1 = "antsImage", e2 = "logical"),
          function(e1, e2) {
            operator = "=="
            e2 = as.numeric(e2)
            res = .Call("antsImageOperatorsImageNumeric", 
                        e1, e2, 
                        operator, PACKAGE = "ANTsRCore") 
            return(res)            
            # return(.Call("antsImage_RelationalOperators", e1, e2, region,
            #              operator, PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImageops
#' @aliases ==,ANY,antsImage-method
setMethod("==", signature(e1 = "ANY", e2 = "antsImage"),
          function(e1, e2) {
            a2 = as.array(e2)
            res = callGeneric(e1, a2)
            # res = as.antsImage(res, reference = e1)
            return(res)
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
            res = .Call("antsImageOperatorsImageNumeric", 
                        e1, e2, 
                        operator, PACKAGE = "ANTsRCore")
            return(res)

          })

#' @rdname antsImageops
#' @aliases >,antsImage,list-method
setMethod(">", signature(e1 = "antsImage", e2 = "list"),
          function(e1, e2) {
            stop("antsRegions not done yet!")
          })

#' @rdname antsImageops
#' @aliases >,antsImage,ANY-method
setMethod(">", signature(e1 = "antsImage", e2 = "ANY"),
          function(e1, e2) {
            operator = ">"
            res = .Call("antsImageOperatorsImageNumeric", 
                        e1, e2, 
                        operator, PACKAGE = "ANTsRCore")  
            return(res)
            # return(.Call("antsImage_RelationalOperators", e1, e2, region,
            #              operator, PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImageops
#' @aliases >,antsImage,logical-method
setMethod(">", signature(e1 = "antsImage", e2 = "logical"),
          function(e1, e2) {
            operator = ">"
            e2 = as.numeric(e2)
            res = .Call("antsImageOperatorsImageNumeric", 
                        e1, e2, 
                        operator, PACKAGE = "ANTsRCore") 
            return(res)            
            # return(.Call("antsImage_RelationalOperators", e1, e2, region,
            #              operator, PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImageops
#' @aliases >,ANY,antsImage-method
setMethod(">", signature(e1 = "ANY", e2 = "antsImage"),
          function(e1, e2) {
            a2 = as.array(e2)
            res = callGeneric(e1, a2)
            # res = as.antsImage(res, reference = e1)
            return(res)
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
            res = .Call("antsImageOperatorsImageNumeric", 
                        e1, e2, 
                        operator, PACKAGE = "ANTsRCore")
            return(res)

          })

#' @rdname antsImageops
#' @aliases <,antsImage,list-method
setMethod("<", signature(e1 = "antsImage", e2 = "list"),
          function(e1, e2) {
            stop("antsRegions not done yet!")
          })

#' @rdname antsImageops
#' @aliases <,antsImage,ANY-method
setMethod("<", signature(e1 = "antsImage", e2 = "ANY"),
          function(e1, e2) {
            operator = "<"
            res = .Call("antsImageOperatorsImageNumeric", 
                        e1, e2, 
                        operator, PACKAGE = "ANTsRCore")  
            return(res)
            # return(.Call("antsImage_RelationalOperators", e1, e2, region,
            #              operator, PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImageops
#' @aliases <,antsImage,logical-method
setMethod("<", signature(e1 = "antsImage", e2 = "logical"),
          function(e1, e2) {
            operator = "<"
            e2 = as.numeric(e2)
            res = .Call("antsImageOperatorsImageNumeric", 
                        e1, e2, 
                        operator, PACKAGE = "ANTsRCore") 
            return(res)            
            # return(.Call("antsImage_RelationalOperators", e1, e2, region,
            #              operator, PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImageops
#' @aliases <,ANY,antsImage-method
setMethod("<", signature(e1 = "ANY", e2 = "antsImage"),
          function(e1, e2) {
            a2 = as.array(e2)
            res = callGeneric(e1, a2)
            # res = as.antsImage(res, reference = e1)
            return(res)
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
            res = .Call("antsImageOperatorsImageNumeric", 
                        e1, e2, 
                        operator, PACKAGE = "ANTsRCore")
            return(res)

          })

#' @rdname antsImageops
#' @aliases !=,antsImage,list-method
setMethod("!=", signature(e1 = "antsImage", e2 = "list"),
          function(e1, e2) {
            stop("antsRegions not done yet!")
          })

#' @rdname antsImageops
#' @aliases !=,antsImage,ANY-method
setMethod("!=", signature(e1 = "antsImage", e2 = "ANY"),
          function(e1, e2) {
            operator = "!="
            res = .Call("antsImageOperatorsImageNumeric", 
                        e1, e2, 
                        operator, PACKAGE = "ANTsRCore")  
            return(res)
            # return(.Call("antsImage_RelationalOperators", e1, e2, region,
            #              operator, PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImageops
#' @aliases !=,antsImage,logical-method
setMethod("!=", signature(e1 = "antsImage", e2 = "logical"),
          function(e1, e2) {
            operator = "!="
            e2 = as.numeric(e2)
            res = .Call("antsImageOperatorsImageNumeric", 
                        e1, e2, 
                        operator, PACKAGE = "ANTsRCore") 
            return(res)            
            # return(.Call("antsImage_RelationalOperators", e1, e2, region,
            #              operator, PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImageops
#' @aliases !=,ANY,antsImage-method
setMethod("!=", signature(e1 = "ANY", e2 = "antsImage"),
          function(e1, e2) {
            a2 = as.array(e2)
            res = callGeneric(e1, a2)
            # res = as.antsImage(res, reference = e1)
            return(res)
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
            res = .Call("antsImageOperatorsImageNumeric", 
                        e1, e2, 
                        operator, PACKAGE = "ANTsRCore")
            return(res)

          })

#' @rdname antsImageops
#' @aliases <=,antsImage,list-method
setMethod("<=", signature(e1 = "antsImage", e2 = "list"),
          function(e1, e2) {
            stop("antsRegions not done yet!")
          })

#' @rdname antsImageops
#' @aliases <=,antsImage,ANY-method
setMethod("<=", signature(e1 = "antsImage", e2 = "ANY"),
          function(e1, e2) {
            operator = "<="
            res = .Call("antsImageOperatorsImageNumeric", 
                        e1, e2, 
                        operator, PACKAGE = "ANTsRCore")  
            return(res)
            # return(.Call("antsImage_RelationalOperators", e1, e2, region,
            #              operator, PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImageops
#' @aliases <=,antsImage,logical-method
setMethod("<=", signature(e1 = "antsImage", e2 = "logical"),
          function(e1, e2) {
            operator = "<="
            e2 = as.numeric(e2)
            res = .Call("antsImageOperatorsImageNumeric", 
                        e1, e2, 
                        operator, PACKAGE = "ANTsRCore") 
            return(res)            
            # return(.Call("antsImage_RelationalOperators", e1, e2, region,
            #              operator, PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImageops
#' @aliases <=,ANY,antsImage-method
setMethod("<=", signature(e1 = "ANY", e2 = "antsImage"),
          function(e1, e2) {
            a2 = as.array(e2)
            res = callGeneric(e1, a2)
            # res = as.antsImage(res, reference = e1)
            return(res)
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
            res = .Call("antsImageOperatorsImageNumeric", 
                        e1, e2, 
                        operator, PACKAGE = "ANTsRCore")
            return(res)

          })

#' @rdname antsImageops
#' @aliases >=,antsImage,list-method
setMethod(">=", signature(e1 = "antsImage", e2 = "list"),
          function(e1, e2) {
            stop("antsRegions not done yet!")
          })

#' @rdname antsImageops
#' @aliases >=,antsImage,ANY-method
setMethod(">=", signature(e1 = "antsImage", e2 = "ANY"),
          function(e1, e2) {
            operator = ">="
            res = .Call("antsImageOperatorsImageNumeric", 
                        e1, e2, 
                        operator, PACKAGE = "ANTsRCore")  
            return(res)
            # return(.Call("antsImage_RelationalOperators", e1, e2, region,
            #              operator, PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImageops
#' @aliases >=,antsImage,logical-method
setMethod(">=", signature(e1 = "antsImage", e2 = "logical"),
          function(e1, e2) {
            operator = ">="
            e2 = as.numeric(e2)
            res = .Call("antsImageOperatorsImageNumeric", 
                        e1, e2, 
                        operator, PACKAGE = "ANTsRCore") 
            return(res)            
            # return(.Call("antsImage_RelationalOperators", e1, e2, region,
            #              operator, PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImageops
#' @aliases >=,ANY,antsImage-method
setMethod(">=", signature(e1 = "ANY", e2 = "antsImage"),
          function(e1, e2) {
            a2 = as.array(e2)
            res = callGeneric(e1, a2)
            # res = as.antsImage(res, reference = e1)
            return(res)
          })











