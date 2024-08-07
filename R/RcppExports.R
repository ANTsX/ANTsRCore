# Generated by using Rcpp::compileAttributes() -> do not edit by hand
# Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#' ANTSIntegrateVectorField
#'
#' @param r_refimg value
#' @param r_velocity value
#' @param r_deformation value
#' @param r_t0 value
#' @param r_t1 value
#' @param r_dt value
#' @return ANTSIntegrateVectorField
ANTSIntegrateVectorField <- function(r_refimg, r_velocity, r_deformation, r_t0, r_t1, r_dt) {
    .Call(`_ANTsRCore_ANTSIntegrateVectorField`, r_refimg, r_velocity, r_deformation, r_t0, r_t1, r_dt)
}

addNoiseToImageR <- function(r_inputImage, r_whichNoiseModel, r_parameters) {
    .Call(`_ANTsRCore_addNoiseToImageR`, r_inputImage, r_whichNoiseModel, r_parameters)
}

Atropos <- function(r_args) {
    .Call(`_ANTsRCore_Atropos`, r_args)
}

createJacobianDeterminantImageR <- function(r_domainImg, r_tx, r_dolog, r_dogeom) {
    .Call(`_ANTsRCore_createJacobianDeterminantImageR`, r_domainImg, r_tx, r_dolog, r_dogeom)
}

DenoiseImage <- function(r_args) {
    .Call(`_ANTsRCore_DenoiseImage`, r_args)
}

fitBsplineDisplacementFieldR <- function(r_dimensionality, r_displacementField, r_displacementFieldWeightImage, r_displacementOrigins, r_displacements, r_displacementWeights, r_origin, r_spacing, r_size, r_direction, r_numberOfFittingLevels, r_numberOfControlPoints, r_splineOrder, r_enforceStationaryBoundary, r_estimateInverse, r_rasterizePoints) {
    .Call(`_ANTsRCore_fitBsplineDisplacementFieldR`, r_dimensionality, r_displacementField, r_displacementFieldWeightImage, r_displacementOrigins, r_displacements, r_displacementWeights, r_origin, r_spacing, r_size, r_direction, r_numberOfFittingLevels, r_numberOfControlPoints, r_splineOrder, r_enforceStationaryBoundary, r_estimateInverse, r_rasterizePoints)
}

fitBsplineObjectToScatteredDataR <- function(r_scatteredData, r_parametricData, r_dataWeights, r_parametricDomainOrigin, r_parametricDomainSpacing, r_parametricDomainSize, r_isParametricDimensionClosed, r_numberOfFittingLevels, r_numberOfControlPoints, r_splineOrder) {
    .Call(`_ANTsRCore_fitBsplineObjectToScatteredDataR`, r_scatteredData, r_parametricData, r_dataWeights, r_parametricDomainOrigin, r_parametricDomainSpacing, r_parametricDomainSize, r_isParametricDimensionClosed, r_numberOfFittingLevels, r_numberOfControlPoints, r_splineOrder)
}

fitThinPlateSplineDisplacementFieldR <- function(r_dimensionality, r_displacementOrigins, r_displacements, r_origin, r_spacing, r_size, r_direction) {
    .Call(`_ANTsRCore_fitThinPlateSplineDisplacementFieldR`, r_dimensionality, r_displacementOrigins, r_displacements, r_origin, r_spacing, r_size, r_direction)
}

HausdorffDistanceR <- function(r_inputImage1, r_inputImage2) {
    .Call(`_ANTsRCore_HausdorffDistanceR`, r_inputImage1, r_inputImage2)
}

hessianObjectnessR <- function(r_inputImage, r_objectDimension, r_isBrightObject, r_sigmaMin, r_sigmaMax, r_numberOfSigmaSteps, r_useSigmaLogarithmicSpacing, r_alpha, r_beta, r_gamma, r_setScaleObjectnessMeasure) {
    .Call(`_ANTsRCore_hessianObjectnessR`, r_inputImage, r_objectDimension, r_isBrightObject, r_sigmaMin, r_sigmaMax, r_numberOfSigmaSteps, r_useSigmaLogarithmicSpacing, r_alpha, r_beta, r_gamma, r_setScaleObjectnessMeasure)
}

