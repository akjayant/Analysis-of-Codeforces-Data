#include <bits/stdc++.h>
using namespace std;
#define int long long
#define stoi stoll
using pii=pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define all(c) begin(c),end(c)
#define rall(c) rbegin(c),rend(c)
#define fore(x,c) for(auto &&x:c)
#define rep(i,a,n) for(int i=a,i##len=(int)(n);i<i##len;++i)
#define rrep(i, a, n) for(int i=(int)(n-1);i>=a;--i)
#define sz(c) ((int)c.size())
#define contains(c,x) (c.find(x)!=end(c))
#define inseg(l,x,r) ((l)<=(x)&&(x)<(r))
#define dump(...)
#define pb push_back
#define _ 0
const signed INF_=1001001001; const long long INF=1001001001001001001LL;
const int DX[9]={0,1,0,-1,1,1,-1,-1,0},DY[9]={-1,0,1,0,-1,1,1,-1,0};
template<class T> ostream& operator<<(ostream &os,const vector<T> &v) {
    for (auto i = begin(v); i != end(v); i++) os<<*i<<(i==end(v)-1?"":" ");return os;}
template<class T> istream& operator>>(istream &is,vector<T> &v) {
    for (auto i = begin(v); i != end(v); i++) is>>*i;return is;}
template<class T,class U> istream& operator>>(istream &is, pair<T,U> &p) {
    is>>p.first>>p.second;return is;}
template<class T, class U> bool chmax(T &a,const U &b){return a<b?a=b,1:0;}
template<class T, class U> bool chmin(T &a,const U &b){return a>b?a=b,1:0;}
template <class T> void psum(T& c) {partial_sum(begin(c), end(c), begin(c));}
template<class T> using heap=priority_queue<T,vector<T>,greater<T>>;
struct before_main_function {
    before_main_function() {
        cin.tie(nullptr); ios::sync_with_stdio(0);
        cout << setprecision(15) << fixed;
        // #define endl "\n"
    }
} before_main_function;
//------------------8<------------------------------------8<--------------------

template <int mod>
class ModInt {
public:
    ModInt() : v(0) {}
    ModInt(int x) : v((x+mod)%mod) {}
    int value() const {return v;}
    const ModInt operator+(const ModInt &r) const { return ModInt(this->v + r.v); }
    const ModInt operator-(const ModInt &r) const { return ModInt(this->v + mod - r.v); }
    const ModInt operator*(const ModInt &r) const { return ModInt(this->v * r.v); }
    const ModInt operator/(const ModInt &r) const { return (*this * (~r)); }
    const ModInt operator^(int k) const { return ModInt(bpow(this->v, k)); }
    const ModInt operator~() const { return ModInt(bpow(this->v, mod-2)); }
    bool operator==(const ModInt &r) const { return this->v == r.v; }
    bool operator!=(const ModInt &r) const { return this->v != r.v; }
    ModInt& operator+=(const ModInt &r) { return *this = *this + r; }
    ModInt& operator-=(const ModInt &r) { return *this = *this - r; }
    ModInt& operator*=(const ModInt &r) { return *this = *this * r; }
    ModInt& operator/=(const ModInt &r) { return *this = *this * (~r); }
private:
    int v;
    int bpow(int a, int b) const {
        int ret = 1;
        while (b > 0) {
            if (b & 1) ret = (ret * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return ret;
    }
};
using Mint = ModInt<1000000007>;
signed main() {
    string s;
    cin >> s;
    if (s.find('m') != string::npos || s.find('w') != string::npos) {
        cout << 0 << endl;
        return 0;
    }

    int N = sz(s);
    vector<Mint> dp(N + 1, 0);
    dp[0] = 1;
    rep(i, 0, N) {
        dp[i + 1] += dp[i];
        if (i + 2 <= N) dp[i + 2] += dp[i];
    }

    int u_cont = 0;
    int n_cont = 0;
    Mint ans = 1;
    s += '#';
    rep(i, 0, N + 1) {
        if (s[i] == 'u') {
            u_cont++;
        } else {
            if (u_cont) {
                ans *= dp[u_cont];
                u_cont = 0;
            }
        }

        if (s[i] == 'n') {
            n_cont++;
        } else {
            if (n_cont) {
                ans *= dp[n_cont];
                n_cont = 0;
            }
        }
    }
    cout << ans.value() << endl;
    return (0^_^0);
}

