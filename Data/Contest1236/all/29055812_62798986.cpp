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
ll ans[302][302];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll n,i,j;
  cin>>n;
  for(j=1;j<=n;j++){
     for(i=1;i<=n;i++){
      if(j%2==0)
       ans[i][j]=(j-1)*n+(n-i)%n+1;
      else
       ans[i][j]=(j-1)*n+i;
     }
  }
  for(j=1;j<=n;j++){
     for(i=1;i<=n;i++){
      cout<<ans[j][i]<<" ";
     }
     cout<<'\n';
  }
  return 0;
} 