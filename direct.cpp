#include "common.h"

#include <iostream>

class DynamicImplementation {
  uint64_t counter;

public:
  DynamicImplementation()
    : counter(0) {
  }

  // adding virtual here makes it as slow as the dynamic version
  void tick(uint64_t n) {
    counter += n;
  }

  uint64_t getvalue() {
    return counter;
  }
};

void run_direct(DynamicImplementation* obj) {
  for (unsigned i = 0; i < N; ++i) {
    for (unsigned j = 0; j < i; ++j) {
      obj->tick(j);
    }
  }
}

int main() {
  auto obj = new DynamicImplementation();
  run_direct(obj);
  std::cout << "counter=" << obj->getvalue() << "\n";
  return 0;
}
