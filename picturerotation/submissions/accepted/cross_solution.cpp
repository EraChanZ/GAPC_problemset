#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int w, h, d;
    cin >> w >> h >> d;
    double deg = (d%360) * M_PI / 180;
    double res = (w*w + h*h) *fabs(sin(deg)*cos(deg));
    cout.precision(10);
    cout << fixed<< res << endl;
}