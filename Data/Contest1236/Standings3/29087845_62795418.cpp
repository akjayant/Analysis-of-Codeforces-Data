#include <bits/stdc++.h>
#define MAXN 305
using namespace std;

int inv=1,n,a[MAXN][MAXN];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		if (inv)
			for (int j=1;j<=n;j++)
				a[j][i]=(i-1)*n+j;
		
		else
			for (int j=1;j<=n;j++)
				a[j][i]=(i-1)*n+(n-j+1);
		inv^=1;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			printf("%d%c",a[i][j],j==n?'\n':' ');
	return 0;
}