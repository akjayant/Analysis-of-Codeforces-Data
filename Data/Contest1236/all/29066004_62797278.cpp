#include<bits/stdc++.h>
using namespace std;
#define maxn 300005
typedef long long ll;
ll mod=1e9+7;
ll qsm(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
int arr[305][305];
int main()
{
	int n,now=0;
	scanf("%d",&n);
	for(int j=n;j>=1;j--)
	{
		if((n-j+1)&1)
		{
			for(int i=n;i>=1;i--)
			arr[i][j]=++now;
		}
		else
		{
			for(int i=1;i<=n;i++)
			arr[i][j]=++now;
		}
	}
	for(int i=1;i<=n;i++,printf("\n"))
		for(int j=1;j<=n;j++)
			printf("%d ",arr[i][j]);
		
    return 0;
}