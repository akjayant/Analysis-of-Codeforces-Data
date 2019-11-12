#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int quickpow(int x,int y)
{
	long long base=x,res=1;
	while(y)
	{
		if(y&1)res*=base,res%=mod;
		y>>=1;
		base*=base,base%=mod;
	}
	return res;
}
signed main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d",quickpow(quickpow(2,m)-1+mod,n));
	return 0;
}
