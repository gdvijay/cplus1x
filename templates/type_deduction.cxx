#include<iostream>
typedef struct
{

}ty;
int main()
{
	int n = std::max(7,8);

	 std::pair<int , double> mypair(7,8);
	
	 //alternative use make_xxx
	 auto mypair2 = std::make_pair(7, 9);
	 std::pair mypair1(9,7);
}
