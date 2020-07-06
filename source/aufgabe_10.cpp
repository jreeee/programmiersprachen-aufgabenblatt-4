#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <cmath>      
#include <algorithm>  //std::remove_if, std::all_of, std::generate
#include <vector>     //std::vector<> 
#include <cstdlib>    //std::rand

//helper function to determine if the int is a multiple of three
bool is_multiple_of_3(unsigned int i) {
  return ((i % 3) == 0);
}

 /*
  generating a vector with 100 random unsigned ints inside, using the
  Erase-remove idiom to delete all elements which are not a multiple of 3
  testing if the vector only contains elements which are multiples of 3.
  */
TEST_CASE()
{
  std::vector<unsigned int> v(100);
  std::transform(v.begin(), v.end(), v.begin(), [] (unsigned int el) { return rand()% 101;});
  v.erase(std::remove_if(v.begin(), v.end(), [] (unsigned int i) {return ((i % 3) != 0);}), v.end());
  REQUIRE(std::all_of(v.begin(), v.end(), is_multiple_of_3));
}

int main (int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}