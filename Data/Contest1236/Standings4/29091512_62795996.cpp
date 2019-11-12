#include<bits/stdc++.h>
using namespace std;
int m,n,i,j,cnt;
int mp[310][310];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if(i&1)
		{
			for(j=1;j<=n;j++)
			{
				mp[j][i]=++cnt;
			}
		}
		else
		{
			for(j=n;j>=1;j--)
			{
				mp[j][i]=++cnt;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<n;j++)
		{
			printf("%d ",mp[i][j]);
		}
		printf("%d\n",mp[i][n]);
	}
	return 0;
}