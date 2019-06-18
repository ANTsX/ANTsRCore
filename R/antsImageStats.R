antsImageStats = function( image, mask=NULL, na.rm=FALSE ) {

  return( .Call("antsImageStats", image, mask, na.rm, PACKAGE="ANTsRCore") )

}
