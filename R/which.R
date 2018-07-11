which.antsImage <- function(x, arr.ind = FALSE, useNames = TRUE) { 
  x = coerce_mask(x, error = TRUE)
  which(x, arr.ind = arr.ind, useNames = useNames)
}

#' @aliases which,antsImage-method
#' @export
setMethod("which", "antsImage", which.antsImage)



