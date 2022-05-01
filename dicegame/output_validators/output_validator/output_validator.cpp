#include "validation.h"

int main(int argc, char **argv) {
    std::ifstream in(argv[1]);
    OutputValidator v(argc, argv);

    int n, m;
    in >> n >> m;

    double EPS = 1e-4;
    v.read_floats("answer", n, -EPS, 1 + EPS);

    return 0;
}
