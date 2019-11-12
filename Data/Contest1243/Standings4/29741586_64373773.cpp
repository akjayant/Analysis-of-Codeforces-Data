#include <bits/stdc++.h>

using namespace std;

const int DIM = 1007;

int v[DIM];

bool check(int mid, int n)
{
	if(v[n - mid + 1] >= mid)
		return true;
}

void solve()
{
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++)
		cin >> v[i];
	
	sort(v + 1, v + 1 + n);
	
	int res = 1;
	
	for(int i = n; i >= 1; i--)
		if(v[i] >= (n - i + 1))
			res = n - i + 1;
		else
			break;
	
	cout << res << '\n';
}

main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--)
	{
		solve();
	}
}