#include <vector>     //std::vector<>
#include <set>        //std::set<>
#include <map>        //std::map<>

#include <algorithm>  //std::tansform()
#include <cstdlib>    //std::rand() / std::srand()
#include <ctime>      //std::time()

#include <iostream>   //std::cout

int main(int argc, char* argv[])
{
  //4.2

  /*
  Initializing the vector "vec" of the size 100, getting a random seed for rand() using srand() 
  and populating the vector with random numbers from 0 to 100, then Initializing the set "st".
  */
  std::vector<unsigned int> vec(100);
  std::srand(std::time(0));
  std::transform (vec.begin(), vec.end(), vec.begin(), [] (unsigned int el) -> auto { return rand()% 101;});
  std::set<unsigned int> st{};

  //4.2.1

  /*
  All of the Vector values are inserted into the set. Beacuse of the properties of set every digit
  that appears multiple times is simply overwritten and you end up with a sorted set conatining 
  every different digit "vec" contains. Hence the size of this set is the amount of different digits in vec.
  */
  std::cout << "\n4.2.1 - Amount of different elements in the vector:\n\n";
  for (auto i : vec) {
    st.insert(i);
  }
  std::cout << "\tThere are "<< st.size() <<" different elements in the vector\n\n";

  //4.2.2

  /*
  Since the digits in the set are sorted in ascending order, one can simply use a for loop from 0 to 100
  and check if the digit is present in "st". If not it gets printed out. Since that didn't look too good
  I used the int lnbrk to handle linebreaks and display the digits a bit nicer.
  */
  std::cout << "\n4.2.2 - All the elements not present in the vector:\n";
  auto itr = st.begin();
  unsigned int lnbrk = 0;
  for (unsigned int i = 0; i < 101; ++i) {
    if (*itr == i) {
      ++itr;
    } 
    else {
      if ((lnbrk % 10) == 0 ) { 
        std::cout << "\n\t";
      }
      (100 - lnbrk == st.size()) ? std::cout << i << "\n\n" : std::cout << i << ", ";
      lnbrk++;
    }
  }

  //4.3

  /*
  Initializing the map "mp" and filling it with keys from 0 to 100, each having the value 0.
  Iterating over the vector using a for loop and generating for each cycle a map iterator
  pointing to the key that corresponds with the value of vec and incrementing its value by one.
  */
  std::cout << "\n4.3 - Elements and their number of occurrences\n";
  std::map<unsigned int, unsigned int> mp{};
  for (int i = 0; i < 101; ++i) {
    mp.insert(std::pair<unsigned int, unsigned int>(i, 0));
  }
  for (auto i : vec) {
    mp.find(i)->second++;
  }

  /*
  since the output wasn't nice to look at I wrote a small print-function utilizing lnbrk again.
  Every element and its number of occurences is displayed in rows of ten, | element : occurence(s) |
  */
  lnbrk = 0;
  for (auto i : mp) {
    if ((lnbrk % 10) == 0 ) { 
        std::cout << "\n\t| ";
      }
    if (lnbrk < 10) {
      std::cout << i.first << "  : " << i.second << " | ";
    }
    if ((lnbrk > 9) && (lnbrk < 100)) {
      std::cout << i.first << " : " << i.second << " | ";
    }
    if (lnbrk == 100) {
      std::cout << i.first << ": " << i.second << " |\n\n";
    }
    lnbrk++;
  }
  return 0;
}