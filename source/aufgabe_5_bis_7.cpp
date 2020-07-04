#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "circle.hpp"

#include <list>       //std::list<>

#include <cstdlib>    //rand()
#include <algorithm>  //std::is_sorted


//4.5
TEST_CASE("testing if the circle list is sorted using sort() - 4.5", "[srtd_circ_5]")
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

//4.6
TEST_CASE("testing if the circle list is sorted using lambda - 4.6", "[srtd_circ_6]")
{
  //Initializing a list containing circles and filling it with circles with random radius
  std::list<Circle> sorted_circles;
  int sc_size = 20;
  for (int i = 0; i < sc_size; ++i) {
    sorted_circles.push_back(Circle(float(rand() % 501)));
  }
  //sorting the list and checking if it was sorted correctly using the lambda to compare the radii
  auto sorting_lambda = (sorted_circles.begin(), sorted_circles.end(), [] (Circle const& lhs, Circle const& rhs) -> bool {
    return lhs < rhs;
    });
  sorted_circles.sort(sorting_lambda);
  REQUIRE(std::is_sorted(sorted_circles.begin(), sorted_circles.end()));
}

//4.7
template<typename T>
class comp {
  public:
    bool operator() (T const& lhs, T const& rhs) {
      return lhs < rhs;
    }
};

TEST_CASE("testing if the circle list is sorted using functor - 4.7", "[srtd_circ_7]")
{
  

  //Initializing a list containing circles and filling it with circles with random radius
  std::list<Circle> sorted_circles;
  int sc_size = 20;
  for (int i = 0; i < sc_size; ++i) {
    sorted_circles.push_back(Circle(float(rand() % 501)));
  }
  //sorting the list and checking if it was sorted correctly using the lambda to compare the radii
  auto sorting_functor = (sorted_circles.begin(), sorted_circles.end(), comp<Circle>{});
  sorted_circles.sort(sorting_functor);
  REQUIRE(std::is_sorted(sorted_circles.begin(), sorted_circles.end()));
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}