#include "validation.h"

// Check the grammar of the input files.
// You should also check properties of the input.
// E.g., check that a graph is connected.

int main(int argc, char** argv) {
    InputValidator v(argc, argv);
    int n = v.read_integer("n", 2, 100000001);
    v.newline();
    v.read_integers("ai", /*count=*/n, 0, 1000000001);
    //v.newline();
    return 0;
   
}
