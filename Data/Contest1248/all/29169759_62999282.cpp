#include<map>
#include<cmath>
#include<queue>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

namespace Solve1
{
	const int mo=1000000007;
	const int maxn=100005;
	long long inv[maxn],fac[maxn];
	void Pre_Inv(int n,int p)
	{
		inv[1]=1;
		for(int i=2;i<=n;i++)
			inv[i]=inv[p%i]*(p-p/i)%p;
		for(int i=2;i<=n;i++)
			inv[i]=inv[i]*inv[i-1]%mo;
		fac[1]=1;fac[0]=1;inv[0]=1;
		for(int i=2;i<=n;i++)
			fac[i]=fac[i-1]*i%mo;
		return;
	}
	int n,m;
	void work()
	{
		scanf("%d%d",&n,&m);
		Pre_Inv(100000,mo);
		long long prt1=0,prt2=0;
		for(int p=1;p<=(n>>1);p++)
		{
			int q=n-(p<<1);
			prt1=(prt1+fac[p+q]*inv[p]%mo*inv[q]%mo)%mo;
		}
		prt1=(prt1<<1)%mo;
		for(int p=1;p<=(m>>1);p++)
		{
			int q=m-(p<<1);
			prt2=(prt2+fac[p+q]*inv[p]%mo*inv[q]%mo)%mo;
		}
		prt2=(prt2<<1)%mo;
		cout<<(prt1+prt2+2)%mo;
		return;
	}
}
int main()
{
	#ifdef LOCAL
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	#endif
	
	Solve1::work();
	
	return 0;
}
