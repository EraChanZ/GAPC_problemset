#include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << fixed;
    cout.precision(12);

    int n, m;
    cin >> n >> m;

    double chance = 1.0;
    double win = 1.0 / m;
    double skip = 1 - win;
    vector<double> ans(n);

    int i = 0;
    while (chance > 1e-13) {
        ans[i] += chance * win;
        chance *= skip;
        i = (i + 1) % n;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i];
        if (i < n-1) cout << " ";
    }
    cout << endl;

    return 0;
}
