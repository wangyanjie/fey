#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

int main() {
  std::ifstream ifs_rule("rule.txt");
  if(! ifs_rule) {
    return 1;
  }
  std::string s_rule, s_mean;
  std::map<std::string, std::string> map_rule;
  while(ifs_rule >> s_rule) {
    char c;
    ifs_rule.get(c);
    if(getline(ifs_rule, s_mean)) {
      map_rule.insert({s_rule, s_mean});
    }
  }
  ifs_rule.close();
  
  std::ifstream ifs_aim("aim.txt");
  if(! ifs_aim) {
    return -2;
  }
  std::string s_aim, s_line;
  std::vector<std::string> vs;
  while(getline(ifs_aim, s_line)) {
    std::istringstream iss(s_line);
    while(iss >> s_aim) {
      auto k = map_rule.find(s_aim);
      if(k != map_rule.end()) {
        vs.push_back(k->second);
      } else {
        vs.push_back(s_aim);
      }
    }
    vs.push_back(std::string("\n"));
  }

  for(auto beg = vs.begin(); beg != vs.end(); ++beg) {
    if(*beg == "\n") {
      std::cout << std::endl;
    } else {
      std::cout << *beg << " ";
    }
  }
  std::cout << std::endl;

  return 0;
}
