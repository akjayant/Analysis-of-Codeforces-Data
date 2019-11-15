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

int beats[256];
int frA[256];
vector<int> p{'R', 'P', 'S'};
int main()
{
  #ifdef OJUDGE
    //freopen("in","r",stdin);
  #endif
  INIT;
  
  beats['S'] = 'R';
  beats['R'] = 'P';
  beats['P'] = 'S';
  
  int tt;
  cin >> tt;
  while(tt--)
  {
    
    memset(frA, 0, sizeof frA);
    int n;
    cin >> n;
    
    cin >> frA['R'];
    cin >> frA['P'];
    cin >> frA['S'];
    
    int totWins = 0;
    string G, ans="";
    cin >> G;
    for(char c: G)
    {
      //~ cerr << c << ' ' << frA[beats[c]]  << ' '<< beats[c];
      if(frA[beats[c]] > 0) -- frA[beats[c]], ans += beats[c], ++totWins
      //~ , cerr << "win"
      ;
      else ans += '$';
      //~ cerr << endl;
    }
    
    
    //~ cerr << totWins << endl;
    for(int i=0;i<n;++i) if(ans[i] == '$')
    {
      for(auto& j: p) if(frA[j] > 0)
      {
        ans[i] = j;
        --frA[j];
        break;
      }
    }
    if(totWins >= (n + 1) / 2) cout << "YES\n" << ans << endl;
    else cout << "NO\n";
  }
  
  return 0;
}

#warning you will remember this, overflow is there, though you might not see it ...
 