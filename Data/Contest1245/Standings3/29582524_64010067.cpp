#include<bits/stdc++.h>
#define int long long
#define ld long double
#define endl '\n'
const int mod=1e9+7;
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
#define si(a) a.size()
#define pii pair<int,int>
using namespace std;
#if !defined(ONLINE_JUDGE)
#include "debugging.h"
#endif

void fail(){cout<<"0\n";exit(0);}

int32_t main() {
   std::ios::sync_with_stdio(false);cin.tie(NULL);
   int n;
   //cin>>n;
   string s;
   cin>>s;
   n=s.size();
   s='*'+s;
   int dp[n+1]={0};
   dp[1]=1;
   dp[0]=1;
   for(int i=1;i<=n;i++)
   {
      if(s[i]=='m' || s[i]=='w')fail();
      if((s[i]=='n'|| s[i]=='u') && (s[i]==s[i-1]) )
      {
         dp[i]=dp[i-2]+dp[i-1];
         dp[i]%=mod;
      }
      else
      {
         dp[i]=dp[i-1];
      }
      dp[i]%=mod;
      //dbg(dp[i]);
   }
   cout<<dp[n]<<endl;
   return 0;
}