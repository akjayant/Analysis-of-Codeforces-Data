#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,n1,n2,m1,m2;
int main()
{
	int x;
	scanf("%d",&t);
	while(t--)
	{
		n1=n2=m1=m2=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x%2==1)
			n1++;
			else
			n2++;
		}
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&x);
			if(x%2==1)
			m1++;
			else
			m2++;
		}
		printf("%lld\n",1ll*m1*n1+1ll*m2*n2);
	}
	return 0;
}