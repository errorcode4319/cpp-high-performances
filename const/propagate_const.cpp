#include<experimental/propagate_const>

namespace exp = std::experimental;

class Foo {
public:
    auto set_ptr(int* p) const {
        ptr_ = p;
    }
    auto set_val(int v) const {
        val_ = v;
    }
    auto set_ptr_val(int v) const {
        *ptr_ = v;
    }

private:
    // Compile Failed 
    exp::propagate_const<int*> ptr_ = nullptr;
    int val_{};
};

int main() {

    Foo foo;
}