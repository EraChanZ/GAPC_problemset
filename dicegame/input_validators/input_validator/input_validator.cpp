#include "validation.h"

int main(int argc, char** argv) {
    InputValidator v(argc, argv);
    int n = v.read_integer("n", 1, 1000);
    v.space();
    int m = v.read_integer("m", 1, 1000);
    v.newline();
    return 0;
}
