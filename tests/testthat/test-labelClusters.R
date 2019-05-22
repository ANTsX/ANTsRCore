context("Checking labelClusters")
img<-antsImageRead( getANTsRData("r16") )
clusts = img < 200 & img > 100

test_that("labelClusters Table is correct", {
  
  timgFully = labelClusters( clusts,
                             fullyConnected = TRUE)
  expect_true(min(timgFully) == 0)
  
  timgnotFully = labelClusters( clusts,
                                fullyConnected = FALSE)
  expect_true(min(timgnotFully) == 0)  
})

test_that("labelClusters Table is correct", {
  
  
  timgFully = labelClusters( img, minClusterSize = 10, 
                             minThresh = 128, 
                             maxThresh = 150, 
                             fullyConnected = TRUE)
  expect_true(sum(timgFully) == 9026)
  check_tab = structure(c(`0` = 64796L, `1` = 71L, `2` = 63L, `3` = 51L, `4` = 43L, 
                          `5` = 35L, `6` = 33L, `7` = 28L, `8` = 24L, `9` = 24L, `10` = 23L, 
                          `11` = 22L, `12` = 20L, `13` = 18L, `14` = 17L, `15` = 16L, `16` = 16L, 
                          `17` = 16L, `18` = 16L, `19` = 15L, `20` = 15L, `21` = 15L, `22` = 14L, 
                          `23` = 14L, `24` = 14L, `25` = 13L, `26` = 13L, `27` = 13L, `28` = 12L, 
                          `29` = 12L, `30` = 12L, `31` = 11L, `32` = 11L, `33` = 10L, `34` = 10L
  ), .Dim = 35L, 
  .Dimnames = list(timgFully = c("0", "1", "2", 
                                 "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", 
                                 "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", 
                                 "26", "27", "28", "29", "30", "31", "32", "33", "34")), class = "table")
  
  
  tab = table(timgFully)
  expect_identical(tab, check_tab)
  
  timgFace = labelClusters( img, minClusterSize = 10, 
                            minThresh = 128, 
                            maxThresh = 150, 
                            fullyConnected = FALSE )
  
  expect_true(sum(timgFace) == 3947)
  check_tab = structure(c(`0` = 65146L, `1` = 40L, `2` = 33L, `3` = 23L, `4` = 20L, 
                          `5` = 18L, `6` = 17L, `7` = 17L, `8` = 17L, `9` = 16L, `10` = 16L, 
                          `11` = 15L, `12` = 15L, `13` = 14L, `14` = 14L, `15` = 13L, `16` = 13L, 
                          `17` = 12L, `18` = 12L, `19` = 11L, `20` = 11L, `21` = 11L, `22` = 11L, 
                          `23` = 11L, `24` = 10L), .Dim = 25L, 
                        .Dimnames = list(timgFace = c("0", 
                                                      "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", 
                                                      "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", 
                                                      "24")), class = "table")
  
  tab = table(timgFace)
  expect_identical(tab, check_tab)
  
})

