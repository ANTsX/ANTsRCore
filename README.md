# ANTsRCore

<!-- badges: start -->

[![R-CMD-check](https://github.com/ANTsX/ANTsRCore/actions/workflows/package-build.yml/badge.svg)](https://github.com/ANTsX/ANTsRCore/actions/workflows/package-build.yml)
<!-- badges: end -->

The ANTsRCore package provides Rcpp bindings for the C++ biomedical image processing library [ANTs](https://github.com/ANTsX/ANTs). This package should not be used directly, as it is meant to provide the core functionality for the user-facing [ANTsR](http://stnava.github.io/ANTsR/) package.

<br />

## Installation

The package can be installed the pre-compiled binaries (fast) or from source.

### From r-universe (recommended)

Pre-built binaries for Windows, macOS, and Linux are built on [r-universe](https://antsx.r-universe.dev/builds). Install ANTsRCore and its dependencies (including ITKR) by adding the ANTsX universe to the repositories used by `install.packages()`:

```R
install.packages(
  "ANTsRCore",
  repos = c("https://antsx.r-universe.dev", "https://cloud.r-project.org")
)
```

Including the CRAN repository alongside the universe lets dependencies that are on CRAN (e.g. Rcpp) resolve normally. To make the universe available for every install in a session, add it to your repository options (e.g. in your `.Rprofile`):

```R
options(repos = c(
  antsx = "https://antsx.r-universe.dev",
  CRAN = "https://cloud.r-project.org"
))
install.packages("ANTsRCore")
```

You can check the build status of each package and platform on the [ANTsX r-universe builds page](https://antsx.r-universe.dev/builds).

### Pre-compiled binaries from GitHub releases

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
