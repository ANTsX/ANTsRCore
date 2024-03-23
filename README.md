# ANTsRCore

<!-- badges: start -->

[![R-CMD-check](https://github.com/ANTsX/ANTsRCore/actions/workflows/package-build.yml/badge.svg)](https://github.com/ANTsX/ANTsRCore/actions/workflows/package-build.yml)
[![Coverage status](https://codecov.io/gh/muschellij2/ANTsRCore/branch/master/graph/badge.svg)](https://codecov.io/github/muschellij2/ANTsRCore?branch=master)

<!-- badges: end -->

The ANTsRCore package wraps the C++ ANTs package in R. This package provides the core features for [ANTsR](http://stnava.github.io/ANTsR/).

<br />

## Installation

The package can be installed the pre-compiled binaries (fast) or from source.

### Pre-compiled binaries

The fastest way to install ANTsRCore is from pre-compiled binaries made available on the [Releases Page](https://github.com/ANTsX/ANTsRCore/releases). Download the relevant version and install it from the command line:

```
R CMD INSTALL ANTsRCore_*.tgz
```

### From source using devtools

To install ANTsRCore from source, you can use devtools to install the latest version of the code directly form GitHub. This should also automatically install the main dependencies.

```R
devtools::install_github('ANTsX/ANTsR')
```

### From source using R CMD INSTALL

Alternatively, you can clone and install ANTsRCore and its main dependency (ITKR), then install them as you would traditional R source packages.

First, clone the repositories:

```sh
$ git clone https://github.com/stnava/ITKR.git
$ git clone https://github.com/ANTsX/ANTsRCore.git
```

Install the package as follows:

```sh
$ R CMD INSTALL ITKR
$ R CMD INSTALL ANTsRCore
```

<br />

## Usage

Functions from this package should never be exposed directly to any users. Instead, this package should always be wrapped by user-facing functions. All library functions can be found in the `R/RcppExports.R` file which is automatically generated during the build.

<br />

## Developer notes

Using devtools to install and document the package is useful but requires rebuilding the package from scratch every time it's run. If you are going to develop on the package, it is best to install it with `R CMD INSTALL`.

All documentation is done through Rcpp within the cpp files in the src/ directory. New Rcpp functions are imported to R by adding the `// [[Rcpp::export]]` tag and then running `Rcpp::compileAttributes()`. You should never have to edit any R files directly.

### Authors

[Brian B. Avants](http://stnava.github.io/) (maintainer), Benjamin M. Kandel, Jeff T. Duda, Philip A. Cook, Nicholas J. Tustison

### License

Apache License (>=2.0)

<br />

## Contributing

If you have a question or feature request, please create an issue on GitHub. Any issues related to ANTsR should preferably be posted in that repository.
