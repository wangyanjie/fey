#include <iostream>
#include <utility>
#include <vector>
#include <string>

int main() {
  std::cout << "Please input : " << std::endl;
  std::vector<std::pair<std::string, int>> v;
  std::string s;
  int i;
  while(std::cin >> s && std::cin >> i) {
    std::pair<std::string, int> p(s, i);
    v.push_back(p);
  }

  for(auto beg = v.begin(); beg != v.end(); ++beg) {
    std::cout << beg->first << " : " << beg->second << std::endl;
  }

  return 0;
}
