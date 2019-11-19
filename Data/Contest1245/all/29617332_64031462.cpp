#include<bits/stdc++.h>

using namespace std;
const int N=11000;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef long long LL;
int T;
int a,b;
int ca[110],cb[110];
int na,nb;
LL pw3[110];
LL dp[40][2][2];
LL dfs(int len,int cur1,int cur2)
{
	if (dp[len][cur1][cur2]!=-1) return dp[len][cur1][cur2];
	dp[len][cur1][cur2]=0;
	if (len==0) return dp[len][cur1][cur2]=1;
	for (int i1=0;i1<=1;i1++)
		for (int i2=0;i2<=1;i2++)
		{
			if (cur1&&i1>ca[len]) continue;
			if (cur2&&i2>cb[len]) continue;
			int ncur1=cur1&&(i1==ca[len]);
			int ncur2=cur2&&(i2==cb[len]);
			if (i1&i2) continue;
			if (ncur1&&ncur2)
			{
				if (i1&i2) continue;
				dp[len][cur1][cur2]+=dfs(len-1,ncur1,ncur2);
			}
			else if (!ncur1&&!ncur2)
			{
				dp[len][cur1][cur2]+=pw3[len-1];
			}
			else if (ncur1&&!ncur2)
			{
				if (i1==1) dp[len][cur1][cur2]+=dfs(len-1,ncur1,ncur2);
				else dp[len][cur1][cur2]+=dfs(len-1,ncur1,ncur2);
			}
			else
			{
				if (i2==1) dp[len][cur1][cur2]+=dfs(len-1,ncur1,ncur2);
				else dp[len][cur1][cur2]+=dfs(len-1,ncur1,ncur2);
			}
		}
	return dp[len][cur1][cur2];
}
LL work(int a,int b)
{
	if (a<0||b<0) return 0;
	memset(dp,-1,sizeof(dp));
	na=nb=0;
	while (a) ca[++na]=a&1,a>>=1;
	while (b) cb[++nb]=b&1,b>>=1;
	for (int i=nb+1;i<=na;i++)
		cb[i]=0;
	return dfs(na,1,1);
}
int main()
{
	pw3[0]=1;
	for (int i=1;i<=33;i++)
		pw3[i]=pw3[i-1]*3LL;
	cin>>T;
	while (T--)
	{
		int l,r;
		cin>>l>>r;
		LL ans1=work(r,r);
		LL ans2=work(r,l-1);
		LL ans3=work(l-1,l-1);
		cout<<ans1-2LL*ans2+ans3<<endl;
	}
	return 0;
}