# ANTsRCore

<!-- badges: start -->
[![R-CMD-check](https://github.com/ANTsX/ANTsRCore/actions/workflows/package-build.yml/badge.svg)](https://github.com/ANTsX/ANTsRCore/actions/workflows/package-build.yml)
[![Coverage status](https://codecov.io/gh/muschellij2/ANTsRCore/branch/master/graph/badge.svg)](https://codecov.io/github/muschellij2/ANTsRCore?branch=master)  
<!-- badges: end -->

The ANTsRCore package wraps the C++ ANTs package in R. This package provides the core features for [ANTsR](http://stnava.github.io/ANTsR/).

## Installation from source

Currently the only way to install ANTsRCore is from source. The main dependency is the `ITKR` package which you can install from `stnava/ITKR` (or if that fails try a fork at `ncullen93/ITKR`). 

Then, to install ANTsRCore you can follow these steps:

- clone this repo
- in RStudio, run `devtools::install()`. Alternatively, from the command-line you can navigate to the top-level package directory and then run `R CMD INSTALL .` 


## Developer notes

Using devtools to install and document the package is useful but requires rebuilding the package from scratch every time it's run. 


## Usage

Functions from this package should never be exposed directly to any users. Instead, this package should always be wrapped by user-facing functions. All library functions can be found in the `R/RcppExports.R` file which is automatically generated during the build.

## License

Apache License (>=2.0)

## Authors

Brian B. Avants, Benjamin M. Kandel, Jeff T. Duda, Philip A. Cook, Nicholas J. Tustison

### Maintainer

[Brian B. Avants](http://stnava.github.io/)

## Contributing

If you have a question or need help solving a problem, please create an issue on GitHub. If you want to contribute code or have feature request, creating an issue on GitHub is also the best place to start.
