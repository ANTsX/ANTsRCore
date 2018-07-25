#' mutual information between two images
#'
#' compute mutual information between two images
#'
#' @param in_image1 antsImage
#' @param in_image2 antsImage
#' @return mutual information value
#' @author Brian B. Avants
#' @keywords image information mutual similarity,
#' @examples
#'
#' fi<-antsImageRead( getANTsRData("r16") ,2)
#' mi<-antsImageRead( getANTsRData("r64") ,2)
#' testthat::expect_error(antsImageMutualInformation(fi,"hey"))
#' testthat::expect_error(antsImageMutualInformation("hey", fi))
#' fi3 = resampleImage(fi, c(2, 2))
#' fi2 = antsImageClone(fi)
#' pixeltype(fi2) = "unsigned int" 
#' testthat::expect_error(antsImageMutualInformation(fi2,mi))
#' testthat::expect_error(antsImageMutualInformation(fi3,mi))
#'
#' @export antsImageMutualInformation
antsImageMutualInformation <- function(in_image1, in_image2) {
  error_not_antsImage(in_image1, "in_image1")
  error_not_antsImage(in_image2, "in_image2")
  
  if (length(dim(in_image1)) == 1)
    if (dim(in_image1)[1] == 1)
      return(NULL)
  if (in_image1@pixeltype != "float" | in_image2@pixeltype != "float") {
    print(args(antsImageMutualInformation))
    stop("input images must have float pixeltype")
  }
  if ( ! antsImagePhysicalSpaceConsistency( in_image1, in_image2 ) )
    stop("images do not occupy the same physical space as checked in antsImagePhysicalSpaceConsistency.")

  .Call("antsImageMutualInformation", in_image1, in_image2, PACKAGE = "ANTsRCore")
}
