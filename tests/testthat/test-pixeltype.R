context("pixeltype")
### Name: pixeltype
### Title: Extract Image Attributes 'pixeltype' from antsImages
### Aliases: pixeltype pixeltype,antsImage-method pixeltype<-
###   pixeltype<-,antsImage-method components components,antsImage-method
###   components<- components<-,antsImage-method spacing
###   spacing,antsImage-method spacing<- spacing<-,antsImage-method
###   direction direction,antsImage-method direction<-
###   direction<-,antsImage-method origin origin,antsImage-method origin<-
###   origin<-,antsImage-method

### ** Examples
test_that({
  img01 <- as.antsImage(array(1:64, c(4, 4, 4, 1)))
  stopifnot(is.character(pixeltype(img01)))
  pixeltype(img01) = "float"
  testthat::expect_error({
    pixeltype(img01) = 1.5
  })
  img01 <- as.antsImage(array(1:64, c(4, 4, 4, 1)))
  stopifnot(components(img01) == 1)
  components(img01) = 1L
  testthat::expect_error({
    components(img01) = 1.5
  })
  img01 <- as.antsImage(array(1:64, c(4, 4, 4, 1)))
  stopifnot(spacing(img01) == rep(1, 4))
  spacing(img01) = rep(1, 4)
  img01 <- as.antsImage(array(1:64, c(4, 4, 4, 1)))
  stopifnot(is.matrix(direction(img01)))
  direction(img01) = diag(4)
  img01 <- as.antsImage(array(1:64, c(4, 4, 4, 1)))
  stopifnot(all(origin(img01) == rep(0, 4)))
  origin(img01) = rep(0, 4)
  
}, "pixeltypes and components and origin are wrong")
