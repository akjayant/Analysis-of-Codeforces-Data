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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    ll k;
    cin >> k;
    forn (i, k) {
        ll n;
        cin >> n;
        vi rr;
        string s, t;
        cin >> s >> t;
        int r = 0;
        forn (j, n) {
            if (s[j] != t[j]) {
                r++;
                rr.pb(j);
            }
        }
        if (r == 0) {
            cout << "Yes\n";
            continue;
        }
        if (r > 2 || r == 1) {
            cout << "No\n";
            continue;
        }

        swap (s[rr[0]], t[rr[0]]);
        if (s == t) {
            cout << "Yes\n";
            continue;
        }
        swap (s[rr[0]], t[rr[0]]);
        swap (s[rr[1]], t[rr[1]]);
        if (s == t) {
            cout << "Yes\n";
            continue;
        }
        swap (s[rr[1]], t[rr[1]]);
        swap (s[rr[0]], t[rr[1]]);
        if (s == t) {
            cout << "Yes\n";
            continue;
        }
        swap (s[rr[0]], t[rr[1]]);
        swap (s[rr[1]], t[rr[0]]);
        if (s == t) {
            cout << "Yes\n";
            continue;
        }
        swap (s[rr[1]], t[rr[0]]);

        cout << "No\n";
    }
}