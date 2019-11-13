#include <bits/stdc++.h>
 
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define INF  (1<<30)
#define INFL (1LL<<60)
#define EPS ((ld)(1e-9))
 
#define sz(x) ((int)(x).size())
#define setz(x) memset(x, 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define rep(i, e) for (int i = 0, _##i = (e); i < _##i; i++)
#define repp(i, s, e) for (int i = (s), _##i = (e); i < _##i; i++)
#define repr(i, s, e) for (int i = (s)-1, _##i = (e); i >= _##i; i--)
#define repi(i, x) for (auto &i : (x))
#define ARR(...) vector<int>({__VA_ARGS__})
#define ARS(...) vector<string>({__VA_ARGS__})
 
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef complex<double> base;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
 
template<typename T, typename V>
ostream &operator<<(ostream &os, const pair<T, V> pai) { 
    return os << '(' << pai.first << ' ' << pai.second << ')';
}
 
template<typename T>
ostream &operator<<(ostream &os, const vector<T> v) {
    cout << '[';
    for (auto p : v) cout << p << ",";
    cout << "]";
    return os;
}
 
template<typename T, typename V>
ostream &operator<<(ostream &os, const set<T, V> v) {
    cout << "{";
    for (auto p : v) cout << p << ",";
    cout << "}";
    return os;
}
 
template<typename T, typename V>
ostream &operator<<(ostream &os, const map<T, V> v) {
    cout << "{";
    for (auto p : v) cout << p << ",";
    cout << "}";
    return os;
}
 
#ifndef __DJKIM613
#define debug(...) 0
#define endl '\n'
#else
#define debug(...) cout << " [-] ", _dbg(#__VA_ARGS__, __VA_ARGS__)
template<class TH> void _dbg(const char *sdbg, TH h){ cout << sdbg << '=' << h << endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
    while(*sdbg != ',') cout << *sdbg++;
    cout << '=' << (h) << ','; 
    _dbg(sdbg+1, a...);
}
#endif
 
template<typename T> void get_max(T &a, T b) {a = max(a, b);}
template<typename T> void get_min(T &a, T b) {a = min(a, b);}


typedef long long ll;
const ll MOD = 1e9 + 7;

ll mod_pow(ll a, ll b){
    ll ret = 1;
    while(b){
        if(b & 1) ret *= a, ret %= MOD;
        a = a * a % MOD;   b >>= 1;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    ll base = (mod_pow(2, M) + MOD - 1) % MOD;
    base = mod_pow(base, N);

    cout << base << '\n';
    return 0;
}