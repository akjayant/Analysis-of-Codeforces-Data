#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		int x, y, z, tot = 0, ans = 0;
		cin >> x >> y >> z;
		tot = (min(y, z / 2));
		y -= tot;
		z -= tot * 2;
		ans += tot * 3;
		tot = min(x, y / 2);
		x -= tot;
		y -= tot * 2;
		ans += tot * 3;
		cout << ans <<"\n";
	}
	return 0;
}