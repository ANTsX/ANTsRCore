#' Threshold Image
#'
#' converts a scalar image into a binary image by thresholding operations
#'
#' @usage thresholdImage(inimg, lothresh, hithresh, inval=1, outval=0)
#' @param inimg Input image to operate on
#' @param lothresh Lower edge of threshold window
#' @param hithresh Higher edge of threshold window
#' @param inval Output value for image voxels in between \code{lothresh} and \code{hithresh}
#' @param outval Output value for image voxels lower than \code{lothresh} or higher than \code{hithresh}
#' @return antsImage
#' @author Shrinidhi KL
#' @examples
#' set.seed(1234)
#' img <- makeImage(c(5,5), rnorm(25)+0.5)
#' imgt<-thresholdImage( img, 0.5, Inf )
#' testthat::expect_equal(sum(imgt), 9)
#' imgt<-thresholdImage( img > 0.5, 0.1, Inf )
#' testthat::expect_equal(sum(imgt), 9)
#' @export thresholdImage
thresholdImage <- function(inimg,
  lothresh, hithresh, inval=1, outval=0) {
  inimg = check_ants(inimg)
  inimg = antsImageClone(inimg, out_pixeltype = "float")
  dim <- inimg@dimension
  outimg <- antsImageClone( inimg )
  args <- list(dim, inimg, outimg, lothresh, hithresh, inval, outval)
  temp <- .Call("ThresholdImage", .int_antsProcessArguments(args),
    PACKAGE = "ANTsRCore")
  return(outimg)
}
