#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e8;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs(vector<vector<int> > & d) {
    int n = d.size();
    int m = d[0].size();
    vector<int> qx;
    vector<int> qy;
    int qj = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (d[i][j] == 0) {
                qx.push_back(i);
                qy.push_back(j);
            }
        }
    }
    while (qj < qx.size()) {
        int cx = qx[qj];
        int cy = qy[qj];
        qj++;
        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (d[nx][ny] == INF) {
                    d[nx][ny] = d[cx][cy] + 1;
                    qx.push_back(nx);
                    qy.push_back(ny);
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> f(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }

    vector<vector<int> > es(n, vector<int>(m, INF));
    vector<vector<int> > xs(n, vector<int>(m, INF));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (f[i][j] == 'E') {
                es[i][j] = 0;
            } else if (f[i][j] == 'X') {
                xs[i][j] = 0;
            }
        }
    }
    bfs(es);
    bfs(xs);

    int ans = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (f[i][j] == 'S') {
                ans = min(ans, es[i][j] + xs[i][j]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
