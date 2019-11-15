#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;
const int inf = 1e9 + 7;


int gcd(int a, int b) {
    while (b != 0) {
        int w = a % b;
        a = b;
        b = w;
    }
    return a;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int a, b;
        cin >> a >> b;
        int q = gcd(a, b);
        if (q == 1) cout << "Finite" << endl;
        else cout << "Infinite" << endl;
    }
    return 0;
}