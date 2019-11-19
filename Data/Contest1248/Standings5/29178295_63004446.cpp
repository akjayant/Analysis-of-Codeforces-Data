#include<bits/stdc++.h>
#define ll long long
#define int long long
#define pb push_back 
#define ins insert
#define rs resize
#define br break;
#define cont continue;
#define vi vector<ll>
#define vll vector<long long>
#define si set<ll>
#define sll set<long long>
#define pii pair<ll,ll>
#define pll pair<long long, long long>
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vec vector
#define cend cout<<endl;
#define sc second
#define fr first
#define retz return 0;
#define ll_MAX (ll)(1e9*1e9)
#define lb lower_bound
#define ub upper_bound
#define rep(i,a,b)  for(int i=a; i<=b; i++)
#define repd(i,a,b) for(int i=a; i>=b; i--)
#define ps(arr, n) for(int i=1; i<n; i++)arr[i]+=arr[i-1];
#define inp(arr, n)for(int i=0; i<n; i++)cin>>arr[i];
#define out(arr, n)for(int i=0; i<n; i++)cout<<arr[i];
#define inp1(arr,n,m)for(int i=0; i<n; i++)for(int j=0;j<m;j++)cin>>arr[i][j];
#define out1(arr,n,m)for(int i=0; i<n; i++)for(int j=0;j<m;j++)cin>>arr[i][j];
#define loop(q) for(auto it:q)
#define loop1(q) for(auto&it:q)
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////

int mod = 1e9+7;
int dp[100001];


int s1(int n)
{
	if(n<0)
		return 0;
	if(n==0)
		return 1;
	if(n==1)
		return 1;
	if(dp[n]!=-1)
		return dp[n];
	dp[n] = (s1(n-1) + s1(n-2))%mod;
	return dp[n];
}

ll modex(ll a, ll p)
{
  if(p==0)
    return 1;
  ll s = 1;
  while(p!=1)
  {
    if(p%2)
      s = (s*a)%mod;
    a = (a*a)%mod;
    p /= 2;
  }
  return (a*s)%mod;
}


void solve()
{
	rep(i,0,100000)
		dp[i] = -1;
	int n,m;
	cin >> n >> m;

	int ans = (((2*s1(n-1))%mod+(2*s1(n-2))%mod)%mod+((2*s1(m-1))%mod+(2*s1(m-2))%mod)%mod-2+mod)%mod;
	ans %= mod;
	cout << ans << endl;
	
}




int32_t main()
{
    speed
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
}