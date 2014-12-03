#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main() {
  std::cout << "Please input numbers : " << std::endl;
  std::istream_iterator<int> in(std::cin), end;
  std::vector<int> vi;
  copy(in, end, back_inserter(vi));
  sort(vi.begin(), vi.end());
  auto vend = unique(vi.begin(), vi.end());

  for(auto beg = vi.begin(); beg != vend; ++beg) {
    std::cout << *beg << " ";
  }
  std::cout << std::endl;

  return 0;
}
