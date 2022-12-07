#include <iostream>

class Document {

public:
    Document() { std::cout << "Create Document" << std::endl; }
    ~Document() { std::cout << "Remove Document" << std::endl; }

public:
    auto operator new(size_t size) -> void* {
        std::cout << "User Custom New Operator" << std::endl;
        return ::operator new(size);
    } 

    auto operator delete(void* p) -> void {
        std::cout << "User Custom Delete Operator" << std::endl;
        ::operator delete(p);
    }

};

int main() {
    auto* p = new Document{};
    delete p;


    auto* p2 = ::new Document{};
    ::delete p2;
}