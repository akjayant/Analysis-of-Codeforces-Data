#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define N 100050
using namespace std;
ll mod= 1e9+7;
ll dp[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   string s; cin>>s;
   ll ans=1;
   int n= s.length();
   int cu=0;
   dp[0]=1;
   dp[1]=1; dp[2]=2;
   for(int i=3;i<=n;i++){
    dp[i]=dp[i-1]+dp[i-2];
    if(dp[i]>=mod)dp[i]-=mod;
   }
   for(int i=0;i<n;i++){
    if(s[i]=='w'||s[i]=='m'){
        cout<<"0";
        return 0;
    }
   }
   for(int i=0;i<n;i++){
    if(s[i]!='u'){
        ans*=dp[cu];
        if(ans>=mod)ans%=mod;
        cu=0; continue;
    }
    cu++;
   }
   ans*=dp[cu];
    if(ans>=mod)ans%=mod;
   cu=0;
   for(int i=0;i<n;i++){
    if(s[i]!='n'){
        ans*=dp[cu];
        if(ans>=mod)ans%=mod;
        cu=0; continue;
    }
    cu++;
   }
   ans*=dp[cu];
    if(ans>=mod)ans%=mod;
   cout<<ans;
   return 0;
}
