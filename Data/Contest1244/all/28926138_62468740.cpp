#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN=1100;
char a[MAXN];
int main()
{
//	freopen("B.in", "r", stdin);
//	freopen("B.out", "w", stdout);
	int t; scanf("%d", &t);
	while (t--)
	{
		int n, ans;
		scanf("%d%s", &n, a+1); ans=n;
		for (int i=1; i<=n; i++)
			if (a[i]=='1') ans=max(ans, 2*max(i, n-i+1));
		printf("%d\n", ans);
	}
	return 0;
}