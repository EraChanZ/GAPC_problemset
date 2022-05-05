#include <iostream>
#include <vector>

using namespace std;
 
bool isPrime(int n) {
    for (int d = 2; d * d <= n; d++) {
        if (n%d == 0) {
            return false;
        }
    }
    return n > 1;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    vector<bool> dp(n+1);
    dp[n] = true;
    for (int i = n-1; i >= 0; i--) {
        int cur = 0;
        for (int j = i; j < n; j++) {
            cur = 10 * cur + s[j] - '0';
            if (isPrime(cur) && dp[j+1]) {
                dp[i] = true;
            }
        }
    }
    cout << (dp[0] ? "YES" : "NO") << endl;
}