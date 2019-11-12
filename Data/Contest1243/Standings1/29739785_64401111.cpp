#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define endl "\n"
#define int long long

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
		string s, t;
		cin >> s >> t;
		map<char, int> mps, mpt;
		vector<pair<int, int>> swaps;
		for(int i = 0; i < n; i++)
		{
			if(s[i] == t[i])
				continue;
			mps[s[i]]++;
			mpt[t[i]]++;
		}
		int flag = 0;
		for(int i = 0; i < 26; i++)
		{
			char ch = 'a' + i;
			if((mps[ch] + mpt[ch]) % 2)
			{
				flag = 1;
				break;
			}
		}
		if(flag)
		{
			cout << "No" << endl;
			continue;
		}
		for(int i = 0; i < n - 1; i++)
		{
			if(s[i] == t[i])
				continue;
			int done = 0;
			for(int j = i+1; j < n; j++)
			{
				if(s[j] == s[i])
				{
					swaps.pb({j, i});
					char x = t[i];
					t[i] = s[j];
					s[j] = x;
					done = 1;
					break;
				}
			}
			if(done)
				continue;
			for(int j = i+1; j < n; j++)
			{
				if(s[i] == t[j])
				{
					swaps.pb({i+1, j});
					swaps.pb({i+1, i});
					char x = s[i+1];
					s[i+1] = t[i];
					t[i] = t[j];
					t[j] = x;
					break;
				}
			}
		}
		cout << "Yes" << endl;
		cout << swaps.size() << endl;
		for(int i = 0; i < swaps.size(); i++)
			cout << swaps[i].first + 1 << " " << swaps[i].second + 1 << endl;
		cout << endl;
	}
	return 0;
}