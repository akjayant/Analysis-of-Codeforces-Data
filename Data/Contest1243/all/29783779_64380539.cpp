#include <stdio.h>

int n, k, ans[20];
char c1[10010], c2[10010];

int main(void)
{
	int i, j, cnt, v1, v2;

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &k);
		scanf("%s %s", &c1[1], &c2[1]);

		cnt = 0; v1 = 0; v2 = 0;
		for (j = 1; j <= k; j++)
			if (c1[j] == c2[j])
				cnt++;
			else
			{
				if (v1 == 0)
					v1 = j;
				else
					v2 = j;
			}

		if (cnt + 2 == k && c1[v1] == c1[v2] && c2[v1] == c2[v2])
			ans[i] = 1;
		else
			ans[i] = 0;
	}

	for (i = 1; i <= n; i++)
		if (ans[i])
			printf("Yes\n");
		else
			printf("No\n");

	return 0;
}