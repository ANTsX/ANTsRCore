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

setMethod("abs", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "abs", PACKAGE = "ANTsRCore"))
          })

setMethod("sign", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "sign", PACKAGE = "ANTsRCore"))
          })

setMethod("sqrt", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "sqrt", PACKAGE = "ANTsRCore"))
          })

setMethod("ceiling", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "ceiling", PACKAGE = "ANTsRCore"))
          })

setMethod("floor", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "floor", PACKAGE = "ANTsRCore"))
          })

setMethod("trunc", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "trunc", PACKAGE = "ANTsRCore"))
          })

setMethod("log", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "log", PACKAGE = "ANTsRCore"))
          })

setMethod("log10", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "log10", PACKAGE = "ANTsRCore"))
          })

setMethod("log2", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "log2", PACKAGE = "ANTsRCore"))
          })

setMethod("acos", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "acos", PACKAGE = "ANTsRCore"))
          })

setMethod("asin", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "asin", PACKAGE = "ANTsRCore"))
          })

setMethod("atan", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "atan", PACKAGE = "ANTsRCore"))
          })

setMethod("acosh", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "acosh", PACKAGE = "ANTsRCore"))
          })

setMethod("asinh", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "asinh", PACKAGE = "ANTsRCore"))
          })

setMethod("atanh", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "atanh", PACKAGE = "ANTsRCore"))
          })

setMethod("cos", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "cos", PACKAGE = "ANTsRCore"))
          })

setMethod("sin", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "sin", PACKAGE = "ANTsRCore"))
          })

setMethod("tan", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "tan", PACKAGE = "ANTsRCore"))
          })

setMethod("cosh", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "cosh", PACKAGE = "ANTsRCore"))
          })

setMethod("sinh", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "sinh", PACKAGE = "ANTsRCore"))
          })

setMethod("tanh", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "tanh", PACKAGE = "ANTsRCore"))
          })

setMethod("cospi", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "cospi", PACKAGE = "ANTsRCore"))
          })

setMethod("sinpi", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "sinpi", PACKAGE = "ANTsRCore"))
          })

setMethod("tanpi", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "tanpi", PACKAGE = "ANTsRCore"))
          })

setMethod("exp", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "exp", PACKAGE = "ANTsRCore"))
          })

setMethod("gamma", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "gamma", PACKAGE = "ANTsRCore"))
          })

setMethod("lgamma", signature(x = "antsImage"),
          function(x) {
            return(.Call("antsImageMath", x, "lgamma", PACKAGE = "ANTsRCore"))
          })
