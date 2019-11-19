#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		long long a,b,c,d,k;
		cin >> a >> b >> c >> d >> k;
		long long x = (a - 1) / c + 1;
		long long y = (b - 1) / d + 1;
		if(x + y > k)
			cout << -1 << endl;
		else
			cout << x << " " << y << endl;
	}
}