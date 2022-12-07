#include <iostream>
#include <cstddef>
#include <memory>

int main() {

    auto* p1 = new char{};
    auto* p2 = new char{};
    auto address1 = reinterpret_cast<std::uintptr_t>(p1);
    auto address2 = reinterpret_cast<std::uintptr_t>(p2);
    auto max_alignment = alignof(std::max_align_t);
    std::cout << (address1 % max_alignment) << '\n';
    std::cout << "Diff:" << address2 - address1 << std::endl;
    std::cout << "Max Alignment:" << max_alignment << std::endl;

    delete p1;
    delete p2;

}