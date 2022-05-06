#include "validation.h"

// Check the grammar of the input files.
// You should also check properties of the input.
// E.g., check that a graph is connected.

int main(int argc, char** argv) {
    InputValidator v(argc, argv);
    int k = v.read_integer("k", 0, 1000000);
    v.newline();
    v.read_integers("xi", /*count=*/k, 0, 1000000000000);
    return 0;

    
}
