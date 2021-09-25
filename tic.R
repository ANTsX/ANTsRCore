# R CMD Check OS specific build and check arguments
args <- c("--as-cran","--install-args=--build")
error_on <- "warnings"

# do not treat warnings as errors for windows
if (.Platform$OS.type == "windows") error_on <- "error"

do_package_checks(args = args, error_on = error_on)

InstallRemoteBinaries <- R6Class(
  "InstallRemoteBinaries",
  inherit = TicStep,

  public = list(
    run = function() {
      # get remotes and try to install binaries
      remotes = ghtravis::get_remotes()

      if(!is.null(remotes)) {
        for(remote in remotes) {
          remote_info <- ghtravis::parse_remotes(remote)
          github_user <- sapply(remote_info, `[[`, "username")
          repo <- sapply(remote_info, `[[`, "repo")
          slug <- paste0(paste0(github_user,"/",repo))

          if(!is.null(github_user) && !is.null(repo)) {
            message(paste0("Installing ",repo," binaries"))
            ghtravis::install_remote_binaries(check_r_version = TRUE, force_sha = FALSE, remotes = c(slug))

            # install binary package deps (not already installed)
            binary_deps <- ghtravis::remote_package_deps(slug)
            binary_deps_list <- binary_deps[[1[]]]$name
            install.packages(binary_deps_list[!(binary_deps_list %in% installed.packages())])
          }
        }
      }
    }
  )
)

step_install_remote_binaries <- function() {
  InstallRemoteBinaries$new()
}

get_stage("before_install") %>%
add_step(step_install_remote_binaries())

