#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <cmath>      
#include <algorithm>  //std::remove_if, std::all_of, std::generate
#include <vector>     //std::vector<> 
#include <cstdlib>
#include <functional>

template<class T, class UnaryPredicate> 
//T filter(T const& s, const std::function<bool(const element&)>predicate)
T filter(T s, UnaryPredicate p)
{
  T nw;
  //std::copy (s.begin(), s.end(), nw.end());
  //return (std::remove_if(nw.begin(), nw.end(), p));
  return (std::copy_if (s.begin(), s.end(), nw.end(), p));
}

TEST_CASE()
{
  std::function<bool(int)>is_even = [] (int n) { return n % 2 == 0; };
  std::vector<int> v{1, 2, 3, 4, 5, 6};
  std::vector<int> all_even = filter(v, is_even);

  REQUIRE(std::all_of(all_even.begin(), all_even.end(), [] (int i) {return (i % 2) == 0;}));
}

int main (int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}