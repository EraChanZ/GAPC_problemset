#include "validation.h"

int main(int argc, char** argv) {
    InputValidator v(argc, argv);

    int w = v.read_integer("w", 1, 100);
    v.space();
    int h = v.read_integer("h", 1, 100);
    v.space();
    int n = v.read_integer("n", 0, 1000);
    v.newline();

    return 0;
}
