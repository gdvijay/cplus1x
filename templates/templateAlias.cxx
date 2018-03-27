#include <iostream>
#include <vector>
#include <map>
#include <string>

template <typename T> 
using vec_x = std::vector<T>; 


using byte    = unsigned char; 
using pbyte   = unsigned char *; 
using array_t = int[10]; 
using fn      = void(byte, double); 

void func(byte b, double d) { /*...*/ } 

int main()
{
	vec_x<int>           vi;
	vi.push_back(1);

        byte b {42}; 
        pbyte pb = new byte[10] {0}; 
        array_t a{0,1,2,3,4,5,6,7,8,9}; 
        fn* f = func;

}