histogramMatchImageR <- function(r_sourceImage, r_referenceImage, r_numberOfHistogramBins, r_numberOfMatchPoints, r_useThresholdAtMeanIntensity) {
    .Call(`_ANTsRCore_histogramMatchImageR`, r_sourceImage, r_referenceImage, r_numberOfHistogramBins, r_numberOfMatchPoints, r_useThresholdAtMeanIntensity)
}

integrateVelocityFieldR <- function(r_dimensionality, r_velocityField, r_lowerBound, r_upperBound, r_numberOfIntegrationSteps) {
    .Call(`_ANTsRCore_integrateVelocityFieldR`, r_dimensionality, r_velocityField, r_lowerBound, r_upperBound, r_numberOfIntegrationSteps)
}

invertDisplacementFieldR <- function(r_dimensionality, r_displacementField, r_inverseFieldInitialEstimate, r_maxNumberOfIterations, r_meanErrorToleranceThreshold, r_maxErrorToleranceThreshold, r_enforceBoundaryCondition) {
    .Call(`_ANTsRCore_invertDisplacementFieldR`, r_dimensionality, r_displacementField, r_inverseFieldInitialEstimate, r_maxNumberOfIterations, r_meanErrorToleranceThreshold, r_maxErrorToleranceThreshold, r_enforceBoundaryCondition)
}

KellyKapowski <- function(r_args) {
    .Call(`_ANTsRCore_KellyKapowski`, r_args)
}

LabelClustersUniquely <- function(r_args) {
    .Call(`_ANTsRCore_LabelClustersUniquely`, r_args)
}

LabelGeometryMeasures <- function(r_args) {
    .Call(`_ANTsRCore_LabelGeometryMeasures`, r_args)
}

labelOverlapMeasuresR <- function(r_sourceImage, r_targetImage) {
    .Call(`_ANTsRCore_labelOverlapMeasuresR`, r_sourceImage, r_targetImage)
}

N3BiasFieldCorrection <- function(r_args) {
    .Call(`_ANTsRCore_N3BiasFieldCorrection`, r_args)
}

N4BiasFieldCorrection <- function(r_args) {
    .Call(`_ANTsRCore_N4BiasFieldCorrection`, r_args)
}

simulateBSplineDisplacementFieldR <- function(r_domainImage, r_numberOfRandomPoints, r_standardDeviationDisplacementField, r_enforceStationaryBoundary, r_numberOfFittingLevels, r_numberOfControlPoints) {
    .Call(`_ANTsRCore_simulateBSplineDisplacementFieldR`, r_domainImage, r_numberOfRandomPoints, r_standardDeviationDisplacementField, r_enforceStationaryBoundary, r_numberOfFittingLevels, r_numberOfControlPoints)
}

simulateExponentialDisplacementFieldR <- function(r_domainImage, r_numberOfRandomPoints, r_standardDeviationDisplacementField, r_enforceStationaryBoundary, r_standardDeviationSmoothing) {
    .Call(`_ANTsRCore_simulateExponentialDisplacementFieldR`, r_domainImage, r_numberOfRandomPoints, r_standardDeviationDisplacementField, r_enforceStationaryBoundary, r_standardDeviationSmoothing)
}

ThresholdImage <- function(r_args) {
    .Call(`_ANTsRCore_ThresholdImage`, r_args)
}

AntsAffineInitializer <- function(r_args) {
    .Call(`_ANTsRCore_AntsAffineInitializer`, r_args)
}

AntsApplyTransforms <- function(r_args) {
    .Call(`_ANTsRCore_AntsApplyTransforms`, r_args)
}

AntsApplyTransformsToPoints <- function(r_args) {
    .Call(`_ANTsRCore_AntsApplyTransformsToPoints`, r_args)
}

antsImage <- function(r_pixeltype, r_dimension, r_components) {
    .Call(`_ANTsRCore_antsImage`, r_pixeltype, r_dimension, r_components)
}

antsImageArith <- function(r_in_image1, r_in_image2, r_op) {
    .Call(`_ANTsRCore_antsImageArith`, r_in_image1, r_in_image2, r_op)
}

antsImage_isna <- function(r_antsimage) {
    .Call(`_ANTsRCore_antsImage_isna`, r_antsimage)
}

