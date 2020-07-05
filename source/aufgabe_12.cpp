#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <cmath>      
#include <algorithm>  //std::remove_if, std::all_of, std::generate
#include <vector>     //std::vector<> 
#include <cstdlib>
#include <functional>

template<typename T> 
T filter(T const& s, const std::function<bool(const T&)>predicate)
{
  T nw;
  return nw.back(std::any_of(s.begin(), s.end(), [&] (const T& t) {return predicate}));
  //s.erase(std::remove_if(s.begin(), s.end(), [] (auto i) {return ((i % 2) != 0);}), s.end());
}
TEST_CASE()
{
  bool is_even = [] (int n) -> bool { return n % 2 == 0;};
  std::vector<int> v{1, 2, 3, 4, 5, 6};
  std::vector<int> all_even = filter(v, is_even);
 
  
  REQUIRE(std::all_of(all_even.begin(), all_even.end(), [] (int i) {return (i % 2) == 0;}));
}

int main (int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}