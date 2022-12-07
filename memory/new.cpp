#include <iostream>
#include <memory>

class User {

public:
    User(const std::string& name) : name_{name} {}
    void print_name() const { std::cout << name_ << std::endl; }

private:
    std::string name_;
};

int main(int argc, char* argv[]) {

    {
        auto memory = std::malloc(sizeof(User));
        auto user = new (memory) User("john");
        user->print_name();
        user->~User();
        std::free(memory);
    }

    {   // uninitialized_
        auto memory = std::malloc(sizeof(User));
        auto user_ptr = reinterpret_cast<User*>(memory);
        user_ptr->print_name();
        std::uninitialized_fill_n(user_ptr, 1, User{"john"});
        user_ptr->print_name();
        std::destroy_at(user_ptr);
        std::free(memory);
    }


}