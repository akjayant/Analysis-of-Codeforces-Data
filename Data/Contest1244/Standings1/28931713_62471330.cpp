#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAX_N = 1e3 + 5;

int q, n;
char s[MAX_N];

int main()
{
	scanf("%d", &q);
	while (q--)
	{
		memset(s, 0x00, sizeof(s));
		scanf("%d %s", &n, s + 1);	
		int cnt = 0;
		for (int i = 1; i <= n; ++i)
			if (s[i] == '1') ++cnt;
		if (cnt == 0) printf("%d\n", n);
		else
		{
			int lo = 1, hi = n;
			while (s[lo] == '0') ++lo;
			while (s[hi] == '0') --hi;
			printf("%d\n", std::max(n - lo + 1, hi) * 2);
		}
	}
	return 0;
}
