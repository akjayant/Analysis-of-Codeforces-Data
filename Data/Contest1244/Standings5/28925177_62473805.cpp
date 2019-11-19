#include <bits/stdc++.h>
using namespace std;
char s[1005];
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		long long ret;
		scanf("%d", &n);
		scanf("%s", s + 1);
		ret = n;
		for (int i = 1; i <= n; ++i)
			if (s[i] == '1')
				ret = max(ret, max((n - i + 1) * 2ll, i * 2ll));
		printf("%lld\n", ret);
	}
	return 0;
}