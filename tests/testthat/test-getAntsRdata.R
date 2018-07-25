
context("read in each data set")

validlist = c(
  "r16", "r27", "r30", "r62", "r64", "r85", "r64",
  # "nki", 
  "pcasl",
  "ch2","ch2a","ch2b","finn","finncsv",
  "mni","mnia","mnib","mnit","mninat","mnijhu1","mnijhu2","mnidfn","mniyeo",
  "atroposseg","simple","fmrinetworks",
  "rsbold", "rsboldmask", "rsboldseg", "rsboldpts", "decslice", "dtislice",
  "adfmri", "population", "surf", "blob", "rand")


for (ilist in validlist) {
  suppressMessages({
    res = getANTsRData(ilist, quiet = TRUE)
  })
  if (is.character(res)) {
    print(res)
    # res = antsImageRead(res)
  }
  # print(res)
  # cloned = antsImageClone(res)
}

