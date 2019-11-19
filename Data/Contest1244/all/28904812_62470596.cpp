#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll t, n, l, r, ans;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for (int o = 1; o <= t; o ++)
	{
		cin >> n;
		cin >> s;
		l = r = -1;
		for (int i = 0; i < (ll)s.size(); i ++)
		{
			if ((l == -1) && (s[i] == '1'))
				l = i;
				if (s[i] == '1')
					r = i;
		}
		if (l == r && r == -1)
		{
			cout << n << endl;
			continue;
		}
		ans = max(2 * (r + 1), max(n + 1, 2 * (n - l)));
		cout << ans << endl;
	}
	return 0;
}