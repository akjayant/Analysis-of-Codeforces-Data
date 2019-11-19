#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long
using namespace std;
int t,n,m,p[100050],q[100050],ji_p,ou_p,ji_q,ou_q;
signed main()
{
	scanf("%lld",&t);
	while(t--)
	{
		ji_p=ou_p=ji_q=ou_q=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)scanf("%lld",&p[i]);
		scanf("%lld",&m);
		for(int i=1;i<=m;i++)scanf("%lld",&q[i]);
		for(int i=1;i<=n;i++)
		{
			if(p[i]%2)++ji_p;
			else ++ou_p;
		}
		for(int i=1;i<=m;i++)
		{
			if(q[i]%2)++ji_q;
			else ++ou_q;
		}
		printf("%lld\n",ji_p*ji_q+ou_p*ou_q);
	}
	return 0;
}