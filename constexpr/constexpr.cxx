//Added in C++11
//-std=c++17
//-std=c++14
//-std=c++11

//https://www.tutorialspoint.com/compile_cpp11_online.php
//http://en.cppreference.com/w/cpp/language/constexpr
//https://godbolt.org/

#include <iostream>
using namespace std;

constexpr int multiply( int x, int y)
{
	return (x*y);
}

//error only in c++11. 
//error: invalid return type ‘void’ of constexpr function
constexpr void test()
{

}

/*
//error in c++11, c++14, c++17
int product( int x, int y)
{
	return (x*y);
}
constexpr int multiply_1( int x, int y)
{
    //error: call to non-constexpr function
	return product(x, y);
}
*/

int main ()
{
	int x = multiply(10,20);
	cout << "x =" << x << endl << "y =" << y <<endl;
	return 0;
}
