#include <cstdio>
const int MAXN=330;
int a[MAXN][MAXN];
int main()
{
//	freopen("C.in", "r", stdin);
//	freopen("C.out", "w", stdout);
	int n;
	scanf("%d", &n);
	int k=0;
	for (int j=1, t=0; j<=n; j++, t^=1)
		if (!t) for (int i=1; i<=n; i++)
			a[i][j]=++k;
		else for (int i=n; i>=1; i--)
			a[i][j]=++k;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
			printf("%d ", a[i][j]);
		putchar('\n');
	}
	return 0;
}