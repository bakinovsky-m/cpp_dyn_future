#include "header.hpp"
#include <future>
extern "C" {
  std::future<int> fut(int i) {
    return std::async([i]{return i + 1;});
  }
  
  S s_foo() {
    S s;
    s.i = 321;
    return s;
  }
int foo(int) {
  return 123;
}
}  
