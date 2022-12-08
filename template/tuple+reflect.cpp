#include <iostream>
#include <sstream>
#include <tuple>
#include <type_traits>
#include <experimental/type_traits> // is_detected 

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

// Reflection Sample
template<typename T>
using has_reflect_member = decltype(&T::reflect);

template<typename T>
constexpr bool is_reflectable_v = std::experimental::is_detected<has_reflect_member, T>::value;

class Town {

public:
    Town(size_t houses, size_t settlers, const std::string& name)
    : houses_{houses}, settlers_{settlers}, name_{name} {}
    auto reflect() const {return std::tie(houses_, settlers_, name_);}

private:
    size_t houses_{};
    size_t settlers_{};
    std::string name_{};
};

template <typename T, bool IsReflectable = is_reflectable_v<T>>
auto operator<<(std::ostream& ostr, const T& t) 
-> std::enable_if_t<IsReflectable, std::ostream&> {
    tuple_for_each(t.reflect(), [&ostr](const auto& m){
        ostr << m << " ";
    });
    return ostr;
}

int main() {
    auto msg = make_string(123, "Test", 3.24);
    std::cout << msg << std::endl;

    auto v = Town{34, 68, "Shire"};
    std::cout << v << std::endl;

}