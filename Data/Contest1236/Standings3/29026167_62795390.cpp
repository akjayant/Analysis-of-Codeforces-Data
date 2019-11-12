#include<bits/stdc++.h>
using namespace std;
int n;
int a[301][301],l,t;
int main()
{
	scanf("%d",&n);
	l=0;
	t=1;
	for(int i=1;i<=n;i++)
	if(i%2==1)
	{
		for(int j=1;j<=n;j++)
		a[j][i]=(i-1)*n+j;
	}
	else
	{
		for(int j=n;j>=1;j--)
		a[j][i]=(i-1)*n+n-j+1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		printf("%d ",a[i][j]);
		puts("");
	}
	return 0;
}