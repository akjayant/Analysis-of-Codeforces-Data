#include <bits/stdc++.h>
#define ll long long
#define sc scanf
#define pr printf
using namespace std;
char s[1005];
int main()
{
	int T;
	sc("%d", &T);
	while (T--)
	{
		int n;
		sc("%d", &n);
		sc("%s", s + 1);
		int l = -1, r = -1;
		for (int i = 1; i <= n; i++)
		{
			if (s[i] == '1')
			{
				if (l == -1)
					l = i;
				r = max(r, i);
			}
		}
		int ans = 0;
		if (l == -1 && r == -1)
			ans = n;
		else
		{
			ans = (r - l + 1) * 2;
			ans += 2 * max(l - 1, n - r);
		}
		pr("%d\n", ans);
	}
}