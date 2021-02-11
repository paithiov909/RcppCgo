// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::depends(RcppThread)]]
#define STRICT_R_HEADERS
#define R_NO_REMAP
#define RCPPTHREAD_OVERRIDE_THREAD 1
#include <Rcpp.h>
#include <cstdlib>
#include "../inst/include/librcgo.h"

using namespace Rcpp;

//' Greeting from Rcpp
//'
//' This function bridges between Rcpp and librcgo.
//'
//' @param v Character vector
//' @return Character vector
//'
//' @export
//'
// [[Rcpp::interfaces(r, cpp)]]
// [[Rcpp::export]]
Rcpp::CharacterVector hi(Rcpp::CharacterVector v) {

  char* response;

  std::function< Rcpp::String(Rcpp::String) > func = [&](Rcpp::String x) {
    const char* s = x.get_cstring();
    const std::size_t n = std::strlen(s);
    const std::ptrdiff_t len = n;
    const GoString message = { s, len };

    response = Hi(message);
    const std::string res = response;

    const Rcpp::String result = res;
    return result;
  };

  const Rcpp::CharacterVector result = sapply(v, func);

  free(response);

  return result;
}
