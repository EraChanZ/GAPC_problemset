#include "validation.h"
#include <vector>

int main(int argc, char** argv) {
    InputValidator v(argc, argv);
    int n = v.read_integer("n", 3, 500);
    v.space();
    int m = v.read_integer("m", 3, 500);
    v.newline();

    std::vector<std::string> grid(n);
    for (int i = 0; i < n; i++) {
        grid[i] = v.read_string("line", m, m);
        v.newline();
    }

    bool haveE = false;
    bool haveX = false;
    bool haveS = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool isSide = i == 0 || i == n - 1 || j == 0 || j == m-1; 
            if (grid[i][j] == 'E') {
                haveE = true;
                if (!isSide) {
                    v.WA("Input contains E not on the side");
                }
            } else if (grid[i][j] == 'X') {
                haveX = true;
                if (!isSide) {
                    v.WA("Input contains X not on the side");
                }
            } else if (grid[i][j] == 'S') {
                haveS = true;
                if (isSide) {
                    v.WA("Input contains S on the side");
                }
            } else if (grid[i][j] == '.') {

            } else {
                v.WA("Input contains invalid character");
            }
        }
    }

    if (!haveE) {
        v.WA("Input doesn't contain E");
    }
    if (!haveX) {
        v.WA("Input doesn't contain X");
    }
    if (!haveS) {
        v.WA("Input doesn't contain S");
    }

    return 0;
}
