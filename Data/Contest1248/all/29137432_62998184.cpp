/*********************
*  Author: xuziyuan  * 
*********************/

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

const LL MOD=1e9+7;

int n,dp[510],mnl[510],mnr[510],ans=0,ans2=1,ans3=1;
string s;

int main()
{
	cin>>n>>s;
	rep(i,n)
	{
		rep(j,n)
		{
			swap(s[i],s[j]);
			memset(dp,0,sizeof(dp));
			rep(k,505) mnl[k]=mnr[k]=1e9;
			rep(k,n) dp[k+1]=dp[k]+(s[k]=='(' ? 1:-1);
			if(dp[n]!=0)
			{
				cout<<0<<endl<<1<<' '<<1<<endl;
				return 0;
			}
			repn(k,n) mnl[k]=min(mnl[k-1],dp[k]);
			for(int k=n;k>0;k--) mnr[k]=min(mnr[k+1],dp[k]);
			int res=0;
			repn(k,n) if(mnr[k]-dp[k-1]>=0&&((k>1&&mnl[k-1]+dp[n]-dp[k-1]>=0)||k==1)) res++;
			if(res>ans)
			{
				ans=res;
				ans2=i+1;
				ans3=j+1;
			}
			swap(s[i],s[j]);
		}
	}
	cout<<ans<<endl<<ans2<<' '<<ans3<<endl;
	return 0;
}