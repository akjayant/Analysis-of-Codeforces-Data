#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(v) ((ll)v.size())
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define F first
#define S second
#define pii pair<ll,ll> 
const ll mod = 1000000007;
const ll mod1= 1000000009;
const ll base= 10529;
const ll base1=11699 ;
const ll N=(1<<16);
#define MAXN 2000004
const ll mx=10000000000000000;
ll dp[102][102][102];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll i,j,k;
  for(i=0;i<=100;i++) for(j=0;j<=100;j++) for(k=0;k<=100;k++){
    if(i>=1 and j>=2) dp[i][j][k]=max(dp[i][j][k],3+dp[i-1][j-2][k]);
    if(j>=1 and k>=2) dp[i][j][k]=max(dp[i][j][k],3+dp[i][j-1][k-2]);
  }
  ll t;
  cin>>t;
  while(t--){
    ll a,b,c;
    cin>>a>>b>>c;
    cout<<dp[a][b][c]<<'\n';
  }
  return 0;
} 