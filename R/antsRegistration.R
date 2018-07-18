#' Perform registration between two images.
#'
#' Register a pair of images either through the full or simplified interface
#' to the ANTs registration method.
#'
#' @param fixed fixed image to which we register the moving image.
#' @param moving moving image to be mapped to fixed space.
#' @param typeofTransform A linear or non-linear registration type.  Mutual
#' information metric by default. See \code{Details.}
#' @param initialTransform transforms to prepend
#' @param outprefix output will be named with this prefix.
#' @param mask mask the registration.
#' @param gradStep gradient step size (not for all tx)
#' @param flowSigma smoothing for update field
#' @param totalSigma smoothing for total field
#' @param affMetric the metric for the affine part (GC, mattes, meansquares)
#' @param affSampling the nbins or radius parameter for the syn metric
#' @param synMetric the metric for the syn part (CC, mattes, meansquares, demons)
#' @param synSampling the nbins or radius parameter for the syn metric
#' @param affIterations vector of iterations for low-dimensional registration.  
#' we will set the smoothing and multi-resolution parameters based on the 
#' length of this vector.
#' @param regIterations vector of iterations for syn.  we will set the smoothing
#' and multi-resolution parameters based on the length of this vector.
#' @param multivariateExtras list of additional images and metrics which will 
#' trigger the use of multiple metrics in the registration process 
#' in the deformable stage. Multivariate metrics needs 5 entries: 
#' name of metric, fixed, moving, weight, samplingParam.  
#' the list should be of the form 
#' \code{ list( list( "nameOfMetric2", img, img, weight, metricParam ) ) }.  
#' Another example would be \code{ list( list( "MeanSquares", f2, m2, 0.5, 0 ), 
#' list( "CC", f2, m2, 0.5, 2 ) ) }.  This is only compatible with the 
#' \code{SyNOnly} transformation.
#' @param restrictTransformation This option allows the user to restrict the 
#' optimization of the displacement field, translation, rigid or affine 
#' transform on a per-component basis. For example, if one wants to limit 
#' the deformation or rotation of 3-D volume to the first two dimensions, 
#' this is possible by specifying a weight vector of \code{c(1,1,0)} for a 
#' 3D deformation field or \code{c(1,1,0,1,1,0)} for a rigid transformation. 
#' Restriction currently only works if there are no preceding transformations.
#' @param verbose request verbose output (useful for debugging)
#' @param ... additional options see antsRegistration in ANTs
#' @details
#' typeofTransform can be one of:
#' \itemize{
#'   \item{"Translation": }{Translation transformation.}
#'   \item{"Rigid": }{Rigid transformation: Only rotation and translation.}
#'   \item{"Similarity": }{Similarity transformation: scaling, rotation and 
#'   translation.}
#'   \item{"QuickRigid": }{Rigid transformation: Only rotation and translation.
#'   May be useful for quick visualization fixes.'}
#'   \item{"DenseRigid": }{Rigid transformation: Only rotation and translation.
#'   Employs dense sampling during metric estimation.'}
#'   \item{"BOLDRigid": }{Rigid transformation: Parameters typical for BOLD
#'   to BOLD intrasubject registration'.'}
#'   \item{"Affine": }{Affine transformation: Rigid + scaling.}
#'   \item{"AffineFast": }{Fast version of \code{Affine}.}
#'   \item{"BOLDAffine": }{Affine transformation: Parameters typical for BOLD
#'   to BOLD intrasubject registration'.'}
#'   \item{"TRSAA": }{translation, rigid, similarity, affine (twice). please set
#'     \code{regIterations} if using this option.  this would be used in cases
#'     where you want a really high quality affine mapping (perhaps with mask).}
#'   \item{"ElasticSyN": }{Symmetric normalization: Affine + deformable transformation.
#'     Uses \code{synMetric} as optimization metric and elastic regularization.}
#'   \item{"SyN": }{Symmetric normalization: Affine + deformable transformation.
#'     Uses \code{synMetric} as optimization metric.}
#'   \item{"SyNRA": }{Symmetric normalization: Rigid + Affine + deformable transformation.
#'     Uses \code{synMetric} as optimization metric.}
#'   \item{"SyNOnly": }{Symmetric normalization: no initial transformation.
#'     Uses \code{synMetric} as optimization metric.  Assumes images are
#'     aligned by an inital transformation. Can be useful if you want to run
#'     an unmasked affine followed by masked deformable registration.}
#'   \item{"SyNCC": }{SyN, but with cross-correlation as the metric.
#'     Note, the default or chosen parameters will be replaced with
#'     \code{synMetric="CC", synSampling=4, synits="2100x1200x1200x20",
#'          smoothingsigmas="3x2x1x0", shrinkfactors="4x3x2x1"}. }
#'   \item{"SyNabp": }{SyN optimized for abpBrainExtraction, forces mutual information
#'     as optimization metric.}
#'   \item{"SyNBold": }{SyN, but optimized for registrations between
#'     BOLD and T1 images.}
#'   \item{"SyNBoldAff": }{SyN, but optimized for registrations between
#'     BOLD and T1 images, with additional affine step.}
#'   \item{"SyNAggro": }{SyN, but with more aggressive registration
#'     (fine-scale matching and more deformation).  Takes more time than \code{SyN}.}
#'   \item{"TVMSQ": }{time-varying diffeomorphism with mean square metric}
#'   \item{"TVMSQC": }{time-varying diffeomorphism with mean square metric 
#'   for very large deformation}
#' }
#' @return outputs a list containing:
#' \itemize{
#'   \item{warpedmovout: }{Moving image warped to space of fixed image.}
#'   \item{warpedfixout: }{Fixed image warped to space of moving image.}
#'   \item{fwdtransforms: }{Transforms to move from moving to fixed image.}
#'   \item{invtransforms: }{Transforms to move from fixed to moving image.}
#' }
#' Ouptut of 1 indicates failure
#' @author Shrinidhi KL, Tustison NJ, Avants BB
#' @examples
#'
#' fi <- antsImageRead(getANTsRData("r16") )
#' mi <- antsImageRead(getANTsRData("r64") )
#' mytx2 <- antsRegistration(fixed=fi,  typeofTransform = '')
#' rig <- antsRegistration(fixed=fi, moving = mi,
#'  typeofTransform = 'Rigid', verbose = TRUE)
#' trans = readAntsrTransform(rig$fwdtransforms, 2)
#' postrig <- antsRegistration(fixed=fi, moving=mi,
#' typeofTransform = "Affine", initialTransform = trans) 
#' for (itype in c("AffineFast", "BOLDAffine", "QuickRigid",
#' "DenseRigid", "BOLDRigid", "Translation","Rigid", "Similarity", 
#' "Affine", "TRSAA", "SyN","SyNRA","SyNOnly","SyNCC","SyNabp", 
#' "SyNBold", "SyNBoldAff", "SyNAggro", "SyNLessAggro", 
#' "TVMSQ","TVMSQC","ElasticSyN")) {
#' print(itype)
#' mytx2 <- antsRegistration(fixed=fi, moving=mi,
#' typeofTransform = itype)
#' } 
#' mytx2 <- antsRegistration(fixed=fi, moving=mi,
#' typeofTransform = "SyNOnly", 
#' multivariateExtras = list(list( "MeanSquares", fi, mi, 0.5, 0 )) )
#' testthat::expect_error(
#' antsRegistration(fixed=fi, moving=mi, typeofTransform = "sdf")
#' )
#' bad <- antsRegistration(fixed=fi, moving=mi, regIterations = 40)
#' 
#' 
#' fi<-resampleImage(fi,c(60,60),1,0)
#' mi<-resampleImage(mi,c(50, 50),1,0) # speed up
#' mytx <- antsRegistration(fixed=fi, moving=mi, typeofTransform = c('SyN') )
#' mywarpedimage <- antsApplyTransforms( fixed=fi, moving=mi,
#'   transformlist=mytx$fwdtransforms )
#' mytx2 <- antsRegistration(fixed=fi, moving=mi, typeofTransform = c('SyN') )
#' mywarpedimage2 <- antsApplyTransforms( fixed=fi, moving=mi,
#'   transformlist=mytx2$fwdtransforms )   
#' testthat::expect_equal(mywarpedimage, mywarpedimage2)
#'
#' \dontrun{ # quick visualization fix for images with odd orientation
#' mni = antsImageRead( getANTsRData( "mni" ) )
#' strokt1=antsImageRead('strokt1.nii.gz')
#' strokt1reg=antsRegistration(
#'   fixed=mni,
#'   moving=strokt1,
#'   typeofTransform = "QuickRigid",verbose=TRUE )
#'  plot(  strokt1reg$warpedmovout, axis=3, nslices=20)
#' # now - how to use a mask
#' fi <- antsImageRead(getANTsRData("r16") )
#' fiseg = kmeansSegmentation( fi, 3 )
#' mi <- antsImageRead(getANTsRData("r64") )
#' msk = thresholdImage(fiseg$segmentation, 0, 0 )
#' mytx <- antsRegistration(fixed=fi, moving=mi, typeofTransform = c('SyNCC'),
#'   mask=msk, verbose=F )
#' jac = createJacobianDeterminantImage( fi, mytx$fwdtransforms[1] )
#' }
#'
#' @export antsRegistration
antsRegistration <- function(
  fixed = NA,
  moving = NA,
  typeofTransform = "SyN",
  initialTransform = NA,
  outprefix = "",
  mask = NA,
  gradStep=0.2,
  flowSigma=3,
  totalSigma=0,
  affMetric = "mattes",
  affSampling=32,
  synMetric = "mattes",
  synSampling=32,
  affIterations,
  regIterations = c(40,20,0),
  multivariateExtras,
  restrictTransformation,
  verbose=FALSE, ... ) {
  numargs <- nargs()
  if (numargs == 1 & typeof(fixed) == "list") {
    .Call("antsRegistration", 
          .int_antsProcessArguments(c(fixed)), PACKAGE = "ANTsRCore")
    return(0)
  }
  if (nchar(typeofTransform) == 0)
    typeofTransform = "SyN"
  if (nchar(outprefix) == 0 || length(outprefix) == 0) {
    outprefix = tempfile()
  }

  find_tx = function(outprefix) {
    alltx = Sys.glob( paste0( outprefix, "*", "[0-9]*") )
    findinv = grepl( "[0-9]InverseWarp.nii.gz", alltx )
    findaff = grepl( "[0-9]GenericAffine.mat", alltx )
    findfwd = grepl( "[0-9]Warp.nii.gz", alltx )
    L = list(alltx = alltx,
             findinv = findinv,
             findfwd = findfwd,
             findaff = findaff)
    return(L)
  }
  all_tx = find_tx(outprefix)
  pre_transform = all_tx$alltx[ all_tx$findinv | all_tx$findfwd | all_tx$findaff]
  rm(list = "all_tx")

  if ( numargs < 1 | missing(fixed) | missing(moving)
       | missing(typeofTransform) | missing(outprefix) )
  {
    cat("for simplified mode: \n")
    cat(paste0(" antsRegistration( fixed , moving , ", 
               "typeofTransform = c(\"Rigid\",\"Affine\",\"AffineFast\",", 
               "\"SyN\",\"SyNCC\"),  outputPrefix=\"./antsRegOut\" \n"))
    cat("")
    cat("For full mode: use standard ants call , e.g. : \n")
    cat(paste0(" ANTsR::antsRegistration( list( d=2,m=\"mi[r16slice.nii.gz,", 
               "r64slice.nii.gz,1,20,Regular,0.05]\", t=\"affine[1.0]\", ", 
               "c=\"2100x1200x1200x0\",  s=\"3x2x1x0\", f=\"4x3x2x1\", ", 
               "u=\"1\", o=\"[xtest,xtest.nii.gz,xtest_inv.nii.gz]\" ) )\n"))
    cat("full help: \n")
    .Call("antsRegistration", .int_antsProcessArguments(c(list("--help"))), 
          PACKAGE = "ANTsRCore")
    return(0)
  }
  args <- list(fixed, moving, typeofTransform, outprefix, ...)
  myl=0
  myfAff = "6x4x2x1"
  mysAff = "3x2x1x0"
  metsam = 0.2
  myiterations <- "2100x1200x1200x10"
  if ( ! missing( affIterations ) ) {
    myiterations = paste0( affIterations, collapse='x' )
    itlen = length( affIterations )-1
    if ( itlen == 0 ) {
      mysAff = 0
      myfAff   = 1
      myiterations = affIterations
    } else {
      mysAff = itlen:0
      myfAff   = 2^mysAff
      mysAff = paste( mysAff, collapse='x' )
      myfAff = paste( myfAff, collapse='x' )
    }
   }
  if ( typeofTransform == "AffineFast" ) {
    typeofTransform <- "Affine"
    myiterations <- "2100x1200x0x0"
  }
  if ( typeofTransform == "BOLDAffine" ) {
    typeofTransform <- "Affine"
    myfAff="2x1"
    mysAff="1x0"
    myiterations <- "100x20"
    myl=1
  }
  if ( typeofTransform == "QuickRigid" ) {
    typeofTransform <- "Rigid"
    myiterations <- "20x20x0x0"
  }
  if ( typeofTransform == "DenseRigid" ) {
    typeofTransform <- "Rigid"
    metsam = 0.8
  }
  if ( typeofTransform == "BOLDRigid" ) {
    typeofTransform <- "Rigid"
    myfAff="2x1"
    mysAff="1x0"
    myiterations <- "100x20"
    myl=1
  }
  mysyn = paste("SyN[",gradStep,",",flowSigma,",",totalSigma,"]", sep = "")
  itlen = length( regIterations )-1
  if ( itlen == 0 ) {
    smoothingsigmas = 0
    shrinkfactors   = 1
    synits = regIterations
  } else {
    smoothingsigmas = itlen:0
    shrinkfactors   = 2^smoothingsigmas
    smoothingsigmas = paste( smoothingsigmas, collapse='x' )
    shrinkfactors = paste( shrinkfactors, collapse='x' )
    synits = paste( regIterations, collapse='x')
  }
  if (!is.character(fixed)) {
    if (fixed@class[[1]] == "antsImage" & moving@class[[1]] == "antsImage") {
      inpixeltype <- fixed@pixeltype
      ttexists <- FALSE
      # change this to a match.arg
      allowableTx <- c("Translation","Rigid", "Similarity", "Affine", "TRSAA",
                       "SyN","SyNRA","SyNOnly","SyNCC","SyNabp", "SyNBold", "SyNBoldAff",
                       "SyNAggro", "SyNLessAggro", "TVMSQ","TVMSQC","ElasticSyN")
      ttexists <- typeofTransform %in% allowableTx
      if (ttexists) {
        initx = initialTransform
        if ( class( initx ) == "antsrTransform" )
          {
          tempTXfilename = tempfile( fileext = ".mat" )
          initx = invertAntsrTransform( initialTransform )
          initx = invertAntsrTransform( initx )
          writeAntsrTransform( initx, tempTXfilename )
          initx = tempTXfilename
          }
        moving <- antsImageClone(moving, "float")
        fixed <- antsImageClone(fixed, "float")
        warpedfixout <- antsImageClone(moving)
        warpedmovout <- antsImageClone(fixed)
        f <- antsrGetPointerName(fixed)
        m <- antsrGetPointerName(moving)
        wfo <- antsrGetPointerName(warpedfixout)
        wmo <- antsrGetPointerName(warpedmovout)
        if (!is.na(mask)) {
          maskScale = mask - min( mask )
          maskScale = maskScale / max( maskScale ) * 255
          charmask <- antsImageClone( maskScale , "unsigned char")
          maskopt <- paste("[",antsrGetPointerName(charmask),",NA]",sep='')
        } else maskopt=NA
        if (is.na(initx)) {
          initx = paste("[", f, ",", m, ",1]", sep = "")
        }
        if (typeofTransform == "SyNBold") {
          args <- list("-d", as.character(fixed@dimension), "-r", initx,
                       "-m", paste(affMetric,"[", f, ",", m, ",1,",
                                   affSampling,",regular,0.2]", sep = ""),
                       "-t", "Rigid[0.25]", "-c", "[1200x1200x100,1e-6,5]", "-s", "2x1x0",
                       "-f", "4x2x1",
                       "-x", "[NA,NA]",
                       "-m", paste(synMetric,"[", f, ",", m, ",1,",synSampling,"]", sep = ""),
                       "-t", mysyn, "-c", paste("[",synits,",1e-7,8]",collapse=''),
                       "-s", smoothingsigmas, "-f", shrinkfactors, "-u", "0", "-z", "1", "-l", myl,
                       "-o", paste("[", outprefix, ",", wmo, ",", wfo, "]", sep = ""))
          if ( !is.na( maskopt )  )
            args=lappend(  args, list( "-x", maskopt ) ) else args=lappend( args, list( "-x", "[NA,NA]" ) )
        }
        if (typeofTransform == "SyNBoldAff") {
          args <- list("-d", as.character(fixed@dimension), "-r", initx,
                       "-m", paste(affMetric,"[", f, ",", m, ",1,",affSampling,
                                   ",regular,0.2]", sep = ""),
                       "-t", "Rigid[0.25]", "-c", "[1200x1200x100,1e-6,5]", "-s", "2x1x0",
                       "-f", "4x2x1",
                       "-x", "[NA,NA]",
                       "-m", paste(affMetric,"[", f, ",", m, ",1,",affSampling,
                                   ",regular,0.2]", sep = ""),
                       "-t", "Affine[0.25]", "-c", "[200x20,1e-6,5]", "-s", "1x0",
                       "-f", "2x1",
                       "-x", "[NA,NA]",
                       "-m", paste(synMetric,"[", f, ",", m, ",1,",synSampling,
                                   "]", sep = ""),
                       "-t", mysyn,
                       "-c", paste("[",synits,",1e-7,8]",collapse=''),
                       "-s", smoothingsigmas, "-f", shrinkfactors, "-u", "0", "-z", "1", "-l", myl,
                       "-o", paste("[", outprefix, ",", wmo, ",", wfo, "]", sep = ""))
          if ( !is.na( maskopt )  )
            args=lappend(  args, list( "-x", maskopt ) ) else args=lappend( args, list( "-x", "[NA,NA]" ) )
        }
        if (typeofTransform == "ElasticSyN") {
          args <- list("-d", as.character(fixed@dimension), "-r", initx,
                       "-m", paste(affMetric,"[", f, ",", m, ",1,",affSampling,",regular,0.2]", sep = ""),
                       "-t", "Affine[0.25]", "-c", "2100x1200x200x0", "-s", "3x2x1x0",
                       "-f", "4x2x2x1",
                       "-x", "[NA,NA]",
                       "-m", paste(synMetric,"[", f, ",", m, ",1,",synSampling,"]", sep = ""),
                       "-t", mysyn,
                       "-c", paste("[",synits,",1e-7,8]",collapse=''),
                       "-s", smoothingsigmas, "-f", shrinkfactors,
                       "-u", "0", "-z", "1", "-l", myl,
                       "-o", paste("[", outprefix, ",",wmo, ",", wfo, "]", sep = ""))
          if ( !is.na(maskopt)  )
            args=lappend(  args, list( "-x", maskopt ) ) else args=lappend( args, list( "-x", "[NA,NA]" ) )
        }
        if (typeofTransform == "SyN") {
          args <- list("-d", as.character(fixed@dimension), "-r", initx,
                       "-m", paste(affMetric,"[", f, ",", m, ",1,",affSampling,",regular,0.2]", sep = ""),
                       "-t", "Affine[0.25]", "-c", "2100x1200x1200x0", "-s", "3x2x1x0",
                       "-f", "4x2x2x1",
                       "-x", "[NA,NA]",
                       "-m", paste(synMetric,"[", f, ",", m, ",1,",synSampling,"]", sep = ""),
                       "-t", paste(typeofTransform, "[0.25,3,0]", sep = ""),
                       "-c", paste("[",synits,",1e-7,8]",collapse=''),
                       "-s", smoothingsigmas, "-f", shrinkfactors, "-u",
                       "0", "-z", "1", "-l", myl, "-o", paste("[", outprefix, ",",
                                                              wmo, ",", wfo, "]", sep = ""))
          if ( !is.na(maskopt)  )
            args=lappend(  args, list( "-x", maskopt ) ) else args=lappend( args, list( "-x", "[NA,NA]" ) )
        }
        if (typeofTransform == "SyNRA") {
          args <- list("-d", as.character(fixed@dimension), "-r", initx,
                       "-m", paste(affMetric,"[", f, ",", m, ",1,",affSampling,",regular,0.2]", sep = ""),
                       "-t", "Rigid[0.25]", "-c", "2100x1200x1200x0", "-s", "3x2x1x0",
                       "-f", "4x2x2x1",
                       "-x", "[NA,NA]",
                       "-m", paste(affMetric,"[", f, ",", m, ",1,",affSampling,",regular,0.2]", sep = ""),
                       "-t", "Affine[0.25]", "-c", "2100x1200x1200x0", "-s", "3x2x1x0",
                       "-f", "4x2x2x1",
                       "-x", "[NA,NA]",
                       "-m", paste(synMetric,"[", f, ",", m, ",1,",synSampling,"]", sep = ""),
                       "-t", mysyn,
                       "-c", paste("[",synits,",1e-7,8]",collapse=''),
                       "-s", smoothingsigmas, "-f", shrinkfactors, "-u",
                       "0", "-z", "1", "-l", myl, "-o", paste("[", outprefix, ",",
                                                              wmo, ",", wfo, "]", sep = ""))
          if ( !is.na(maskopt)  )
            args=lappend(  args, list( "-x", maskopt ) ) else args=lappend( args, list( "-x", "[NA,NA]" ) )
        }
        if (typeofTransform == "SyNOnly") {
          args <- list("-d", as.character(fixed@dimension), "-r", initx,
                       "-m", paste(synMetric,"[", f, ",", m, ",1,",synSampling,"]", sep = ""),
                       "-t", mysyn,
                       "-c", paste("[",synits,",1e-7,8]",collapse=''),
                       "-s", smoothingsigmas, "-f", shrinkfactors,
                       "-u", "0", "-z", "1", "-l", myl, "-o", paste("[", outprefix, ",",
                       wmo, ",", wfo, "]", sep = ""))
          if ( ! missing( multivariateExtras ) ) {
            args0 <- list("-d", as.character(fixed@dimension), "-r", initx,
                         "-m", paste(synMetric,"[", f, ",", m,
                         ",1,",synSampling,"]", sep = "") )
            args1 = list( )
            for ( mm in 1:length( multivariateExtras ) ) {
              if ( length( multivariateExtras[[mm]] ) != 5 )
                stop(paste0("multivariate metric needs 5 entries: ", 
                            "name of metric, fixed, moving, weight, ", 
                            "samplingParam"))
              args1 <- lappend( args1, list(
                "-m", paste(
                  as.character(multivariateExtras[[mm]][[1]]),"[",
                antsrGetPointerName(multivariateExtras[[mm]][[2]]), ",",
                antsrGetPointerName(multivariateExtras[[mm]][[3]]), ",",
                as.character(multivariateExtras[[mm]][[4]]), ",",
                as.character(multivariateExtras[[mm]][[5]]),"]", sep = "") ) )
              }
            args2 <- list(
                         "-t", mysyn,
                         "-c", paste("[",synits,",1e-7,8]",collapse=''),
                         "-s", smoothingsigmas, "-f", shrinkfactors,
                         "-u", "0", "-z", "1", "-l", myl, "-o", paste("[", outprefix, ",",
                         wmo, ",", wfo, "]", sep = ""))
            args=lappend(args0,args1)
            args=lappend(args,args2)
          }
          if ( !is.na(maskopt)  )
            args=lappend(  args, list( "-x", maskopt ) ) else args=lappend( args, list( "-x", "[NA,NA]" ) )
        }
        if (typeofTransform == "SyNAggro") {
          args <- list("-d", as.character(fixed@dimension), "-r", initx,
                       "-m", paste(affMetric,"[", f, ",", m, ",1,",affSampling,",regular,0.2]", sep = ""),
                       "-t", "Affine[0.25]", "-c", "2100x1200x1200x100", "-s", "3x2x1x0",
                       "-f", "4x2x2x1",
                       "-x", "[NA,NA]",
                       "-m", paste(synMetric,"[", f, ",", m, ",1,",synSampling,"]", sep = ""),
                       "-t", mysyn,
                       "-c", paste("[",synits,",1e-7,8]",collapse=''),
                       "-s", smoothingsigmas,
                       "-f", shrinkfactors, "-u", "0", "-z", "1", "-l", myl,
                       "-o", paste("[", outprefix, ",", wmo, ",", wfo, "]", sep = ""))
          if ( !is.na(maskopt)  )
            args=lappend(  args, list( "-x", maskopt ) ) else args=lappend( args, list( "-x", "[NA,NA]" ) )
        }
        if (typeofTransform == "SyNCC") {
          synMetric="CC"
          synSampling=4
          synits="2100x1200x1200x20"
          smoothingsigmas="3x2x1x0"
          shrinkfactors="4x3x2x1"
          mysyn=paste("SyN[0.15,3,0]", sep = "")
          args <- list("-d", as.character(fixed@dimension), "-r", initx,
                       "-m", paste(affMetric,"[", f, ",", m, ",1,",affSampling,",regular,0.2]", sep = ""),
                       "-t", "Rigid[1]",
                       "-c", "2100x1200x1200x0",
                       "-s", "3x2x1x0",
                       "-f", "4x4x2x1",
                       "-x", "[NA,NA]",
                       "-m", paste(affMetric,"[", f, ",", m, ",1,",affSampling,",regular,0.2]", sep = ""),
                       "-t", "Affine[1]", "-c", "1200x1200x100", "-s", "2x1x0",
                       "-f", "4x2x1",
                       "-x", "[NA,NA]",
                       "-m", paste(synMetric,"[", f, ",", m, ",1,",synSampling,"]", sep = ""),
                       "-t", mysyn,
                       "-c", paste("[",synits,",1e-7,8]",collapse=''),
                       "-s", smoothingsigmas,
                       "-f", shrinkfactors, "-u", "0", "-z", "1", "-l", myl,
                       "-o", paste("[", outprefix, ",", wmo, ",", wfo, "]", sep = ""))
          if ( !is.na(maskopt)  )
            args=lappend(  args, list( "-x", maskopt ) ) else args=lappend( args, list( "-x", "[NA,NA]" ) )
        }

        if (typeofTransform == "TRSAA") {
          itlen  = length( regIterations )
          itlenlow  = round( itlen/2 + 0.0001 )
          dlen   = itlen - itlenlow
          myconvlow = paste(
            c( rep( 2000, itlenlow ), rep(    0, dlen  ) ), collapse = 'x' )
          myconvhi = paste( regIterations, collapse='x')
          myconvhi = paste("[",myconvhi,",1.e-7,10]",sep='')
          args <- list("-d", as.character(fixed@dimension), "-r", initx,
                       "-m", paste(affMetric,"[", f, ",", m, ",1,",affSampling,",regular,0.3]", sep = ""),
                       "-t", "Translation[1]",
                       "-c", myconvlow,
                       "-s", smoothingsigmas,
                       "-f", shrinkfactors,
                       "-x", "[NA,NA]",
                       "-m", paste(affMetric,"[", f, ",", m, ",1,",affSampling,",regular,0.3]", sep = ""),
                       "-t", "Rigid[1]",
                       "-c", myconvlow,
                       "-s", smoothingsigmas,
                       "-f", shrinkfactors,
                       "-x", "[NA,NA]",
                       "-m", paste(affMetric,"[", f, ",", m, ",1,",affSampling,",regular,0.3]", sep = ""),
                       "-t", "Similarity[1]",
                       "-c", myconvlow,
                       "-s", smoothingsigmas,
                       "-f", shrinkfactors,
                       "-x", "[NA,NA]",
                       "-m", paste(affMetric,"[", f, ",", m, ",1,",affSampling,",regular,0.3]", sep = ""),
                       "-t", "Affine[1]",
                       "-c", myconvhi,
                       "-s", smoothingsigmas,
                       "-f", shrinkfactors,
                       "-x", "[NA,NA]",
                       "-m", paste(affMetric,"[", f, ",", m, ",1,",affSampling,",regular,0.3]", sep = ""),
                       "-t", "Affine[1]",
                       "-c", myconvhi,
                       "-s", smoothingsigmas,
                       "-f", shrinkfactors,
                       "-u", "0", "-z", "1", "-l", myl,
                       "-o", paste("[", outprefix, ",", wmo, ",", wfo, "]", sep = ""))
          if ( !is.na(maskopt)  )
            args=lappend(  args, list( "-x", maskopt ) ) else args=lappend( args, list( "-x", "[NA,NA]" ) )
        }

        if (typeofTransform == "SyNabp") {
          args <- list("-d", as.character(fixed@dimension), "-r", initx,
                       "-m", paste("mattes[", f, ",", m, ",1,32,regular,0.25]", sep = ""),
                       "-t", "Rigid[0.1]", "-c", "1000x500x250x100", "-s", "4x2x1x0",
                       "-f", "8x4x2x1",
                       "-x", "[NA,NA]",
                       "-m", paste("mattes[", f, ",", m, ",1,32,regular,0.25]", sep = ""),
                       "-t", "Affine[0.1]", "-c", "1000x500x250x100", "-s", "4x2x1x0",
                       "-f", "8x4x2x1",
                       "-x", "[NA,NA]",
                       "-m", paste("CC[", f, ",", m, ",0.5,4]", sep = ""),
                       "-t", paste("SyN[0.1,3,0]", sep = ""), "-c", "50x10x0",
                       "-s", "2x1x0", "-f", "4x2x1", "-u", "0", "-z", "1", "-l", myl,
                       "-o", paste("[", outprefix, ",", wmo, ",", wfo, "]", sep = ""))
          if ( !is.na(maskopt)  )
            args=lappend(  args, list( "-x", maskopt ) ) else args=lappend( args, list( "-x", "[NA,NA]" ) )
        }

        if (typeofTransform == "SyNLessAggro") {
          args <- list("-d", as.character(fixed@dimension), "-r", initx,
                       "-m", paste(affMetric,"[", f, ",", m, ",1,",affSampling,",regular,0.2]", sep = ""),
                       "-t", "Affine[0.25]", "-c", "2100x1200x1200x100", "-s", "3x2x1x0",
                       "-f", "4x2x2x1",
                       "-x", "[NA,NA]",
                       "-m", paste(synMetric,"[", f, ",", m, ",1,",synSampling,"]", sep = ""),
                       "-t", mysyn,
                       "-c", paste("[",synits,",1e-7,8]",collapse=''),
                       "-s", smoothingsigmas,
                       "-f", shrinkfactors, "-u", "0", "-z", "1", "-l", myl,
                       "-o", paste("[", outprefix, ",", wmo, ",", wfo, "]", sep = ""))
          if ( !is.na(maskopt)  )
            args=lappend(  args, list( "-x", maskopt ) ) else args=lappend( args, list( "-x", "[NA,NA]" ) )
        }
        if ( typeofTransform == "TVMSQ" ) {
          if ( is.na(gradStep) ) gradStep=1.0
          tvtx=paste("TimeVaryingVelocityField[",
                     gradStep,", 4,",flowSigma,",0.0,",totalSigma,",0 ]",sep='')
          args <- list("-d", as.character(fixed@dimension), "-r", initx,
                       "-m", paste(synMetric,"[", f, ",", m, ",1,",synSampling,"]", sep = ""),
                       "-t", tvtx,
                       "-c", paste("[",synits,",1e-7,8]",collapse=''),
                       "-s", smoothingsigmas,
                       "-f", shrinkfactors,
                       "-u", "0", "-z", "1", "-l", myl,
                       "-o", paste("[", outprefix, ",", wmo, ",", wfo, "]", sep = ""))
          if ( !is.na(maskopt)  )
            args=lappend(  args, list( "-x", maskopt ) ) else args=lappend( args, list( "-x", "[NA,NA]" ) )
        }
        if ( typeofTransform == "TVMSQC" ) {
          if ( is.na(gradStep) ) gradStep=2.0
          tvtx=paste("TimeVaryingVelocityField[",
                     gradStep,", 8, 1.0,0.0, 0.05,0 ]",sep='')
          args <- list("-d", as.character(fixed@dimension), # "-r", initx,
                       "-m", paste("demons[", f, ",", m, ",0.5,0]", sep = ""),
                       "-m", paste("meansquares[", f, ",", m, ",1,0]", sep = ""),
                       "-t", tvtx,
                       "-c", "[1200x1200x100x20x0,0,5]",
                       "-s", "8x6x4x2x1vox",
                       "-f", "8x6x4x2x1",
                       "-u", "0", "-z", "1", "-l", myl,
                       "-o", paste("[", outprefix, ",", wmo, ",", wfo, "]", sep = ""))
          if ( !is.na(maskopt)  )
            args=lappend(  args, list( "-x", maskopt ) ) else args=lappend( args, list( "-x", "[NA,NA]" ) )
        }
        if ( typeofTransform == "Rigid" |
             typeofTransform == "Similarity" |
             typeofTransform == "Translation" |
             typeofTransform == "Affine"  )
        {
          args <- list(
            "-d", as.character(fixed@dimension), "-r", initx,
            "-m", paste(affMetric,"[", f, ",", m, ",1,",affSampling,",regular,",metsam,"]", sep = ""),
            "-t", paste(typeofTransform, "[0.25]", sep = ""), "-c", myiterations,
            "-s", mysAff, "-f", myfAff, "-u", "0", "-z", "1", "-l", myl,
            "-o", paste("[", outprefix, ",", wmo, ",", wfo, "]", sep = ""))
          if ( !is.na(maskopt)  )
            args=lappend(  args, list( "-x", maskopt ) ) else args=lappend( args, list( "-x", "[NA,NA]" ) )
        }

        if ( !missing( restrictTransformation ) ) {
          args[[ length(args)+1]]="-g"
          args[[ length(args)+1]]=paste( restrictTransformation, collapse='x')
        }


        args[[ length(args)+1]]="--float"
        args[[ length(args)+1]]="1"
        if ( verbose ) {
          args[[ length(args)+1]]="-v"
          args[[ length(args)+1]]="1"
        }

        args = .int_antsProcessArguments(c(args))
        .Call("antsRegistration", args, PACKAGE = "ANTsRCore")





        all_tx = find_tx(outprefix)
        alltx = all_tx$alltx
        findinv = all_tx$findinv
        findfwd = all_tx$findfwd
        findaff = all_tx$findaff
        rm(list = "all_tx")
        # this will make it so other file naming don't mess this up
        alltx = alltx[ findinv | findfwd | findaff]

        if ( any( findinv )) {
          fwdtransforms = rev( alltx[ findfwd | findaff ] )
          invtransforms = alltx[ findinv | findaff ]
          if ( length( fwdtransforms ) != length( invtransforms ) ) {
            message(paste0("transform composite list may not be ",
                           "invertible - return all transforms and ",
                           "leave it to user to figure it out"))
            invtransforms = alltx
          }
        } else {
          fwdtransforms = rev( alltx )
          invtransforms = ( alltx )
        }
        if ( sum(  fixed - warpedmovout ) == 0  ) # FIXME better error catching
          stop( "Registration failed. Use verbose mode to diagnose." )
        return(
          list( warpedmovout = antsImageClone(warpedmovout, inpixeltype),
                warpedfixout = antsImageClone(warpedfixout, inpixeltype),
                fwdtransforms = fwdtransforms,
                invtransforms = invtransforms,
                prev_transforms = pre_transform)
        )
      }
      if (!ttexists) {
        stop("Unrecognized transform type.")
      }
    }
    return(0)
  }
  args[[ length(args)+1]]="--float"
  args[[ length(args)+1]]="1"
  if ( verbose ) {
    args[[ length(args)+1]]="-v"
    args[[ length(args)+1]]="1"
  }
  args = .int_antsProcessArguments(c(args))
  .Call("antsRegistration", args, PACKAGE = "ANTsRCore")
}

