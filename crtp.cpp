#include "common.h"

#include <iostream>

template <typename Implementation>
class CRTPInterface {
public:
  void tick(uint64_t n) {
    impl().tick(n);
  }

  uint64_t getvalue() {
    return impl().getvalue();
  }
private:
  Implementation& impl() {
    return *static_cast<Implementation*>(this);
  }
};

class CRTPImplementation : public CRTPInterface<CRTPImplementation> {
  uint64_t counter;
public:
  CRTPImplementation()
    : counter(0) {
  }

  void tick(uint64_t n) {
    counter += n;
  }

  uint64_t getvalue() {
    return counter;
  }
};

template <typename Implementation>
void run_crtp(CRTPInterface<Implementation>* obj) {
  for (unsigned i = 0; i < N; ++i) {
    for (unsigned j = 0; j < i; ++j) {
      obj->tick(j);
    }
  }
}

int main() {
        auto obj = new CRTPInterface<CRTPImplementation>();
        run_crtp(obj);
        std::cout << "counter=" << obj->getvalue() << "\n";
        return 0;
}
