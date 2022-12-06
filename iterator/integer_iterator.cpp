#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

// https://en.cppreference.com/w/cpp/iterator/iterator_traits


class IntIterator{
public:
    using difference_type = size_t;
    using value_type = int;
    using reference = int&;
    using pointer = int*;
    using iterator_category = std::bidirectional_iterator_tag;

    IntIterator(int v): v_{v} {}
    auto operator==(const IntIterator& it) const { return v_ == it.v_; }
    auto operator!=(const IntIterator& it) const { return !(*this == it);}
    auto& operator*() const { return v_; }
    auto& operator++() { ++v_; return *this; }
    auto& operator--() { --v_; return *this; }

private:
    int v_{};
};

template<typename Iterator>
auto iterator_distance(Iterator a, Iterator b) {
    using Traits = typename std::iterator_traits<Iterator>;
    using Category = typename Traits::iterator_category;
    using Difference = typename Traits::difference_type;

    constexpr auto is_random_access = 
        std::is_same_v<Category, std::random_access_iterator_tag>;
    if constexpr(is_random_access) {
        return b - a;
    }
    else {
        auto steps = Difference{};
        while(a != b) { ++steps; ++a; }
        return steps;
    }
}

int main(int argc, char* argv[]) {
    auto numbers = std::vector<int>{};
    std::copy(IntIterator(5), IntIterator(12), std::back_inserter(numbers));
    for(auto n: numbers) {
        std::cout << n << ' ';
    }
    std::cout << '\n';
    for(auto it = IntIterator{12}; it != IntIterator{-1}; --it) {
        std::cout << *it << " ";
    }
}