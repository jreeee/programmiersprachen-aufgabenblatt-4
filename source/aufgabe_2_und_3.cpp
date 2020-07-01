#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

int main(int argc, char* argv[])
{
 std::vector<unsigned int> vec(100);
 std::transform (vec.begin(), vec.end(), vec.begin(), [] (unsigned int el) -> auto { return rand() % 101;});
 
 for (auto i : vec) {
   std::cout << i << "\n";
 }
  return 0;
}