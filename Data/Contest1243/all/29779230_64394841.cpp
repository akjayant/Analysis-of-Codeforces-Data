#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef double ld;

ll gcd (ll a, ll b) {
    if (a == 0) return b;
    return gcd (b % a, a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    ll n;
    cin >> n;
    vll del;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            del.pb(i);
            if (i * i != n) {
                del.pb(n / i);
            }
        }
    }
    del.pb(n);
    sort (all(del));
    ll ans = del[0];
    forn (i, del.size()) {
        ans = gcd (ans, del[i]);
    }
    cout << ans;
}