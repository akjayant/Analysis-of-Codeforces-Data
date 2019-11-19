#include <iostream>
#include <algorithm>

using namespace std;
char c[2000];
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		scanf("%s", c);

		int a = 0;
		for (int i = 0; i < n; i++)
		{
			if (c[i] == '1')
			{
				break;
			}
			else
			{
				a++;
			}
		}
		int b = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (c[i] == '1')
			{
				break;
			}
			else
			{
				b++;
			}
		}
		a = min(a, b);
		int ans = 2 * (n - a);
		if (ans == 0) ans = n;
		printf("%d\n", ans);
	}
}