################################ 
# .antsrmakeRandomString(n, length) function generates a random string random
# string of the length (length), made up of numbers, small and capital letters
# helper function
################################ 
.antsrmakeRandomString <- function(n = 1, mylength = 12) {
  randomString <- c(1:n)  # initialize vector
  for (i in 1:n) {
    randomString[i] <- paste(sample(c(0:9, letters, LETTERS), mylength, replace = TRUE),
                             collapse = "")
  }
  return(randomString)
}


#' Return the antsImage pointer string
#'
#' This is a low-level function that may be useful for debugging.  It will
#' return the pointer name itself from an antsImage object.
#'
#' @param img  image whose pointer we want
#' @return string
#' @author Avants BB
#' @examples
#'
#' img = antsImageRead( getANTsRData("r16") )
#' antsrGetPointerName( img )
#' antsrGetPointerName( antsImageClone( img ))
#'
#' @export antsrGetPointerName
antsrGetPointerName <- function(img) {
  # if ( Sys.info()['sysname'] == 'Linux' ) endofpointer<-20 if (
  # Sys.info()['sysname'] == 'Darwin' ) endofpointer<-21 pname<- substr(
  # .int_antsProcessArguments( list( img ) ) , 11 , endofpointer )
  splitptrname <- strsplit(.int_antsProcessArguments(list(img)), " ")[[1]][2]
  pname <- strsplit(splitptrname, ">")
  return(pname[[1]])
}







