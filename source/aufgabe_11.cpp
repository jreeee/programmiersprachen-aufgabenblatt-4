#define CATCH_CONFIG_RUNNER
#include "catch.hpp"     
#include <algorithm>  //std::transform, std::all_of
#include <vector>     //std::vector<> 

 /*
  generating three vectors with length nine.
  Utilizing transform and a lambda to add the first two vectors together
  and moving the resulting int into the third vector.
  Testing if the third vector only contains 10s.
  */
TEST_CASE()
{
  std::vector<int> v_1{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> v_2{9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::vector<int> v_3(9);
  //I prefer the commented out part since it is more elegant, however the requirement was to write a lambda
  //std::transform(v_1.begin(), v_1.end(), v_2.begin(), v_3.begin(), std::plus<int>());
  std::transform(v_1.begin(), v_1.end(), v_2.begin(), v_3.begin(), [] (int const lhs, int const rhs) {return rhs + lhs;});
  REQUIRE(std::all_of(v_3.begin(), v_3.end(), [] (int i) {return i == 10;}));
}

int main (int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}