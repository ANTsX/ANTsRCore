antsImageStats = function( image, mask=NULL, na.rm=FALSE ) {
  
  if (!is.null(mask)) {
    mask = check_ants(mask)
  }
  res =  .Call("antsImageStats", image, mask, na.rm, PACKAGE="ANTsRCore")
  res = lapply(res, drop)
  return(res )

}
