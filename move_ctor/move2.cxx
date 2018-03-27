#include <iostream>
#include <string>

class Sample {
public:
  Sample();
  Sample(const Sample &);
  Sample(Sample &&);
  Sample &operator=(const Sample &);
  Sample &operator=(Sample &&);
};

Sample::Sample() { std::cout << "Inside default cntr:" << this << std::endl; }

Sample::Sample(const Sample &s) {
  std::cout << "Inside copy cntr:" << this << std::endl;
}

Sample::Sample(Sample &&s) {
  std::cout << "Inside move cntr:" << this << std::endl;
}

Sample &Sample::operator=(const Sample &s) {
  std::cout << "inside copy assignment:" << this << std::endl;
  return *this;
}

Sample &Sample::operator=(Sample &&s) {
  std::cout << "inside move assignment:" << this << std::endl;
  return *this;
}

Sample func2() {
  std::cout << "inside func2() - begin" << std::endl;
  return Sample();
}

Sample func() {
  std::cout << "begin func()" << std::endl;
  Sample s; // default cntr
  std::cout << "address:" << &s << std::endl;
  std::cout << "end func()" << std::endl;
  return s;
}

void func3(const Sample s) // func3() and func5() no behavioural change
{
  std::cout << "address:" << &s << std::endl;
  std::cout << "inside func3 - begin" << std::endl;
  return;
}

void func5(const Sample &s) {
  std::cout << "address:" << &s << std::endl;
  std::cout << "inside func5 - begin" << std::endl;
  return;
}

Sample func4(Sample s) {
  std::cout << "inside func4 - begin:" << &s << std::endl;
  return s;
}

Sample func6(const Sample s) {
  std::cout << "inside func6 - begin" << std::endl;
  return s;
}

int main() {
  std::cout << "=======================" << std::endl;
  Sample obj1, obj2; // default cntr             ;
  std::cout << "=======================" << std::endl;
  obj2 = func(); // move assignment               ;
  std::cout << "=======================" << std::endl;
  Sample obj3(func()); // copy elision
  std::cout << "address obj3:" << &obj3 << std::endl;
  ;
  std::cout << "=======================" << std::endl;
  Sample obj4(func2()); // copy elision            ;
  std::cout << "=======================" << std::endl;
  func3(Sample()); // copy elision
  std::cout << "=======================" << std::endl;
  func5(Sample()); // copy elision   	;
  std::cout << "=======================" << std::endl;
  obj2 = obj1; // copy assignment                       ;
  std::cout << "=======================" << std::endl;
  Sample obj5(func4(Sample())); // move ctr --> need to know why
  std::cout << "address obj5:" << &obj5 << std::endl;
  ;
  std::cout << "=======================" << std::endl;
  func4(Sample()); // move ctr
  std::cout << "=======================" << std::endl;
  func6(Sample()); // copy cntr

  return 0;
}
