#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <cmath>      
#include <algorithm>  //std::remove_if, std::all_of, std::generate
#include <vector>     //std::vector<> 
#include <functional> //std::function

template<class T, class UnaryPredicate> 
T filter(T s, UnaryPredicate p)
{
  T nw;
  using std::begin;
  using std::end;
  std::copy (begin(s), end(s), std::back_inserter(nw));
  //return (std::remove_if(begin(nw), end(nw), p));
  //return std::copy_if (begin(s), end(s), std::backinserter(nw), p);
  return nw;
}

TEST_CASE()
{
  //bool is_even = [] (int n) { return n % 2 == 0; };
  std::function<bool(int)>is_even = [] (int n) { return n % 2 == 0; };
  std::vector<int> v{1, 2, 3, 4, 5, 6};
  std::vector<int> all_even = filter(v, is_even);

  REQUIRE(std::all_of(all_even.begin(), all_even.end(), [] (int i) {return (i % 2) == 0;}));
}

int main (int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}