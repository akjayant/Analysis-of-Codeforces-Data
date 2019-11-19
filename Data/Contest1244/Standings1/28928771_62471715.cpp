#include <bits/stdc++.h>

using namespace std;

int T, n;
string s;

int main()
{
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--)
	{
		cin >> n >> s;
		int t = 0, cnt = 0;
		for (int i = 0; i < s.size(); i++)
			if (s[i] == '1')
			{
				t = max(t, max(i + 1, n - i));
				cnt++;
			}
		if (!cnt) cout << n << endl;
		else cout << max(n, t * 2) << endl;
	}
	return 0;
}
