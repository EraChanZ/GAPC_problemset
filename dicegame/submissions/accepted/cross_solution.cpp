#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10);

    int n, m;
    cin >> n >> m;
    // t = (m-1)/m
    // x * (1 + t + ... + t^(n-1)) = 1
    // x * (t^n - 1)/(t - 1) = 1
    // x = (t - 1) / (t^n - 1)
    double t = (m - 1.0) / m;
    double x = (t - 1) / (pow(t, n) - 1);

    double cur = x;
    for (int i = 0; i < n; i++) {
        cout << cur << " ";
        cur *= t;
    }
}