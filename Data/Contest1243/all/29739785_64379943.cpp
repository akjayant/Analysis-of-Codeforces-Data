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
		string s, t;
		cin >> n;
		cin >> s >> t;
		vector<char> v1, v2;
		int cnt = 0;

		for(int i = 0; i < n; i++)
		{
			if(s[i] == t[i])
				continue;
			cnt++;
			v1.push_back(s[i]);
			v2.push_back(t[i]);
		}
		if(cnt > 2)
			cout << "No";
		else
		{
			if(v1[0] != v1[1] || v2[0] != v2[1])
				cout << "No";
			else
				cout << "Yes";
		}
		cout << endl;
	}	
	return 0;
}