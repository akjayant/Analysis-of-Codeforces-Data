#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1000000007;
ll dp[100009][6];

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false); 
  ll n,m;
  cin >> n >> m;
  ll o=max(n,m);
  dp[1][2]=1; dp[1][3]=1;
  for(int i=2;i<=o;i++){
    dp[i][0]=dp[i-1][2];
    dp[i][1]=dp[i-1][3];
    dp[i][2]=(dp[i-1][1]+dp[i-1][3])%mod;
    dp[i][3]=(dp[i-1][0]+dp[i-1][2])%mod;
  }
  ll N=0,M=0;
  for(int i=0;i<4;i++){N+=dp[n][i]; N%=mod; M+=dp[m][i]; M%=mod;}
  //cout << N << " " << M << endl;
  cout << (N+M-2)%mod << endl;
}