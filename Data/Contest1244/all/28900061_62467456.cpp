#include <bits/stdc++.h>

using namespace std;

int t;
int n;
string s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while(t--)
	{
		cin >> n;
		int res = n;
		cin >> s;
		int mn = -1;
		int mx = -1;
		for (int i=0;i<n;i++)
			if (s[i] == '1')
			{
				if (mn == -1) mn = i;
				mx = max(mx,i);
			}
		if (mn != -1)
		{
			res = max(res,2*(n-mn));
			res = max(res,2*(mx+1));
		}
		cout << res << '\n';
	}
}