#include<bits/stdc++.h>
using namespace std;
char s[105];
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		scanf("%s", s + 1);
		if (s[1] == '1' || s[n] == '1')
			printf("%d\n", 2 * n);
		else
		{
			int ans = 0;
			int l = n + 1, r = 0;
			for (int i = 1; i <= n; i++)
			{
				if (s[i] == '1')
				{
					l = min(i, l);
					r = max(i, r);
					ans++;
				}
			}
			if (ans == 0)
				printf("%d\n", n);
			else
			{
				ans = (r - l + 1) * 2 + 2*max(l - 1, n - r);
				printf("%d\n",ans);
			}
		}
	}
}