#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  std::vector<int> vi{1, 2, 3 ,4 ,0, 5, 6, 0, 7};
  auto it = find(vi.rbegin(), vi.rend(), 0);

  std::cout << *(it - 1) << " " 
            << *it << " "
            << *(it + 1) << std::endl;

  return 0;
}
