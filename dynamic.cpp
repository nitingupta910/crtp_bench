#include "common.h"

class DynamicInterface {
public:
  virtual void tick(uint64_t n) = 0;
  virtual uint64_t getvalue() = 0;
};

class DynamicImplementation : public DynamicInterface {
  uint64_t counter;

public:
  DynamicImplementation()
    : counter(0) {
  }

  virtual void tick(uint64_t n) {
    counter += n;
  }

  virtual uint64_t getvalue() {
    return counter;
  }
};

void run_dynamic(DynamicInterface* obj) {
  for (unsigned i = 0; i < N; ++i) {
    for (unsigned j = 0; j < i; ++j) {
      obj->tick(j);
    }
  }
}

int main() {
  run_dynamic(new DynamicImplementation());
  return 0;
}
