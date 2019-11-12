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
ll expo(ll a,ll b){
  ll res=1;
  while(b){
    if(b&1) res=(res*a)%mod;
    a=(a*a)%mod;
    b>>=1;
  }
  return res;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll n,m;
  cin>>n>>m;
  ll kp=(expo(2,m)-1+mod)%mod;
  cout<<expo(kp,n);
  return 0;
} 