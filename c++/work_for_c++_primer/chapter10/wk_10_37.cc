#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main() {
  std::vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> vi_2;
  copy(vi.rbegin() + 3, vi.rend() - 3, std::back_inserter(vi_2));
  for(auto beg = vi_2.begin(); beg != vi_2.end(); ++beg) {
    std::cout << *beg << " ";
  }
  std::cout << std::endl;

  return 0;
}
