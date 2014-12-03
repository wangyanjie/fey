#include <iostream>
#include <vector>
#include <iterator>

int main() {
  std::vector<int> vi{1, 2, 3, 4, 5, 6};
  for(auto rbeg = vi.rbegin(); rbeg != vi.rend(); ++rbeg) {
    std::cout << *rbeg << " ";
  }
  std::cout << std::endl;

  return 0;
}
