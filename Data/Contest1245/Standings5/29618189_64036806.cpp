#include <bits/stdc++.h>

using namespace std;

int T;

int a, b, c, n;

int ans;

char s[1005];

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d%d", &n, &a, &b, &c);
		scanf("%s", s + 1);
		int x, y, z;
		int xx, yy, zz;
		x = y = z = 0;
		for(int i = 1; i <= n; i++)
		{
			if (s[i] == 'R')
				x++;
			if (s[i] == 'P')
				y++;
			if (s[i] == 'S')
				z++;
		}

		ans = min(z, a) + min(x, b) + min(y, c);
		xx = min(z, a);
		yy = min(x, b);
		zz = min(y, c);
		if (ans < (n + 1) / 2)
		{
			cout << "NO" << endl;
		}
		else
		{
			
			cout << "YES" << endl;
			for(int i = 1; i <= n; i++)
			{
				if (s[i] == 'R')
				{
					if (yy)
						b--, yy--, printf("P");
					else if (a > xx)
						a--, printf("R");
					else if (c > zz)
						c--, printf("S");
				}
				if (s[i] == 'P')
				{
					if (zz)
						c--, zz--, printf("S");
					else if (a > xx)
						a--, printf("R");
					else if (b > yy)
						b--, printf("P");
				}
				if (s[i] == 'S')
				{
					if (xx)
						a--, xx--, printf("R");
					else if (b > yy)
						b--, printf("P");
					else if (c > zz)
						c--, printf("S");
				}
			}
			cout << endl;
		}
	}
	return 0;
}