antsImage_dim <- function(r_antsimage) {
    .Call(`_ANTsRCore_antsImage_dim`, r_antsimage)
}

antsImage_asVector <- function(r_antsimage, r_mask, r_antsregion) {
    .Call(`_ANTsRCore_antsImage_asVector`, r_antsimage, r_mask, r_antsregion)
}

antsImage_GetNeighborhoodMatrix <- function(r_antsimage, r_maskimage, r_radius, r_physical, r_boundary, r_spatial, r_gradient) {
    .Call(`_ANTsRCore_antsImage_GetNeighborhoodMatrix`, r_antsimage, r_maskimage, r_radius, r_physical, r_boundary, r_spatial, r_gradient)
}

antsImage_GetNeighborhood <- function(r_antsimage, r_index, r_kernel, r_radius, physical) {
    .Call(`_ANTsRCore_antsImage_GetNeighborhood`, r_antsimage, r_index, r_kernel, r_radius, physical)
}

antsImage_GetPixels <- function(r_antsimage, r_indices) {
    .Call(`_ANTsRCore_antsImage_GetPixels`, r_antsimage, r_indices)
}

antsImage_SetPixels <- function(r_antsimage, r_coordinates, r_value) {
    .Call(`_ANTsRCore_antsImage_SetPixels`, r_antsimage, r_coordinates, r_value)
}

antsImage_GetSpacing <- function(r_antsimage) {
    .Call(`_ANTsRCore_antsImage_GetSpacing`, r_antsimage)
}

antsImage_SetSpacing <- function(r_antsimage, r_spacing) {
    .Call(`_ANTsRCore_antsImage_SetSpacing`, r_antsimage, r_spacing)
}

antsImage_GetOrigin <- function(r_antsimage) {
    .Call(`_ANTsRCore_antsImage_GetOrigin`, r_antsimage)
}

antsImage_SetOrigin <- function(r_antsimage, r_origin) {
    .Call(`_ANTsRCore_antsImage_SetOrigin`, r_antsimage, r_origin)
}

antsImage_GetDirection <- function(r_antsimage) {
    .Call(`_ANTsRCore_antsImage_GetDirection`, r_antsimage)
}

antsImage_SetDirection <- function(r_antsimage, r_direction) {
    .Call(`_ANTsRCore_antsImage_SetDirection`, r_antsimage, r_direction)
}

antsImage_TransformIndexToPhysicalPoint <- function(r_antsimage, r_index) {
    .Call(`_ANTsRCore_antsImage_TransformIndexToPhysicalPoint`, r_antsimage, r_index)
}

antsImage_TransformPhysicalPointToIndex <- function(r_antsimage, r_point) {
    .Call(`_ANTsRCore_antsImage_TransformPhysicalPointToIndex`, r_antsimage, r_point)
}

antsImage_SetRegion <- function(r_antsimage, r_mask, r_antsregion, r_value) {
    .Call(`_ANTsRCore_antsImage_SetRegion`, r_antsimage, r_mask, r_antsregion, r_value)
}

antsImage_SetByImage <- function(r_antsimage, r_mask, r_value) {
    .Call(`_ANTsRCore_antsImage_SetByImage`, r_antsimage, r_mask, r_value)
}

antsImage_asantsImage <- function(r_vector, r_pixeltype, r_spacing, r_origin, r_direction, r_components) {
    .Call(`_ANTsRCore_antsImage_asantsImage`, r_vector, r_pixeltype, r_spacing, r_origin, r_direction, r_components)
}

antsImage_RelationalOperators <- function(r_antsimage, r_value, r_antsregion, r_operator) {
    .Call(`_ANTsRCore_antsImage_RelationalOperators`, r_antsimage, r_value, r_antsregion, r_operator)
}

antsImageArithImageNumeric <- function(r_antsimage, r_numeric, r_operator) {
    .Call(`_ANTsRCore_antsImageArithImageNumeric`, r_antsimage, r_numeric, r_operator)
}

antsImageArithNumericImage <- function(r_numeric, r_antsimage, r_operator) {
    .Call(`_ANTsRCore_antsImageArithNumericImage`, r_numeric, r_antsimage, r_operator)
}

antsImageArithImageImage <- function(r_antsimage1, r_antsimage2, r_operator) {
    .Call(`_ANTsRCore_antsImageArithImageImage`, r_antsimage1, r_antsimage2, r_operator)
}

