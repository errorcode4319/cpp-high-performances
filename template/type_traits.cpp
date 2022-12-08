#include <iostream>
#include <type_traits>



auto sign_func = [](const auto& v) -> int {
    using ReferenceType = decltype(v);
    using ValueType = std::remove_reference_t<ReferenceType>;
    if (std::is_unsigned_v<ValueType>) {
        return 1;
    }
    return v < 0 ? -1 : 1;
};

template<typename Range>
auto to_vector(const Range& r) {
    using IteratorType = decltype(r.begin());
    using ReferenceType = decltype(*IteratorType());
    using ValueType = std::decay_t<ReferenceType>;
}

template<typename T>
auto interpolate(T left, T right, T power) 
-> std::enable_if_t<std::is_floating_point_v<T>, T> {
    return left * (1 - power) + right * power;
}