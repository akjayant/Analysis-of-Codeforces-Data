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

const ll N = 2050;
ll c[N], order[N], dist[N], x[N], bst[N], y[N], k[N], n;
bool vis[N];

bool comp(ll x, ll y) {
    return c[x] < c[y];
}

inline ll man_dist(ll i, ll j) {
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

signed main() {
    fast_io;

    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        order[i] = i;
    }

    for (ll i = 0; i < n; i++)
        cin >> c[i];
    for (ll i = 0; i < n; i++)
        cin >> k[i];


    for (ll i = 0; i < n; i++) {
        dist[order[i]] = BIG_INF;
//        for (ll j = 0; j < i; j++) {
//            if (dist[order[i]] > man_dist(order[i], order[j]) * (k[order[i]] + k[order[j]])) {
//                dist[order[i]] = man_dist(order[i], order[j]) * (k[order[i]] + k[order[j]]);
//                bst[order[i]] = order[j];
//            }
//        }
    }

    ll ans = 0;
    vector<ll> el;
    vector<pii> ed;

    for (ll i = 0; i < n; i++) {
        ll mnad = BIG_INF, v = -1;
        for (ll j = 0; j < n; j++) {
            if (vis[j])
                continue;
            if (min(dist[j], c[j]) < mnad) {
                mnad = min(dist[j], c[j]);
                v = j;
            }
        }
        ans += mnad;
        vis[v] = true;
        if (c[v] < dist[v]) {
            el.pb(v + 1);
        }
        else {
            ed.pb(mp(v + 1, bst[v] + 1));
        }
        for (ll j = 0; j < n; j++) {
            if (vis[j])
                continue;
            if (dist[j] > man_dist(j, v) * (k[j] + k[v])) {
                dist[j] = man_dist(j, v) * (k[j] + k[v]);
                bst[j] = v;
           }
        }
    }

    cout << ans << endl;
    cout << el.size() << endl;
    for (ll i = 0; i < el.size(); i++) {
        cout << el[i] << " ";
    }
    cout << endl;
    cout << ed.size() << endl;
    for (ll i = 0; i < ed.size(); i++) {
        cout << ed[i].fs << " " << ed[i].sc << endl;
    }


    return 0;
}
