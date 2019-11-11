#include <bits/stdc++.h>
using namespace std;

int t, a, b;

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        if (gcd(a, b) == 1) {
            cout << "Finite" << endl;
        } else {
            cout << "Infinite" << endl;
        }
    }
    return 0;
}