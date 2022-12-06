#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>

struct Flower {

    auto operator==(const Flower& f) const {
        return height_ == f.height_;
    }
    auto operator<(const Flower& f) const {
        return height_ < f.height_;
    }

    int height_{};
};

int main(int argc, char* argv[]) {

    auto garden = std::vector<Flower>{Flower{12}, Flower{13}, Flower{4}};

    // operator <
    auto tallest_flower = std::max_element(garden.begin(), garden.end());

    // opereator==
    auto magic_flower = *std::find(garden.begin(), garden.end(), Flower{13});

    auto names = std::vector<std::string> {
        "Ralph", "Lisa", "Homer", "Maggie", "Apu", "Bart"
    };

    auto equal_case_insensitive = [](const std::string& needle) {
        return [&needle](const std::string& s) {
            if (needle.size() != s.size()) {
                return false;
            }
            auto eq_lower = [](char a, char b) {
                return std::tolower(a) == std::tolower(b);
            };
            return std::equal(s.begin(), s.end(), needle.begin(), eq_lower);
        };
    };

    auto num_maggies = std::count_if(names.begin(), names.end(), equal_case_insensitive(std::string{"maggie"}));
    assert(num_maggies == 1);

}