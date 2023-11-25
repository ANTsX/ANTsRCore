[ANTsR Instagram](https://www.instagram.com/antsrx/)

![ants edie](http://i.imgur.com/DcV1NVT.png)

# ANTsRCore

<!-- badges: start -->
[![R build status](https://github.com/ANTsX/ANTsRCore/workflows/R-CMD-check/badge.svg)](https://github.com/ANTsX/ANTsRCore/actions)
[![Travis Build Status](https://travis-ci.org/ANTsX/ANTsRCore.png?branch=master)](https://travis-ci.org/ANTsX/ANTsRCore)
[![Coverage status](https://codecov.io/gh/ANTsX/ANTsRCore/branch/master/graph/badge.svg)](https://codecov.io/github/ANTsX/ANTsRCore?branch=master)
muschellij2 coverage badge:
[![Coverage status](https://codecov.io/gh/muschellij2/ANTsRCore/branch/master/graph/badge.svg)](https://codecov.io/github/muschellij2/ANTsRCore?branch=master)  
<!-- badges: end -->
A package providing core features for [ANTsR](http://stnava.github.io/ANTsR/).

## Description

Version: 0.0

License: 	Apache License (>=2.0)

Depends:	R (≥ 3.0), methods

Imports:	Rcpp, tools

LinkingTo:	Rcpp, ITKR

Author:	Brian B. Avants, Benjamin M. Kandel, Jeff T. Duda, Philip A. Cook, Nicholas J. Tustison

Maintainer:	[Brian B. Avants](http://stnava.github.io/)

URL:	[homepage](https://github.com/stnava/ANTsRCore)

BugReports: [github issues](http://github.com/stnava/ANTsRCore/issues)

NeedsCompilation:	yes

Travis checks:	[ANTsRCore results](https://travis-ci.org/stnava/ANTsRCore)

Documentation: [https://antsx.github.io/ANTsRCore/](https://antsx.github.io/ANTsRCore/).


Install the binary, after downloading, via command line:

```
R CMD INSTALL ANTsRCore_*.tgz
```

**Suggested packages** [https://github.com/stnava/ANTsRDocker/blob/master/install.R](https://github.com/stnava/ANTsRDocker/blob/master/install.R)


## to tag

```
git tag -d latest
git push origin :refs/tags/latest
git tag latest
git push  --tags origin
```

## 0.0.0

First attempt release.

## other

if you see an error like: `error: src refspec refs/heads/master matches more than one` then try

```
git push origin master:master
```
