#include <iostream>
#include <iomanip>

#define UNARY_LEFT_FOLD(NAME, OP)   \
template<typename... Args>          \
auto NAME(Args&&... args) {         \
  return (... OP args);             \
}

UNARY_LEFT_FOLD(add,+);
UNARY_LEFT_FOLD(sub,-);
UNARY_LEFT_FOLD(mul,*);
UNARY_LEFT_FOLD(divide,/);
UNARY_LEFT_FOLD(mod,%);
UNARY_LEFT_FOLD(bxor,^);
UNARY_LEFT_FOLD(band,&);
UNARY_LEFT_FOLD(bor,|);
UNARY_LEFT_FOLD(assign,=);
UNARY_LEFT_FOLD(lt,<);
#ifndef __clang__ 
UNARY_LEFT_FOLD(gt,>); 
UNARY_LEFT_FOLD(rshift,>>); 
#endif
UNARY_LEFT_FOLD(lshift,<<);
UNARY_LEFT_FOLD(addassign,+=);
UNARY_LEFT_FOLD(subassign,-=);
UNARY_LEFT_FOLD(mulassign,*=);
UNARY_LEFT_FOLD(divassign,/=);
UNARY_LEFT_FOLD(modassign,%=);
UNARY_LEFT_FOLD(bxorassign,^=);
UNARY_LEFT_FOLD(bandassign,&=);
UNARY_LEFT_FOLD(borassign,|=);
UNARY_LEFT_FOLD(lshiftassign,<<=);
UNARY_LEFT_FOLD(rshiftassign,>>=);
UNARY_LEFT_FOLD(equals,==);
UNARY_LEFT_FOLD(nequals,!=);
UNARY_LEFT_FOLD(lte,<=);
UNARY_LEFT_FOLD(gte,>=);
UNARY_LEFT_FOLD(land,&&);
UNARY_LEFT_FOLD(lor,||);
UNARY_LEFT_FOLD(objptrmem,.*);
UNARY_LEFT_FOLD(ptrptrmem,->*);

template<typename... Args>
auto comma(Args&&... args) {
  return (... , args);
}


int main(void) 
{

  std::cout << std::boolalpha;
  std::cout << "add "            << add(1)           << " " << add(1,2,3)        << "\n";// 1
  std::cout << "sub "            << sub(1)           << " " << sub(1,2,3)        << "\n";
  std::cout << "mul "            << mul(1)           << " " << mul(1,2,3)        << "\n";
  std::cout << "divide "         << divide(1)        << " " << divide(18,2,3)    << "\n";
  std::cout << "mod "            << mod(1)           << " " << mod(23, 3,2)      << "\n";
  std::cout << "bxor "           << bxor(1)          << " " << bxor(1,2,4)       << "\n";
  std::cout << "band "           << band(1)          << " " << band(1,3,7)       << "\n";
  std::cout << "assign "         << assign(1)        << " " << assign(1,2,4)     << "\n";
    
  auto a = 99; 
  std::cout << "assign-a "       << assign(a);
  std::cout << " "               << assign(a,2,4);
  std::cout << " "               << a << "\n";
    
  #ifndef __clang__ 
  std::cout << "gt "             << gt(1)          << " " << gt(3,2,0)         << "\n"; 
  std::cout << "rshift "         << rshift(1)        << " " << rshift(32,2,2)    << "\n"; 
  #endif

  std::cout << "lt "             << lt(1)            << " " << lt(1,2,-1)         << "\n"; 
  std::cout << "lshift "         << lshift(1)        << " " << lshift(1,2,3)     << "\n";
  std::cout << "addassign "      << addassign(1)     << " " << addassign(2,3,2)  << "\n";
  std::cout << "subassign "      << subassign(1)     << " " << subassign(7,2)    << "\n";
  std::cout << "mulassign "      << mulassign(1)     << " " << mulassign(2,3,2)  << "\n";
  std::cout << "divassign "      << divassign(1)     << " " << divassign(7,2)    << "\n";
  std::cout << "modassign "      << modassign(1)     << " " << modassign(23,3,2) << "\n";
  std::cout << "bxorassign "     << bxorassign(1)    << " " << bxorassign(7,2)   << "\n";
  std::cout << "bandassign "     << bandassign(1)    << " " << bandassign(7,6)   << "\n";
  std::cout << "borassign "      << borassign(1)     << " " << borassign(1,2,4,8) << "\n";
  std::cout << "lshiftassign "   << lshiftassign(1)  << " " << lshiftassign(8,2)  << "\n";
  std::cout << "rshiftassign "   << rshiftassign(1)  << " " << rshiftassign(16,1,2)   << "\n";
  std::cout << "equals "         << equals(1)        << " " << equals(8,3,2)     << "\n";
  std::cout << "nequals "        << nequals(1)       << " " << nequals(7,2,0)    << "\n";
  std::cout << "lte "            << lte(1)           << " " << lte(7,2,0)        << "\n";
  std::cout << "gte "            << gte(1)           << " " << gte(7,3,1)        << "\n";
  std::cout << "land "           << land()           << " " << land(7,2)         << "\n";
  std::cout << "lor "            << lor()            << " " << lor(7,2)          << "\n";
  std::cout << "comma "          << comma(1)         << " " << comma(8,3,2,7,5,6,9)      << "\n";
  

}
