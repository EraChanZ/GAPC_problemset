#include <iostream>
#include <vector>

using namespace std;

bool can(const vector<int> & a, const vector<int> & b, int k, int x) {
    int n = a.size();
    int m = b.size();
    int i = 0;
    int j = 0;
    int have = 0;
    int last = -1e9;
    while (true) {
        if (have % 2 == 0) {
            if (i == n) {
                break;
            }
            while (i < n && last + x > a[i]) {
                i++;
            }
            if (i < n) {
                have++;
                last = a[i];
                i++;
            }
        } else {
            if (j == m) {
                break;
            }
            while (j < m && last + x > b[j]) {
                j++;
            }
            if (j < m) {
                have++;
                last = b[j];
                j++;
            }
        }
    }
    return have >= 2 * k - 1;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(m);
    for (int j = 0; j < m; j++) {
        cin >> b[j];
    }

    int l = 0;
    int r = 1e9;
    while (l + 1 != r) {
        int mid = (l + r) / 2;
        if(can(a, b, k, mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << endl;

    return 0;
}
