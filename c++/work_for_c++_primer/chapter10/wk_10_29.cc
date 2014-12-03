#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>

int main() {
  std::ifstream ifs("wk_10_27.cc");
  std::istream_iterator<std::string> in(ifs), eof;
  std::vector<std::string> vs(in, eof);
  for(auto beg = vs.begin(); beg != vs.end(); ++beg) {
    std::cout << *beg << " ";
  }
  std::cout << std::endl;

  return 0;
}
