
#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;


void passValueGetDatatype()
{
	auto x = 4;
	cout <<  "type of 4 is "<<typeid(x).name() << endl;
	
	auto y = 3.37;
	cout<<  "type of 3.37 is "<<typeid(y).name() << endl;
	
	auto ptr = &x;
	std::cout<< "type of &x(int x) "<<typeid(ptr).name() << endl;
		
	auto z = {1,2};
	std::cout<<" type of z "<<typeid(z).name() <<endl;
	
        auto a{1};
        std::cout<<" type of a "<<typeid(a).name() <<endl;
        
   	//auto{1,2};//ERRor direct-list-initialization of ‘auto’ requires exactly one element
   	
}


void autoExampleWithVector()
{
	std::cout<<"\n Example\n";
	std::vector<int> v = {0, 1, 2, 3, 4, 5};
 
	for (const int& i : v) // access by const reference
        	std::cout << i << ' ';
	std::cout << '\n';
	for (auto i : v) // access by value, the type of i is int
        	std::cout << i << ' ';
	std::cout << '\n';

}

void deductionRules()
{
	int x = int();
	const int& y = x;
	auto z = y;//type of z is int , because auto will strip out const and reference

	const int c = 0;
	auto& rc = c;
	//rc = 44; // ERROR
	
      

}

int foo()
	{return 0;}

int main()
{

	passValueGetDatatype();
	autoExampleWithVector();
	deductionRules();

	auto x1 = foo(); // x1 : int
	const auto& x2 = foo(); // x2 : const int&
	//auto& x3 = foo(); //ERROR Because a reference has to refer to an object in the memory, and for an object to exist, it has to be created first. Since the object is unnamed, it is a temporary object. It has no name. 
	//int && z = 12; //C+11 only  // rvalue reference


	//Multivalue declearation
	int i;
	auto a = 1, *b = &i;
	//auto a= 1, b = 2.2;//ERROR ovi


}

//template<typename T1, typename T2>

//auto sum(T1 & t1, T2 & t2) -> decltype(t1 + t2){

//return t1 + t2;

//}
