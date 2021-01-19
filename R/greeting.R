#' Hello world from CGO via Rcpp
#'
#' An example function.
#'
#' @param message Character vector
#' @return Character vector
#' @export
greet <- function(message = "World") {
  res <- .Call("_RcppCgo_hi", PACKAGE = "RcppCgo", as.character(message))
  return(res)
}
