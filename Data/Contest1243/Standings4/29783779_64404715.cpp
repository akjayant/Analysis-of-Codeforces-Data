#include <stdio.h>

int n, k, ans[1010], chr[36], siz[1010], si[1010][10010], tj[1010][10010];
char c1[60], c2[60];

void swap(int x, int s, int t)
{
	siz[x]++;
	si[x][siz[x]] = s;
	tj[x][siz[x]] = t;
	
	char temp = c1[s];
	c1[s] = c2[t];
	c2[t] = temp;
}
int main(void)
{
	int i, j, l, cnt, v1, v2, ok;

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &k);
		scanf("%s %s", &c1[1], &c2[1]);

		ans[i] = 1;
		for (j = 0; j < 26; j++)
			chr[j] = 0;
		for (j = 1; j <= k; j++)
		{
			chr[c1[j] - 'a']++;
			chr[c2[j] - 'a']++;
		}
		for (j = 0; j < 26; j++)
			if (chr[j] % 2 == 1)
			{
				ans[i] = 0;
				break;
			}
		if (ans[i])
		{
			for (j = 1; j < k; j++)
				if (c1[j] != c2[j])
				{
					ok = 1;
					for (l = j + 1; l <= k && ok; l++)
						if (c1[j] == c1[l])
						{
							swap(i, l, j);
							ok = 0;
						}
					if (ok)
					{
						for (l = j + 1; l <= k && ok; l++)
							if (c1[j] == c2[l])
							{
								swap(i, l, l);
								swap(i, l, j);
								ok = 0;
							}
					}
				}
		}
	}

	for (i = 1; i <= n; i++)
		if (ans[i])
		{
			printf("Yes\n");
			printf("%d\n", siz[i]);
			for (j = 1; j <= siz[i]; j++)
				printf("%d %d\n", si[i][j], tj[i][j]);
		}
		else
			printf("No\n");

	return 0;
}