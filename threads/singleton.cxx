#include <iostream>
#include <thread>

class X {
public:
  static X get_instance() {
    static X instance;
    std::cout << "Address of instance : " << &instance << std::endl;
    return instance;
  }
};
class Y {
public:
  Y * instance;
  Y* get_instance() {
    if (!instance)
      instance = new Y(); 
    std::cout << "Address of instance : " << instance << std::endl;
    return instance;
  }
};

void thread_function() {
  X::get_instance();
  Y y;
y.get_instance();
  for (int i = 0; i < 10000; i++)
    ;
  std::cout << "thread function Executing" << std::endl;
}

void thread_function2() {
  X::get_instance();
  Y y;
  y.get_instance();
  for (int i = 0; i < 10000; i++)
    ;
  std::cout << "thread2 function Executing" << std::endl;
}

int main() {

  std::thread threadObj(thread_function);
  std::thread threadObj2(thread_function2);
  for (int i = 0; i < 10000; i++)
    ;
  std::cout << "Display From MainThread" << std::endl;
  threadObj.join();
  threadObj2.join();
  std::cout << "Exit of Main function" << std::endl;
  return 0;
}