AntsImageClone <- function(r_in_image, r_out_pixeltype) {
    .Call(`_ANTsRCore_AntsImageClone`, r_in_image, r_out_pixeltype)
}

antsImageComparisonImageNumeric <- function(r_antsimage, r_numeric, r_operator) {
    .Call(`_ANTsRCore_antsImageComparisonImageNumeric`, r_antsimage, r_numeric, r_operator)
}

antsImageComparisonImageImage <- function(r_antsimage1, r_antsimage2, r_operator) {
    .Call(`_ANTsRCore_antsImageComparisonImageImage`, r_antsimage1, r_antsimage2, r_operator)
}

AntsImageHeaderInfo <- function(r_filename) {
    .Call(`_ANTsRCore_AntsImageHeaderInfo`, r_filename)
}

AntsImageIterator <- function(r_antsimage) {
    .Call(`_ANTsRCore_AntsImageIterator`, r_antsimage)
}

antsImageIterator_Get <- function(r_antsimageiterator) {
    .Call(`_ANTsRCore_antsImageIterator_Get`, r_antsimageiterator)
}

antsImageIterator_Set <- function(r_antsimageiterator, r_value) {
    .Call(`_ANTsRCore_antsImageIterator_Set`, r_antsimageiterator, r_value)
}

antsImageIterator_Next <- function(r_antsimageiterator) {
    .Call(`_ANTsRCore_antsImageIterator_Next`, r_antsimageiterator)
}

antsImageIterator_Previous <- function(r_antsimageiterator) {
    .Call(`_ANTsRCore_antsImageIterator_Previous`, r_antsimageiterator)
}

antsImageIterator_IsAtEnd <- function(r_antsimageiterator) {
    .Call(`_ANTsRCore_antsImageIterator_IsAtEnd`, r_antsimageiterator)
}

antsImageIterator_GoToBegin <- function(r_antsimageiterator) {
    .Call(`_ANTsRCore_antsImageIterator_GoToBegin`, r_antsimageiterator)
}

antsImageIterator_GetIndex <- function(r_antsimageiterator) {
    .Call(`_ANTsRCore_antsImageIterator_GetIndex`, r_antsimageiterator)
}

antsImageIterator_SetIndex <- function(r_antsimageiterator, r_index) {
    .Call(`_ANTsRCore_antsImageIterator_SetIndex`, r_antsimageiterator, r_index)
}

antsImageIterator_Remaining <- function(r_antsimageiterator) {
    .Call(`_ANTsRCore_antsImageIterator_Remaining`, r_antsimageiterator)
}

antsImageIterator_GoToReverseBegin <- function(r_antsimageiterator) {
    .Call(`_ANTsRCore_antsImageIterator_GoToReverseBegin`, r_antsimageiterator)
}

antsImageIterator_IsAtReverseEnd <- function(r_antsimageiterator) {
    .Call(`_ANTsRCore_antsImageIterator_IsAtReverseEnd`, r_antsimageiterator)
}

antsImageLogicImageNumeric <- function(r_antsimage, r_numeric, r_operator) {
    .Call(`_ANTsRCore_antsImageLogicImageNumeric`, r_antsimage, r_numeric, r_operator)
}

antsImageLogicImageImage <- function(r_antsimage1, r_antsimage2, r_operator) {
    .Call(`_ANTsRCore_antsImageLogicImageImage`, r_antsimage1, r_antsimage2, r_operator)
}

antsImageMath <- function(r_antsimage, r_operator) {
    .Call(`_ANTsRCore_antsImageMath`, r_antsimage, r_operator)
}

antsImageMutualInformation <- function(r_in_image1, r_in_image2) {
    .Call(`_ANTsRCore_antsImageMutualInformation`, r_in_image1, r_in_image2)
}

AntsImageRead <- function(r_filename, r_pixeltype, r_dimension, r_components) {
    .Call(`_ANTsRCore_AntsImageRead`, r_filename, r_pixeltype, r_dimension, r_components)
}

AntsImageStats <- function(r_antsimage, r_mask, r_narm) {
    .Call(`_ANTsRCore_AntsImageStats`, r_antsimage, r_mask, r_narm)
}

