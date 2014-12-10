#include <iostream>
#include <memory>

void process(std::shared_ptr<int> ptr) {}

int main() {
  auto p = new int();
  auto sp = std::make_shared<int>();

  process(sp);
//  process(new int());
//  process(p);
  process(std::shared_ptr<int>(p));

  return 0;
  
  /*
   wk12_12.cc: In function ‘int main()’:
   wk12_12.cc:11:20: error: could not convert ‘(operator new(4ul), (<statement>, ((int*)<anonymous>)))’ from ‘int*’ to ‘std::shared_ptr<int>’
      process(new int());
                       ^
   wk12_12.cc:12:12: error: could not convert ‘p’ from ‘int*’ to ‘std::shared_ptr<int>’
      process(p);
   */
}
