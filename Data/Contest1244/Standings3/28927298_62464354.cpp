#include <iostream>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int a, b, c, d, k;
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
		bool ok = false;
		for (int x = 0; x <= k; x++)
		{
			int y = k - x;
			if (c * x >= a && d * y >= b)
			{
				ok = true;
				printf("%d %d\n", x, y);
				break;
			}
		}
		if (!ok)
		{
			printf("%d\n", -1);
		}
	}
}