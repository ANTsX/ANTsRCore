antsImageStats = function( image, mask=NULL, na.rm=FALSE ) {

  res =  .Call("antsImageStats", image, mask, na.rm, PACKAGE="ANTsRCore")
  res = lapply(res, drop)
  return(res )

}
