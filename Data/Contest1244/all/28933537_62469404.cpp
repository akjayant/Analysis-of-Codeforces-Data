#include <bits/stdc++.h>


#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#define ull unsigned long long
#define pll pair<ll, ll>
#define mp make_pair
#define ll long long
#define ld long double
#define i128 ll
#define pb push_back
#define deb(x) cout << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define vi vector<ll>
typedef std::complex<ld> cmpl;


const ll mod = 1e9 + 7;
const ll P = 239;
const ll inf = (ll)1e18;
const long double MATH_E = 2.718281828459;
const long double eps = 1e-9;
const long double MATH_PI = atan2l(0, -1);


using namespace std;


template <class T>
istream& operator>>(istream &in, vector<T> &arr) {
    for (T &cnt : arr) {
        in >> cnt;
    }
    return in;
};


void solve() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll ans = n;
        for (ll i = 0; i < n; i++) {
            if (s[i] == '1') {
                ans = max(ans, (i + 1) * 2);
            }
        }
        reverse(all(s));
        for (ll i = 0; i < n; i++) {
            if (s[i] == '1') {
                ans = max(ans, (i + 1) * 2);
            }
        }
        cout << ans << "\n";
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout.precision(30);
    srand(time(0));
    cout.setf(ios::fixed);
    solve();
    return 0;
}