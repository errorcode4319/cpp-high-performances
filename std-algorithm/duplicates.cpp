#include <iostream>
#include <vector>
#include <type_traits>
#include <algorithm>


template <typename Iterator>
auto contains_duplicates_nn(Iterator first, Iterator last) {
    for (auto it = first; it != last; ++it) {
        if (std::find(std::next(it), last, *it) != last) 
            return true;
    }
    return false; 
}

template <typename Iterator>
auto contains_duplicates_nlogn(Iterator first, Iterator last) {
    using ValueType = std::decay_t<decltype(*first)>;
    auto c = std::vector<ValueType>(first, last);
    std::sort(c.begin(), c.end());
    return std::adjacent_find(c.begin(), c.end()) != c.end();
}

int main(int argc, char* argv[]) {
    auto nums = std::vector<int>{1,5,2,6,7,8,1,3};

    std::cout << "Has Duplicates => " << contains_duplicates_nn(nums.begin(), nums.end()) << std::endl;
    std::cout << "Has Duplicates => " << contains_duplicates_nlogn(nums.begin(), nums.end()) << std::endl;
     
}