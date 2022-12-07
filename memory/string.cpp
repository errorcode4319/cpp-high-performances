#include <iostream>

auto allocated = size_t{0};

auto operator new(size_t size) -> void* {
    void* p = std::malloc(size);
    allocated += size;
    return p;
}

auto operator delete(void* p) noexcept -> void {
    return std::free(p);
}

int main(int argc, char* argv[]) {

    allocated = 0;
    auto s = std::string{""};
    std::cout << "stack space = " << sizeof(s) 
        << ", heap space = " << allocated 
        << ", capacity = " << s.capacity() << '\n';

    return 0;
}