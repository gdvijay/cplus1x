#include <iostream>
#include <vector>
#include <map>
#include <string>

template<typename T>
struct myTempl{
    T val;
};

template<typename T>
using func = T (*)(T);

//template<typename T>
//typedef T(*funcptr)(T);
//typedef int(*funcptr)(int); // valid in C++98


int main (int, char const *[])
{
	using templ_i = myTempl<int>;
	templ_i i;
	i.val=4;

	typedef myTempl<float> templ_f;
	templ_f f;
	f.val=5.3;

	func<int> fptr = [](int i) {return i*i;};


	return 0;
}
