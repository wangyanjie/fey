#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

bool check_size(const std::string &s, std::string::size_type sz) {
  return s.length() > sz;
}

int main() {
  std::vector<std::string> vs{"wang", "yan", "jie", "chongqing", "university"};
  std::string s_aim{"yanjie"};
  auto it = find_if(vs.begin(), vs.end(), 
                    bind(check_size, std::placeholders::_1, s_aim.length()));
  if(it != vs.end()) {
    std::cout << *it << std::endl;
  }

  return 0;
}

