#include <iostream>
#include <vector>

using namespace std;

int pickNext(vector<int> &a, int last, int v) {
    for (int i = last+1; i < a.size(); i++) {
        if (a[i] >= v) {
            return i;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int j = 0; j < m; j++) {
        cin >> b[j];
    }
    auto check = [&] (int d) -> bool {
        int ia = 0;
        int ib = -1;
        for (int c = 0; c < k-1; c++) {
            ib = pickNext(b, ib, a[ia] + d);
            if (ib == -1) {
                return false;
            }
            ia = pickNext(a, ia, b[ib] + d);
            if (ia == -1) {
                return false;
            }
        }
        return true;
    };
    int l = 0, r = 1e9;
    while (l < r) {
        int mid = (l+r+1)/2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid-1;
        }
    }
    int ans = check(l) ? l : -1;
    cout << ans << endl;
}