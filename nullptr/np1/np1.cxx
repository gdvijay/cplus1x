// C++ program to demontrate problem with NULL
#include <bits/stdc++.h>
using namespace std;

// function with integer argument
int fun(int N) { cout << "fun(int)"; } // ERROR Ambiguous

// Overloaded function with char pointer argument
int fun(char *s) { cout << "fun(char *)"; }

int main() {
  // Ideally, it should have called fun(char *),
  // but it causes compiler error.
  fun(nullptr);
  //    fun(NULL);  //ERROR Ambiguous
}
