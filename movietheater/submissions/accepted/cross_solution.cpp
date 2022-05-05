#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    vector<vector<int>> dst(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (char start: string("EX")) {
        vector<pair<int, int>> q;
        vector<vector<int>> st(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == start) {
                    q.push_back({i, j});
                    st[i][j] = 0;
                }
            }
        }
        for (int qi = 0; qi < q.size(); qi++) {
            auto pr = q[qi];
            for (auto dir: dirs) {
                int i = pr.first + dir.first;
                int j = pr.second + dir.second;
                if (0 <= i && i < n && 0 <= j && j < m && st[i][j] == -1) {
                    st[i][j] = st[pr.first][pr.second] + 1;
                    q.push_back({i, j});
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dst[i][j] += st[i][j];
            }
        }
    }
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'S') {
                ans = min(ans, dst[i][j]);
            }
        }
    }
    cout << ans << endl;
}