AntsImageWrite <- function(r_img, r_filename, r_asTensor) {
    .Call(`_ANTsRCore_AntsImageWrite`, r_img, r_filename, r_asTensor)
}

antsJointFusion <- function(r_args) {
    .Call(`_ANTsRCore_antsJointFusion`, r_args)
}

antsMatrix <- function(r_elementtype) {
    .Call(`_ANTsRCore_antsMatrix`, r_elementtype)
}

antsMatrix_asList <- function(r_antsmatrix) {
    .Call(`_ANTsRCore_antsMatrix_asList`, r_antsmatrix)
}

antsMatrix_asantsMatrix <- function(r_list, r_elementtype) {
    .Call(`_ANTsRCore_antsMatrix_asantsMatrix`, r_list, r_elementtype)
}

AntsMotionCorr <- function(r_args) {
    .Call(`_ANTsRCore_AntsMotionCorr`, r_args)
}

antsMotionCorrStats <- function(r_tsimg, r_mask, r_moco, r_stupidoffset) {
    .Call(`_ANTsRCore_antsMotionCorrStats`, r_tsimg, r_mask, r_moco, r_stupidoffset)
}

AntsRegistration <- function(r_args) {
    .Call(`_ANTsRCore_AntsRegistration`, r_args)
}

antsrMetric <- function(r_pixeltype, r_dimension, r_type, r_isVector, r_fixed, r_moving) {
    .Call(`_ANTsRCore_antsrMetric`, r_pixeltype, r_dimension, r_type, r_isVector, r_fixed, r_moving)
}

antsrMetric_SetImage <- function(r_metric, r_antsimage, r_isFixed, r_isMask) {
    .Call(`_ANTsRCore_antsrMetric_SetImage`, r_metric, r_antsimage, r_isFixed, r_isMask)
}

antsrMetric_SetTransform <- function(r_metric, r_antsrtransform, r_isFixed) {
    .Call(`_ANTsRCore_antsrMetric_SetTransform`, r_metric, r_antsrtransform, r_isFixed)
}

antsrMetric_GetValue <- function(r_metric) {
    .Call(`_ANTsRCore_antsrMetric_GetValue`, r_metric)
}

antsrMetric_GetDerivative <- function(r_metric) {
    .Call(`_ANTsRCore_antsrMetric_GetDerivative`, r_metric)
}

antsrMetric_SetSampling <- function(r_metric, r_strategy, r_percentage) {
    .Call(`_ANTsRCore_antsrMetric_SetSampling`, r_metric, r_strategy, r_percentage)
}

antsrMetric_SetNumberOfHistogramBins <- function(r_metric, r_nBins) {
    .Call(`_ANTsRCore_antsrMetric_SetNumberOfHistogramBins`, r_metric, r_nBins)
}

antsrMetric_SetRadius <- function(r_metric, r_radius) {
    .Call(`_ANTsRCore_antsrMetric_SetRadius`, r_metric, r_radius)
}

antsrMetric_Initialize <- function(r_metric) {
    .Call(`_ANTsRCore_antsrMetric_Initialize`, r_metric)
}

antsrTransform <- function(r_precision, r_dimension, r_type) {
    .Call(`_ANTsRCore_antsrTransform`, r_precision, r_dimension, r_type)
}

antsrTransform_MatrixOffset <- function(r_type, r_precision, r_dimension, r_matrix, r_offset, r_center, r_translation, r_parameters, r_fixedparameters) {
    .Call(`_ANTsRCore_antsrTransform_MatrixOffset`, r_type, r_precision, r_dimension, r_matrix, r_offset, r_center, r_translation, r_parameters, r_fixedparameters)
}

antsrTransform_GetParameters <- function(r_transform) {
    .Call(`_ANTsRCore_antsrTransform_GetParameters`, r_transform)
}

antsrTransform_SetParameters <- function(r_transform, r_parameters) {
    .Call(`_ANTsRCore_antsrTransform_SetParameters`, r_transform, r_parameters)
}

antsrTransform_GetFixedParameters <- function(r_transform) {
    .Call(`_ANTsRCore_antsrTransform_GetFixedParameters`, r_transform)
}

antsrTransform_SetFixedParameters <- function(r_transform, r_parameters) {
    .Call(`_ANTsRCore_antsrTransform_SetFixedParameters`, r_transform, r_parameters)
}

