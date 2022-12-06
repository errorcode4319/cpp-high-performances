#include <iostream>
#include <vector>
#include <algorithm>

template <typename Container>
auto move_n_elements_to_back_for(Container& c, size_t n) {
    for (size_t i = 0; i < n; i++) {
        auto value = *std::next(c.begin(), i);
        c.emplace_back(std::move(value));
    }
    c.erase(c.begin(), std::next(c.begin(), n));
}

template <typename Container>
auto move_n_elements_to_back(Container& c, size_t n) {
    auto new_begin = std::next(c.begin(), n);
    std::rotate(c.begin(), new_begin, c.end());
}