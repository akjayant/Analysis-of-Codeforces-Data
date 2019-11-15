#include <bits/stdc++.h>

using namespace std;
const int MAXN = 10100;
int k, n, cnt;
char s[MAXN], t[MAXN];

int main()
{
	for(scanf("%d", &k); k--;)
	{
		scanf("%d %s %s", &n, s, t), cnt = 0;
		for(int i = 0; i < n; ++i)
			cnt += (s[i] != t[i]);
		if(cnt > 2 || cnt == 1)
		{
			printf("No\n");
			continue;
		}
		for(int i = 0, j = -1; i < n; ++i)
			if(s[i] != t[i])
			{
				if(j != -1)
				{
					swap(s[i], t[j]);
				}
				else
					j = i;
			}
		printf(!strcmp(s, t) ? "Yes\n" : "No\n");
	}
}