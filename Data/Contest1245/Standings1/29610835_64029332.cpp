#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T;
ll l,r;
ll a[35],b[35];
ll fastpow(ll a,ll p)
{
	ll ans=1;
	while(p)
	{
		if(p&1)ans=ans*a;
		a=a*a;p>>=1;
	}
	return ans;
}
ll dp[35][2][2][2][2];
bool vis[35][2][2][2][2];
ll dfs(ll len,ll x,ll y,ll lim1,ll lim2)
{
	if(!len)return 1;
	if(vis[len][x][y][lim1][lim2])return dp[len][x][y][lim1][lim2];
	vis[len][x][y][lim1][lim2]=1;
	ll res=0;
	if(a[len-1]==1&&b[len-1]==1)
	{
		res+=dfs(len-1,0,1,0,lim2)+dfs(len-1,1,0,lim1,0)+dfs(len-1,0,0,0,0);
	}
	else if(a[len-1]==1)
	{
		res+=dfs(len-1,0,0,0,lim2)+dfs(len-1,1,0,lim1,lim2);
		if(!lim2)res+=dfs(len-1,0,1,0,0);
	}
	else if(b[len-1]==1)
	{
		res+=dfs(len-1,0,0,lim1,0)+dfs(len-1,0,1,lim1,lim2);
		if(!lim1)res+=dfs(len-1,1,0,0,0);
	}
	else
	{
		res+=dfs(len-1,0,0,lim1,lim2);
		if(!lim1)res+=dfs(len-1,1,0,0,lim2);
		if(!lim2)res+=dfs(len-1,0,1,lim1,0);
	}
	return dp[len][x][y][lim1][lim2]=res;
}
ll solve(ll x,ll y)
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(dp,0,sizeof(dp));
	memset(vis,0,sizeof(vis));
	for(int i=30;i>=0;--i)a[i]=(x>>i)&1,b[i]=(y>>i)&1;
	ll ans=dfs(31,0,0,1,1);
	return ans;
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>l>>r;
		if(l>0)cout<<solve(r,r)-solve(r,l-1)-solve(l-1,r)+solve(l-1,l-1)<<endl;
		else cout<<solve(r,r)<<endl;
	}
}