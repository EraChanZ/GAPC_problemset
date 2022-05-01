#include "validation.h"

int main(int argc, char** argv) {
    InputValidator v(argc, argv);
    std::string s = v.read_string("s", 1, 20);
    v.newline();

    for (char c : s) {
        bool is_digit = c >= '0' && c <= '9';
        bool is_lower = c >= 'a' && c <= 'z';
        bool is_upper = c >= 'A' && c <= 'Z';
        if (!is_digit && !is_lower && !is_upper) {
            v.WA("The input contains invalid characters");
        }
    }

    return 0;
}
