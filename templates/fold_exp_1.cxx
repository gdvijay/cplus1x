#include <iostream>

auto old_sum(){
    return 0;
}

template<typename T1, typename... T>
auto old_sum(T1 s, T... ts){
    return s + old_sum(ts...);
}

auto old_mul(){
    return 1;
}

template<typename T1, typename... T>
auto old_mul(T1 s, T... ts){
    return s + old_sum(ts...);
}

template<typename... T>
auto fold_sum_1(T... s){
    return (s + ...);
}

template<typename... T>
auto fold_sum_2(T... s){
    return (s + ... + 10);
}

template<typename... T>
auto fold_mul_1(T... s){
    return (s * ...);
}
//(pack op ...init)
template<typename... T>
auto fold_mul_2(T... s){
    return (s * ... * 10);
}

//typedef std::integral_constant<int, 2> two_t;

template<std::size_t... V>
struct fold_tmp_mul : std::integral_constant<std::size_t, (V * ...)> {};

template<bool... B>
struct fold_and : std::integral_constant<bool, (B && ...)> {};

template<bool... B>
struct fold_or : std::integral_constant<bool, (B || ...)> {};

template<typename ...Args>
void print_1(Args&&... args) {
    (std::cout << ... <<args) << '\n';
}

template<typename ...Args>
void print_2(Args&&... args) {
    (print_1(args), ...);
}

int main(){
    std::cout << "old_sum(1,2,3,4,5) "<<old_sum(1, 2, 3, 4, 5) << "\n\n";
    std::cout << "old_sum() "<<old_sum() << "\n\n";

    std::cout << "fold_sum_1(1,2,3,4,5) "<<fold_sum_1(1, 2, 3, 4, 5) <<"\n\n";
    std::cout << "fold_sum_2(1,2,3,4,5) "<<fold_sum_2(1, 2, 3, 4, 5) <<"\n\n";
    std::cout << fold_sum_1(1) <<"\n\n";
 //   std::cout << fold_sum_2() <<"\n\n";
    
    std::cout << "old_mul(1,2,3,4,5) "<<old_mul(1, 2, 3, 4, 5) <<"\n\n";
    std::cout << "old_mul() "<<old_mul() <<"\n\n";

    std::cout << "fold_mul_1(1,2,3,4,5) "<<fold_mul_1(1, 2, 3, 4, 5) << "\n\n";
    std::cout << "fold_mul_2(1,2,3,4,5) "<<fold_mul_2(1, 2, 3, 4, 5) << "\n\n";
//    std::cout << fold_mul_1() << "\n\n";
//    std::cout << fold_mul_2() <<"\n\n";

    std::cout << "fold_tmp_mul<1,2,3,4,5> "<<fold_tmp_mul<1, 2, 3, 4, 5>::value <<"\n\n";

    std::cout << "fold_and<true, false, true> "<<fold_and<true, false, true>::value <<"\n\n";
    std::cout << "fold_or<true, false, true> "<<fold_or<true, false, true>::value <<"\n\n";

    print_1(1,"cout",'Z',1.0f);
    //print_2(1,"cout",'Z',1.0f);

    return 0;
}
