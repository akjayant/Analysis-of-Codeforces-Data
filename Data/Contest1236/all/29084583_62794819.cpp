#include <cstdio>
const int S=303;
int n,a[S][S],b[S][S],t[S];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		if (i&1)
		{
			for (int j=1;j<=n;j++)
				b[j][++t[j]]=(i-1)*n+j;
		}
		else
		{
			for (int j=n;j;--j)
				b[n-j+1][++t[n-j+1]]=(i-1)*n+j;
		}
	}
	for (int i=1;i<=n;i++,puts(""))
		for (int j=1;j<=n;j++)
			printf("%d ",b[i][j]);
	return 0;
}