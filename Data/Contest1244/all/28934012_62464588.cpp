#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int M = 1e5 + 5;
const int INF = 1e9 + 5;
const int base = 1e4;

typedef long long ll;

const ll mod = 1e9 + 7;

int a, b, c, k, t, d;

int main() {
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d >> k;
        int x = a / c + (a % c != 0);
        int y = b / d + (b % d != 0);
        if (x + y > k) {
            cout << "-1\n";
        } else {
            cout << x << " " << y << "\n";
        }
    }
}
