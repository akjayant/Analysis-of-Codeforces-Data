#include <bits/stdc++.h>

using namespace std;

#define LL long long int
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int oo = 1e9;
// const LL oo = 1e18;
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int N = 4e5;
// const long double PI = acos(-1);

void solve() {
    int a, b;
    cin >> a >> b;
    int g = __gcd(a, b);
    if (g == 1) cout << "Finite\n";
    else cout << "Infinite\n";
}

int main() {
    FASTIO; 
    int t = 1; 
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        solve();
    }
    return 0;
}