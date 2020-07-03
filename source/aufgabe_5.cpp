#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "circle.hpp"

#include <list>       //std::list<>

#include <cstdlib>    //rand()
#include <algorithm>  //std::is_sorted



TEST_CASE("testing if the circle list is sorted", "[srtd_circ]")
{
  //Initializing a list containing circles and filling it with circles with random radius
  std::list<Circle> sorted_circles;
  int sc_size = 20;
  for (int i = 0; i < sc_size; ++i) {
    sorted_circles.push_back(Circle(float(rand() % 501)));
  }
  //sorting the list and checking if it was sorted correctly
  sorted_circles.sort();
  REQUIRE(std::is_sorted(sorted_circles.begin(), sorted_circles.end()));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}