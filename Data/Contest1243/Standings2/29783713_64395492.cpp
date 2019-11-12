#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <iomanip>
 
#define SWS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define ppb pop_back
#define ft first
#define sd second
#define read freopen("input.txt", "r", stdin)
#define write freopen("output.txt", "w", stdout)
#define files read; write
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
 
const int Z = (int)3e3 + 228;
const int N = (int)2e5 + 228;
const int INF = (int)1e9 + 228;
const int MOD = (int)1e9 + 7;

int main()
{
	SWS;
	//files;
	int q;
	cin >> q;
	while (q--)
	{
		int n;
		string s, t;
		cin >> n >> s >> t;
		vector<int> cnt(26, 0);
		for (int i = 0; i < n; i++)
		{
			cnt[s[i] - 'a']++;
			cnt[t[i] - 'a']++;
		}
		bool f = true;
		for (int i = 0; i < 26; i++)
			if (cnt[i] % 2) f = false;
		if (!f)
		{
			cout << "No\n";
			continue;
		}
		vector<pii> ans;
		for (int i = 0; i < n; i++)
			if (s[i] != t[i])
			{
				int pos = -1;
				for (int j = i + 1; j < n; j++)
					if (s[j] == s[i]) pos = j;
				if (pos != -1)
				{
					swap(s[pos], t[i]);
					ans.pb({pos, i});
					continue;
				}
				for (int j = i + 1; j < n; j++)
					if (t[j] == s[i]) pos = j;
				swap(s[i + 1], t[pos]);
				ans.pb({i + 1, pos});
				swap(s[i + 1], t[i]);
				ans.pb({i + 1, i});
			}
		//if (n == 5) cout << "DEBUG : " << s << ' ' << t << "\n";
		if (s != t) cout << "No\n";
		else
		{
			cout << "Yes\n";
			cout << ans.size() << "\n";
			for (int i = 0; i < ans.size(); i++)
				cout << ans[i].ft + 1 << ' ' << ans[i].sd + 1 << "\n";
		}
	}
	return 0; 
}