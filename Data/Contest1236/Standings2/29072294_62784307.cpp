#include <bits/stdc++.h>

#define SZ(x) (((int)x.size()))

typedef long long ll;
typedef long double ld;

using namespace std;

int a, b, c, t, mx;

int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		mx = 0;
		cin >> a >> b >> c;
		for (int j = 0; j <= a; j++)
		{
			for (int k = 0; k <= b; k++)
			{
				if (j * 2 + k <= b && 2 * k <= c)
					mx = max(mx, (j + k) * 3);
			}
		}
		cout << mx << endl;
	}
	return 0;
}
