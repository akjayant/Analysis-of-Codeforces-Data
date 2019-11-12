#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long qp(long long p,int q)
{
	long long res=1;
	while(q)
	{
		if(q&1)
		res=res*p%mod;
		p=p*p%mod;
		q/=2;
	}
	return res;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%lld\n",qp(qp(2,m)-1,n));
	return 0;
}