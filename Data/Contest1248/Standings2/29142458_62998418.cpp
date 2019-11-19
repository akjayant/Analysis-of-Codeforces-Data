#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5+20;
const int MOD = 1e9+7;
int n,m;
ll dp[MAXN][2];
int main() {
  cin >> n >> m;
  if(n < m)swap(n,m);
  dp[0][0]=1;
  for (int i = 1; i < n; ++i) {
    dp[i][0]=(dp[i-1][0]+dp[i-1][1])%MOD;
    dp[i][1]=dp[i-1][0];
  }
  ll ans0=(dp[n-1][0]+dp[n-1][1]-1+MOD)*2;
  ll ans1=(dp[m-1][0]+dp[m-1][1]-1+MOD)*2;
  cout << (ans0+ans1+2)%MOD << endl;
}