antsrTransform_TransformPoint <- function(r_transform, r_point) {
    .Call(`_ANTsRCore_antsrTransform_TransformPoint`, r_transform, r_point)
}

antsrTransform_TransformVector <- function(r_transform, r_vector) {
    .Call(`_ANTsRCore_antsrTransform_TransformVector`, r_transform, r_vector)
}

antsrTransform_TransformImage <- function(r_transform, r_image, r_ref, r_iterpolation) {
    .Call(`_ANTsRCore_antsrTransform_TransformImage`, r_transform, r_image, r_ref, r_iterpolation)
}

antsrTransform_Read <- function(r_filename, r_dimension, r_precision) {
    .Call(`_ANTsRCore_antsrTransform_Read`, r_filename, r_dimension, r_precision)
}

antsrTransform_Compose <- function(r_list, r_dimension, r_precision) {
    .Call(`_ANTsRCore_antsrTransform_Compose`, r_list, r_dimension, r_precision)
}

antsrTransform_FromDisplacementField <- function(r_field) {
    .Call(`_ANTsRCore_antsrTransform_FromDisplacementField`, r_field)
}

antsrTransform_ToDisplacementField <- function(r_tx, r_ref) {
    .Call(`_ANTsRCore_antsrTransform_ToDisplacementField`, r_tx, r_ref)
}

antsrTransform_Inverse <- function(r_transform) {
    .Call(`_ANTsRCore_antsrTransform_Inverse`, r_transform)
}

antsrTransform_Write <- function(r_transform, filename_) {
    .Call(`_ANTsRCore_antsrTransform_Write`, r_transform, filename_)
}

CropImage <- function(r_in_image1, r_in_image2, r_label, r_decrop, r_loind, r_upind) {
    .Call(`_ANTsRCore_CropImage`, r_in_image1, r_in_image2, r_label, r_decrop, r_loind, r_upind)
}

ExtractSlice <- function(r_in_image1, r_slice, r_direction, r_collapseStrategy) {
    .Call(`_ANTsRCore_ExtractSlice`, r_in_image1, r_slice, r_direction, r_collapseStrategy)
}

fastMarchingExtension <- function(r_speedImage, r_labelImage, r_valueImage) {
    .Call(`_ANTsRCore_fastMarchingExtension`, r_speedImage, r_labelImage, r_valueImage)
}

fsl2antsrTransformR <- function(r_matrix, r_reference, r_moving, r_flag) {
    .Call(`_ANTsRCore_fsl2antsrTransformR`, r_matrix, r_reference, r_moving, r_flag)
}

iMathInterface <- function(r_args) {
    .Call(`_ANTsRCore_iMathInterface`, r_args)
}

iMathInterface1 <- function(r_args) {
    .Call(`_ANTsRCore_iMathInterface1`, r_args)
}

iMathInterface2 <- function(r_args) {
    .Call(`_ANTsRCore_iMathInterface2`, r_args)
}

imagesToMatrixR <- function(r_fns, r_mask, r_n) {
    .Call(`_ANTsRCore_imagesToMatrixR`, r_fns, r_mask, r_n)
}

invariantImageSimilarity <- function(r_in_image1, r_in_image2, thetas, thetas2, thetas3, localSearchIterations, whichMetric, r_scale, r_doref, txfn, whichTransform, r_mask) {
    .Call(`_ANTsRCore_invariantImageSimilarity`, r_in_image1, r_in_image2, thetas, thetas2, thetas3, localSearchIterations, whichMetric, r_scale, r_doref, txfn, whichTransform, r_mask)
}

itkConvolveImage <- function(r_in_image1, r_in_image2) {
    .Call(`_ANTsRCore_itkConvolveImage`, r_in_image1, r_in_image2)
}

labelStatsR <- function(r_image, r_labelImage) {
    .Call(`_ANTsRCore_labelStatsR`, r_image, r_labelImage)
}

makeImageR <- function(r_pixeltype, r_size, r_spacing, r_origin, r_direction, r_components) {
    .Call(`_ANTsRCore_makeImageR`, r_pixeltype, r_size, r_spacing, r_origin, r_direction, r_components)
}

