#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <cmath>      
#include <algorithm>  //std::remove_if, std::all_of, std::generate
#include <vector>     //std::vector<> 
#include <functional> //std::function
#include <map>        //std::map<>
#include <array>      //std::array<>



template<class T, class UnaryPredicate> 
T filter(T const& s, const UnaryPredicate p)
{
  //getting the size of the new container
  unsigned int i = std::count_if(std::begin(s), std::end(s), p);
  //allocating the elements using i as size
  T nw(i);
  //return (std::remove_if(begin(nw), end(nw), p));
  std::copy_if (std::begin(s), std::end(s), std::begin(nw), p);
  return nw;
}

TEST_CASE()
{
  //bool is_even = [] (int n) { return n % 2 == 0; };
  std::function<bool(int)>is_even = [] (int n) { return (n % 2 == 0); };

  std::vector<int> v{1, 2, 3, 4, 5, 6};
  std::vector<int> all_even = filter(v, is_even);
  
  REQUIRE(std::all_of(all_even.begin(), all_even.end(), [] (int i) {return (i % 2) == 0;}));
}

int main (int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}