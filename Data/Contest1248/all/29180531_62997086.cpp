#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define pb push_back
#define endl '\n'
#define PI acos(-1)
#define bitcount(a) __builtin_popcountll(a)
#define P pair<int,int>
#define ff first
#define ss second
typedef tree<int,null_type,less_equal <int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
long double eps=1e-9;
int mod=1e9+7;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	if(m>n)
		swap(n,m);
	int dp[n+1][2]={0};
	dp[1][1]=1;dp[1][0]=1;
	dp[0][1]=1,dp[0][0]=1;
	int ans=0;
	for(int i=2;i<=n;i++)
	{
		dp[i][1]=dp[i-1][0]+dp[i-2][0];
		dp[i][1]%=mod;
		dp[i][0]=dp[i-1][1]+dp[i-2][1];
		dp[i][0]%=mod;
	}
	// cout<<dp[n][1]<<" "<<dp[n][0]<<endl;
	ans+=dp[n][1]+dp[n][0];
	ans%=mod;
	for(int i=0;i<=n;i++)
		dp[i][0]=0,dp[i][1]=0;
	dp[1][1]=1;dp[1][0]=1;
	dp[0][1]=1,dp[0][0]=1;
	for(int i=2;i<=m;i++)
	{
		dp[i][1]=dp[i-1][0]+dp[i-2][0];
		dp[i][1]%=mod;
		dp[i][0]=dp[i-1][1]+dp[i-2][1];
		dp[i][0]%=mod;
	}
	ans+=dp[m][1]+dp[m][0];
	ans%=mod;
	ans=(ans-2+mod)%mod;
	cout<<ans<<endl;

	return 0;
}