#' iMath
#'
#' Perform various (often mathematical) operations on the input image/s.
#' Additional parameters should be specific for each operation.  See the
#' the full iMath in ANTs, on which this function is based.
#'
#' @param img input object, usually antsImage
#' @param operation a character string e.g. "GetLargestComponent" ... the
#' special case of "GetOperations" or "GetOperationsFull" will return
#' a list of operations and brief description.
#' Some operations may not be valid (WIP), but most are.
#' @param param ... additional parameters
#' @param ... further parameter options
#' @author JT Duda
#' @examples
#' fi<-antsImageRead( getANTsRData("r16") , 2 )
#' mask<-getMask( fi )
#' op1<-iMath( fi , "GD" , 1 )  # gray matter dilation by 1 voxel
#' op2<-iMath( mask , "D" )  # distance transform
#' op3<-iMath( 0 , "GetOperations" )  # list all ops
#'
#' if ( usePkg("magrittr") ) { # string ops together
#'   lapgd <- fi %>% iMath("Laplacian",1)  %>% iMath("GD",3)
#' }
#' # Canny is useful e.g.
#' # canny = ( iMath(myreg$warpedmovout,"Normalize")*255 ) %>% iMath("Canny",1,5,12)
#'
#' @export iMath
iMath <- function(img, operation, param = NA, ...) {
  iMathOps <- NULL
  list_0 = c("Canny", "D", "FillHoles", "GC", "GD")
  list_1 = c("Laplacian",
             "MC",
             "MD",
             "ME",
             "MO",
             "MaurerDistance",
             "Normalize",
             "PadImage",
             "PeronaMalik",
             "PropagateLabelsThroughMask",
             "Sharpen",
             "TruncateIntensity")
  list_3 = c("GD",
             "GE",
             "GO",
             "GetLargestComponent",
             "Grad",
             "HistogramEqualization")
  # input is usually an 'antsImage'
  if (is.na(img))
  {
    stop("No input provided")
  }
  if (is.na(operation) || (!is.character(operation)))
  {
    stop("operation must be a character string")
  }
  
  data("iMathOps", package = "ANTsRCore", envir = environment())
  
  if (operation == "GetOperations" |
      operation == "GetOperationsFull")
  {
    if (operation == "GetOperationsFull")
    {
      return(iMathOps)
    }
    else
    {
      return(iMathOps$Operation)
    }
  }
  else
  {
    # Temp fix for backward compat
    if (operation == "TruncateImageIntensity")
    {
      print(paste(
        operation,
        "is moving to TruncateIntensity. Please update your code"
      ))
      operation = "TruncateIntensity"
    }
    
    if (!(operation  %in% iMathOps$Operation))
    {
      stop(paste("'operation'", operation, " not recognized"))
    }
    
    args = list()
    if (is.na(param))
    {
      args = list(img, operation, ...)
    }
    else
    {
      args =  list(img, operation, param, ...)
    }
    
    if (operation %in% list_0) {
      # print("yes in 0")
      retval = .Call("iMathInterface", args)
    } else if (operation %in% list_1) {
      # print("yes in 1")
      retval = .Call("iMathInterface1", args)
    } else if (operation %in% list_3) {
      # print("yes in 3")
      retval = .Call("iMathInterface3", args)
    } else {
      print("No match")
    }
    
    
  }
  
  return(retval)
  
}
