#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define mod 1000000007
int n;
int a[305][305];
int main()
{
	int tot=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
				a[i][j]=++tot;
		}
		else
		{
			for(int j=n;j>=1;j--)
				a[i][j]=++tot;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d ",a[j][i]);
		printf("\n");
	}
}

