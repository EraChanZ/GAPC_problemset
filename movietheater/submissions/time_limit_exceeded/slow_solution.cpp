#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e8;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> f(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }

    vector<pair<int, int> > e;
    vector<pair<int, int> > x;
    vector<pair<int, int> > s;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (f[i][j] == 'E') {
                e.push_back({i,j});
            } else if (f[i][j] == 'X') {
                x.push_back({i,j});
            } else if (f[i][j] == 'S') {
                s.push_back({i,j});
            }
        }
    }

    int ans = INF;
    for (auto pe : e) {
        for (auto ps : s) {
            for (auto px : x) {
                int de = abs(pe.first - ps.first) + abs(pe.second - ps.second);
                int dx = abs(px.first - ps.first) + abs(px.second - ps.second);
                ans = min(ans, de + dx);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
