#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
string s;
int f[1234567];
signed main()
{
	cin >> s;
	int n = s.length();
	s = " " + s;
	for(int i = 1;i <= n;i++)
		if(s[i] == 'm' || s[i] == 'w')
		{
			cout << 0 << endl;
			return 0;
		}
	f[0] = f[1] = 1;
	for(int i = 2;i <= n;i++)
		if(s[i] == s[i - 1] && (s[i] == 'u' || s[i] == 'n'))
			(f[i] = f[i - 2] + f[i - 1]) %= mod;
		else
			f[i] = f[i - 1];
	cout << f[n] << endl;
	return 0;
}