#include<iostream>
struct person {
  std::uint64_t &get_id();
  std::string &get_name();
  std::uint16_t &get_age();

private:
  std::uint64_t id_;
  std::string name_;
  std::uint16_t age_;
};

template <std::size_t I> auto &get(person &p) {
  if constexpr (I == 0)
    return p.get_id();
  else if constexpr (I == 1)
    return p.get_name();
  else if constexpr (I == 2)
    return p.get_age();
}

int main() {}
