#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <bitset>
#include <complex>
#include <deque>
#include <iomanip>
#include <list>
#include <map>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
#define sqr(x) ((x) * (x))
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define forb(n, i) for (int i = n - 1; i >= 0; --i)
#define readp(v) cin >> (v).x >> (v).y

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld PI = 3.141592653589793116;
const int LEN = 2002;

ll x[LEN], y[LEN], c[LEN], k[LEN], d[LEN], par[LEN];
bool use[LEN];

ll ways(ll i, ll j) {
    return (abs(x[i] - x[j]) + abs(y[i] - y[j])) * (k[i] + k[j]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    fill(par, par + LEN, -1);
    forn (i, n) {
        cin >> x[i] >> y[i];
    }

    forn(i, n) {
        cin >> c[i];
        d[i] = c[i];
        use[i] = true;
    }

    forn(i, n) {
        cin >> k[i];
    }

    for(;;) {
        int ind = -1;
        forn (i, n) {
            if (use[i] && ((ind == -1) || (d[ind] > d[i]))) {
                ind = i;
            }
        }

        if (ind == -1) {
            break;
        }

        use[ind] = false;
        forn(i, n) {
            if (use[i]) {
                ll way = ways(ind, i);
                if (way < d[i]) {
                    par[i] = ind;
                    d[i] = way;
                }
            }
        }
    }

    ll ans = 0;
    vector<int> ansv;
    vector<pii> ed;
    for (int i = 0; i < n; ++i) {
        ans += d[i];
        if (par[i] == -1) {
            ansv.pb(i);
        } else {
            ed.em(i, par[i]);
        }
    }

    cout << ans << '\n';
    cout << ansv.size() << '\n';
    for (auto cur : ansv) {
        cout << cur + 1 << ' ';
    }
    cout << '\n';

    cout << ed.size() << '\n';
    for (auto cur : ed) {
        cout << cur.x + 1 << ' ' << cur.y + 1 << ' ';
    }
    cout << '\n';
}
