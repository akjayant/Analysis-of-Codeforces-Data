#include <bits/stdc++.h>
#define FOR(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define REP(i, r) for(int i = (int)0; i < (int)r; ++i)
#define FORD(i, l, r) for(int i = (int)l; i >= (int)r; --i)
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

ll n, m;

ll power(ll a, ll k) {
    if (k == 0) return 1;
    ll tmp = power(a, k / 2);
    tmp = (tmp * tmp) % MOD;
    if (k % 2 == 0) return tmp;
    else return (tmp * a) % MOD;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef yt
        freopen("in.inp", "r", stdin);
    #endif
    cin >> n >> m;
    ll ans = power(2, m) - 1;
    cout << power(ans, n);
}

