#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,m;
int binpow(int a,int t)
{
	int res=1,p=a;
	for (int i=t;i;i>>=1)
	{
		if (i&1) res=1ll*res*p%mod;
		p=1ll*p*p%mod;
	}
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	cout<<(binpow(binpow(2,m)-1,n)+mod)%mod<<endl;
	return 0;
}