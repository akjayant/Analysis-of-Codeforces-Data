#include<stdio.h>
using namespace std;

int main()
{
	int t,n,m,i,p,q;
	long long cntp1,cntp2,cntq1,cntq2;
	scanf("%d",&t);
	while(t)
	{
		t--;
		cntp1=cntp2=cntq1=cntq2=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&p);
			if(p&1)cntp1++;
			else cntp2++;
		}
		scanf("%d",&m);
		for(i=1;i<=m;i++)
		{
			scanf("%d",&q);
			if(q&1)cntq1++;
			else cntq2++;
		}
		printf("%lld\n",cntp1*cntq1+cntp2*cntq2);
	}
}