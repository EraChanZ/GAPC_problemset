#include "validation.h"

int main(int argc, char** argv) {
    InputValidator v(argc, argv);
    int n = v.read_integer("n", 0, 100000);
    v.space();
    int m = v.read_integer("m", 0, 100000);
    v.space();
    int k = v.read_integer("k", 0, 100000);
    v.newline();
    v.read_integers("a", /*count=*/n, 0, 1000000, Increasing);
    v.read_integers("b", /*count=*/m, 0, 1000000, Increasing);
    return 0;
}
