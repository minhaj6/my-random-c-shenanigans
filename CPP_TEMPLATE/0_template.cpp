// CPPCon 2016 Template normal programming
#include<iostream>

template<class T>
T add(T a, T b) {
    return a+b;
}

int main() {
    std::cout << add<int>(5, 4) << std::endl;
}