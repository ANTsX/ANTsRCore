library(ANTsR)
layout(matrix(1:8,nrow=4,byrow=T))
# these are in inst extdata
img=antsImageRead("r16slice.jpg")
img2=antsImageRead("r85slice.jpg")
lmrk=antsImageRead("r16sliceLM.nii.gz")
lmrk2=antsImageRead("r85sliceLM.nii.gz")
lmrkA=thresholdImage( lmrk,1,1)
lmrkB=thresholdImage( lmrk,2,2)
lmrk2A=thresholdImage( lmrk2,1,1)
lmrk2B=thresholdImage( lmrk2,2,2)
plot(img,list(lmrkA,lmrkB))
plot(img2,list(lmrk2A,lmrk2B))
lmrkAgauss = exp( -1.0 * iMath( lmrkA, "D" )/25.0 )
lmrkBgauss = exp( -1.0 * iMath( lmrkB, "D" )/25.0 )
lmrk2Agauss = exp( -1.0 * iMath( lmrk2A, "D" )/25.0 )
lmrk2Bgauss = exp( -1.0 * iMath( lmrk2B, "D" )/25.0 )
plot( img,lmrkAgauss, doCropping=FALSE, alpha=0.5 )
plot( img2,lmrk2Agauss, doCropping=FALSE, alpha=0.5 )
its = c(100, 100,100,20)
reg = antsRegistration( img, img2, 'SyNOnly', verbose=F, regIterations=its)
curvemetrics =
  list(
    list( "MeanSquares", lmrkAgauss, lmrk2Agauss, 2, 0 ),
    list( "MeanSquares", lmrkBgauss, lmrk2Bgauss, 0.2, 0 ) )
reg2 = antsRegistration( img, img2, 'SyNOnly', multivariateExtras=curvemetrics, regIterations=its )
curvemetrics =
  list(
    list( "MeanSquares", lmrkAgauss, lmrk2Agauss, 5.e1, 0 ),
    list( "MeanSquares", lmrkBgauss, lmrk2Bgauss, 5.e1, 0 ) )
reg3 = antsRegistration( img, img2, 'SyNOnly', multivariateExtras=curvemetrics, regIterations=its )
curvemetrics =
  list(
    list( "MeanSquares", lmrkAgauss, lmrk2Agauss, 5.e2, 0 ),
    list( "MeanSquares", lmrkBgauss, lmrk2Bgauss, 5.e-2, 0 ) )
reg4 = antsRegistration( img, img2, 'SyNOnly', multivariateExtras=curvemetrics, regIterations=its )
plot( reg$warpedmovout )
plot( reg2$warpedmovout )
plot( reg3$warpedmovout )
plot( reg4$warpedmovout )
