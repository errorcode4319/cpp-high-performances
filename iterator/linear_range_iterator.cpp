#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

template <typename T>
auto get_step_size(T start, T stop, size_t num_values) {
  assert(num_values >= 2);
  return (stop - start) / (num_values-1);
}

template<typename T>
class LinearRangeIterator {

public:
    using difference_type = size_t;
    using value_type = T;
    using reference = T;
    using pointer = void;
    using iterator_category = std::bidirectional_iterator_tag;

    LinearRangeIterator(T start, T step_size, size_t idx) 
    :start_{start}, step_size_{step_size}, idx_{idx} {}

    auto operator==(const LinearRangeIterator& lri) const {
        return idx_ == lri.idx_;
    }

    auto operator!=(const LinearRangeIterator& lri) const {
        return !(*this == lri);
    }

    auto& operator++() { ++idx_; return *this; }
    auto& operator--() { --idx_; return *this; }
    auto operator*() const { return start_ + (idx_ * step_size_); }

private:
    size_t idx_{};
    T start_{};
    T step_size_{};

};

template<typename T>
class LinearRange {
    using iterator = LinearRangeIterator<T>;

public:
    LinearRange(T start, T stop, size_t num_values)
    : start_{start}
    , step_size_{get_step_size(start, stop, num_values)}
    , num_values_{num_values} 
    {}

    auto begin() const { return iterator{start_, step_size_, 0}; }
    auto end() const { return iterator{start_, step_size_, num_values_}; }

private:
    T start_{};
    T step_size_{};
    size_t num_values_{};

};

template<typename T>
auto make_linear_range(T start, T stop, size_t n) {
    return LinearRange<T>{ start, stop, n};
}

int main(int argc, char* argv[]) {
    for (auto t: make_linear_range(0.0, 1.0, 4)) { std::cout << t << ", "; }
}