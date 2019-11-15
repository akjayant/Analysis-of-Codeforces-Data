#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define eps 1e-5

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ld pi = acos(-1);
const int MOD = 1e9 + 7;
int dp[100010];
int solve(int x){
   if(x == 0)return 1;
   if(x == 1)return 1;
   if(dp[x]!=0)return dp[x];
   dp[x] = (solve(x-1) + solve(x-2)) % MOD;
   return dp[x];
}
int main(){ _
   string s;
   cin >> s;
   ll ret = 1;
   int tot = 0;
   for(char c: s){
      if(c == 'm' or c == 'w')
      {
         cout << 0 << endl;
         exit(0);
      }
   }
   for(int i = 0; i < s.size(); i++){
      if(s[i] == 'u'){
         tot++;
      }
      else{
         ret = (ret * solve(tot)) % MOD;
         tot = 0;
      }
   }
   ret = (ret * solve(tot))%MOD;
   tot = 0;
   for(int i = 0; i < s.size(); i++){
      if(s[i] == 'n'){
         tot++;
      }
      else{
         ret = (ret * solve(tot)) % MOD;
         tot = 0;
      }
   }
   ret = (ret * solve(tot))%MOD;
   cout << ret << endl;
   exit(0);
}
