#include <iostream>
#include <deque>
#include <iterator>

int main() {
  std::deque<int> di_1{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::deque<int> di_2, di_3, di_4;

  copy(di_1.begin(), di_1.end(), back_inserter(di_2));
  copy(di_1.begin(), di_1.end(), front_inserter(di_3));
  copy(di_1.begin(), di_1.end(), inserter(di_4, di_4.begin()));

  std::cout << "back_inserter : ";
  for(auto beg = di_4.begin(); beg != di_4.end(); ++beg) {
    std::cout << *beg << " ";
  }
  std::cout << std::endl;

  std::cout << "front_inserter : ";
  for(auto beg = di_3.begin(); beg != di_3.end(); ++beg) {
    std::cout << *beg << " ";
  }
  std::cout << std::endl;

  std::cout << "inserter : ";
  for(auto beg = di_4.begin(); beg != di_4.end(); ++beg) {
    std::cout << *beg << " ";
  }
  std::cout << std::endl;

  return 0;
}
