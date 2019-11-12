#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

#define n_l '\n'
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; cout << to_string(__VA_ARGS__) << endl
template <typename T, size_t N> int SIZE(const T (&t)[N]){ return N; } template<typename T> int SIZE(const T &t){ return t.size(); } string to_string(const string s, int x1=0, int x2=1e9){ return '"' + ((x1 < s.size()) ? s.substr(x1, x2-x1+1) : "") + '"'; } string to_string(const char* s) { return to_string((string) s); } string to_string(const bool b) { return (b ? "true" : "false"); } string to_string(const char c){ return string({c}); } template<size_t N> string to_string(const bitset<N> &b, int x1=0, int x2=1e9){ string t = ""; for(int __iii__ = min(x1,SIZE(b)),  __jjj__ = min(x2, SIZE(b)-1); __iii__ <= __jjj__; ++__iii__){ t += b[__iii__] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(const A (&v), int x1=0, int x2=1e9, C... coords); int l_v_l_v_l = 0, t_a_b_s = 0; template <typename A, typename B> string to_string(const pair<A, B> &p) { l_v_l_v_l++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; l_v_l_v_l--; return res; } template <typename A, typename... C> string to_string(const A (&v), int x1, int x2, C... coords) { int rnk = rank<A>::value; string tab(t_a_b_s, ' '); string res = ""; bool first = true; if(l_v_l_v_l == 0) res += n_l; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2-x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; l_v_l_v_l++; if(e != l){ if(rnk > 1) { res += n_l; t_a_b_s = l_v_l_v_l; }; } else{ t_a_b_s = 0; } res += to_string(*e, coords...); l_v_l_v_l--; } res += "]"; if(l_v_l_v_l == 0) res += n_l; return res; } void dbgm(){;} template<typename Heads, typename... Tails> void dbgm(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgm(T...); }
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgm(__VA_ARGS__); cout << endl

#define REP(i,b) for(int i=0;i<(b);i++)
#define REPP(i,b) for(int i=1;i<=(b);i++)
#define PER(i,a,b) for(int i=(a);i>(b);i++)
#define SZ(a) int((a).size())
#define ALL(a) (a).begin(), (a).end()
#define MS(s) memset(s, 0, sizeof(s))
#define PB push_back
#define MP make_pair

typedef vector<pair<int, int>> VPII;
typedef pair<int, int> PII;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = (int) 1e9 + 7;
string ascii_lowercase = "abcdefghijklmnopqrstuvwxyz";
string ascii_uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

struct hashLL { /* mp.rehash(n << 2); */
    size_t operator()(ll x) const {
        x = (x ^ (x >> 30)) * UINT64_C(0xbf58476d1ce4e5b9);
        x = (x ^ (x >> 27)) * UINT64_C(0x94d049bb133111eb);
        x = x ^ (x >> 31);
        return x;
    }
};

long long inv(long long a, long long b) {
    return 1 < a ? b - inv(b % a, a) * b / a : 1;
}

const ll INF = 1e6;

// unordered_map<int, int, custom_hash> mp;
// unordered_map<int, unordered_map<int, int, custom_hash>, custom_hash> g;

ll gcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll distsq(ll x1, ll y1, ll x2, ll y2) {
    return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}

ll n, m;

ll mul(ll a, ll b) {
    return (a*b)%MOD;
}
ll add(ll a, ll b) {
    return (a+b)%MOD;
}

ll powmod(ll b, ll p) {
    ll ans = 1;
    ll curr = b;
    while(p) {
        if(p&1) ans = mul(ans, curr);
        curr = mul(curr, curr);
        p>>=1;
    }
    return ans;
}

int main() {
    // freopen("input.txt", "r", stdin); freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    ll coeffSum = powmod(2, m);
    ll x = coeffSum - 1;
    ll ways = powmod(x, n);
    cout << ways;
    return 0;
}