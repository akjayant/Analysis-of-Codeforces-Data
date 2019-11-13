#include <bits/stdc++.h>

#define y1 theboatman
#define make_struct(args...) {args}

using namespace std;
typedef long long ll;

const int N = 1e6 + 10;
const int inf = 1e9 + 10;
const long long INF = 1e18 + 10;

void solve() {
    int a, b;
    cin >> a >> b;

    int gcd = __gcd(a, b);
    if (gcd != 1) {
        cout << "Infinite\n";
    }
    else {
        cout << "Finite\n";
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int test;
    cin >> test;

    while(test--) {
        solve();
    }

    return 0;
}
/*
*/
