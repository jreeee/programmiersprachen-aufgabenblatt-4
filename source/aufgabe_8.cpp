#include <cstdlib>    //std::rand()
#include <vector>     //std::vector<>
#include <list>       //std::list<>
#include <iostream>   //std::cout
#include <iterator>   //std::ostream_iterator<>
#include <algorithm>  //std::reverse, std::generate

int main()
{
  std::cout << "Vector v_0 contains the following\n";
  //initializing a vector containing ints with size 10 
  std::vector<int> v_0(10);

  //populating that vector using a range based foor loop and assigning the ierator a random number for each element
  for (auto& v : v_0) {
    v = std::rand();
  }

  //using copy to ierate over the vector printing, via std::ostream_it, the value of each element in a new line 
  std::copy(std::cbegin(v_0), std::cend(v_0), std::ostream_iterator<int>(std::cout, "\n"));

  //creating a list l_0 containing the same elements as v_0
  std::list<int> l_0(std::cbegin(v_0), std::cend(v_0));
  //creating a list l_1 containing the same elements as l_0 (and v_0)
  std::list<int> l_1(std::cbegin(l_0), std::cend(l_0));
  //reversing l_1
  std::reverse(std::begin(l_1), std::end(l_1));
  //using copy as mentioned above, this time for l_1
  std::cout << "\n\nreversed list l_1 contains the following\n";
  std::copy(std::cbegin(l_1), std::cend(l_1), std::ostream_iterator<int>(std::cout, "\n"));

  //sorting l_1 in ascending order
  l_1.sort();

  std::cout << "\n\nl_1 when sorted:\n";
  std::copy(l_1.cbegin(), l_1.cend(), std::ostream_iterator<int>(std::cout, "\n"));

  std::cout << "\n\nv_0 with new values and from back to front\n";
  //overwrites the values in v_0 
  std::generate(std::begin(v_0), std::end(v_0), std::rand);
  std::copy(v_0.crbegin(), v_0.crend(), std::ostream_iterator<int>(std::cout, "\n"));

  return 0;
}