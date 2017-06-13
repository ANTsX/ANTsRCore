code = readLines("comparison_operator_template.R")
comparators = c("==", ">", "<", "!=", "<=", ">=")
res_code = lapply(comparators, function(iop){ 
  c(gsub("OPERATOR", iop, code), rep("", 5))
})
res_code = unlist(res_code)
writeLines(res_code, con = "R/zzz_Comparison.R")
