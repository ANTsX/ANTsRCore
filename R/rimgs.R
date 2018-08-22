#' Minimal function for creating r images
#'
#' r16, r27, r30, r62, r64, r85 are t1-weighted MRI slices of the 
#' human brain that have been around for a long time.  We use them 
#' for quick registration, segmentation and other processing tests.
#' This function will return these images to the user.
#'
#' @param x one of 16, 27, 30, 62, 64, 85 or 'all'. values 1 through 6 are also acceptable.
#' @return image or image list is output
#' @author Avants BB
#' @examples
#'
#' r16 = ri( 16 )
#'
#' @export ri
ri <- function( x ) {
  if ( x != 'all' ) {
    if ( x <= 6 ) x = c( 16, 27, 30, 62, 64, 85 )[x]
    img = antsImageRead( getANTsRData( paste0( "r", x ) ) ) 
    return( img )
  } else {
  ilist = list( )
  for ( x in c( 16, 27, 30, 62, 64, 85 ) ) {
    ilist = lappend( ilist, antsImageRead( getANTsRData( paste0( "r", x ) ) ) )
    }
  return( ilist )
  }
  
}





#' Local gyrification index.
#'
#' Estimate the gyrification index at a specific scale.  This will produce images of
#' local sulcification and gyrification as as well as the difference of these
#' two measurements.  The most gyral values are near 1 and most sulcal negative 1.
#' The function is not limited to brain data and should work on any 3D shape.
#' See the paper entitled the shape operator for differential image analysis.
#'
#' @param segmentation - potentially from antsCorticalThickness
#' @param sigma - scale parameter
#' @param k - size of neighborhood
#' @param ksigma - sigma for k-neighborhood
#' @return lGI image
#' @author Avants BB
#' @examples
#' \dontrun{
#' seg = antsImageRead( 'segmentation.nii.gz' )
#' wm = thresholdImage( seg, 3, 3 ) %>% morphology( "dilate", 1 )
#' lgi = localGyrificationIndex( wm )
#' }
#'
#' @export localGyrificationIndex
localGyrificationIndex <- function(
  segmentation,
  sigma = 3,
  k = 25,
  ksigma = 3
  )
{
  wmdil = smoothImage( segmentation, 0.5 )
  kapch = weingartenImageCurvature( wmdil, sigma, 'characterize' )
  kapmn = weingartenImageCurvature( wmdil, sigma, 'mean' )
  gyrsulc = kapch * segmentation
  gyri = thresholdImage( gyrsulc, 1, 1 )  + thresholdImage( gyrsulc, 5, 5 )
  sulc = thresholdImage( gyrsulc, 2, 2 )  + thresholdImage( gyrsulc, 6, 6 )
  gyrsulc = gyri + sulc * 2
  spatmat = t( imageDomainToSpatialMatrix( segmentation, segmentation ) )
  smoothingMatrix = knnSmoothingMatrix( spatmat, k = k, sigma = ksigma )
  localGyri = makeImage( segmentation, as.numeric( smoothingMatrix %*% gyri[ segmentation == 1 ] ) )
  localSulci = makeImage( segmentation, as.numeric( smoothingMatrix %*% sulc[ segmentation == 1 ] ) )
  localGyriMinusSulci = localGyri - localSulci
  return( list(
    localGyri = localGyri,
    localSulci = localSulci,
    localGyriMinusSulci = localGyriMinusSulci
    )
    )
}
