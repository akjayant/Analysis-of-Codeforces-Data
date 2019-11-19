#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<iomanip>
#include<cstring>
#define initdp(a,b) for(int i=0;i<=a;i++)for(int j=0;j<=b;j++)dp[i][j]=-1;
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define rep(i,n) for(int i=0;i<n;i++)
#define repd(i,n) for(int i=n-1;i>=0;i--)
#define inf 1e9+1
#define inf1 1e18+1
#define mod 1000000007
#define pie 3.14159265358979323846
#define N 1000005
#define mid(l,r) l+(r-l)/2
using namespace std;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int ddx[8]={1,1,0,-1,-1,-1,0,1},ddy[8]={0,1,1,1,0,-1,-1,-1};
void mad(ll &a,ll b){a=(a+b)%mod;if(a<0)a+=mod;}
ll gcd(ll a,ll b){ if(a>b)swap(a,b);if(!a)return b;return gcd(b%a,a);}
ll int dp[100005][2];
ll int f[100005];
int n;
ll rec(int i,int pre){
	if(i==n)return 1;
	if(i>n)return 0;
	if(dp[i][pre]!=-1)return dp[i][pre];
	dp[i][pre]=(rec(i+1,1-pre)+rec(i+2,1-pre))%mod;
	return dp[i][pre];
}
void solve(){
	int m;
	cin>>n>>m;
	if(n>m)swap(n,m);
	ll ans=rec(0,0)+rec(0,1);
	for(int i=0;i<m;i++)ans=(ans+f[i])%mod;
		cout<<ans;
}
int main()
{
	f[0]=0;
	f[1]=2;
	for(int i=2;i<100005;i++){
		f[i]=(f[i-1]+f[i-2])%mod;
	}
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	//cin>>t;
	for(int i=0;i<100005;i++)dp[i][0]=dp[i][1]=-1;
	t=1;
	while(t--){
		solve();
	}
}