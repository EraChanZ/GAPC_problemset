#include "validation.h"

int main(int argc, char **argv) {
    OutputValidator v(argc, argv);

    int answer = v.read_integer("answer", 0, 1000000000);
    v.newline();

    return 0;
}
