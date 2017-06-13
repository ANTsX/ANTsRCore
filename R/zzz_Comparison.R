
#' @rdname antsImageops
#' @aliases Ops,antsImage,numeric-method
setMethod("==", signature(e1 = "antsImage", e2 = "numeric"),
          function(e1, e2) {
            res = .Call("antsImageOperatorsImageNumeric", e1, e2, "==", PACKAGE="ANTsRCore")
            return(res)
          })

#' @rdname antsImageops
#' @aliases Ops,antsImage,numeric-method
setMethod("==", signature(e1 = "numeric", e2 = "antsImage"),
          function(e1, e2) {
            res = .Call("antsImageOperatorsImageNumeric", e2, e1, "==", PACKAGE="ANTsRCore")
            return(res)
          })

#' @rdname antsImageops
#' @aliases Ops,antsImage,numeric-method
setMethod("!=", signature(e1 = "antsImage", e2 = "numeric"),
          function(e1, e2) {
            res = .Call("antsImageOperatorsImageNumeric", e1, e2, "!=", PACKAGE="ANTsRCore")
            return(res)
          })

#' @rdname antsImageops
#' @aliases Ops,antsImage,numeric-method
setMethod("!=", signature(e1 = "numeric", e2 = "antsImage"),
          function(e1, e2) {
            res = .Call("antsImageOperatorsImageNumeric", e2, e1, "!=", PACKAGE="ANTsRCore")
            return(res)
          })

#' @rdname antsImageops
#' @aliases Ops,antsImage,numeric-method
setMethod("<=", signature(e1 = "antsImage", e2 = "numeric"),
          function(e1, e2) {
            res = .Call("antsImageOperatorsImageNumeric", e1, e2, "<=", PACKAGE="ANTsRCore")
            return(res)
          })

#' @rdname antsImageops
#' @aliases Ops,antsImage,numeric-method
setMethod("<=", signature(e1 = "numeric", e2 = "antsImage"),
          function(e1, e2) {
            res = .Call("antsImageOperatorsImageNumeric", e2, e1, ">=", PACKAGE="ANTsRCore")
            return(res)
          })

#' @rdname antsImageops
#' @aliases Ops,antsImage,numeric-method
setMethod(">=", signature(e1 = "antsImage", e2 = "numeric"),
          function(e1, e2) {
            res = .Call("antsImageOperatorsImageNumeric", e1, e2, ">=", PACKAGE="ANTsRCore")
            return(res)
          })

#' @rdname antsImageops
#' @aliases Ops,antsImage,numeric-method
setMethod(">=", signature(e1 = "numeric", e2 = "antsImage"),
          function(e1, e2) {
            res = .Call("antsImageOperatorsImageNumeric", e2, e1, "<=", PACKAGE="ANTsRCore")
            return(res)
          })

#' @rdname antsImageops
#' @aliases Ops,antsImage,numeric-method
setMethod("<", signature(e1 = "antsImage", e2 = "numeric"),
          function(e1, e2) {
            res = .Call("antsImageOperatorsImageNumeric", e1, e2, "<", PACKAGE="ANTsRCore")
            return(res)
          })

#' @rdname antsImageops
#' @aliases Ops,antsImage,numeric-method
setMethod("<", signature(e1 = "numeric", e2 = "antsImage"),
          function(e1, e2) {
            res = .Call("antsImageOperatorsImageNumeric", e2, e1, ">", PACKAGE="ANTsRCore")
            return(res)
          })
