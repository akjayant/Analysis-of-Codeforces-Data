#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

const ll mod=1e9+7;
ll mu(ll a,ll b){
  return (ll)a*b%mod;
}
ll ad(ll a,ll b){
  if((a+=b)>=mod)a-=mod;
  return a;
}
ll pw(ll a,ll b,ll c=1LL){
  for(;b;b>>=1,a=mu(a,a))if(b&1)c=mu(c,a);
  return c;
}
ll dv(ll a,ll b){
  return mu(a,pw(b,mod-2));
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  int n=s.size();
  ll dp[n+1];
  rep(i,n+1) dp[i]=0;
  dp[0]=1;dp[1]=1;dp[2]=2;
  for(int i=3; i<=n;i++){
    dp[i]=ad(dp[i-1],dp[i-2]);
  }
  ll ans=1;
  ll us,ns;
  us=ns=0;
  rep(i,n){
    if(s[i]=='u') us++;
    if(s[i]=='n') ns++;
    if((s[i]!='u' || i==n-1)&& us>0){
      ans = mu(ans, dp[us]);
      us=0;
    }
    if((s[i]!='n' || i==n-1)&& ns>0){
      ans = mu(ans, dp[ns]);
      ns=0;
    }
    if(s[i]=='m' || s[i]=='w'){
      cout << 0 << endl;
      return 0;
    }
  }
  cout << ans << endl;
  
  return 0;
    

}
