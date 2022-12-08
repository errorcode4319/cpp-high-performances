#include <iostream>
#include <type_traits>

constexpr auto sum(int x, int y, int z) { return x + y + z; }

const auto ksum = std::integral_constant<int, sum(1, 2, 3)>::value;

int main() {

    auto sum_compile_time = std::integral_constant<int, sum(1,2,3)>::value;
    int x, y, z;
    std::cin >> x >> y >> z;
    
    // Compile Error
    //auto sum_runtime = std::integral_constant<int, sum(x, y, z)>::value;

    

}