#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

int main(int argc, char* argv[])
{
  //4.2

  std::vector<unsigned int> vec(100);
  std::transform (vec.begin(), vec.end(), vec.begin(), [] (unsigned int el) -> auto { return rand() % 101;});
  std::set<unsigned int> st{};

  //4.2.1

  std::cout << "\n4.2.1 - Amount of different elements in the vector:\n\n";
  for (auto i : vec) {
    st.insert(i);
  }
  std::cout << "\tThere are "<< st.size() <<" different elements in the vector\n\n\n";

  //4.2.2

  std::cout << "4.2.2 - All the elements not present in the vector:\n";
  auto itr = st.begin();
  int lnbrk = 10;
  for (int i = 0; i < 101; ++i) {
    if (*itr == i) {
      ++itr;
    } 
    else {
      if (lnbrk == 10) { 
        std::cout << "\n\t";
        lnbrk = 0;
      }
      (*st.rbegin()-1 == i) ? std::cout << i << "\n\n" : std::cout << i << ", ";
      lnbrk++;
    }
  }  
 /*
 for (auto i : vec) {
   std::cout << i << "\n";
 }
 */
  return 0;
}