#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 3e6+10;
const LL mod = 1e9+7;

int T , n , a , b , c , g , f[110];
char s[110] , ss[110];

int main()
{
	int i , j;
	cin >> T;
	while (T--)
	{
		cin >> n;
		cin >> a >> b >> c;
		cin >> s+1;
		g = 0;
		for (i = 1 ; i <= n ; i++)
			f[i] = 0;
		for (i = 1 ; i <= n ; i++)
		{
			if (s[i] == 'S' && a)
			{
				a--;
				ss[i] = 'R';
				f[i] = 1;
				g++;
			}
			else if (s[i] == 'R' && b)
			{
				b--;
				ss[i] = 'P';
				f[i] = 1;
				g++;
			}
			else if (s[i] == 'P' && c)
			{
				c--;
				ss[i] = 'S';
				f[i] = 1;
				g++;
			}
		}
		if (g < (n+1)/2)
		{
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for (i = 1 ; i <= n ; i++)
		{
			if (!f[i] && a)
			{
				a--;
				ss[i] = 'R';
			}
			else if (!f[i] && b)
			{
				b--;
				ss[i] = 'P';
			}
			else if (!f[i] && c)
			{
				c--;
				ss[i] = 'S';
			}
		}
		ss[n+1] = '\0';
		cout << ss+1 << "\n";
	}
	return 0;
}