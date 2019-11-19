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

const int MX = 2222;

struct Edge
{
  int u, v;
  ll w;
  Edge(){}
  Edge(int u, int v, ll w)
  : u(u), v(v), w(w){}
  bool operator <(const Edge& e)const
  {
    return w < e.w;
  }
};

ll c[MX], x[MX], y[MX], k[MX];

ll dist(int i, int j)
{
  return labs(x[i] - x[j]) + labs(y[i] - y[j]);
}

int rt[MX];
int rk[MX];
int fs(int x)
{
  if(rt[x] != x) return rt[x] = fs(rt[x]);
  return x;
}

bool js(int x, int y)
{
  x = fs(x);
  y = fs(y);
  if(x == y) return false;
  if(rk[x] < rk[y]) swap(x, y);
  rk[x] += rk[y];
  rt[y] = x;
  return true;
}

int main()
{
  #ifdef OJUDGE
    //freopen("in","r",stdin);
  #endif
  //~ INIT;
  
  int n;
  scanf("%d", &n);
  for(int i=1;i<=n;++i)
  {
    scanf("%lld %lld", x+i, y+i);
  }
  for(int i=1;i<=n;++i) scanf("%lld", c+i);
  for(int i=1;i<=n;++i) scanf("%lld", k+i);
  
  vector<Edge> E;
  for(int i=1;i<=n;++i) E.eb(0, i, c[i]);
  
  for(int i=1;i<=n;++i)
    for(int j=i+1;j<=n;++j)
      E.eb(i, j, (k[i] + k[j]) * dist(i, j));
  
  for(int i=0;i<=n;++i) rt[i] = i, rk[i] = 1;
  
  vector<int> PE;
  vector<pii> Conn;
  sort(all(E));
  ll sol = 0;
  for(auto & e: E)
  {
    if(js(e.u, e.v))
    {
      sol += e.w;
      if(e.u == 0 || e.v == 0)
      {
        PE.pb(max(e.u, e.v));
      }else Conn.eb(e.u, e.v);
    }
  }
  
  printf("%lld\n", sol);
  printf("%d\n", sz(PE));
  for(int i: PE) printf("%d ", i);
  printf("\n");
  printf("%d\n", sz(Conn));
  for(pii i:Conn) printf("%d %d\n", i.fr, i.sc);
  printf("\n");
  
  return 0;
}

#warning you will remember this, overflow is there, though you might not see it ...

