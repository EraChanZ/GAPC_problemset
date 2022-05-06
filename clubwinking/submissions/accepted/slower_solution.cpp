#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int mygcd(int a, int b) {
    if (b == 0) return a;
    return mygcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> m >> n;
    vector<vector<int> > people;
    vector<string> vibes(n); 
    for (int i = 0; i < n; i++) {
        vector<int> v(m);
        for (int j = 0; j < m; j++) {
            cin >> v[j];
        }
        people.push_back(v);
        cin >> vibes[i];
    }

    vector<int> ans;
    int ansVibes = 0;
    for (int s = 0; s < n; s++) {
        map<vector<int>, vector<int> > groups; 
        for (int i = 0; i < n; i++) {
            if (i == s) continue;
            int g = 0;
            int mult = 0;
            for (int j = 0; j < m; j++) {
                int diff = people[i][j] - people[s][j];
                if (mult == 0 && diff > 0) {
                    mult = 1;
                }
                if (mult == 0 && diff < 0) {
                    mult = -1;
                }
                g = mygcd(abs(diff), g);
            }
            vector<int> key(m);
            for (int j = 0; j < m; j++) {
                key[j] = mult * (people[i][j] - people[s][j]) / g;
            }
            groups[key].push_back(i);
        }
        for (auto & p : groups) {
            vector<int> & currentGroup = p.second;
            currentGroup.push_back(s);
            sort(currentGroup.begin(), currentGroup.end());
            set<string> currentVibes;
            for (int i : currentGroup) {
                currentVibes.insert(vibes[i]);
            }
            if (currentVibes.size() > ansVibes ||
                (currentVibes.size() == ansVibes && currentGroup.size() > ans.size())) {
                ans = currentGroup;
                ansVibes = currentVibes.size();
            }
        }
    }
    cout << ans.size() << "\n";
    for (int x : ans) {
        cout << x << "\n";
    }

    return 0;
}
