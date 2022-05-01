#include <iostream>

using namespace std;

bool is_prime(int x) {
    if (x <= 1) {
        return false;
    }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

bool check(int x) {
    if (x == 0) {
        return true;
    }
    int curr = 0;
    int mult = 1;
    while (x > 0) {
        int d = x % 10;
        curr += mult * d;
        mult *= 10;
        x /= 10;
        if (d != 0 && is_prime(curr) && check(x)) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    if (check(n)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
