#include<bits/stdc++.h>
#define pb   push_back
#define mp   make_pair
#define f    first
#define s    second
#define ll   long long
#define vi vector< int >
#define vl vector< ll >
#define rep(i,j,n)  for(int (i) = (j); i < n; i++)
#define MAX(a, b)     ((a) > (b) ? (a) : (b))
#define MIN(a, b)     ((a) < (b) ? (a) : (b))
#define all(v) v.begin(), v.end()
#define DEBUG(X) { cout << #X << " = " << (X) << endl; }
#define T() int tt; cin>>tt; while(tt--)
#define Max  INT_MAX
#define Min  INT_MIN
#define mod  1000000007
#define N 1000099
using namespace std;

ll power(ll b,ll exp,ll m)   //only for +ve values of b
{ll ans=1;b%=m;
 while(exp){if(exp&1) ans=(ans*b)%m;
  exp>>=1;b=(b*b)%m;}
 return ans;}
ll dp[N], n, m;
ll solve(ll i, ll x){
	if(i==x) return 1LL;
	if(dp[i]!=-1)return dp[i];
	ll ans=0;
	ans = (ans+solve(i+1,x))%mod;
	if(i+2<=x)  ans = (ans+solve(i+2,x))%mod;
	return dp[i]=ans%mod;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>m>>n;
	memset(dp,-1,sizeof(dp));
	ll ans=0;
	ans=solve(0,n);
	memset(dp,-1,sizeof(dp));
	ans=(ans+solve(0,m))%mod;
	ans=(ans-1LL+mod);
	ans = (ans*2LL)%mod;
	cout<<ans%mod<<"\n";
}


