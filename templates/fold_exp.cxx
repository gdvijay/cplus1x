#include<iostream>

template<typename... T>
auto fold_sum_2(T... s){
    return (0 + ... + s);
}


int main()
{
	int sum = fold_sum_2(1,2,3,3);
	std::cout<<"\n\nsum "<<sum<<"\n\n";

}
