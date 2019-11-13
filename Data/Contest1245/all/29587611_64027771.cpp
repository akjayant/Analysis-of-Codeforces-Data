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

const ll mod = 1e9+7;

ll a[100'007];

int main()
{
  #ifdef OJUDGE
    //freopen("in","r",stdin);
  #endif
  INIT;
  
  a[1] = 1;
  a[2] = 2;
  for(int i=3;i<100'007;++i) a[i] = (a[i-1] + a[i-2]) % mod;
  
  string s;
  cin >> s;
  
  ll ans = 1;
  int uStreak = 0;
  int nStreak = 0;
  for(char c: s)
  {
    if(c == 'w' || c == 'm') return !(cout << "0\n");
    
    if(c == 'u')
    {
      ++uStreak;
      if(nStreak > 1) ans = ans * a[nStreak] % mod;
      nStreak = 0;
    }else if(c == 'n')
    {
      ++nStreak;
      if(uStreak > 1) ans = ans * a[uStreak] % mod;
      uStreak = 0;
    }else
    {
      if(uStreak > 1) ans = ans * a[uStreak] % mod;
      if(nStreak > 1) ans = ans * a[nStreak] % mod;
      uStreak = 0;
      nStreak = 0;
    }
  }
  if(uStreak > 1) ans = ans * a[uStreak] % mod;
  if(nStreak > 1) ans = ans * a[nStreak] % mod;
  
  cout << ans << endl;
  
  return 0;
}

#warning you will remember this, overflow is there, though you might not see it ...

