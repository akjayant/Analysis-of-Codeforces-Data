#pragma GCC target("avx2")
#pragma GCC optimize("O3")
   
#include <x86intrin.h>
#include <bits/stdc++.h>   
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;

template<typename T> using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
     
#define F first
#define S second           
#define lb lower_bound               
#define ub upper_bound
#define pb push_back
#define pf push_front    
#define ppb pop_back
#define mp make_pair
#define bpp __builtin_popcountll                                                                                        
#define sqr(x) ((x) * (x)) 
#define al 0x3F3F3F3F
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define in insert
#define ppf pop_front
#define endl '\n'
#define int long long
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
 
const int mod = (int)1e9 + 7;
const int N = (int)3e5 + 123;
const ll inf = (ll)1e18 + 1;

const double pi = acos (-1.0);
const double eps = 1e-7;                  
const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};

int n, k, a[N], suff[N], s[N], p[N], pref[N], ans, sum1;
vector <pii> v;
vector <int> u;

inline void boost () {                    
   ios_base :: sync_with_stdio (NULL);
   cin.tie (NULL), cout.tie (NULL);          
}                                                     

inline void Solve () {
   cin >> n >> k;
   for (int i = 1; i <= n; i ++) cin >> a[i];
   sort (a + 1, a + n + 1);
   ans = a[n] - a[1];
   for (int i = 1; i <= n; i ++) {
      int j = i;
      while (j + 1 <= n && a[j + 1] == a[i]) j ++;
      v.pb ({a[i], j - i + 1});
      u.pb (a[i]);
      i = j;
   }
   for (int i = sz (v) - 1; i >= 0; i --) {
      suff[i] = suff[i + 1] + v[i].F * v[i].S;
      s[i] = s[i + 1] + v[i].S;
   }
   for (int i = 0; i < sz (v); i ++) {
      pref[i] = (i ? pref[i - 1] : 0) + v[i].F * v[i].S;
      p[i] = (i ? p[i - 1] : 0) + v[i].S;     
   }
   for (int i = 0; i < sz (v); i ++) {
      sum1 = v[i].F * (i ? p[i - 1] : 0) - (i ? pref[i - 1] : 0);
      int l = v[i].F, r = v.back ().F, pos = inf;
      while (l <= r) {
         int mid = l + r >> 1;
         int id = ub (all (u), mid) - u.begin ();
         if (suff[id] - s[id] * mid + sum1 <= k) r = mid - 1, pos = mid;
         else l = mid + 1;     
      }
      ans = min (ans, pos - v[i].F);
   }
   for (int i = sz (v) - 1; i >= 0; i --) {
      sum1 = suff[i + 1] - v[i].F * s[i + 1];
      int l = v[0].F, r = v[i].F, pos = -inf;
      while (l <= r) {
         int mid = l + r >> 1;
         int id = lb (all (u), mid) - u.begin () - 1;
         if ((id >= 0 ? p[id] * mid - pref[id] : 0) + sum1 <= k) l = mid + 1, pos = mid;
         else r = mid - 1;
      }
      ans = min (ans, v[i].F - pos);
   }
   cout << ans;
}

main () {                                       
// freopen (".in", "r", stdin);    
// freopen (".out", "w", stdout);              
   boost ();
   int tt = 1;
   //cin >> tt;   
   while (tt --) {
      Solve ();
   }                                               
   return 0;      
}
                          