#include <iostream>
#include <sstream>
#include <tuple>

template <size_t Index, typename Tuple, typename Functor>
auto tuple_at(const Tuple& tpl, const Functor& func) -> void {
    const auto& v = std::get<Index>(tpl);
    func(v);
}

template <typename Tuple, typename Functor, size_t Index = 0>
auto tuple_for_each(const Tuple& tpl, const Functor& f) -> void {
    constexpr auto tuple_size = std::tuple_size_v<Tuple>;
    if constexpr(Index < tuple_size) {
        tuple_at<Index>(tpl, f);
        tuple_for_each<Tuple, Functor, Index+1>(tpl, f);
    }
}

template <typename ...Ts>
auto expand_pack(const Ts& ...values) {
    auto tuple = std::tie(values...);
}

template <typename ...Ts>
auto make_string(const Ts& ...values) -> std::string {
    auto sstr = std::stringstream{};
    auto tuple = std::tie(values...);
    tuple_for_each(tuple, [&sstr](const auto& v) { sstr << v << ' '; });
    return sstr.str();
}

int main() {
    auto msg = make_string(123, "Test", 3.24);
    std::cout << msg << std::endl;
}