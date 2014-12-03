#include <iostream>
#include <vector>

int main() {
  std::vector<int> vi{1, 2, 3, 4, 5};
  for(auto end = vi.end() - 1; end != vi.begin(); --end) {
    std::cout << *end << " ";
  }
  std::cout << *vi.begin() << std::endl;
  
  return 0;
}
