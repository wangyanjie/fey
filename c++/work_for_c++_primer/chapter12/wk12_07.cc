#include <iostream>
#include <vector>
#include <memory>

std::shared_ptr<std::vector<int>> get() {
  auto spv = std::make_shared<std::vector<int>>();
  int i = 0;
  while(std::cin >> i) {
    spv->push_back(i);
  }

  return spv;
}

void read(std::shared_ptr<std::vector<int>> spv) {
  for(auto beg = spv->begin(); beg != spv->end(); ++beg) {
    std::cout << *beg << " ";
  }
  std::cout << std::endl;
}

int main() {
  auto spv = get();
  read(spv);

  return 0;
}
