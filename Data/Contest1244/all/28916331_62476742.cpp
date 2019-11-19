#include<bits/stdc++.h>
using namespace std;
int t,n,x[1005],mx=0,lft,rgt;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		mx=n;
		for(int i=1;i<=n;i++)
		{
			scanf("%1d",&x[i]);
			mx+=x[i];
		}
		if(mx==n)
		{
			printf("%d\n",n);
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(x[i]>0)
			{
				lft=i;
				break;
			}
		}
		for(int i=n;i>=1;i--)
		{
			if(x[i]>0)
			{
				rgt=i;
				break;
			}
		}
		if(rgt+rgt>mx)
		mx=rgt+rgt;
		if(n-lft+1+n-lft+1>mx)
		mx=n-lft+1+n-lft+1;
		printf("%d\n",mx);
	}
	return 0;
}