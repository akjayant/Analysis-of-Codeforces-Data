#include <bits/stdc++.h>

/*
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/

#define mp make_pair
#define ll long long
#define ld long double
#define pb push_back
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fs first
#define sc second
#define getfiles ifstream cin("input.txt"); ofstream cout("output.txt");
#define endl '\n'
#define con continue
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()

const ll INF = 2000000005;
const ll BIG_INF = 2000000000000000005;
const ll mod = 1000000007;
const ll P = 31;
const ld PI = 3.141592653589793238462643;
const double eps = 1e-9;

using namespace std;

vector< pair<ll, ll> > dir = {
    {
        -1, 0
    },
    {
        0, 1
    },
    {
        1, 0
    },
    {
        0, -1
    }
};

bool valid(ll x, ll y, ll n, ll m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

mt19937 rng(1999999973);

map<ll, bool> vis;

signed main() {
    fast_io;

    ll n, p, w, d;
    cin >> n >> p >> w >> d;

    ll ost = p % w, curost = ost;

    for (ll col = 0; col <= n; col++) {
        if (vis[curost])
            break;

        vis[curost] = true;

        if (p - col * d < 0)
            break;

        if ((p - col * d) >= 0 && (p - col * d) % w == 0 && (p - col * d) / w + col <= n) {
            cout << (p - col * d) / w << " " << col << " " << n - (p - col * d) / w - col;
            return 0;
        }
        curost = (curost - (d % w) + w) % w;
    }
    cout << -1;




    return 0;
}
