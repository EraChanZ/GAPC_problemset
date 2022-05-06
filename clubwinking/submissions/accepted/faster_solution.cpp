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
    vector<int> vibes(n);
    map<string, int> vibesMap;
    for (int i = 0; i < n; i++) {
        vector<int> v(m);
        for (int j = 0; j < m; j++) {
            cin >> v[j];
        }
        people.push_back(v);
        string vibe;
        cin >> vibe;
        if (!vibesMap.count(vibe)) {
            int vibeCode = vibesMap.size();
            vibesMap[vibe] = vibeCode;
        }
        vibes[i] = vibesMap[vibe];
    }

    vector<int> ans;
    int ansVibes = 1;
    for (int s = 0; s < n; s++) {
        map<pair<unsigned long long, unsigned long long>, vector<int> > groups; 
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
            pair<unsigned long long, unsigned long long> key = {0, 0};
            for (int j = 0; j < m; j++) {
                int val = mult * (people[i][j] - people[s][j]) / g;
                key = {key.first * 137 + 1e9 + val, key.second * 337 + 1e9 + val};
            }
            if (groups[key].empty()) {
                groups[key].push_back(s);
            }
            groups[key].push_back(i);
        }
        for (auto & p : groups) {
            vector<int> & currentGroup = p.second;
            set<int> currentVibes;
            currentVibes.insert(vibes[s]);
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