#' ANTs template building.
#'
#' Iteratively estimate a population shape and intensity average image.  This
#' can be computationally intensive and currently is not parallelized.  Perhaps
#' better to use official \code{antsMultivariateTemplateConstruction*} in ANTs.
#' However, this code can be useful for smaller problems/populations.
#'
#' @param initialTemplate fixed image to which we register the population.
#' @param imgList moving image list from which template will be built.
#' @param typeofTransform A linear or non-linear registration type.  Mutual
#' information metric by default. See \code{antsRegistration.}
#' @param iterations should be greater than 1 less than 10.
#' @param gradientStep should be less than 1, speed of shape update step.
#' Passed to \code{\link{antsRegistration}}
#' @param verbose print diagnostic messages, 
#' passed to \code{\link{antsRegistration}}
#' @param ... Additional options to pass to \code{\link{antsRegistration}}
#' @return template antsImage
#' @author Avants BB
#' @examples
#' pop = getANTsRData( "population" )
#' avg = antsAverageImages( pop ) # this is in ANTsR
#' template = buildTemplate( avg, pop, 'SyN', iterations = 1)
#' @export buildTemplate
buildTemplate <- function(
  initialTemplate,
  imgList,
  typeofTransform,
  iterations = 3,
  gradientStep = 0.25,
  verbose = TRUE,
  ...
) {
  template = antsImageClone( initialTemplate )
  for (i in 1:iterations ) {
    if (verbose) {
      message(paste0("Iteration: ", i))
    }
    avgIlist = list()
    avgWlist = c()
    for (k in 1:length( imgList ) ) {
      w1 = antsRegistration( 
        template,
        imgList[[k]], typeofTransform = typeofTransform,
        gradStep = gradientStep,
        verbose = verbose > 1,
        ...)
      avgIlist[[k]] = w1$warpedmovout
      avgWlist[ k ] = antsApplyTransforms(  
        initialTemplate, imgList[[k]],
        w1$fwdtransforms, compose = w1$fwdtransforms[1] )
    }
    if (verbose) {
      message("Averaging images")
    }    
    template = antsAverageImages( avgIlist )
    if (verbose) {
      message("Averaging warped composed transforms")
    }        
    wavg = antsAverageImages( avgWlist ) * (-1.0 * gradientStep)
    wavgfn = tempfile( fileext = ".nii.gz" )
    antsImageWrite( wavg, wavgfn )
    template = antsApplyTransforms( template, template, wavgfn )
    if (verbose) {
      message("Sharpening template image")
    }        
    template = template * 0.5 + iMath( template, "Sharpen" ) * 0.5
  }
  return( template )
}
