#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define mod 1000000007
#define maxn 50005

int n;
int a, b, c;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> a >> b >> c;
		int ans = 0;
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (i <= a && 2 * i + j <= b && 2 * j <= c)
					ans = max(ans, i + j);
			}
		}
		printf("%d\n", ans * 3);
	}

	return 0;
}