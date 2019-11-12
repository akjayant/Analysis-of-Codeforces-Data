#include <cstdio>
const int MOD=1E9+7;
int qpow(int n, int k)
{
	int r=1;
	while (k)
	{
		if (k&1) r=1ll*r*n%MOD;
		n=1ll*n*n%MOD; k>>=1;
	}
	return r;
}
int main()
{
//	freopen("B.in", "r", stdin);
//	freopen("B.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%d\n", qpow((qpow(2, m)-1+MOD)%MOD, n));
	return 0;
}