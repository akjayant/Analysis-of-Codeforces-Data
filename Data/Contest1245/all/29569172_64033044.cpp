#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx")

#include <bits/stdc++.h>   
#include <stdio.h>    
 
using namespace std;
     
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
 
const int N = (int)2e5 + 123;
const ll inf = (ll)3e18 + 1;

const double pi = acos (-1.0);
const double eps = 1e-7;                  
const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};

int l, r, ans, dp[30][2][2][2][2];

int calc (int b = 29, bool sp1 = 1, bool sp2 = 1, bool sp3 = 1, bool sp4 = 1) {
   if (b < 0) return 1;
   int &res = dp[b][sp1][sp2][sp3][sp4];
   if (res != -1) return res;
   res = 0;
   for (int f1 = 0; f1 <= 1; f1 ++)
      for (int f2 = 0; f2 <= 1; f2 ++) {
         if (f1 == 1 && f2 == 1) continue;
         bool is1 = ((r & (1ll << b)) > 0);
         bool is2 = ((l & (1ll << b)) > 0);
         if ((sp2 && f2 < is2) || (sp1 && f1 > is1)) continue;
         if ((sp3 && f1 < is2)) continue;
         if ((sp4 && f2 > is1)) continue;
         bool _sp1 = (sp1 & (is1 == f1));
         bool _sp2 = (sp2 & (is2 == f2));
         bool _sp3 = (sp3 & (is2 == f1));
         bool _sp4 = (sp4 & (is1 == f2));
         res += calc (b - 1, _sp1, _sp2, _sp3, _sp4);
      }                                  
   return res;
}

inline void boost () {                    
   ios_base :: sync_with_stdio (NULL);
   cin.tie (NULL), cout.tie (NULL);          
}                                                     

inline void Solve () {
   cin >> l >> r;
   memset (dp, -1, sizeof dp);    
   cout << calc () << endl;
}                                     

main () {                                       
// freopen (".in", "r", stdin);    
// freopen (".out", "w", stdout);              
   boost ();
   int tt = 1;
   cin >> tt;   
   while (tt --) {
      Solve ();
   }                                               
   return 0;      
}
