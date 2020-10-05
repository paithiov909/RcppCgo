// [[Rcpp::plugins(cpp11)]]
#define R_NO_REMAP
#include <Rcpp.h>
#include <cstdlib>
#include "../inst/include/librcgo.h"

using namespace Rcpp;

//' Greeting from Rcpp
//'
//' This function bridges between Rcpp and librcgo.
//'
//' @param v character vector
//' @return character vector
//'
//' @export
//'
// [[Rcpp::interfaces(r, cpp)]]
// [[Rcpp::export]]
Rcpp::CharacterVector hi(Rcpp::CharacterVector v) {

  std::function< Rcpp::String(Rcpp::String) > func_obj = [](Rcpp::String x) {
    const char* s = x.get_cstring();
    const std::size_t n = std::strlen(s);
    const std::ptrdiff_t len = n;
    const GoString message = { s, len };

    char* response = Hi(message);
    const std::string res = response;

    free(response);

    const Rcpp::String result = res;
    return result;
  };

  const Rcpp::CharacterVector result = sapply(v, func_obj) ;
  return result;
}
