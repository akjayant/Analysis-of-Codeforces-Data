#include<bits/stdc++.h>
#define ll long long
#define clr(c) memset(c,0,sizeof(c))
const int M=1e5+10;
const int mod=1e9+7;
using namespace std;
inline ll read()
{
	ll b=1,sum=0; char c=getchar();
	while(!isdigit(c)){if(c=='-') b=-1; c=getchar();}
	while(isdigit(c)){sum=sum*10+c-48;c=getchar();}
	return b*sum;
} 
ll n,m;
ll ans;
ll dp[M][3],f[M][3];// 1代表最后两个颜色重复   0 代表没有 
int main()
{
	ll i,j;
	n=read(),m=read();
	ll ans=0;
	
	dp[1][0]=2;
	dp[2][0]=2; dp[2][1]=2;
	for(i=3;i<=m;i++)
	{
		dp[i][1]=dp[i-1][0];
		dp[i][0]=(dp[i-1][1]+dp[i-1][0])%mod;
	}
	
	ans=(dp[m][1]+dp[m][0])%mod;
	ans-=2;
	
	f[1][0]=2;
	f[2][0]=2; f[2][1]=2;
	for(i=3;i<=n;i++)
	{
		f[i][1]=f[i-1][0];
		f[i][0]=(f[i-1][1]+f[i-1][0])%mod;
	}	
	ans=(f[n][1]+f[n][0]+ans-2)%mod;
	


	ans=((ans+2)%mod+mod)%mod;
	printf("%lld",ans);
	return 0;
}