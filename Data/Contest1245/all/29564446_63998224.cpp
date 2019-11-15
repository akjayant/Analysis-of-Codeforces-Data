#pragma GCC optimize("03")
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long 

using namespace std;

int v[100100];
int a, b, t;

int main() {
    // ifstream cin("tst.in");
    // ofstream cout("tst.out");
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> t;
    while (t--) {
        // memset(v, 0, sizeof v);
        cin >> a >> b;
        if (__gcd(a, b) == 1)
            cout << "Finite\n";
        else cout << "Infinite\n";
    }

    return 0;
}