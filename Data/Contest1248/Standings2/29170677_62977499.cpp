#include <bits/stdc++.h>

using namespace std;

#define LL long long int
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int oo = 1e8;
// const LL oo = 1e16 + 5;
const int MOD = 1e9 + 7;
const int N = 1e6+5;
// const int MOD = 998244353;
// const long double PI = acos(-1);

int v[N];
void solve() {
    int n, i, m;
    LL eve[2] = {0, 0}, odd[2] = {0, 0};
    for (i=0;i<2;i++) {
        int x; cin >> x;
        for (int j=0;j<x;j++) {
            int y; cin >> y;
            if (y & 1) odd[i]++;
            else eve[i]++;
        }
    }
    cout << eve[0] * eve[1] + odd[0] * odd[1] << '\n';
}

int main() {
    FASTIO; int t = 1; 
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        solve();
    }
    return 0;
}