#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <map>


int main() {
  std::ifstream ifs("wk_11_09.cc");
  std::list<int> list_line;
  std::map<std::string, std::list<int>> map_string;

  int line = 0;
  std::string s_line;
  while(getline(ifs, s_line)) {
    ++line;
    std::istringstream iss(s_line);
    std::string s;
    while(iss >> s) {
      std::cout << s;
      map_string[s].push_front(line);
    }
  }

  for(auto beg = map_string.begin(); beg != map_string.end(); ++beg) {
    std::cout << beg->first << " occurs : " << std::endl;
    for(auto lbeg = beg->second.begin(); lbeg != beg->second.end(); ++lbeg) {
      std::cout << *lbeg << ", "; 
    }
    std::cout << std::endl;
  }

  return 0;
}
