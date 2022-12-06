#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main(int argc, char* argv[]) {
    auto vals = std::vector<int>{1, 2, 3, 4};
    auto squared_vec = std::vector<int>{};
    std::transform(vals.begin(), vals.end(), std::back_inserter(squared_vec), [](int v){ return v * v;});

    auto squared_set = std::set<int>{};
    std::transform(vals.begin(), vals.end(), std::inserter(squared_set, squared_set.end()), [](int v) { return v * v;});

    for(auto n: squared_vec) {
        std::cout << n << ' ';
    }
    std::cout << '\n';
    for(auto n: squared_set) {
        std::cout << n << ' ';
    }
    std::cout << '\n';

}