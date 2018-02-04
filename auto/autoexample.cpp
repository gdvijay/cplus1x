#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;


void passValueGetDatatype()
{
	auto x = 4;
	auto y = 3.37;
	auto ptr = &x;
	cout <<  "type of 4 is "<<typeid(x).name() << endl
       	<<  "type of 3.37 is "<<typeid(y).name() << endl
   	<< "type of &x(int x) "<<typeid(ptr).name() << endl;
}

void autoExampleWithVector()
{
	cout<<"\n Example\n";
	vector<int> v = {0, 1, 2, 3, 4, 5};
	for (const int& i : v) // access by const reference
        	cout << i << ' ';
		cout << '\n';
	for (auto i : v) // access by value, the type of i is int
        	cout << i << ' ';
        	cout << '\n';
}

int main()
{
	passValueGetDatatype();
	autoExampleWithVector();
}
