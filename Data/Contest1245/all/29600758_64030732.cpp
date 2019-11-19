#include<bits/stdc++.h>
using namespace std;
const int maxn=65;
const int mod=1e9+7;
typedef long long ll;
ll l,r;
ll dp[maxn][2][2][2];
ll cal(int ind,int bot,int top,int lead)
{
	if(ind<0) return 1;
	if(dp[ind][bot][top][lead]!=-1) return dp[ind][bot][top][lead];
	dp[ind][bot][top][lead]=0;
	int up=!(!(r&(1ll<<ind)));
	int down=!(!(l&(1ll<<ind)));
	//cout<<ind<<" "<<bot<<" "<<top<<" "<<lead<<" "<<up<<" "<<down<<endl;
	ll ans=0;
	for(int i=0;i<2;i++)//y
	{
		for(int j=0;j<2;j++)//x
		{
			//cout<<i<<" "<<j<<" "<<up<<" "<<down<<endl;
			if(i==1&&j==1) continue;
			if((!lead)&&(!((i==1&&j==0)||(i==0&&j==0)))) continue;
			if(bot&&(j<down)) continue;
			if(top&&(i>up)) continue;
			ans+=cal(ind-1,bot&&(j==down),top&&(i==up),lead||(i>0));
			//cout<<ans<<endl;
			//ans%=mod;
			//cout<<ans<<endl;
		}
	}
	dp[ind][bot][top][lead]=ans;
	//cout<<ind<<" "<<bot<<" "<<top<<" "<<lead<<" "<<dp[ind][bot][top][lead]<<endl;
	return ans;
}
int main()
{
	int t;cin>>t;
	while(t--)
	{
		scanf("%lld %lld",&l,&r);memset(dp,-1,sizeof dp);
		ll ans=cal(32,1,1,0);
		if(l==0)
		{
			cout<<ans*2ll-1<<endl;
		}
		else cout<<ans*2ll<<endl;
	}
 } 
