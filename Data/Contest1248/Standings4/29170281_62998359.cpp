#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define N 100005
#define M 100005
#define INF 0x3f3f3f3f
#define mk(x) (1<<x) // be conscious if mask x exceeds int
#define sz(x) ((int)x.size())
#define upperdiv(a,b) (a/b + (a%b>0))
#define mp(a,b) make_pair(a, b)
#define endl '\n'
#define lowbit(x) (x&-x)

using namespace std;
typedef long long ll;
typedef double db;

/** fast read **/
template <typename T>
inline void read(T &x) {
    x = 0; T fg = 1; char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') fg = -1;
        ch = getchar();
    }
    while (isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    x = fg * x;
}
template <typename T, typename... Args>
inline void read(T &x, Args &... args) { read(x), read(args...); }
template <typename T>
inline void write(T x) {
    int len = 0; char c[21]; if (x < 0) putchar('-'), x = -x;
    do{++len; c[len] = x%10 + '0';} while (x /= 10);
    for (int i = len; i >= 1; i--) putchar(c[i]);
}
template <typename T, typename... Args>
inline void write(T x, Args ... args) { write(x), write(args...); }

/** math **/
#define md 1000000007
inline ll mul(ll a) {return a;}
template <typename... Args>
inline ll mul(ll a, Args ... args) {return a*mul(args...) % md;}
inline ll add(ll a) {return a;}
template <typename... Args>
inline ll add(ll a, Args ... args) {
    ll res = (a+add(args...)) % md;
    if (res < 0) res += md;
    return res;
}
inline ll fpow(ll a, ll p) {
    ll res = 1;
    for (; p; p >>= 1) {
        if (p&1) res = mul(res, a);
        a = mul(a, a);
    }
    return res;
}
inline ll getInv(ll x) { return fpow(x, md-2); }
inline ll fmul(ll a, ll b) {
    ll res = 0;
    for (; b; b >>= 1) {
        if (b&1) res = add(res, a);
        a = add(a, a);
    }
    return res;
}
ll fac[N], inv[N];
ll C(ll n, ll m) { if (m < 0 || m > n) return 0; return mul(fac[n], mul(inv[n-m], inv[m])); }
ll P(ll n, ll m) { return mul(fac[n], fac[n-m]); }
#define MAXN 100002
void init() {
    fac[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fac[i] = mul(fac[i-1], i);
    }
    inv[MAXN-1] = fpow(fac[MAXN-1], md-2);
    for (int i = MAXN-2; i >= 0; i--)
        inv[i] = mul(inv[i+1], i+1);
}

ll f[N];
int main()
{
    init();
    int n, m;
    read(n, m);
    ll ans = 0;
    for (int i = n%2; i <= n; i += 2) {
        ll cnt12 = (n-i)/2;
        ans = add(ans, C(cnt12+i, i));
    }
    for (int i = m%2; i <= m; i += 2) {
        ll cnt12 = (m-i)/2;
        ans = add(ans, C(cnt12+i, i));
    }
    ans = add(ans, -1);
    cout << mul(ans, 2) << endl;

    return 0;
}
