#include "validation.h"

// Check the grammar of the input files.
// You should also check properties of the input.
// E.g., check that a graph is connected.

int main(int argc, char** argv) {
    InputValidator v(argc, argv);
    long long int a = v.read_integer("a", 0, 10000000000);
    v.space();
    long long int b = v.read_integer("b", 0, 10000000000);
    v.space();
    long long int c = v.read_integer("c", 0, 10000000000);
    v.newline();
    int n = v.read_integer("n", 1, 1000000);
    v.newline();
    for (int i = 0; i < n; i++) {
        long long int x = v.read_integer("a", 0, 10000000000);
        v.space();
        long long int y = v.read_integer("b", 0, 10000000000);
        v.space();
        long long int z = v.read_integer("c", 0, 10000000000);
        v.newline();
    }

    // In its destructor, v automatically exits with code 42 here.
    // TODO: Remove this comment, and summarize your input validator.
}
