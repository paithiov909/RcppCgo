#' @noRd
#' @keywords internal
NULL

#' @noRd
#' @keywords internal
.onUnload <- function(libpath) {
  library.dynam.unload("RcppCgo", libpath)
}
