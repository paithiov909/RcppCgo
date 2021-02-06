#' @noRd
#' @keywords internal
.onUnload <- function(libpath) {
  library.dynam.unload("RcppCgo", libpath)
}
