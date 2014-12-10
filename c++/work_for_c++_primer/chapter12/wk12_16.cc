#include <memory>

int main() {
  std::unique_ptr<int> up;
 // auto up_2 = up;

  return 0;

  /*
   wk12_16.cc: In function ‘int main()’:
   wk12_16.cc:5:15: error: use of deleted function ‘std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = int; _Dp = std::default_delete<int>]’
      auto up_2 = up;
                  ^
   In file included from /usr/include/c++/4.8/memory:81:0,
                    from wk12_16.cc:1:
   /usr/include/c++/4.8/bits/unique_ptr.h:273:7: error: declared here
          unique_ptr(const unique_ptr&) = delete;
          ^
   */
}
