#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

typedef double d;
typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define INIT ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0)
#define endl '\n'
#define fr first
#define sc second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define ers erase
#define sz(c) ((int)(c).size())
#define all(x) (x).begin(),(x).end()
#define unique(x) (x).resize(unique(all(x))-(x).begin())
#define debug(_fmt,...) fprintf(stderr,"("#__VA_ARGS__ ") = (" _fmt")\n",__VA_ARGS__)

const d eps = 1e-12;

inline int sign(d x) { return x < -eps ? -1 : x > eps; }
inline int realcmp(d x, d y) { return sign(x-y); }
template<typename T> void na(vector<T>& a, int n) {a = vector<T>(n);for(T& i: a) cin >> i;}
template<typename T> void pv(vector<T>& a) { for(T& i: a) cout << i << ' '; cout << endl; }
template<typename T> vector<T> shrink(vector<T>& x) { vector<T> vals = x; sort(all(vals)); unique(vals); for(T& i: x) i = ub(all(vals), i) - vals.begin(); return vals; }

typedef vector<vector<ll>> mat;

const ll mod = 1e9+7;

mat base
{
  {1,1,1},
  {1,0,0},
  {0,0,1}
};

mat iden
{
  {1,0,0},
  {0,1,0},
  {0,0,1}
};

mat mul(mat a, mat b)
{
  int n = a.size();
  int nn = b.size();
  int m = b.front().size();
  mat res(n, vector<ll> (m, 0));
  for(int i=0;i<n;++i)
    for(int j=0;j<m;++j)
      for(int k=0;k<nn;++k)
        res[i][j] = (res[i][j] + a[i][k] * b[k][j] % mod) % mod;
  return res;
}

mat qpow(mat b, int e)
{
  if(e == 0) return iden;
  if(e == 1) return b;
  if(e & 1) return mul(b, qpow(b, e-1));
  auto tmp = qpow(b, e >> 1);
  return mul(tmp, tmp);
}

ll qpow(ll b, ll e)
{
  if(e == 0) return 1;
  if(e == 1) return b;
  if(e & 1) return b * qpow(b, e-1) % mod;
  auto tmp = qpow(b, e >> 1);
  return tmp*tmp%mod;
}

int main()
{
  #ifdef OJUDGE
    //freopen("in","r",stdin);
  #endif
  INIT;
  
  int n, m;
  cin >> n >> m;
  
  auto a = mul(qpow(base, n-1), mat({{4},{2},{0}}))[1][0];
  auto b = mul(qpow(base, n-1), mat({{6},{4},{mod-2}}))[1][0];
  auto c = mul(qpow(base, n-1), mat({{8},{6},{mod-4}}))[1][0];
  cerr << "a = " << a << " b = " << b << " c = " << c << endl;
  
  //~ if(n == 1)
    cout << mul(qpow(base, m-1), mat({{b},{a},{(c + mod - (a + b) % mod)%mod}}))[1][0] << endl;
  //~ else
    //~ cout << mul(qpow(base, m-1), mat({{b},{a},{(mod-qpow(2ll, n-1))%mod}}))[1][0] << endl;
  
  
  return 0;
}

#warning you will remember this, overflow is there, though you might not see it ...

