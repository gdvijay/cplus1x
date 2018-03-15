#include <iostream>
using namespace std;

// To end the recursion

/*
void print()
{
	cout << __PRETTY_FUNCTION__ << endl;
}
*/

template <typename T, typename... Tn>
void print (T a, Tn...args)
{
	        cout << __PRETTY_FUNCTION__ << endl << "Number of arguments: "<<sizeof...(args)<< endl<<"a = "<< a << endl;

		//if (sizeof..(args) >0)
		if constexpr (sizeof...(args) >0)
		{
			print(args...);
		}
}
int main()
{
	print(10, "test", 89.45);
	return 0;
}
