#include <bits/stdc++.h>
using namespace std;

// macros
#define overload_rep(_1, _2 ,_3 ,name, ...) name
#define re_p(i, n) for(int i = 0; i < (n); ++i)
#define r_ep(i, x, y) for(int i = (x); i <= (y); ++i)
#define rep(...) overload_rep(__VA_ARGS__, r_ep, re_p)(__VA_ARGS__)
#define all(a) a.begin(), a.end()
#ifndef STOP_DEBUG
#define debug(...)\
    do { cerr << boolalpha << "[" << #__VA_ARGS__ << "]:";\
    debug_cerr(__VA_ARGS__); cerr << noboolalpha; } while (0)
#else
#define debug(...)
#endif

// functions
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
void debug_cerr(){ cerr << '\n'; }
template<class Head, class... Tail>
void debug_cerr(Head head, Tail... tail){
    cerr << ' ' << head;
    debug_cerr(tail...);
}

// cin/cout setup
struct IoSetup{
    IoSetup(){
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} iosetup;

// Codeforces Round #594 (Div. 2)

template<const int_fast64_t mod = 1000000007>
struct ModInt{
private: using ll = int_fast64_t;
public: ll x;
    constexpr ModInt(ll t = 0) noexcept : x((t %= mod) < 0 ? t + mod : t) {}
    constexpr friend istream& operator >> (istream& s, ModInt& m) noexcept {
        s >> m.x; m.x %= mod; if(m.x < 0)m.x += mod; return s;
    }
    constexpr friend ostream& operator << (ostream& s, ModInt m) noexcept {
        return s << m.x;
    }
    constexpr ModInt operator + (const ModInt m) noexcept { return ModInt(*this) += m; }
    constexpr ModInt& operator += (const ModInt m) noexcept {
        if((x += m.x) >= mod)x -= mod; return *this;
    }
    constexpr ModInt operator - (const ModInt m) noexcept { return ModInt(*this) -= m; }
    constexpr ModInt& operator -= (const ModInt m) noexcept {
        if((x += mod - m.x) >= mod)x -= mod; return *this;
    }
    constexpr ModInt operator * (const ModInt m) noexcept { return ModInt(*this) *= m; }
    constexpr ModInt& operator *= (const ModInt m) noexcept {
        x = x * m.x % mod; return *this;
    }
    constexpr ModInt operator / (const ModInt m) noexcept { return ModInt(*this) /= m; }
    constexpr ModInt& operator /= (const ModInt m) noexcept {
        return *this *= m.inv();
    }
    constexpr ModInt inv() const noexcept {
        ll a = x, b = mod, u = 1, v = 0, t = 0;
        while(b){ t = a / b; a -= t * b; swap(a, b); u -= t * v; swap(u, v); }
        return ModInt(u);
    }
    constexpr ModInt pow(ll p) noexcept {
        ModInt res(1), mult(*this);
        for(; p; p >>= 1){ if(p & 1)res *= mult; mult *= mult; }
        return res;
    }
};

using mint = ModInt<>;
mint dp[100100];

int main(){
    
    int N, M;
    cin >> N >> M;

    dp[0] = dp[1] = mint(1);
    rep(i, 2, 100010)dp[i] = dp[i - 1] + dp[i - 2];

    cout << (dp[M] - mint(1)) * mint(2) + dp[N] * mint(2) << '\n';

}