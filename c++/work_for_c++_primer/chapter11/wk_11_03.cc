#include <iostream>
#include <fstream>
#include <map>

int main() {
  std::map<std::string, int> count_map;
  std::ifstream ifs("wk_11_03.cc");
  std::string s;
  while(ifs >> s) {
    ++count_map[s];
  }

  for(auto beg = count_map.begin(); beg != count_map.end(); ++beg) {
    std::cout << beg->first << " occurs " << beg->second 
              << ((beg->second > 1) ? " times " : " time ") << std::endl;
  }

  return 0;
}
