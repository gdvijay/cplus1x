#include <iostream>
using namespace std;

template <typename T> 
void print (T a);


template <typename T>
void print (T a)
{
        cout << __PRETTY_FUNCTION__ << endl;
}


