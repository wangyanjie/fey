#include <iostream>
#include <fstream>
#include <map>
#include <set>

int main() {
  std::map<std::string, int> count_map;
  std::ifstream ifs("wk_11_03.cc");
  std::string s;
  std::set<std::string> exception_string{",", ".", "::", ">>", "<<"};
  while(ifs >> s) {
    if(exception_string.find(s) == exception_string.end()) {
      ++count_map[s];
    }
  }

  for(auto beg = count_map.begin(); beg != count_map.end(); ++beg) {
    std::cout << beg->first << " occurs " << beg->second 
              << ((beg->second > 1) ? " times " : " time ") << std::endl;
  }

  return 0;
}
