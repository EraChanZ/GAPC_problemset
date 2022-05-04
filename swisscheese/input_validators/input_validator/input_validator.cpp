#include "validation.h"

// Check the grammar of the input files.
// You should also check properties of the input.
// E.g., check that a graph is connected.

int main(int argc, char** argv) {
    InputValidator v(argc, argv);
    int n = v.read_integer("n", 1, 1000);
    v.space();
    int m = v.read_integer("m", 1, 1000);
    v.newline();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            v.read_integer("bin", 0, 1);
            if (j < (n - 1)){
                v.space();
            }
        }
        v.newline();
    }
    
    return 0;

}
