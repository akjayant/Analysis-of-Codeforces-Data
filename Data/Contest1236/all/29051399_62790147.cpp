/**
    *Makacha
**/
#include <bits/stdc++.h>
using namespace std;

template <typename T> inline void read (T &x) { bool b = 0; char c; while (!isdigit (c = getchar()) && c != '-');
if (c == '-') c = getchar(), b = 1; x = c - 48; while (isdigit(c = getchar())) x = (x << 3) + (x << 1) + c - 48; if (b) x = -x; }
template <typename T> inline void wrip(T x) { if (x > 9) wrip(x / 10); putchar(x%10 + 48); }
template <typename T> inline void write(T x) { if (x < 0) putchar('-'), x = -x; wrip(x);}
void reads(string &s) { char c; while (!isalpha(c = getchar())); s = c; while (isalpha(c = getchar())) s += c; }
typedef const int csint;

#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll inf = 1e16;
const int N = 1e5 + 11;
typedef pair <int, ll> ii;

ll pw(ll a, ll b) {
    if (b == 0)
        return 1;
    ll t = pw(a, b / 2);
    if (b % 2 == 0)
        return t * t % mod;
    return t * t % mod * a % mod;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef makacha
        freopen("m.inp", "r", stdin);
        freopen("m.out", "w", stdout);
    #endif // makacha
    ll n, m;
    cin >> n >> m;
    m = (pw(2, m) - 1 + mod) % mod;
    n = pw(m, n);
    cout << n;
}
