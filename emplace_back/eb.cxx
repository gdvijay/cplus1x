#include <iostream>
#include <vector>
using namespace std;

class S {
public:
  S() { puts("S()"); }
  S(int) { puts("S(int)"); }
  ~S() { puts("~S()"); }
  S(const S &) { puts("S(const S&)"); }
  S(S &&) noexcept { puts("S&&"); }
  const S &operator=(const S &s) {
    puts("=");
    return s;
  }
  S &operator=(S &&s) {
    puts("Move =");
    return s;
  }
};

int main() {
  vector<S> s;
  //  s.push_back(S());
  //s.reserve(20);
  s.emplace_back();
  s.emplace_back(6);
}
