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
//#define int long long
  
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
  
const int mod = (int)1e9 + 7;
const int N = (int)1e6 + 123;
const ll inf = (ll)1e18 + 1;
 
const double pi = acos (-1.0);
const double eps = 1e-7;                  
const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};

int n, a, b, c, dp[101][101][101], p[101][101][101];
bool used[101][101][101];
char s[101];
vector <char> res;

inline void boost () {                    
   ios_base :: sync_with_stdio (NULL);
   cin.tie (NULL), cout.tie (NULL);          
}                                                     
 
inline void Solve () {
   cin >> n >> a >> b >> c;
   for (int i = 0; i <= n; i ++)
      for (int j = 0; j <= a; j ++)
         for (int k = 0; k <= b; k ++)
            used[i][j][k] = dp[i][j][k] = p[i][j][k] = 0;
   used[0][a][b] = 1;
   for (int i = 1; i <= n; i ++) {
      cin >> s[i];
      for (int j = 0; j <= a; j ++)
         for (int k = 0; k <= b; k ++) {
            if (!used[i - 1][j][k]) continue;
            int used_c = i - 1 - (a - j + b - k);
            if (used_c < 0 || used_c > c) continue;
            if (j) {
               used[i][j - 1][k] = 1; 
               if (dp[i][j - 1][k] <= dp[i - 1][j][k] + (s[i] == 'S')) {
                  dp[i][j - 1][k] = dp[i - 1][j][k] + (s[i] == 'S');
                  p[i][j - 1][k] = 1;
               }
            }
            if (k) {
               used[i][j][k - 1] = 1; 
               if (dp[i][j][k - 1] <= dp[i - 1][j][k] + (s[i] == 'R')) {
                  dp[i][j][k - 1] = dp[i - 1][j][k] + (s[i] == 'R');
                  p[i][j][k - 1] = 2;
               }
            }
            if (used_c != c) {
               used[i][j][k] = 1; 
               if (dp[i][j][k] <= dp[i - 1][j][k] + (s[i] == 'P')) {
                  dp[i][j][k] = dp[i - 1][j][k] + (s[i] == 'P'); 
                  p[i][j][k] = 3;
               }
            }
         }
   }
   int ans = 0;
   int x = -1, y = -1;
   for (int i = 0; i <= a; i ++)
      for (int j = 0; j <= b; j ++)
         if (used[n][i][j]) {
            if (ans < dp[n][i][j]) ans = dp[n][i][j], x = i, y = j;
         }
   if (ans < (n + 1) / 2) cout << "NO\n";
   else {
      cout << "YES\n";
      while (n) {
         if (p[n][x][y] == 2) y ++, res.pb ('P');
         else if (p[n][x][y] == 1) x ++, res.pb ('R');
         else res.pb ('S');
         n --;
      }
      reverse (all (res));
      for (auto it : res) cout << it;
      cout << endl;
      res.clear ();
   }
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