#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long

int gcd(int a, int b) {
    while (b) {
        int p = a;
        a = b;
        b = p % b;
    }
    return a;
}


signed main() {
    fastio
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        gcd(a, b) == 1 ? cout << "Finite\n" : cout << "Infinite\n";
    }
}