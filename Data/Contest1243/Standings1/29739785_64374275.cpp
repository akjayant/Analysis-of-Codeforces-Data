#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define endl "\n"
// #define int long long

const long INF = 1e8;
const double PI = acos(-1);
int mod = 1e9 + 7;


int32_t main()
{
	IOS
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i = 0; i < n; i++)
			cin >> v[i];
		sort(v.begin(), v.end(), greater<int>());
		int cnt = 0;
		int mn = INF;
		int ans = -1;
		for(int i = 0; i < n; i++)
		{
			cnt++;
			mn = min(mn, v[i]);
			ans = max(ans, min(mn, cnt));
		}
		cout << ans << endl;
	}	
	return 0;
}