#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1010;
int k, n, cnt[MAXN];

int main()
{
	for(scanf("%d", &k); k--;)
	{
		scanf("%d", &n);
		memset(cnt, 0, sizeof cnt);
		for(int i = 1, x; i <= n; ++i)
			scanf("%d", &x), cnt[x]++;
		for(int i = n, cur = 0; i >= 1; --i)
		{
			cur += cnt[i];
			if(cur >= i)
			{
				printf("%d\n", i);
				break;
			}
		}
	}
}