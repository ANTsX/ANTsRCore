.onAttach <- function(lib, pkg) {
  txt <- paste(pkg, utils::packageDescription(pkg, lib)[["Version"]])
  txt <- paste0(
    txt, "\n",
    "For reproducible results, ",
    "please set the environment variable ANTS_RANDOM_SEED,\n",
    "either in .Renviron or with a seed (e.g. XXX): ", 
    "\nSys.setenv(ANTS_RANDOM_SEED = XXX)\n",
    "Sys.setenv(ITK_GLOBAL_DEFAULT_NUMBER_OF_THREADS = 1)\nmay ",
    "also be required for reproducible results. See\n",
    "https://github.com/ANTsX/ANTs/wiki/", 
    "antsRegistration-reproducibility-issues\nfor more information"
  )
  packageStartupMessage(txt)
  }