mergeChannelsR <- function(r_imageList) {
    .Call(`_ANTsRCore_mergeChannelsR`, r_imageList)
}

blobAnalysis <- function(r_inimg, r_outimg, r_numberOfBlobsToExtract, r_minScale, r_maxScale, r_stepsPerOctave) {
    .Call(`_ANTsRCore_blobAnalysis`, r_inimg, r_outimg, r_numberOfBlobsToExtract, r_minScale, r_maxScale, r_stepsPerOctave)
}

patchAnalysis <- function(r_inimg, r_maskimg, r_outimg, r_patchRadius, r_patchSamples, r_patchVar, r_meanCenter, r_canonicalFrame, r_evecBasis, r_rotInvar, r_doProj, r_verbose) {
    .Call(`_ANTsRCore_patchAnalysis`, r_inimg, r_maskimg, r_outimg, r_patchRadius, r_patchSamples, r_patchVar, r_meanCenter, r_canonicalFrame, r_evecBasis, r_rotInvar, r_doProj, r_verbose)
}

rcpp_hello_world22 <- function() {
    .Call(`_ANTsRCore_rcpp_hello_world22`)
}

rcpp_hello_world33 <- function() {
    .Call(`_ANTsRCore_rcpp_hello_world33`)
}

reflectionMatrixR <- function(r_image, r_axis, r_filename) {
    .Call(`_ANTsRCore_reflectionMatrixR`, r_image, r_axis, r_filename)
}

reorientImageR <- function(r_in_image1, r_txfn, r_axis1, r_axis2, rrfl, rscl) {
    .Call(`_ANTsRCore_reorientImageR`, r_in_image1, r_txfn, r_axis1, r_axis2, rrfl, rscl)
}

centerOfMass <- function(r_in_image1) {
    .Call(`_ANTsRCore_centerOfMass`, r_in_image1)
}

sccanX <- function(r_args) {
    .Call(`_ANTsRCore_sccanX`, r_args)
}

robustMatrixTransform <- function(r_matrix) {
    .Call(`_ANTsRCore_robustMatrixTransform`, r_matrix)
}

eigenanatomyCpp <- function(r_X, r_mask, r_sparseness, r_nvecs, r_its, r_cthresh, r_z, r_smooth, r_initializationList, r_mycoption, r_ell1, r_verbose, r_powerit, r_priorWeight, r_maxBasedThresh) {
    .Call(`_ANTsRCore_eigenanatomyCpp`, r_X, r_mask, r_sparseness, r_nvecs, r_its, r_cthresh, r_z, r_smooth, r_initializationList, r_mycoption, r_ell1, r_verbose, r_powerit, r_priorWeight, r_maxBasedThresh)
}

sccanCpp <- function(r_X, r_Y, r_maskx, r_masky, r_sparsenessx, r_sparsenessy, r_nvecs, r_its, r_cthreshx, r_cthreshy, r_z, r_smooth, r_initializationListx, r_initializationListy, r_mycoption, r_ell1, r_verbose, r_priorWeight, r_maxBasedThresh) {
    .Call(`_ANTsRCore_sccanCpp`, r_X, r_Y, r_maskx, r_masky, r_sparsenessx, r_sparsenessy, r_nvecs, r_its, r_cthreshx, r_cthreshy, r_z, r_smooth, r_initializationListx, r_initializationListy, r_mycoption, r_ell1, r_verbose, r_priorWeight, r_maxBasedThresh)
}

smoothImageR <- function(r_inimg, r_outimg, r_sigma, sigmaInPhysicalCoordinates, r_kernelwidth) {
    .Call(`_ANTsRCore_smoothImageR`, r_inimg, r_outimg, r_sigma, sigmaInPhysicalCoordinates, r_kernelwidth)
}

splitChannelsR <- function(r_antsimage) {
    .Call(`_ANTsRCore_splitChannelsR`, r_antsimage)
}

timeSeriesSubtraction <- function(r_antsimage, method) {
    .Call(`_ANTsRCore_timeSeriesSubtraction`, r_antsimage, method)
}

weingartenImageCurvatureR <- function(r_antsimage, r_sigma, r_opt, r_labeled) {
    .Call(`_ANTsRCore_weingartenImageCurvatureR`, r_antsimage, r_sigma, r_opt, r_labeled)
}

