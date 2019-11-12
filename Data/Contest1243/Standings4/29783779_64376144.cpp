#include <stdio.h>

int n, k, a[1010], ans[20];

int main(void)
{
	int i, j, ok, cnt;

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &k);
		for (j = 1; j <= k; j++)
			scanf("%d", &a[j]);

		ans[i] = k;
		ok = 0;
		while(!ok)
		{
			cnt = 0;
			for (j = 1; j <= k; j++)
				if (a[j] >= ans[i])
					cnt++;
			if (cnt >= ans[i])
				ok = 1;
			else
				ans[i]--;
		}
	}

	for (i = 1; i <= n; i++)
		printf("%d\n", ans[i]);

	return 0;
}