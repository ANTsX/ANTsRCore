#' Bias Field Correction
#'
#' Perform Bias Field Correction on the given image
#'
#' @param img input antsImage
#' @param mask input mask, if one is not passed one will be made
#' @param shrinkFactor Shrink factor for multi-resolution correction,
#' typically integer less than 4
#' @param convergence List of:  \code{iters}, vector of maximum number of
#' iterations for each shrinkage factor, and \code{tol}, the convergence tolerance.
#' @param splineParam Parameter controlling number of control points in spline.
#' Either single value, indicating how many control points, or vector
#' with one entry per dimension of image, indicating the spacing in each direction.
#' @param weight_mask antsImage of weight mask
#' @param verbose enables verbose output.
#' @return outimg Bias-corrected image
#' @author BB Avants
#' @examples
#'  dims = c(50, 50)
#'  img<-makeImage(imagesize = dims, rnorm(prod(dims)) )
#'  n4img<-n4BiasFieldCorrection(img)
#'
#' @export
n4BiasFieldCorrection <- function(img ,
                                  mask = NA,
                                  shrinkFactor = 4,
                                  convergence = list(iters = c(50, 50, 50, 50), tol =
                                                       0.0000001),
                                  splineParam = 200,
                                  verbose = FALSE,
                                  weight_mask = NULL)
{
  if (!is.antsImage(mask)) {
    mask <- getMask(img)
  }
  N4_CONVERGENCE_1 <-
    paste(
      "[",
      paste(convergence$iters, collapse = "x"),
      ",",
      sprintf("%.10f", convergence$tol),
      "]",
      sep = ""
    )
  N4_SHRINK_FACTOR_1 <- paste(shrinkFactor)
  if (length(splineParam) == 1) {
    N4_BSPLINE_PARAMS <- paste("[", splineParam, "]", sep = "")
  } else if (length(splineParam) == img@dimension) {
    N4_BSPLINE_PARAMS <-
      paste("[", paste(splineParam, collapse = "x"), "]", sep = "")
  }  else {
    stop("Length of splineParam must either be 1 or dimensionality of image.")
  }
  
  if (!is.null(weight_mask)) {
    if (!is.antsImage(weight_mask)) {
      stop("Weight Image must be an antsImage")
    }
  }
  
  outimg <- antsImageClone(img)
  
  args =
    list(d = outimg@dimension,
         i = img)
  args$w = weight_mask
  
  args$s = N4_SHRINK_FACTOR_1
  args$c = N4_CONVERGENCE_1
  args$b = N4_BSPLINE_PARAMS
  args$x = mask
  args$o = outimg
  args$v = as.numeric(verbose)
  
  .helpn4BiasFieldCorrection(args)
  return(outimg)
}
.helpn4BiasFieldCorrection <- function(...) {
  .Call("N4BiasFieldCorrection", .int_antsProcessArguments(c(...)))
}
