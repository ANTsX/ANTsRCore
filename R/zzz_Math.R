#' @title Math for antsImage Objects
#' @description Overloaded math for antsImage objects
#' @name antsImage-math
#' @rdname antsImagemath
#' @param x is an object of class \code{antsImage}.
#' @aliases Math,antsImage-method
#' @examples
#' img01 <- as.antsImage(array(1:64, c(4,4,4,1)))
#' abs(img01)
#' @export
setMethod("Math", signature(x = "antsImage"),
          function(x) {
            a1 = as.array(x)
            res = callGeneric(a1)
            res = as.antsImage(res, reference = x)
            return(res)
          })

#' @rdname antsImagemath
#' @export
setMethod("abs", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "abs", PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImagemath
#' @export
setMethod("sign", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "sign", PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImagemath
#' @export
setMethod("sqrt", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "sqrt", PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImagemath
#' @export
setMethod("ceiling", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "ceiling", PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImagemath
#' @export
setMethod("floor", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "floor", PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImagemath
#' @export
setMethod("trunc", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "trunc", PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImagemath
#' @export
setMethod("log", signature(x = "antsImage"),
          function(x, base=exp(1) ) {
            if ( base==exp(1) ) {
              return(.Call("antsImageMath", x, "log", PACKAGE = "ANTsRCore"))
            }
            else if ( base==2 ) {
              return(.Call("antsImageMath", x, "log2", PACKAGE = "ANTsRCore"))
            }
            else if ( base==10 ) {
              return(.Call("antsImageMath", x, "log10", PACKAGE = "ANTsRCore"))
            }
            else {
              res=.Call("antsImageMath", x, "log10", PACKAGE = "ANTsRCore")
              res = res/(log10(base))
              return(res)
            }

          })

#' @rdname antsImagemath
#' @export
setMethod("log10", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "log10", PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImagemath
#' @export
setMethod("log2", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "log2", PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImagemath
#' @export
setMethod("acos", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "acos", PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImagemath
#' @export
setMethod("asin", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "asin", PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImagemath
#' @export
setMethod("atan", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "atan", PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImagemath
#' @export
setMethod("acosh", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "acosh", PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImagemath
#' @export
setMethod("asinh", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "asinh", PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImagemath
#' @export
setMethod("atanh", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "atanh", PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImagemath
#' @export
setMethod("cos", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "cos", PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImagemath
#' @export
setMethod("sin", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "sin", PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImagemath
#' @export
setMethod("tan", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "tan", PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImagemath
#' @export
setMethod("cosh", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "cosh", PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImagemath
#' @export
setMethod("sinh", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "sinh", PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImagemath
#' @export
setMethod("tanh", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "tanh", PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImagemath
#' @export
setMethod("cospi", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "cospi", PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImagemath
#' @export
setMethod("sinpi", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "sinpi", PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImagemath
#' @export
setMethod("tanpi", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "tanpi", PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImagemath
#' @export
setMethod("exp", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "exp", PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImagemath
#' @export
setMethod("gamma", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "gamma", PACKAGE = "ANTsRCore"))
          })

#' @rdname antsImagemath
#' @export
setMethod("lgamma", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "lgamma", PACKAGE = "ANTsRCore"))
          })
