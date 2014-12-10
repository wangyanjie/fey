#include <iostream>
#include <vector>
#include <memory>

std::vector<int> *get() {
  return new std::vector<int>;
}

void read(std::vector<int>* pv) {
  for(auto beg = pv->begin(); beg != pv->end(); ++beg) {
    std::cout << *beg << " ";
  }
  std::cout << std::endl;
}

void delete_pv(std::vector<int> *pv) {
  delete pv;
  pv = nullptr;
}
int main() {
  auto pv = get();
  int i = 0;
  while(std::cin >> i) {
    pv->push_back(i);
  }
  read(pv);
  delete_pv(pv);

  return 0;
}
