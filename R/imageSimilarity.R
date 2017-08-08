#' @title imageSimilarity
#' @description measure similarity between two images
#' @param fixed the fixed antsImage
#' @param moving the moving antsImage
#' @param type image metric to calculate
#' \itemize{
#'   \item{MeanSquares}{}
#'   \item{Correlation}{}
#'   \item{ANTSNeighborhoodCorrelation}{}
#'   \item{MattesMutualInformation}{}
#'   \item{JointHistogramMutualInformation}{}
#'   \item{Demons}{}
#' }
#' @param fixed.mask mask for the fixed image
#' @param moving.mask mask for the moving image
#' @param sampling.strategy sampling strategy, default if full sampling
#' \itemize{
#'   \item{none}{Full sampling}
#'   \item{random}{}
#'   \item{regular}{}
#' }
#' @param sampling.percentage percentage of data to sample when calculating metric
#' @return value of image to image metric
#' @examples
#' x =  antsImageRead( getANTsRData( 'r16' ))
#' y =  antsImageRead( getANTsRData( 'r30' ))
#' metric = imageSimilarity(x,y,type="MeanSquares")
#' @export
imageSimilarity <- function( fixed, moving, type="MeanSquares", fixed.mask=NA, moving.mask=NA,
  sampling.strategy="none", sampling.percentage=1 ) {

  metric = antsrImageToImageMetric.Create(  fixed, moving, type=type, fixed.mask=fixed.mask, moving.mask=moving.mask,
    sampling.strategy=sampling.strategy, sampling.percentage=sampling.percentage )
  return( antsrImageToImageMetric.GetValue(metric) )
  }
