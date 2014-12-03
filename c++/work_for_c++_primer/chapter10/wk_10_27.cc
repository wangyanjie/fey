#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main() {
  std::vector<int> vi_1{1, 31, 2, 2, 3, 6, 7, 5, 5, 6, 7};
  std::vector<int> vi_2;

  sort(vi_1.begin(), vi_1.end());
  unique_copy(vi_1.begin(), vi_1.end(), back_inserter(vi_2));

  for(auto beg = vi_2.begin(); beg != vi_2.end(); ++beg) {
    std::cout << *beg << " ";
  }
  std::cout << std::endl;

  return 0;
}
