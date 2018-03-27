//override 
#include<iostream>
struct Base {
  virtual void doSomething(int i) const {
    std::cout << "Base::doSomething with " << i << '\n';
  }
  virtual void doSomethingElse() {
    std::cout << "Base::doSomething with " << '\n';
  }
};

struct Derived : Base {
  virtual void doSomething(int i) const override  {
    std::cout << "Derived::doSomething with " << i << '\n';
  }
  virtual void doSomethingElse(int ) override  {
    std::cout << "Base::doSomething with " << '\n';
  }
};

void callIt(Base& b) {
  b.doSomething(42);
}

int main() {
  Derived d;
  callIt(d); 
}
