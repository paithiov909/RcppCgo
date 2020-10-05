#' @noRd
#' @keywords internal
.onLoad <- function(libname, pkgname) {
  library.dynam("RCgoHello",
    pkgname,
    .libPaths(),
    DLLpath = system.file("libs", pkgname)
  )
}

#' @noRd
#' @keywords internal
.onUnload <- function(libpath) {
  library.dynam.unload("RCgoHello", libpath)
}
