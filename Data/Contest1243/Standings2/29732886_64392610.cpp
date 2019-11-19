#include <bits/stdc++.h>

#define lo(i, n, m) for (int i = n; i < m; i++)
#define loe(i, n, m) for (int i = n; i <= m; i++)
#define rlo(i, n, m) for (int i = n - 1; i >= m; i--)
#define rloe(i, n, m) for (int i = n; i >= m; i--)
#define pb push_back
#define mk make_pair
#define scd(x) scanf("%d", &x)
#define scs(x) scanf("%s", x)
#define sclf(x) scanf("%lf", &x)
#define scll(x) scanf("%lld", &x)
#define clr(a, b) memset((a), (b), sizeof(a))
typedef long long ll;
using namespace std;
// const int INF = 0x3f3f3f3f;
// const int INF = 0x7fffffff;
// const LL INF = 0x3f3f3f3f3f3f3f3f;
// const LL INF = 0x7fffffffffffffff;
const int NIL = -1;
template <class T>
inline T mx(T a, T b) {return a > b ? a : b;}
template <class T>
inline T mi(T a, T b) {return a < b ? a : b;}
template <class T>
inline void sw(T &a, T &b) {
    T t = a; a = b; b = t;
}
template <class T>
inline T mabs(T x) {return x < 0 ? -x : x;}
inline char gc() {
    char ret;
    while ((ret = getchar()) == ' ' || ret == '\n' || ret == '\t');
    return ret;
}
template <class T>
inline T sq(T x) {return x * x;}

namespace Prime {
    typedef vector<pair<ll, ll> > vp;
    const int lim = 1e6 + 10;
    int psz, tra[lim], pct, prime[lim / 3], fct, tpct, gblct[1 << 7];
    ll rr[lim], gbltp[1 << 7], pbuf[lim];
    inline ll mul(ll a, ll b, ll p) {
        a %= p, b %= p;
        if (p <= 1000000000ll) return (a * b) % p;
        else if (p <= 1000000000000ll) return (((a * (b >> 20) % p) << 20) + (a * (b & ((1 << 20) - 1)) % p)) % p;
        else {
            ll d = (ll)floor(a * (long double)b / p + 0.5);
            ll r = (a * b - d * p) % p;
            if (r < 0) r += p;
            return r;
        }
    }
    inline void build(int _) {
        psz = _, pct = 0;
        int tmp;
        loe(i, 1, psz) tra[i] = i;
        loe(i, 2, psz) {
            if (i == tra[i]) prime[pct++] = i;
            for (int j = 0; (tmp = prime[j] * i) <= psz; j++) {
                tra[tmp] = prime[j];
                if (!(i % prime[j])) break;
            }
        }
    }
    inline void init() {
        fct = 0;
    }
    inline ll fp(ll b, ll p, ll m) {
        ll r = 1ll;
        do {
            if (p & 1) r = mul(r, b, m);
            b = mul(b, b, m);
        } while (p >>= 1);
        return r;
    }
    bool inp(ll a, ll n) {
        int cc = 0;
        ll p = n - 1;
        for (;~p&1; p>>=1,++cc);
        ll pre = fp(a, p, n), crt;
        while (cc--) {
            crt = mul(pre, pre, n);
            if (crt == 1 && pre != 1 && pre != n - 1) return true;
            pre = crt;
        }
        return pre != 1;
    }
    bool is_prime(ll x) {
        if (x < 2) return false;
        if (x <= psz) return tra[x] == x;
        if (~x&1) return false;
        loe(i, 0, 7) if (inp(rand() % (x - 1) + 1, x)) return false;
        return true;
    }
    ll gcd(ll a, ll b) {
        ll r = 1ll;
        while (a) {
            if ((~a & 1) && (~b & 1)) r <<= 1ll, a >>= 1ll, b >>= 1ll;
            else if (~a & 1) a >>= 1ll;
            else if (~b & 1) b >>= 1ll;
            else {
                if (a < b) std::swap(a, b);
                a -= b;
            }
        }
        return r * b;
    }
    ll rho(ll n) {
        while (1) {
            ll x = rand() % n, y, z = 1ll, *xp = rr, *yp = rr, c = rand() % 10 + 3;
            int cc = 32;
            *yp++ = x = (mul(x, x, n) + c) % n, xp++;
            *yp++ = y = (mul(x, x, n) + c) % n;
            while (x != y) {
                ll nxt = mul(x - y + n, z, n);
                if (!nxt) return gcd(z, n);
                if (!--cc) {
                    cc = 32;
                    nxt = gcd(nxt, n);
                    if (nxt != 1 && nxt != n) return nxt;
                }
                z = nxt;
                *yp++ = y = (mul(y, y, n) + c) % n;
                *yp++ = y = (mul(y, y, n) + c) % n;
                x = *xp++;
            }
        }
    }
    void decomp(ll x) {
        lo(i, 0, fct) if (!(x % pbuf[i])) x /= pbuf[i], pbuf[fct++] = pbuf[i];
        if (x <= psz) {
            for (; x != 1; x /= tra[x]) pbuf[fct++] = tra[x];
        } else if (is_prime(x)) pbuf[fct++] = x;
        else {
            ll tmp = rho(x);
            decomp(tmp), decomp(x / tmp);
        }
    }
    void ctform() {
        tpct = 0;
        sort(pbuf, pbuf + fct);
        lo(i, 0, fct) if (!i || pbuf[i] != pbuf[i - 1]) {
            gbltp[tpct] = pbuf[i];
            gblct[tpct++] = 1;
        } else {
            ++gblct[tpct - 1];
        }
    }
    vp genP(ll x) {
        init();
        decomp(x);
        ctform();
        vp ret;
        lo(i, 0, tpct) ret.pb(mk(gbltp[i], gblct[i]));
        return ret;
    }
    void dfs(ll crt, int dept, vector<ll> &ret) {
        if (dept == tpct) ret.pb(crt);
        else {
            dfs(crt, dept + 1, ret);
            lo(i, 0, gblct[dept]) dfs(crt *= gbltp[dept], dept + 1, ret);
        }
    }
    vector<ll> genF(ll x) {
        init();
        decomp(x);
        ctform();
        vector<ll> ret;
        dfs(1ll, 0, ret);
        return ret;
    }
};

int main() {
    Prime::build(1000000);
    srand(time(0));
    ll n;
    scanf("%lld", &n);
    if (n == 1) {
        printf("1");
        return 0;
    }
    Prime::vp dat = Prime::genP(n);
    if (dat.size() == 0) {
        printf("%lld", n);
    } else if (dat.size() == 1) {
        printf("%lld", dat[0].first);
    } else {
        printf("%lld", 1ll);
    }
    return 0;
}
