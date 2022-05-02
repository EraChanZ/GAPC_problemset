#include "validation.h"

int main(int argc, char** argv) {
    InputValidator v(argc, argv);
    int n = v.read_integer("n", 2, 100000);
    v.space();
    int m = v.read_integer("m", 2, 100000);
    v.space();
    int k = v.read_integer("k", 2, 100000);
    v.newline();
    if (k > n) {
        v.WA("K is too large for given N");
    }
    if (k - 1 > m) {
        v.WA("K is too large for given M");
    }
    v.read_integers("ai", /*count=*/n, 0, 1000000000, Increasing);
    v.read_integers("bi", /*count=*/m, 0, 1000000000, Increasing);
    return 0;
}
