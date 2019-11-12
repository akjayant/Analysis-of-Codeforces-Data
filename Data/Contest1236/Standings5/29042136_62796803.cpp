#include<bits/stdc++.h>
using namespace std;
int n,p;
int a[310][310];
int main()
{
	scanf("%d",&n); p=0;
	for (int i=1;i<=n;i++)
	{
		if (i%2==1)
		{
			for (int j=1;j<=n;j++)
			{
				p++; a[j][i]=p;
			}
		} else
		{
			for (int j=n;j>=1;j--)
			{
				p++; a[j][i]=p;
			}

		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++) printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}