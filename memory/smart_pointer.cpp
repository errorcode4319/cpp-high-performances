#include <iostream>
#include <memory>


auto operator new(size_t size) -> void* {
    void* p = std::malloc(size);
    std::cout << "allocated " << size << " bytes" << '\n';
    return p;
}

auto operator delete(void* p) noexcept -> void {
    std::cout << "deleted memory" << '\n';
    return std::free(p);
}

int main() {

    auto p1 = std::make_shared<double>(42.0);

    auto p2 = std::shared_ptr<double>(new double{42.0});

    return 0;
}