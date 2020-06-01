#include <iostream>
#include <future>
#include <dlfcn.h>

using namespace std;

#include "header.hpp"

int main() {
  void *handle = dlopen("liblib.so", RTLD_LAZY);
  if(!handle) {
    cout << "err: " << dlerror() << endl;
    return 1;
  }
  int (*foo)(int i);
  foo = (int(*)(int))dlsym(handle, "foo");
  cout << foo(123) << endl;

  S (*s_foo)();
  s_foo = (S(*)())dlsym(handle, "s_foo");
  cout << s_foo().i << endl;

  std::future<int> (*fut)(int i);
  fut = (std::future<int>(*)(int))dlsym(handle, "fut");
  cout << fut(123).get() << endl;
  
  dlclose(handle);
}
