#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
  std::vector<std::string> vs{"wangyanjie", "1992", "chongqing", "ie"};
  int num = count_if(vs.begin(), vs.end(),
                     [](std::string s) { return s.length() > 6; });
  std::cout << num << std::endl;

  return 0;
}
