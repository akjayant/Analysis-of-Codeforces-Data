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
		int n;
		cin >> n;
		string s;
		cin >> s;
		int mx = n;
		for(int i = 0; i < n; i++)
		{
			if(s[i] == '1')
				mx = max({mx, (n - i) * 2, (i + 1) * 2});
		}
		cout << mx << "\n";
	}
}