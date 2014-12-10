#include <iostream>
#include <string>
#include <vector>
#include "StrBlob.h"
#include "StrBlobPtr.h"

int main() {
  StrBlob sb;
  std::string s;
  
  while(std::cin >> s) {
    sb.push_back(s);
  }

  std::cout << "front of StrBlob : " << sb.front() << std::endl;
  std::cout << "back of StrBlob : " << sb.back() << std::endl;

  StrBlobPtr sbp(sb);
  sbp.incr();
  std::cout << "second element : " << sbp.deref() << std::endl;

  return 0;
}
