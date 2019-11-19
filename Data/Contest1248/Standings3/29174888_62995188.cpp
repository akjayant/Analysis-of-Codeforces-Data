
#include<iostream>
 #include<bits/stdc++.h>
using namespace std;
 const int mod=1e9+7;
 long long dp[100005][2][2][2];
 long long ans[100005];
int main()
{
    int n,m;
   cin>>n>>m;
  dp[3][0][1][1]=1;
  dp[3][1][1][0]=1;
  dp[3][0][1][0]=1;
  dp[3][1][0][1]=1;
  dp[3][0][0][1]=1;
  dp[3][1][0][0]=1;
  ans[1]=2;
  ans[2]=4;
  ans[3]=6;
  for(int i=4;i<=max(m,n);i++)
  {
      dp[i][0][1][1]=(dp[i-1][0][0][1]+dp[i-1][1][0][1])%mod;
  dp[i][1][1][0]=dp[i-1][0][1][1];
  dp[i][0][1][0]=(dp[i-1][1][0][1]+dp[i-1][0][0][1])%mod;
  dp[i][1][0][1]=(dp[i-1][0][1][0]+dp[i-1][1][1][0])%mod;
  dp[i][0][0][1]=dp[i-1][1][0][0];
  dp[i][1][0][0]=(dp[i-1][1][1][0]+dp[i-1][0][1][0])%mod;
  ans[i]=(dp[i][0][1][1]+ dp[i][1][1][0]+ dp[i][0][1][0]+dp[i][1][0][1]+ dp[i][0][0][1]+dp[i][1][0][0])%mod;
  }
  long long res;
  res=(ans[m]-2+ans[n])%mod;
  cout<<res;
	return 0;
}
