#include "validation.h"

int main(int argc, char** argv) {
    InputValidator v(argc, argv);
    int n = v.read_integer("n", 3, 500);
    v.space();
    int m = v.read_integer("m", 3, 500);
    v.newline();

    for (int i = 0; i < n; i++) {
        v.read_string("line", m, m);
        v.newline();
    }

    return 0;
}
