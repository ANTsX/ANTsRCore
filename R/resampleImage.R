#' resampleImage
#'
#' Resample image by spacing or number of voxels with various interpolators.
#' Works with multi-channel images.
#'
#' @param image input antsImage matrix
#' @param resampleParams vector of size dimension with numeric values
#' @param useVoxels true means interpret resample params as voxel counts
#' @param interpType one of 0 (linear), 1 (nearest neighbor),
#'   2 (gaussian), 3 (windowed sinc), 4 (bspline)
#' @return output antsImage
#' @author Avants BB
#' @examples
#'
#' fi<-antsImageRead( getANTsRData("r16"))
#' finn<-resampleImage(fi,c(50,60),TRUE,0)
#' filin<-resampleImage(fi,c(1.5,1.5),FALSE,1)
#'
#' @export resampleImage
resampleImage <- function(image, resampleParams, useVoxels = FALSE, interpType = 1) {
  pixtype = image@pixeltype
  numpixtype = NA
  if ( pixtype == "char" ) numpixtype = 0
  if ( pixtype == "unsigned char" ) numpixtype = 1
  if ( pixtype == "short" ) numpixtype = 2
  if ( pixtype == "unsigned short" ) numpixtype = 3
  if ( pixtype == "int" ) numpixtype = 4
  if ( pixtype == "unsigned int" ) numpixtype = 5
  if ( pixtype == "float" ) numpixtype = 6
  if ( pixtype == "double" ) numpixtype = 7
  if ( is.na(  numpixtype ) ) stop( paste( "cannot process pixeltype",pixtype, numpixtype ))
  rsampar <- paste(resampleParams, collapse = "x")
  if ( image@components == 1 )
    {
    outimg = new("antsImage", pixtype, image@dimension )
    args <- list(image@dimension, image, outimg, rsampar,
      as.numeric(useVoxels), interpType, numpixtype )
    k <- .int_antsProcessArguments(args)
    retval <- .Call("ResampleImage", k)
    return(outimg)
    }
  if ( image@components > 1 )
    {
    mychanns = splitChannels( image )
    for ( k in 1:length( mychanns ) )
      {
      outimg = new("antsImage", pixtype, image@dimension )
      args <- list( image@dimension, mychanns[[k]], outimg, rsampar,
        as.numeric(useVoxels), interpType, numpixtype)
      temp <- .int_antsProcessArguments(args)
      retval <- .Call("ResampleImage", temp)
      mychanns[[k]] <- antsImageClone(outimg, image@pixeltype)
      }
    return( mergeChannels( mychanns ) )
    }
}
