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

int main()
{
  #ifdef OJUDGE
    //freopen("in","r",stdin);
  #endif
  //~ INIT;
  int tt;
  scanf("%d", &tt);
  while(tt--)
  {
    int n, m;
    ll odd1=0, odd2=0, even1=0, even2=0;
    scanf("%d", &n);
    for(int i=1;i<=n;++i)
    {
      int x;
      scanf("%d", &x);
      if(x & 1) ++odd1;
      else ++even1;
    }
    scanf("%d", &m);
    for(int i=1;i<=m;++i)
    {
      int x;
      scanf("%d", &x);
      if(x & 1) ++odd2;
      else ++even2;
    }
    printf("%lld\n", 1ll * odd1 * odd2 + 1ll * even1 * even2);
  }
  return 0;
}

#warning you will remember this, overflow is there, though you might not see it ...

