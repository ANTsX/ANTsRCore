# this file defines the S4 classes related to 'antsrTransform' and the associated
# methods



#' @rdname antsrImageToImageMetric
#' @title An S4 class for image metrics between two antsImages
#'
#' @description C++ type used to represent an ITK image metric
#'
#' @param object input object to convert
#' @param .Object input object to convert
#' @param precision string e.g. "float" or "double"
#' @param dimension dimensionality of the transform (2,3,or 4)
#' @param type type of transform'
#' etc noting that short is not supported
#' @param parameters transformation parameters to send to
#' \code{\link{setAntsrTransformParameters}}
#' @slot dimension usually 2 or 3 but can be 4
#' @slot precision math precision is float or double'
#' @slot type The type of transform: usually one of
#' AffineTransform, CenteredAffineTransform, CenteredEuler3DTransform,
#' CenteredRigid2DTransform, CenteredSimilarity2DTransform, Euler2DTransform,
#' Euler3DTransform, QuaternionRigidTransform, Rigid2DTransform,
#' Similarity2DTransform, Similarity3DTransform
#' @slot pointer to the memory location of the itk object
setClass(Class = "antsrImageToImageMetric",
         representation(precision= "character", dimension = "integer",
         type = "character", pixeltype = "character", isVector = "logical",
         pointer = "externalptr"))

#' @rdname antsrTransform
#' @aliases show,antsrTransform-method
setMethod(f = "show", "antsrImageToImageMetric", function(object){
    cat("antsrImageToImageMetric\n")
    cat("  Dimensions    :", object@dimension, "\n")
    cat("  PixelType     :", object@pixeltype, "\n")
    cat("  Type          :", object@type, "\n")
    cat("  isVector      :", object@isVector, "\n")
    cat("\n")
})

#' @rdname antsrTransform
#' @aliases initialize,antsrTransform-method
setMethod(f = "initialize", signature(.Object = "antsrImageToImageMetric"), definition = function(.Object,
  dimension = 3, type = "MeanSquares") {
  tx = .Call("antsrImageToImageMetric", pixeltype, dimension, type, PACKAGE = "ANTsRCore")
  return( tx )
})


#' @title antsrImageToImageMetric.Create
#' @description create object that measures similarity between two images
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
#' metric = antsrImageToImageMetric.Create(x,y,type="MeanSquares")
#' @export
antsrImageToImageMetric.Create <- function( 
  fixed, moving, 
  type=c("MeanSquares", "MattesMutualInformation", 
         "ANTSNeighborhoodCorrelation", "Correlation", 
         "Demons", "JointHistogramMutualInformation"), 
  fixed.mask=NA, moving.mask=NA,
  sampling.strategy="none", sampling.percentage=1 )
{

  type = match.arg(type)

  dimension = 3
  pixeltype = "float"

  # Check for valid dimension
  if ( (dimension < 2) || (dimension > 4) )
  {
    stop(paste("Unsupported dimension:", dimension))
  }

  isVector=FALSE # For now, no multichannel images

  if ( is.antsImage(fixed) ) {
    dimension = fixed@dimension
    pixeltype = fixed@pixeltype
  }
  else {
    stop("Invalid fixed image")
  }

  if ( is.antsImage(moving) ) {
    if (moving@dimension != dimension ) {
      stop("Fixed and Moving images must have same dimension")
    }
    if ( moving@pixeltype != pixeltype ) {
      stop("Fixed and Moving images must have same pixeltype")
    }
  }
  else {
    stop("Invalid moving image")
  }

  metric = .Call("antsrImageToImageMetric", pixeltype, dimension, type, isVector, fixed, moving, PACKAGE = "ANTsRCore")

  if ( is.antsImage(fixed.mask) ) {
    antsrImageToImageMetric.SetFixedImageMask(metric, fixed.mask)
  }
  if ( is.antsImage(moving.mask) ) {
    antsrImageToImageMetric.SetMovingImageMask(metric, moving.mask)
  }

  if ( (sampling.strategy=="regular") | (sampling.strategy=="random"))
  {
    if ( (sampling.percentage <= 0.0) | (sampling.percentage > 1.0) ) {
      stop("Invalid sampling.percentage")
    }
    antsrImageToImageMetric.SetSampling(metric, sampling.strategy, sampling.percentage)
  }
  else if (!(sampling.strategy=="none")) {
    stop("Invalid sampling.strategy")
  }


  antsrImageToImageMetric.Initialize(metric)

  return(metric)
  }

