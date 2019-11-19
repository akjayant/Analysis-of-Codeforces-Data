#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define MOD 1000000007
using namespace std;
vector <ll> vr[100005];
ll n,ar[100005][3],deg[100005],dp[100005][4][4],cr[100005],func(ll,ll,ll,ll);
void prt(ll,ll,ll,ll);
int main()
{
	scanf("%lld",&n);
	rep(i,0,3)
	rep(j,1,n+1)
	{
		scanf("%lld",&ar[j][i]);
	}
	ll x,y,f=0;
	rep(i,0,n-1)
	{
		scanf("%lld %lld",&x,&y);
		deg[x]++;
		deg[y]++;
		if(deg[x]>2||deg[y]>2)
			f=1;
		vr[x].push_back(y);
		vr[y].push_back(x);
	}
	if(f)
		cout<<"-1";
	else
	{
		memset(dp,-1,sizeof(dp));
		ll p;
		rep(i,1,n+1)
		if(deg[i]==1)
			p=i;
		printf("%lld\n",func(p,3,3,-1));
		prt(p,3,3,-1);
		rep(i,1,n+1)
		printf("%lld ",cr[i]);
	}
}
ll func(ll idx,ll cur,ll prev_,ll p)
{
	ll size_=vr[idx].size(),min_=100000000000000ll;
	if(dp[idx][cur][prev_]!=-1)
		return dp[idx][cur][prev_];
	ll f=1;
	rep(i,0,size_)
	{
		if(vr[idx][i]==p)
			continue;
		f=0;
		rep(j,0,3)
		if(j!=cur&&j!=prev_)
			min_=min(min_,func(vr[idx][i],j,cur,idx)+ar[idx][j]);
	}
	if(f)
	{
		rep(j,0,3)
		if(j!=cur&&j!=prev_)
			min_=ar[idx][j];
	}
	//cout<<idx<<" "<<cur<<" "<<prev_<<"\n";
	return dp[idx][cur][prev_]=min_;
}
void prt(ll idx,ll cur,ll prev_,ll p)
{
	ll size_=vr[idx].size();
	ll f=1;
	rep(i,0,size_)
	{
		if(vr[idx][i]==p)
			continue;
		f=0;
		rep(j,0,3)
		if(j!=cur&&j!=prev_&&dp[vr[idx][i]][j][cur]+ar[idx][j]==dp[idx][cur][prev_])
		{
			cr[idx]=j+1;
			prt(vr[idx][i],j,cur,idx);
			break;
		}
	}	
	if(f)
	{
		//cout<<idx<<"SA";
		ll min_=1000000000000000ll;
		rep(j,0,3)
		if(j!=cur&&j!=prev_)
		{
			if(min_>ar[idx][j])
			{
				min_=ar[idx][j];
				cr[idx]=j+1;
			}
		}	
	}	
}