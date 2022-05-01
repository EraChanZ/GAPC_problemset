#include "validation.h"

int main(int argc, char **argv) {
    OutputValidator v(argc, argv);

    std::string answer = v.read_string("answer", 2, 3);
    v.newline();

    return 0;
}
