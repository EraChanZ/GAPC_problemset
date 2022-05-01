#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    bool has_digit = false;
    bool has_lower = false;
    bool has_upper = false;
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            has_digit = true;
        }
        if (c >= 'a' && c <= 'z') {
            has_lower = true;
        }
        if (c >= 'A' && c <= 'Z') {
            has_upper = true;
        }
    }
    int have = has_digit + has_lower + has_upper;
    int len = s.length();
    if (have == 3 && len >= 7 && len <= 16) {
        cout << "YES\n";
    } else if (have == 2 && len >= 7 && len <= 15) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
