#include <bits/stdc++.h>
#define LLI long long int
#define FOR(v, a, b) for(LLI v = (a); v < (b); ++v)
#define FORE(v, a, b) for(LLI v = (a); v <= (b); ++v)
#define REP(v, n) FOR(v, 0, n)
#define REPE(v, n) FORE(v, 0, n)
#define REV(v, a, b) for(LLI v = (a); v >= (b); --v)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define ITR(it, c) for(auto it = (c).begin(); it != (c).end(); ++it)
#define RITR(it, c) for(auto it = (c).rbegin(); it != (c).rend(); ++it)
#define EXIST(c,x) ((c).find(x) != (c).end())
#define fst first
#define snd second
#define popcount __builtin_popcount
#define UNIQ(v) (v).erase(unique(ALL(v)), (v).end())
#define bit(i) (1LL<<(i))

#ifdef DEBUG
#include <misc/C++/Debug.cpp>
#else
#define dump(...) ((void)0)
#endif

#define gcd __gcd

using namespace std;
template <class T> constexpr T lcm(T m, T n){return m/gcd(m,n)*n;}

template <typename I> void join(ostream &ost, I s, I t, string d=" "){for(auto i=s; i!=t; ++i){if(i!=s)ost<<d; ost<<*i;}ost<<endl;}
template <typename T> istream& operator>>(istream &is, vector<T> &v){for(auto &a : v) is >> a; return is;}

template <typename T, typename U> bool chmin(T &a, const U &b){return (a>b ? a=b, true : false);}
template <typename T, typename U> bool chmax(T &a, const U &b){return (a<b ? a=b, true : false);}
template <typename T, size_t N, typename U> void fill_array(T (&a)[N], const U &v){fill((U*)a, (U*)(a+N), v);}

struct Init{
  Init(){
    cin.tie(0);
    ios::sync_with_stdio(false);
  }
}init;

template <uint32_t M> class ModInt{
public:
  uint64_t val;
  ModInt(): val(0){}
  ModInt(int64_t n){
    if(n >= M) val = n % M;
    else if(n < 0) val = n % M + M;
    else val = n;
  }
  
  inline constexpr ModInt operator+(const ModInt &a) const {return ModInt((val+a.val)%M);}
  inline constexpr ModInt operator-(const ModInt &a) const {return ModInt((val-a.val+M)%M);}
  inline constexpr ModInt operator*(const ModInt &a) const {return ModInt((val*a.val)%M);}
  inline constexpr ModInt operator/(const ModInt &a) const {return ModInt((val*a.inv().val)%M);}
  
  inline constexpr ModInt& operator=(const ModInt &a){val = a.val; return *this;}
  inline constexpr ModInt& operator+=(const ModInt &a){if((val += a.val) >= M) val -= M; return *this;}
  inline constexpr ModInt& operator-=(const ModInt &a){if(val < a.val) val += M; val -= a.val; return *this;}
  inline constexpr ModInt& operator*=(const ModInt &a){(val *= a.val) %= M; return *this;}
  inline constexpr ModInt& operator/=(const ModInt &a){(val *= a.inv().val) %= M; return *this;}

  inline constexpr bool operator==(const ModInt &a) const {return val==a.val;}
  inline constexpr bool operator!=(const ModInt &a) const {return val!=a.val;}

  inline constexpr ModInt& operator++(){*this += 1; return *this;}
  inline constexpr ModInt& operator--(){*this -= 1; return *this;}

  inline constexpr ModInt operator++(int){ModInt t = *this; *this += 1; return t;}
  inline constexpr ModInt operator--(int){ModInt t = *this; *this -= 1; return t;}
  
  inline constexpr static ModInt power(int64_t n, int64_t p){
    ModInt ret = 1, e = n;
    for(; p; e *= e, p >>= 1) if(p&1) ret *= e;
    return ret;
  }

  inline constexpr ModInt power(int64_t p) const {return power(val,p);}
  
  inline constexpr ModInt inv() const {
    int64_t a = val, b = M, u = 1, v = 0;

    while(b){
      int64_t t = a/b;
      a -= t*b; swap(a,b);
      u -= t*v; swap(u,v);
    }
    u %= M;
    if(u < 0) u += M;
    
    return u;
  }
};

template <uint32_t M> ModInt<M> operator-(const ModInt<M> &a){return M-a.val;}

template <uint32_t M> ModInt<M> operator+(int64_t a, const ModInt<M> &b){return ModInt<M>(ModInt<M>(a)+b.val);}
template <uint32_t M> ModInt<M> operator-(int64_t a, const ModInt<M> &b){return ModInt<M>(ModInt<M>(a)-b.val);}
template <uint32_t M> ModInt<M> operator*(int64_t a, const ModInt<M> &b){return ModInt<M>(ModInt<M>(a)*b.val);}
template <uint32_t M> ModInt<M> operator/(int64_t a, const ModInt<M> &b){return ModInt<M>(ModInt<M>(a)/b.val);}

template <uint32_t M> istream& operator>>(istream &is, ModInt<M> &a){is >> a.val; return is;}
template <uint32_t M> ostream& operator<<(ostream &os, const ModInt<M> &a){ os << a.val; return os;}




const LLI mod = 1e9+7;
using mint = ModInt<mod>;

int main(){
  LLI n,m;
  while(cin >> n >> m){
    mint ans = (mint::power(2,m)-1).power(n);

    cout << ans << endl;
  }

  return 0;
}
