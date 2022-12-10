#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
struct InProxy { const T& val_; };

struct InTag {};
constexpr static auto in = InTag{}; 

template <typename T>
auto operator<(const T& val, const InTag&) {
    return InProxy<T>{val};
}

template <typename Range, typename T>
auto operator>(const InProxy<T>& proxy, const Range& r) {
    const auto& v = proxy.val_;
    return std::find(r.begin(), r.end(), v) != r.end();
}

int main() {
    auto numbers = std::vector<int> {1,2,3,4,5};
    bool has_num = 3 <in> numbers;
    std::cout << "Has Number: " << std::boolalpha << has_num << std::endl;
}