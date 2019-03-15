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
}

test_that("labelClusters Table is correct", {
  
  
  timgFully = labelClusters( img, minClusterSize = 10, 
                             minThresh = 128, 
                             maxThresh = 150, 
                             fullyConnected = TRUE)
  expect_true(sum(timgFully) == 73999)
  check_tab = structure(c(`0` = 563L, `1` = 64233L, `2` = 71L, `3` = 63L, `4` = 51L, 
                          `5` = 43L, `6` = 35L, `7` = 33L, `8` = 28L, `9` = 24L, `10` = 24L, 
                          `11` = 23L, `12` = 22L, `13` = 20L, `14` = 18L, `15` = 17L, `16` = 16L, 
                          `17` = 16L, `18` = 16L, `19` = 16L, `20` = 15L, `21` = 15L, `22` = 15L, 
                          `23` = 14L, `24` = 14L, `25` = 14L, `26` = 13L, `27` = 13L, `28` = 13L, 
                          `29` = 12L, `30` = 12L, `31` = 12L, `32` = 11L, `33` = 11L, `34` = 10L, 
                          `35` = 10L), .Dim = 36L, .Dimnames = list(timgFully = c("0", 
                                                                                  "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", 
                                                                                  "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", 
                                                                                  "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", 
                                                                                  "35")), class = "table")
  tab = table(timgFully)
  expect_identical(tab, check_tab)
  timgFace = labelClusters( img, minClusterSize = 10, 
                            minThresh = 128, 
                            maxThresh = 150, 
                            fullyConnected = FALSE )
  
  expect_true(sum(timgFace) == 68570)
  check_tab = structure(c(`0` = 913L, `1` = 64233L, `2` = 40L, `3` = 33L, `4` = 23L, 
                          `5` = 20L, `6` = 18L, `7` = 17L, `8` = 17L, `9` = 17L, `10` = 16L, 
                          `11` = 16L, `12` = 15L, `13` = 15L, `14` = 14L, `15` = 14L, `16` = 13L, 
                          `17` = 13L, `18` = 12L, `19` = 12L, `20` = 11L, `21` = 11L, `22` = 11L, 
                          `23` = 11L, `24` = 11L, `25` = 10L), .Dim = 26L, .Dimnames = list(
                            timgFace = c("0", "1", "2", "3", "4", "5", "6", "7", "8", 
                                         "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", 
                                         "19", "20", "21", "22", "23", "24", "25")),
                        class = "table")
  tab = table(timgFace)
  expect_identical(tab, check_tab)
  
})

