#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
//	freopen("A.in", "r", stdin);
//	freopen("A.out", "w", stdout);
	int T; scanf("%d", &T);
	while (T--)
	{
		int a, b, c, ans=0;
		scanf("%d%d%d", &a, &b, &c);
		int k=min(b, c/2);
		ans+=3*k;
		k=min(a, (b-k)/2);
		ans+=3*k;
		printf("%d\n", ans);
	}
	return 0;
}