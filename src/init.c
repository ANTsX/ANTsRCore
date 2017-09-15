#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/*
  The following name(s) appear with different usages
  e.g., with different numbers of arguments:

    antsImageIterator

  This needs to be resolved in the tables and any declarations.
*/

/* FIXME:
   Check these declarations against the C/Fortran source code.
*/

/* .Call calls */
extern SEXP antsApplyTransforms(SEXP);
extern SEXP antsApplyTransformsToPoints(SEXP);
extern SEXP antsImage(SEXP, SEXP, SEXP);
extern SEXP antsImage_asantsImage(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP antsImage_asVector(SEXP, SEXP, SEXP);
extern SEXP antsImage_dim(SEXP);
extern SEXP antsImage_GetDirection(SEXP);
extern SEXP antsImage_GetNeighborhood(SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP antsImage_GetNeighborhoodMatrix(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP antsImage_GetOrigin(SEXP);
extern SEXP antsImage_GetPixels(SEXP, SEXP);
extern SEXP antsImage_GetSpacing(SEXP);
extern SEXP antsImage_isna(SEXP);
//extern SEXP antsImage_rm(SEXP);
//extern SEXP antsImage_RelationalOperators(SEXP, SEXP, SEXP, SEXP);
extern SEXP antsImage_SetDirection(SEXP, SEXP);
extern SEXP antsImage_SetOrigin(SEXP, SEXP);
extern SEXP antsImage_SetPixels(SEXP, SEXP, SEXP);
extern SEXP antsImage_SetRegion(SEXP, SEXP, SEXP, SEXP);
extern SEXP antsImage_SetSpacing(SEXP, SEXP);
extern SEXP antsImage_TransformIndexToPhysicalPoint(SEXP, SEXP);
extern SEXP antsImage_TransformPhysicalPointToIndex(SEXP, SEXP);
extern SEXP antsImageArithImageImage(SEXP,SEXP,SEXP);
extern SEXP antsImageArithImageNumeric(SEXP,SEXP,SEXP);
extern SEXP antsImageArithNumericImage(SEXP,SEXP,SEXP);
extern SEXP antsImageComparisonImageImage(SEXP,SEXP,SEXP);
extern SEXP antsImageComparisonImageNumeric(SEXP,SEXP,SEXP);
extern SEXP antsImageClone(SEXP, SEXP);
extern SEXP antsImageHeaderInfo(SEXP);
// extern SEXP antsImageIterator(SEXP);
extern SEXP antsImageIterator(SEXP, SEXP, SEXP);
extern SEXP antsImageIterator_Get(SEXP);
extern SEXP antsImageIterator_GetIndex(SEXP);
extern SEXP antsImageIterator_GoToBegin(SEXP);
extern SEXP antsImageIterator_GoToReverseBegin(SEXP);
extern SEXP antsImageIterator_IsAtEnd(SEXP);
extern SEXP antsImageIterator_IsAtReverseEnd(SEXP);
extern SEXP antsImageIterator_Next(SEXP);
extern SEXP antsImageIterator_Previous(SEXP);
extern SEXP antsImageIterator_Remaining(SEXP);
extern SEXP antsImageIterator_Set(SEXP, SEXP);
extern SEXP antsImage_SetByImage( SEXP, SEXP, SEXP );
extern SEXP antsImageIterator_SetIndex(SEXP, SEXP);
extern SEXP antsImageLogicImageImage(SEXP,SEXP,SEXP);
extern SEXP antsImageLogicImageNumeric(SEXP,SEXP,SEXP);
extern SEXP antsImageMath(SEXP,SEXP);
extern SEXP antsImageMutualInformation(SEXP, SEXP);
extern SEXP antsImageRead(SEXP, SEXP, SEXP, SEXP);
extern SEXP antsImageWrite(SEXP, SEXP);
extern SEXP antsMatrix(SEXP);
extern SEXP antsMatrix_asantsMatrix(SEXP, SEXP);
extern SEXP antsMatrix_asList(SEXP);
extern SEXP antsRegistration(SEXP);
extern SEXP antsrMetric(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP);
extern SEXP antsrMetric_GetDerivative(SEXP);
extern SEXP antsrMetric_GetValue(SEXP);
extern SEXP antsrMetric_Initialize(SEXP);
extern SEXP antsrMetric_SetImage(SEXP,SEXP,SEXP,SEXP);
extern SEXP antsrMetric_SetNumberOfHistogramBins(SEXP,SEXP);
extern SEXP antsrMetric_SetRadius(SEXP,SEXP);
extern SEXP antsrMetric_SetSampling(SEXP,SEXP,SEXP);
extern SEXP antsrMetric_SetTransform(SEXP,SEXP,SEXP);
extern SEXP antsrTransform(SEXP, SEXP, SEXP);
extern SEXP antsrTransform_Compose(SEXP, SEXP, SEXP);
extern SEXP antsrTransform_FromDisplacementField(SEXP);
extern SEXP antsrTransform_GetFixedParameters(SEXP);
extern SEXP antsrTransform_GetParameters(SEXP);
extern SEXP antsrTransform_Inverse(SEXP);
extern SEXP antsrTransform_MatrixOffset(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP antsrTransform_Read(SEXP, SEXP, SEXP);
extern SEXP antsrTransform_SetFixedParameters(SEXP, SEXP);
extern SEXP antsrTransform_SetParameters(SEXP, SEXP);
extern SEXP antsrTransform_TransformImage(SEXP, SEXP, SEXP, SEXP);
extern SEXP antsrTransform_TransformPoint(SEXP, SEXP);
extern SEXP antsrTransform_TransformVector(SEXP, SEXP);
extern SEXP antsrTransform_Write(SEXP, SEXP);
extern SEXP Atropos(SEXP);
extern SEXP cropImage(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP DenoiseImage(SEXP);
extern SEXP extractSlice(SEXP, SEXP, SEXP);
extern SEXP iMathInterface(SEXP);
extern SEXP LabelClustersUniquely(SEXP);
extern SEXP labelStats(SEXP, SEXP);
extern SEXP makeImage(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP mergeChannels(SEXP, SEXP);
extern SEXP N3BiasFieldCorrection(SEXP);
extern SEXP N4BiasFieldCorrection(SEXP);
extern SEXP patchAnalysis(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP ResampleImage(SEXP);
extern SEXP smoothImage(SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP splitChannels(SEXP, SEXP);
extern SEXP ThresholdImage(SEXP);

static const R_CallMethodDef CallEntries[] = {
    {"antsApplyTransforms",                     (DL_FUNC) &antsApplyTransforms,                      1},
    {"antsApplyTransformsToPoints",             (DL_FUNC) &antsApplyTransformsToPoints,              1},
    {"antsImage",                               (DL_FUNC) &antsImage,                                3},
    {"antsImage_asantsImage",                   (DL_FUNC) &antsImage_asantsImage,                    6},
    {"antsImage_asVector",                      (DL_FUNC) &antsImage_asVector,                       3},
    {"antsImage_dim",                           (DL_FUNC) &antsImage_dim,                            1},
    {"antsImage_GetDirection",                  (DL_FUNC) &antsImage_GetDirection,                   1},
    {"antsImage_GetNeighborhood",               (DL_FUNC) &antsImage_GetNeighborhood,                5},
    {"antsImage_GetNeighborhoodMatrix",         (DL_FUNC) &antsImage_GetNeighborhoodMatrix,          7},
    {"antsImage_GetOrigin",                     (DL_FUNC) &antsImage_GetOrigin,                      1},
    {"antsImage_GetPixels",                     (DL_FUNC) &antsImage_GetPixels,                      2},
    {"antsImage_GetSpacing",                    (DL_FUNC) &antsImage_GetSpacing,                     1},
    {"antsImage_isna",                          (DL_FUNC) &antsImage_isna,                           1},
    //{"antsImage_rm",                            (DL_FUNC) &antsImage_rm,                             1},
    // {"antsImage_RelationalOperators",           (DL_FUNC) &antsImage_RelationalOperators,            4},
    {"antsImage_SetByImage",                    (DL_FUNC) &antsImage_SetByImage,                     3},
    {"antsImage_SetDirection",                  (DL_FUNC) &antsImage_SetDirection,                   2},
    {"antsImage_SetOrigin",                     (DL_FUNC) &antsImage_SetOrigin,                      2},
    {"antsImage_SetPixels",                     (DL_FUNC) &antsImage_SetPixels,                      3},
    {"antsImage_SetRegion",                     (DL_FUNC) &antsImage_SetRegion,                      4},
    {"antsImage_SetSpacing",                    (DL_FUNC) &antsImage_SetSpacing,                     2},
    {"antsImage_TransformIndexToPhysicalPoint", (DL_FUNC) &antsImage_TransformIndexToPhysicalPoint,  2},
    {"antsImage_TransformPhysicalPointToIndex", (DL_FUNC) &antsImage_TransformPhysicalPointToIndex,  2},
    {"antsImageArithImageImage",                (DL_FUNC) &antsImageArithImageImage,                 3},
    {"antsImageArithImageNumeric",              (DL_FUNC) &antsImageArithImageNumeric,               3},
    {"antsImageArithNumericImage",              (DL_FUNC) &antsImageArithNumericImage,               3},
    {"antsImageComparisonImageImage",           (DL_FUNC) &antsImageComparisonImageImage,            3},
    {"antsImageComparisonImageNumeric",         (DL_FUNC) &antsImageComparisonImageNumeric,          3},
    {"antsImageClone",                          (DL_FUNC) &antsImageClone,                           2},
    {"antsImageHeaderInfo",                     (DL_FUNC) &antsImageHeaderInfo,                      1},
    {"antsImageIterator",                       (DL_FUNC) &antsImageIterator,                        1},
    {"antsImageIterator",                       (DL_FUNC) &antsImageIterator,                        3},
    {"antsImageIterator_Get",                   (DL_FUNC) &antsImageIterator_Get,                    1},
    {"antsImageIterator_GetIndex",              (DL_FUNC) &antsImageIterator_GetIndex,               1},
    {"antsImageIterator_GoToBegin",             (DL_FUNC) &antsImageIterator_GoToBegin,              1},
    {"antsImageIterator_GoToReverseBegin",      (DL_FUNC) &antsImageIterator_GoToReverseBegin,       1},
    {"antsImageIterator_IsAtEnd",               (DL_FUNC) &antsImageIterator_IsAtEnd,                1},
    {"antsImageIterator_IsAtReverseEnd",        (DL_FUNC) &antsImageIterator_IsAtReverseEnd,         1},
    {"antsImageIterator_Next",                  (DL_FUNC) &antsImageIterator_Next,                   1},
    {"antsImageIterator_Previous",              (DL_FUNC) &antsImageIterator_Previous,               1},
    {"antsImageIterator_Remaining",             (DL_FUNC) &antsImageIterator_Remaining,              1},
    {"antsImageIterator_Set",                   (DL_FUNC) &antsImageIterator_Set,                    2},
    {"antsImageIterator_SetIndex",              (DL_FUNC) &antsImageIterator_SetIndex,               2},
    {"antsImageLogicImageImage",                (DL_FUNC) &antsImageLogicImageImage,                 3},
    {"antsImageLogicImageNumeric",              (DL_FUNC) &antsImageLogicImageNumeric,               3},
    {"antsImageMath",                           (DL_FUNC) &antsImageMath,                            2},
    {"antsImageMutualInformation",              (DL_FUNC) &antsImageMutualInformation,               2},
    {"antsImageRead",                           (DL_FUNC) &antsImageRead,                            4},
    {"antsImageWrite",                          (DL_FUNC) &antsImageWrite,                           2},
    {"antsMatrix",                              (DL_FUNC) &antsMatrix,                               1},
    {"antsMatrix_asantsMatrix",                 (DL_FUNC) &antsMatrix_asantsMatrix,                  2},
    {"antsMatrix_asList",                       (DL_FUNC) &antsMatrix_asList,                        1},
    {"antsRegistration",                        (DL_FUNC) &antsRegistration,                         1},
    {"antsrMetric",                             (DL_FUNC) &antsrMetric,                              6},
    {"antsrMetric_GetDerivative",               (DL_FUNC) &antsrMetric_GetDerivative,                1},
    {"antsrMetric_GetValue",                    (DL_FUNC) &antsrMetric_GetValue,                     1},
    {"antsrMetric_Initialize",                  (DL_FUNC) &antsrMetric_Initialize,                   1},
    {"antsrMetric_SetImage",                    (DL_FUNC) &antsrMetric_SetImage,                     4},
    {"antsrMetric_SetNumberOfHistogramBins",    (DL_FUNC) &antsrMetric_SetNumberOfHistogramBins,     2},
    {"antsrMetric_SetRadius",                   (DL_FUNC) &antsrMetric_SetRadius,                    2},
    {"antsrMetric_SetSampling",                 (DL_FUNC) &antsrMetric_SetSampling,                  3},
    {"antsrMetric_SetTransform",                (DL_FUNC) &antsrMetric_SetTransform,                 3},
    {"antsrTransform",                          (DL_FUNC) &antsrTransform,                           3},
    {"antsrTransform_Compose",                  (DL_FUNC) &antsrTransform_Compose,                   3},
    {"antsrTransform_FromDisplacementField",    (DL_FUNC) &antsrTransform_FromDisplacementField,     1},
    {"antsrTransform_GetFixedParameters",       (DL_FUNC) &antsrTransform_GetFixedParameters,        1},
    {"antsrTransform_GetParameters",            (DL_FUNC) &antsrTransform_GetParameters,             1},
    {"antsrTransform_Inverse",                  (DL_FUNC) &antsrTransform_Inverse,                   1},
    {"antsrTransform_MatrixOffset",             (DL_FUNC) &antsrTransform_MatrixOffset,              9},
    {"antsrTransform_Read",                     (DL_FUNC) &antsrTransform_Read,                      3},
    {"antsrTransform_SetFixedParameters",       (DL_FUNC) &antsrTransform_SetFixedParameters,        2},
    {"antsrTransform_SetParameters",            (DL_FUNC) &antsrTransform_SetParameters,             2},
    {"antsrTransform_TransformImage",           (DL_FUNC) &antsrTransform_TransformImage,            4},
    {"antsrTransform_TransformPoint",           (DL_FUNC) &antsrTransform_TransformPoint,            2},
    {"antsrTransform_TransformVector",          (DL_FUNC) &antsrTransform_TransformVector,           2},
    {"antsrTransform_Write",                    (DL_FUNC) &antsrTransform_Write,                     2},
    {"Atropos",                                 (DL_FUNC) &Atropos,                                  1},
    {"cropImage",                               (DL_FUNC) &cropImage,                                6},
    {"DenoiseImage",                            (DL_FUNC) &DenoiseImage,                             1},
    {"extractSlice",                            (DL_FUNC) &extractSlice,                             3},
    {"iMathInterface",                          (DL_FUNC) &iMathInterface,                           1},
    {"LabelClustersUniquely",                   (DL_FUNC) &LabelClustersUniquely,                    1},
    {"labelStats",                              (DL_FUNC) &labelStats,                               2},
    {"makeImage",                               (DL_FUNC) &makeImage,                                6},
    {"mergeChannels",                           (DL_FUNC) &mergeChannels,                            2},
    {"N3BiasFieldCorrection",                   (DL_FUNC) &N3BiasFieldCorrection,                    1},
    {"N4BiasFieldCorrection",                   (DL_FUNC) &N4BiasFieldCorrection,                    1},
    {"patchAnalysis",                           (DL_FUNC) &patchAnalysis,                           12},
    {"ResampleImage",                           (DL_FUNC) &ResampleImage,                            1},
    {"smoothImage",                             (DL_FUNC) &smoothImage,                              5},
    {"splitChannels",                           (DL_FUNC) &splitChannels,                            2},
    {"ThresholdImage",                          (DL_FUNC) &ThresholdImage,                           1},
    {NULL, NULL, 0}
};

void R_init_ANTsRCore(DllInfo *dll)
{
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
