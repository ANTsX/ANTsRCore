setwd("~/Dropbox/Packages/ANTs")
fol_names = c("Utilities", "Examples", 
	"Tensor", "ImageRegistration", "ImageSegmentation", 
	"Temporary")
x = sapply(
	fol_names, list.files, pattern = ".c(xx|pp)$", 
	full.names = TRUE,
	recursive = TRUE)
x = unlist(x)
x = unname(x)

xx = lapply(x, readLines)

includes = sapply(xx, function(x) {
  trimws(x[grepl("\\s*#\\s*include", x)])
})
includes = unlist(includes)
includes = includes[ !grepl("\\s*//", includes)]
includes = sub("#include ", "", includes)
includes = trimws(includes)
includes = gsub('^("|<)', "", includes)
includes = gsub('("|>)$', "", includes)
includes = unique(includes)

includes = includes[ !grepl("^vnl/", includes)]

std = c("algorithm", "cassert", "cfloat", "climits", 
        "cstdio", "cstdlib", 
        "cstring", "ctime", "deque", "fstream", 
        "iomanip", "iostream", "iterator", 
        "list",  "map",
        "ostream", "sstream", 
        "string", "vector")
includes = setdiff(includes, std)
# "make_interpolator_snip.tmpl",
