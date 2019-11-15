#include <bits/stdc++.h>
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector < vector <pii> > graph;

const int mod = 1e9 + 7;

signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   string s;
   cin >> s;
   vector <int> dp(s.size() + 1);
   dp[0] = 1;
   dp[1] = 1;
   for(int i = 2; i < dp.size(); i++){
       dp[i] = (dp[i - 2] + dp[i - 1]) % mod;
   }
   int ans = 1;
   for(int i = 0; i < s.size(); i++){
       if(s[i] == 'm' || s[i] == 'w'){
           cout << 0 << '\n';
           return 0;
       }
       if(s[i] == 'n' || s[i] == 'u'){
           int j = i;
           while(j < s.size() && s[i] == s[j]){
               j++;
           }
           int len = j - i;
           if(len == 1){ 
               i = j - 1;
               continue;
           }
           ans = (1ll * ans * dp[len]) % mod;
           i = j - 1;
       }
   }
   cout << ans << '\n';
   return 0;
}
