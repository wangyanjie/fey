#include <iostream>
#include <set>
#include <algorithm>

int main() {
  std::set<int> s{2, 3, 4, 5, 6};
  auto it_upper_0 = s.upper_bound(0);
  auto it_upper_3 = s.upper_bound(3);
  auto it_upper_7 = s.upper_bound(7);
  std::cout << "upper_0 : " << *it_upper_0 <<std::endl;
  std::cout << "upper_3 : " << *it_upper_3 <<std::endl;
  std::cout << "upper_7 : " << *it_upper_7 <<std::endl;

  auto it_lower_0 = s.lower_bound(0);
  auto it_lower_3 = s.lower_bound(3);
  auto it_lower_7 = s.lower_bound(7);
  std::cout << "lower_0 : " << *it_lower_0 <<std::endl;
  std::cout << "lower_3 : " << *it_lower_3 <<std::endl;
  std::cout << "lower_7 : " << *it_lower_7 <<std::endl;

  auto it_equal_0 = s.equal_range(0);
  auto it_equal_3 = s.equal_range(3);
  auto it_equal_7 = s.equal_range(7);
  std::cout << "equal_0" << std::endl;
  for(auto beg = it_equal_0.first; beg != it_equal_0.second; ++beg)
    std::cout << *beg << " ";
  std::cout << std::endl;
  std::cout << "equal_3" << std::endl;
  for(auto beg = it_equal_3.first; beg != it_equal_3.second; ++beg)
    std::cout << *beg << " ";
  std::cout << std::endl;
  std::cout << "equal_7" << std::endl;
  for(auto beg = it_equal_6.first; beg != it_equal_6.second; ++beg)
    std::cout << *beg << " ";
  std::cout << std::endl;
  
  return 0;
}
