which.antsImage <- function(x, arr.ind = FALSE, useNames = TRUE) { 
  x = coerce_mask(x, error = TRUE)
  which(x, arr.ind = arr.ind, useNames = useNames)
}

#' @aliases which,antsImage-method
#' @export
#' @examples 
#' img = makeImage(c(10,10),rnorm(100))
#' mask = img > 0
#' which(mask)
#' which(mask, arr.ind = TRUE)
#' \dontrun{
#' which(mask + 1)
#' }
#' @rdname antsImageops
setMethod("which", "antsImage", which.antsImage)



