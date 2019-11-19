#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<bitset>
#include<string>
#include<queue>
#include<set>
using namespace std;
typedef long long ll;
#define mem(a,b) memset(a,b,sizeof(a))
#define rep(a,b,c) for(int a=b;a<c;a++)
#define repp(a,b,c) for(int a=b;a<=c;a++)
#define pb push_back
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const int maxn=1e5+10;
int arr[maxn];
ll QuickPow(ll x,ll N)
{
    ll res = x;
    ll ans = 1;
    while(N)
    {
        if(N&1)
        {
            ans = (ans * res)%mod;
        }
        res = (res*res)%mod;
        N = N>>1;
    }
    return ans;
}
ll dp[4][maxn]={0};
/*
0 00
1 11
2 01
3 10

*/
ll add(ll a,ll b)
{
	return (a+b)%mod;
}
ll DP[5]={0};
int main()
{
	int n,m;
	cin>>n>>m;
	if(m==1)
	{
		if(n==1)
		{
			cout<<2<<endl;
			return 0;
		}
		else swap(n,m);
	}
	dp[0][2]=1;
	dp[1][2]=1;
	dp[2][2]=1;
	dp[3][2]=1;
	for(int i=3;i<=m;i++)
	{
		dp[0][i]=dp[3][i-1];
		dp[1][i]=dp[2][i-1];
		dp[2][i]=(dp[0][i-1]+dp[3][i-1])%mod;
		dp[3][i]=(dp[1][i-1]+dp[2][i-1])%mod;
	}
	ll sum=add(add(dp[0][m],dp[1][m]),add(dp[2][m],dp[3][m]));
	sum-=2;
	DP[0]=2;
	DP[1]=0;
	for(int i=2;i<=n;i++)
	{
		ll a=DP[0];
		ll b=DP[1];
		DP[0]=(a+b)%mod;
		DP[1]=a;
	}
	cout<<add(add(DP[0],DP[1]),sum)<<endl;
}
