#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
struct ContainsProxy { 
    ContainsProxy(const T& value): value_(value) {}
    const T& value_; 
};

template <typename Range, typename T>
auto operator| (const Range& r, const ContainsProxy<T>& proxy) {
    const auto& v = proxy.value_;
    return std::find(r.begin(), r.end(), v) != r.end();
}

template <typename T>
auto contains(const T& v) { return ContainsProxy<T>{v}; }

int main() {
    auto numbers = std::vector<int>{1, 3, 5, 7, 9};
    bool has_number = numbers | contains(7);
    
    auto names = std::vector<std::string>{"A", "B", "C"};
    bool has_name = names | contains("C");

}