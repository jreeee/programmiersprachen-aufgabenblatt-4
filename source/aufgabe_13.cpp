#define CATCH_CONFIG_RUNNER
#include "circle.hpp"
#include "catch.hpp"   
#include <algorithm>  //std::remove_if, std::all_of, std::generate
#include <vector>     //std::vector<> 

/*
creating a vector containing multiple circles with unique radii and an empty one,
using copy_if to copy every
*/
TEST_CASE()
{
  std::vector<Circle> circles{{5.0f},{3.0f},{8.0f},{1.0f},{6.0f},{7.0f},{9.0f},
                              {2.0f},{10.0f},{0.0f},{11.0f},{13.0f},{12.0f}};
  std::vector<Circle> greater_four;
  std::copy_if(circles.begin(), circles.end(), std::back_inserter(greater_four), [] (Circle const& c) { return c.radius() > 4; });
 
  REQUIRE(std::all_of(greater_four.begin(), greater_four.end(), [] (Circle const& c) { return c.radius() > 4; }));
}

int main (int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}