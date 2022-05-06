#include "validation.h"

// Check the grammar of the input files.
// You should also check properties of the input.
// E.g., check that a graph is connected.

int main(int argc, char** argv) {
    InputValidator v(argc, argv);
    int n = v.read_integer("n", 1, 50);
    v.newline();
    int t = v.read_integer("t", 0, 1000);
    v.newline();
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < n; j++){
            int coord = v.read_integer("coord", -1000000000, 1000000000);
            v.space();
        }
        std::string color = v.read_string("color", 1, 10);
        v.newline();
    }

    return 0;

}
