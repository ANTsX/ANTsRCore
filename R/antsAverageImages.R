#' @title Computes average of image list 
#'
#' @description Calculate the mean of a list of antsImages 
#' @param imageList list of antsImages or a character vector of filenames
#' @param normalize boolean determines if image is divided by mean before
#' averaging
#' @author Avants BB, Pustina D
#' @examples
#' f1 = getANTsRData('r16')
#' f2 = getANTsRData('r64')
#' r16 <- antsImageRead(f1)
#' r64 <- antsImageRead(f2)
#' mylist <- list(r16, r64)
#' antsAverageImages(mylist)
#' bad = resampleImage(r16, c(2, 2), useVoxels = FALSE)
#' antsAverageImages(mylist, normalize = TRUE)
#' antsAverageImages(c(f1, f2))
#' @export
antsAverageImages <- function( imageList, normalize = FALSE)
  {
  
  # determine if input is list of images or filenames
  isfile = FALSE
  if (class(imageList) == 'character') {
    if (any(!file.exists(imageList))) {
      stop('One or more files do not exist.')
    }
    isfile = TRUE
  }
  
  # create empty average image
  if (isfile) {
    avg = antsImageRead(imageList[1])*0
    masterdim = dim(avg)
  } else {  
    avg <- imageList[[1]] * 0
  }
  
  # average them
  for ( i in imageList ) {
    
    if (isfile) {
      img = antsImageRead(i)
      if ( any(dim(img) != masterdim) ) {
           stop(paste('Different dimensions for', i))
      }
      invisible(gc()) # run garbage collection in case old img is not cleaned
    } else {
      img = i
    }
    
    if ( normalize ) {
      img <- img / mean( img )
    }
    avg <- avg + img
  }
  avg <- avg / length(imageList)
  return( avg )
}
