#include<bits/stdc++.h>

using namespace std;

main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;
	while(q--)
	{
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		int cnt1 = (a + c - 1) / c;
		int cnt2 = (b + d - 1) / d;
		if(cnt1 + cnt2 > k)
			cout << "-1\n";
		else
			cout << cnt1 << " " << cnt2 << "\n";
	}
}