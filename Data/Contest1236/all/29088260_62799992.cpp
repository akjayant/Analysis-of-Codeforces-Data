#include<cstdio>
const int MaxN=300;
int n,cnt=0,a[MaxN+1][MaxN+1];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(i&1)
				a[j][i]=++cnt;
			else
				a[n-j+1][i]=++cnt;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			printf("%d ",a[i][j]);
		putchar('\n');
	}
	return 0;
}