#' @title antsrImageToImageMetric.SetFixedImage
#' @description set fixed image for image to image metric
#' @param metric an 'antsrImageToImageMetric'
#' @param image the fixed 'antsImage'
#' @examples
#' x =  antsImageRead( getANTsRData( 'r16' ))
#' y =  antsImageRead( getANTsRData( 'r30' ))
#' metric = antsrImageToImageMetric.Create(x,y,type="MeanSquares")
#' z = x*2
#' antsrImageToImageMetric.SetFixedImage(metric, z)
#' @note After calling this, must call antsrImageToImageMetric.Initialize(metric)
#' @export
  antsrImageToImageMetric.SetFixedImage = function( metric, image ) {
    .Call("antsrImageToImageMetric_SetFixedImage", metric, image, FALSE)
  }

  #' @title antsrImageToImageMetric.SetFixedImageMask
  #' @description set fixed image for image to image metric
  #' @param metric an 'antsrImageToImageMetric'
  #' @param image the fixed 'antsImage'
  #' @param isMask flag indicating if input is image or mask
  #' @examples
  #' x =  antsImageRead( getANTsRData( 'r16' ))
  #' y =  antsImageRead( getANTsRData( 'r30' ))
  #' metric = antsrImageToImageMetric.Create(x,y,type="MeanSquares")
  #' z = getMask(x)
  #' antsrImageToImageMetric.SetFixedImageMask(metric, z)
  #' @note After calling this, must call antsrImageToImageMetric.Initialize(metric)
  #' @export
    antsrImageToImageMetric.SetFixedImageMask = function( metric, image,
                                                          isMask = TRUE) {
      .Call("antsrImageToImageMetric_SetFixedImage", metric, image, isMask)
    }

#' @title antsrImageToImageMetric.SetMovingImage
#' @description set moving image for image to image metric
#' @param metric an 'antsrImageToImageMetric'
#' @param image the moving 'antsImage'
#' @param isMask flag indicating if input is image or mask
#' @examples
#' x =  antsImageRead( getANTsRData( 'r16' ))
#' y =  antsImageRead( getANTsRData( 'r30' ))
#' metric = antsrImageToImageMetric.Create(x,y,type="MeanSquares")
#' z = y*2
#' antsrImageToImageMetric.SetMovingImage(metric, z)
#' @note After calling this, must call antsrImageToImageMetric.Initialize(metric)
#' @export
  antsrImageToImageMetric.SetMovingImage = function( metric, image, 
                                                     isMask = FALSE) {
    .Call("antsrImageToImageMetric_SetMovingImage", metric, image, isMask)
  }

  #' @title antsrImageToImageMetric.SetMovingImageMask
  #' @description set moving image for image to image metric
  #' @param metric an 'antsrImageToImageMetric'
  #' @param image the moving 'antsImage'
  #' @examples
  #' x =  antsImageRead( getANTsRData( 'r16' ))
  #' y =  antsImageRead( getANTsRData( 'r30' ))
  #' metric = antsrImageToImageMetric.Create(x,y,type="MeanSquares")
  #' z = getMask(y)
  #' antsrImageToImageMetric.SetMovingImageMask(metric, z)
  #' @note After calling this, must call antsrImageToImageMetric.Initialize(metric)
  #' @export
    antsrImageToImageMetric.SetMovingImageMask = function( metric, image) {
      .Call("antsrImageToImageMetric_SetMovingImage", metric, image, TRUE)
    }

#' @title antsrImageToImageMetric.SetSampling
#' @description set moving image mask for image to image metric
#' @param metric an 'antsrImageToImageMetric'
#' @param sampling.strategy sampling strategy, default if full sampling
#' \itemize{
#'   \item{none}{Full sampling}
#'   \item{random}{}
#'   \item{regular}{}
#' }
#' @param sampling.percentage percentage of data to sample when calculating metric
#' @examples
#' x =  antsImageRead( getANTsRData( 'r16' ))
#' y =  antsImageRead( getANTsRData( 'r30' ))
#' metric = antsrImageToImageMetric.Create(x,y,type="MeanSquares")
#' antsrImageToImageMetric.SetSampling(metric,"random",0.4)
#' @note After calling this, must call antsrImageToImageMetric.Initialize(metric)
#' @export
  antsrImageToImageMetric.SetSampling = function( 
    metric, sampling.strategy, sampling.percentage ) {
    .Call("antsrImageToImageMetric_SetSampling",
          metric, sampling.strategy, sampling.percentage )
  }

#' @title antsrImageToImageMetric.GetValue
#' @description set moving image mask for image to image metric
#' @param metric an 'antsrImageToImageMetric'
#' @examples
#' x =  antsImageRead( getANTsRData( 'r16' ))
#' y =  antsImageRead( getANTsRData( 'r30' ))
#' metric = antsrImageToImageMetric.Create(x,y,type="MeanSquares")
#' metricValue = antsrImageToImageMetric.GetValue(metric)
#' @return image similarity value
#' @export
  antsrImageToImageMetric.GetValue = function( metric ) {
    return( .Call("antsrImageToImageMetric_GetValue", metric, PACKAGE = "ANTsRCore" ) )
  }

#' @title antsrImageToImageMetric.Initialize
#' @description set moving image mask for image to image metric
#' @param metric an 'antsrImageToImageMetric'
#' @examples
#' x =  antsImageRead( getANTsRData( 'r16' ))
#' y =  antsImageRead( getANTsRData( 'r30' ))
#' z = getMask(y)
#' metric = antsrImageToImageMetric.Create(x,y,type="MeanSquares")
#' antsrImageToImageMetric.SetMovingImageMask(metric, z)
#' antsrImageToImageMetric.Initialize(metric)
#' @note must call this after setting up object, before getting values back
#' @export
  antsrImageToImageMetric.Initialize = function( metric ) {
    return(.Call("antsrImageToImageMetric_Initialize", metric, PACKAGE = "ANTsRCore" ) )
  }
