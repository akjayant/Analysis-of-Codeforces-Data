#include <bits/stdc++.h>

using namespace std;

int t;
int a,b,c;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while(t--)
	{
		cin >> a >> b >> c;
		int res = 0;
		while(b>=1 && c>=2)
		{
			b--;
			c-=2;
			res += 3;
		}
		while(b>=2 && a>=1)
		{
			a--;
			b-=2;
			res += 3;
		}
		cout << res << '\n';
	}
}