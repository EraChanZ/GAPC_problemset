#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.141592653589793;

int main() {
    int w, h, n;
    cin >> w >> h >> n;

    double alpha = n * PI / 180;
    double x = w * abs(cos(alpha)) + h * abs(sin(alpha));
    double y = w * abs(sin(alpha)) + h * abs(cos(alpha));

    cout << x * y - w * h << endl;

    return 0;
}
