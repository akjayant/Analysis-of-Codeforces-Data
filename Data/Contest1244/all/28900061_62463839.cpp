#include <bits/stdc++.h>

using namespace std;

int n;
int a,b,c,d,k;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	while(n--)
	{
		cin >> a >> b >> c >> d >> k;
		int x = a/c;
		if (a%c) x++;
		int y = b/d;
		if (b%d) y++;
		if (x+y > k) cout << -1 << '\n';
		else cout << x << ' ' << y << '\n';
	}
}