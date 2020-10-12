#' N3 bias field correction
#'
#' Perform N3 bias field correction on the given image
#'
#' @param img antsImage to correct
#' @param downsampleFactor integer e.g. 4 downsample by a factor of 4
#' @param ... not used
#' @return antsImage
#' @author Shrinidhi KL
#' @examples
#'
#' img<-makeImage(c(10,10),rnorm(100))
#' n3img<-n3BiasFieldCorrection(  img, 1 )
#'
#' @export n3BiasFieldCorrection
n3BiasFieldCorrection <- function( img, downsampleFactor, ... ) {
  img = check_ants(img)
  outimg <- antsImageClone(img)
  args <- list(img@dimension, img, outimg, downsampleFactor)
  pp <- .Call("N3BiasFieldCorrection",
          .int_antsProcessArguments(args),
          PACKAGE = "ANTsRCore")
  return(outimg)
}

#' N3 Bias field correction
#'
#' Perform N3 bias field correction on the given image
#'
#' @param img input antsImage
#' @param mask input mask, if one is not passed one will be made
#' @param shrinkFactor Shrink factor for multi-resolution correction,
#' typically integer less than 4
#' @param convergence List of:  \code{iters}, maximum number of
#' iterations and \code{tol}, the convergence tolerance.
#' @param splineParam Parameter controlling number of control points in spline.
#' Either single value, indicating how many control points, or vector
#' with one entry per dimension of image, indicating the spacing in each direction.
#' @param weight_mask antsImage of weight mask
#' @param returnBiasField bool, return the field instead of the corrected image.
#' @param verbose enables verbose output.
#' @return bias corrected image or bias field
#' @author Avants BB, Tustison NJ
#' @examples
#'  dims = c(50, 50)
#'  img<-makeImage(imagesize = dims, rnorm(prod(dims)) )
#'  n3img<-n3BiasFieldCorrection2(img)
#'  n3img<-n3BiasFieldCorrection2(img, mask = img > 0)
#'  testthat::expect_error(n3BiasFieldCorrection2(img, weight_mask = "somepath"))
#'  testthat::expect_error(n3BiasFieldCorrection2(img, splineParam = rep(200, 3)))
#'  n3img<-n3BiasFieldCorrection2(img, splineParam = c(200, 20))
#'
#'  rm(img); gc()
#'  rm(n3img); gc()
#' fname = getANTsRData("r16")
#' in_img = antsImageRead(fname)
#' n3 = n3BiasFieldCorrection2(in_img)
#' rm(n3); gc()
#' mask = in_img > 0
#' mask2 = antsImageClone(mask, out_pixeltype = "float")
#' # fails
#' mask
#' sum(mask)
#' n3 = n3BiasFieldCorrection2(in_img, mask = mask, verbose = TRUE)
#' # fails
#' n3 = n3BiasFieldCorrection2(in_img, mask = mask2)
#' @export
n3BiasFieldCorrection2 <- function( img,
                                    mask,
                                    shrinkFactor = 4,
                                    convergence = list(iters = 50, tol = 0.0000001),
                                    splineParam = 200,
                                    numberOfFittingLevels = 4,
                                    returnBiasField = FALSE,
                                    verbose = FALSE,
                                    weight_mask = NULL )
{
  img = check_ants(img)
  if ( var( img ) == 0 ) stop("Input image has no variation.")
  if ( ! missing( mask ) ) {
    mask = check_ants(mask)
    error_not_antsImage(mask, "mask")
  }
  # if mask was character - silent change below - bad
  # if (!is.antsImage(mask)) {
  #   mask <- getMask(img)
  # }
  N3_CONVERGENCE_1 <-
    paste(
      "[",
      convergence$iters,
      ",",
      sprintf("%.10f", convergence$tol),
      "]",
      sep = ""
    )
  N3_SHRINK_FACTOR_1 <- paste(shrinkFactor)
  if (length(splineParam) == 1) {
    N3_BSPLINE_PARAMS <- paste("[", splineParam, ",", numberOfFittingLevels, "]", sep = "")
  } else if (length(splineParam) == img@dimension) {
    N3_BSPLINE_PARAMS <-
      paste("[", paste(splineParam, collapse = "x"), numberOfFittingLevels, "]", sep = "")
  }  else {
    stop("Length of splineParam must either be 1 or dimensionality of image.")
  }

  if (!is.null(weight_mask)) {
    weight_mask = check_ants(weight_mask)
    if (!is.antsImage(weight_mask)) {
      stop("Weight Image must be an antsImage")
    }
  }

  outimg <- antsImageClone(img)*0
  biasimg <- antsImageClone(img)*0
  ptr1=antsrGetPointerName(outimg)
  ptr2=antsrGetPointerName(biasimg)
  args =
    list(d = outimg@dimension,
         i = img)
  if ( ! missing( weight_mask ) ) args$w = weight_mask
  args$s = N3_SHRINK_FACTOR_1
  args$c = N3_CONVERGENCE_1
  args$b = N3_BSPLINE_PARAMS
  if ( ! missing( mask ) ) args$x = mask
  args$o = paste0("[",ptr1,",",ptr2,"]")
  args$v = as.numeric(verbose > 0)

  .helpn3BiasFieldCorrection(args)
  if ( returnBiasField ) return( biasimg )
  return(outimg)
}
.helpn3iasFieldCorrection <- function(...) {
  .Call("N3BiasFieldCorrection", .int_antsProcessArguments(c(...)),
        PACKAGE = "ANTsRCore")
}
