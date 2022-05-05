#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    bool ans = false;
    if (n >= 7 && n <= 16) {
        set<int> req;
        for (char ch: s) {
            if ('a' <= ch && ch <= 'z') {
                req.insert(1);
            } else if ('A' <= ch && ch <= 'Z') {
                req.insert(2);
            } else if ('0' <= ch && ch <= '9') {
                req.insert(3);
            }
        }
        int sz = req.size();
        ans = (sz == 3) || (sz == 2 && n < 16);
    }
    cout << (ans ? "YES" : "NO") << endl;
}