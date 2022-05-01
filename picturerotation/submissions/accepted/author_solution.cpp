#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.141592653589793;

int main() {
    cout << fixed;
    cout.precision(9);

    int w, h, n;
    cin >> w >> h >> n;

    double alpha = n * PI / 180;
    double x = w * cos(alpha) + h * sin(alpha);
    double y = w * sin(alpha) + h * cos(alpha);

    cout << x * y - w * h + 1e-13 << endl;

    return 0;
}
