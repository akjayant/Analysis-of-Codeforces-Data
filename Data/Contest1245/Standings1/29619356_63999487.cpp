#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , la , f[maxn];
char c[maxn];
LL ans = 1;

int main()
{
	int i , j;
	cin >> c+1;
	n = strlen(c+1);
	f[0] = f[1] = 1;
	for (i = 2 ; i <= n ; i++)
		f[i] = (f[i-1]+f[i-2])%mod;
	la = 1;
	for (i = 1 ; i <= n ; i++)
	{
		if (c[i] == 'm' || c[i] == 'w')
		{
			cout << "0\n";
			return 0;
		}
		if (c[i] != c[la])
		{
			if (c[la] == 'n' || c[la] == 'u') ans = ans*f[i-la]%mod;
			la = i;
		}
	}
	if (c[la] == 'n' || c[la] == 'u') ans = ans*f[n+1-la]%mod;
	cout << ans << "\n";
	return 0;
}