#include <iostream>
#include <functional>


// Before C++ 14 (e.g. C++11) - no support of the feature


// C++ 11 solution
template <typename T>
void f_c11(T x) {
    auto lambda = [](T x){ std::cout << "Received param (C++ 11): " << x << "\n"; };
    lambda(x);
}

template <typename T>
std::function<void(T)> h_c11(T x) {
    // we can return lambda function
    return [](T x){ std::cout << "Received param (C++ 14): " << x << "\n"; };
}

// C++ 14 solution
auto lambda_14 = [](auto x){ std::cout << "Received param (C++ 14): " << x << "\n"; };


// C++ 20 solution
auto f_c20 = []<typename T>(T x) {
    std::cout << "Received param (C++ 20): " << x << "\n";
    return true;
};


int main() {
    f_c11(5);
    f_c11("Hi!");
    auto lambda = h_c11(true);
    lambda(7);

    std::cout << "\n";
    lambda_14(10);

    std::cout << "\n";

    f_c20(9);

    int* buffer = (int*)malloc(sizeof(int));
    *buffer = 17;

    auto read_value = [&buffer]<typename T>() -> T{
        return *(const T*)buffer;
    };

    int received_int = read_value.operator()<int>();
    std::cout << "Received result (C++ 20): " << received_int << "\n";
    free(buffer);

    return 0;
}
