#include <bits/stdc++.h>
#define MAX (100000 + 7)

int T, N, M, t[2];
long long ans;

int main()
{
	scanf("%d", &T); while (T--)
	{
		scanf("%d", &N), ans = t[0] = t[1] = 0;
		for (int i = 1, x; i <= N; i++)
			scanf("%d", &x), t[x & 1]++;
		scanf("%d", &M);
		for (int i = 1, x; i <= M; i++)
			scanf("%d", &x), ans += t[x & 1];
		printf("%lld\n", ans);
	}
}