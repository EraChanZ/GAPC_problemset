#include "validation.h"

int main(int argc, char **argv) {
    OutputValidator v(argc, argv);

    double EPS = 1e-4;
    double answer = v.read_float("answer", -EPS, 1000000000 + EPS);
    v.newline();

    return 0;
}
