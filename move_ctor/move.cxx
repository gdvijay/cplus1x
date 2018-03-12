#include<iostream>


class S { 
public:
  S(const S & r){std::cout<<"Copy ctr"<<std::endl;}
  S(S && r){std::cout<<"Move ctr"<<std::endl;}
  S(){std::cout<<"Default ctr"<<std::endl;}
  S& operator=(const S& s){std::cout<<"Overloaded ="<<std::endl; return *this;}
  S& operator=(S&& s){std::cout<<"Overloaded move ="<<std::endl;return *this;}
  int i;
};
S fun()
{
  std::cout<<"inside fun() +"<<std::endl;
  S tObj;
  std::cout<<"inside fun() -"<<std::endl;
  return tObj;
}

int main()
{
 S obj1;
 std::cout<<"================"<<std::endl;
 S obj2(obj1);
 std::cout<<"================"<<std::endl;
 S obj3(std::move(obj1));
 std::cout<<"================"<<std::endl;
 S obj4(fun());
 std::cout<<"================"<<std::endl;
 S obj5 = fun();
 std::cout<<"================"<<std::endl;
 return 0;
}

