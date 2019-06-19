#' @rdname antsImageops
#' @aliases is.na,antsImage-method
setMethod("is.na", signature(x = "antsImage"),
          function(x) {
            x = as.antsImage(is.na(as.array(x)), reference = x) 
            pixeltype(x) = "unsigned char"
            x            
          }
)

#' @rdname antsImageops
#' @aliases anyNA,antsImage-method
setMethod("anyNA", signature(x = "antsImage"),
          function(x, recursive = FALSE) {
            anyNA(as.array(x), recursive = recursive)
          }
)


#' @rdname antsImageops
#' @aliases is.nan,antsImage-method
setMethod("is.nan", signature(x = "antsImage"),
          function(x) {
            x = as.antsImage(is.nan(as.array(x)), reference = x) 
            pixeltype(x) = "unsigned char"
            x            
          }
)


#' @rdname antsImageops
#' @aliases is.infinite,antsImage-method
setMethod("is.infinite", signature(x = "antsImage"),
          function(x) {
            x =as.antsImage(is.infinite(as.array(x)), reference = x) 
            pixeltype(x) = "unsigned char"
            x
          }
)


#' @rdname antsImageops
#' @aliases is.finite,antsImage-method
setMethod("is.finite", signature(x = "antsImage"),
          function(x) {
            x = as.antsImage(is.finite(as.array(x)), reference = x) 
            pixeltype(x) = "unsigned char"
            x            
          }
)



