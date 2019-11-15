#pragma GCC optimize "O3"
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define POP pop_back
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define F first
#define S second
#define X real()
#define Y imag()
#ifndef LOCAL
    #define endl "\n"
#endif

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef long long C;
typedef complex<C> P;

const int INF = 1e9;
const long long LLINF = 1e18;
const double PI = 3.14159265358979323;
const long long PRIME = (1ll << 31) - 1;
const long long PRIME2 = 269;
const long long MOD = 1e9 + 7;

template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T, class U> using ordered_map = tree<T, U, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T> using hash_set = gp_hash_table<T, null_type>;
template <class T, class U> using hash_map = gp_hash_table<T, U>;
template <class T, class U> ostream& operator<< (ostream &out, pair<T, U> p) { return out << "(" << p.F << ", " << p.S << ")"; }
template <class T> ostream& operator<< (ostream &out, vector<T> c) { for (auto it = c.begin(); it != c.end(); ++it) { if (it != c.begin()) out << " "; out << *it; } return out; }
template <class T> ostream& operator<< (ostream &out, set<T> c) { for (auto it = c.begin(); it != c.end(); ++it) { if (it != c.begin()) out << " "; out << *it; } return out; }
template <class T, class U> ostream& operator<< (ostream &out, map<T, U> c) { for (auto it = c.begin(); it != c.end(); ++it) { if (it != c.begin()) out << " "; out << *it; } return out; }
template <class T> ostream& operator<< (ostream &out, ordered_set<T> c) { for (auto it = c.begin(); it != c.end(); ++it) { if (it != c.begin()) out << " "; out << *it; } return out; }
template <class T, class U> ostream& operator<< (ostream &out, ordered_map<T, U> c) { for (auto it = c.begin(); it != c.end(); ++it) { if (it != c.begin()) out << " "; out << *it; } return out; }
template <class T> ostream& operator<< (ostream &out, hash_set<T> c) { for (auto it = c.begin(); it != c.end(); ++it) { if (it != c.begin()) out << " "; out << *it; } return out; }
template <class T, class U> ostream& operator<< (ostream &out, hash_map<T, U> c) { for (auto it = c.begin(); it != c.end(); ++it) { if (it != c.begin()) out << " "; out << *it; } return out; }
template <class T> int sign (T x) { return (x > 0) - (x < 0); }
inline ll mod (ll a, ll b) { return a%b + (a < 0) * b; }
inline ll mod (ll a) { return mod(a, MOD); }
C dot (P a, P b) { return a.X * b.X + a.Y * b.Y; }
C cross (P a, P b) { return a.X * b.Y - b.X * a.Y; }

double startTime;
double currTime() { return duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count() / 1e9; }
double execTime() { return currTime() - startTime; }

ll multiply (ll a, ll b, ll modulo) {
    a = mod(a, modulo);
    b = mod(b, modulo);
    ll result = 0;
    while (b > 0) {
        if (b & 1)
            result = mod(result + a, modulo);
        b = b >> 1;
        a = mod(a * 2, modulo);
    }
    return result;
}

ll pow (ll base, ll exp, ll modulo) {
    if (exp == 0)
        return mod(1, modulo);
    ll result = mod(1, modulo);
    base = mod(base, modulo);
    while (exp > 0) {
        if (exp & 1)
            result = multiply(result, base, modulo);
        exp = exp >> 1;
        base = multiply(base, base, modulo);
    }
    return result;
}

ll inv (ll a, ll modulo) {
    return pow(a, modulo - 2, modulo);
}

ll gcd (ll a, ll b, ll *x = NULL, ll *y = NULL) {
    a = abs(a), b = abs(b);
    pll s = { 1, 0 }, t = { 0, 1 }, r = { a, b };
    while (r.S != 0) {
        ll q = r.F / r.S;
        r = { r.S, r.F - q * r.S };
        s = { s.S, s.F - q * s.S };
        t = { t.S, t.F - q * t.S };
    }
    if (x) *x = s.F;
    if (y) *y = t.F;
    return r.F;
}

vector<int> spf;
void build_sieve (int n) {
    spf.resize(n + 1);
    spf[0] = spf[1] = -1;
    for (int i = 2; i <= n; i++)
        spf[i] = i;
    for (int i = 2; i <= n; i++)
        if (spf[i] == i)
            for (int j = 2 * i; j <= n; j += i)
                spf[j] = min(spf[j], i);
}

bool miller_test (ll n, ll d, ll r, ll a) {
    ll x = pow(a, d, n);
    if (x == 1 || x == n - 1)
        return true;
    for (int i = 0; i < r; i++) {
        x = multiply(x, x, n);
        if (x == n - 1)
            return true;
    }
    return false;
}

bool miller_rabin (ll n) {
    if (n < 2)
        return false;
    if (n < 4)
        return true;
    ll d = n - 1, r = 0;
    while (d % 2 == 0) {
        d /= 2;
        r++;
    }
    vector<ll> a{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
    for (int i = 0; i < a.size() && a[i] <= n - 2; i++)
        if (!miller_test(n, d, r, a[i]))
            return false;
    return true;
}

ll pollard_rho (ll n) {
    while (true) {
        ll a = mod(rand(), n);
        auto f = [&](ll x) { return mod(multiply(x, x, n) + a, n); };
        ll x = mod(rand(), n), y = x;
        do {
            x = f(x);
            y = f(f(y));
            ll p = __gcd(abs(x - y), n);
            if (p > 1 && p < n)
                return p;
        } while (x != y);
    }
}

vector<pll> factorise (ll n) {
    if (n < 2)
        return vector<pll>();
    if (n <= spf.size()) {
        vector<pll> ans;
        while (n > 1) {
            if (ans.empty() || ans.back().F != spf[n])
                ans.PB(MP(spf[n], 1));
            else
                ans.back().S++;
            n /= spf[n];
        }
        return ans;
    } else {
        vector<ll> v, factors;
        v.PB(n);
        while (!v.empty()) {
            ll x = v.back();
            v.POP();
            if (miller_rabin(x))
                factors.PB(x);
            else {
                ll p = pollard_rho(x), q = x/p;
                v.PB(p); v.PB(q);
            }
        }
        sort(factors.begin(), factors.end());
        vector<pll> ans;
        for (int i = 0; i < factors.size(); i++)
            if (ans.empty() || ans.back().F != factors[i])
                ans.PB(MP(factors[i], 1));
            else
                ans.back().S++;
        return ans;
    }
}

int main() {
#ifndef LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    srand(time(0));
    startTime = currTime();

    ll n, m;
    cin >> n >> m;
    cout << pow(mod(pow(2, m, MOD) - 1), n, MOD) << endl;    
}