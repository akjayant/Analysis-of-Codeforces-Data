#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <iterator>
#include <valarray>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <numeric>
#include <utility>
#include <string>
#include <cstring>
#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <memory>
#include <vector>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <tuple>
#include <list>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back
#define m_p make_pair
#define fr first
#define sc second
#define endl '\n'
ll const N = 1000005, mod = 1000000007;
ll n, m, k, t, i, j, ans, kaskad[N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll tt;
	cin >> tt;
	while (tt--)
	{
		string s, t;
		cin >> n;
		cin >> s >> t;
		vector<pii> ans;
		bool flag = true;
		for (i = 0; i < n; ++i)
		{
			if (s[i] == t[i])
			{
				continue;
			}
			for (j = i + 1; j < n; ++j)
			{
				if (t[j] == t[i] && t[j] != s[j])
				{
					ans.push_back(m_p(i, j));
					swap(s[i], t[j]);
					break;
				}
			}
			if (s[i] == t[i])
			{
				continue;
			}
			for (j = i + 1; j < n; ++j)
			{
				if (s[j] == s[i] && t[j] != s[j])
				{
					ans.push_back(m_p(j, i));
					swap(s[j], t[i]);
					break;
				}
			}
			if (s[i] == t[i])
			{
				continue;
			}
			for (j = i + 1; j < n; ++j)
			{
				if (t[i] == s[j] && s[j] != t[j])
				{
					ans.pb(m_p(j, j));
					ans.pb(m_p(i, j));
					swap(s[j], t[j]);
					swap(s[i], t[j]);
				}
			}
			if (s[i] == t[i])
			{
				continue;
			}
			for (j = i + 1; j < n; ++j)
			{
				if (t[j] == s[i] && s[j] != t[j])
				{
					ans.pb(m_p(j, j));
					ans.pb(m_p(j, i));
					swap(s[j], t[j]);
					swap(s[j], t[i]);
				}
			}
			if (s[i] != t[i])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			
			ll SIZE = ans.size();
			if (SIZE > 2 * n)
			{
				cout << "No" << endl;
			}
			else{
				cout << "Yes" << endl;
				cout << SIZE << endl;
				for (i = 0; i < SIZE; ++i)
				{
					cout << ans[i].fr + 1 << " " << ans[i].sc + 1 << endl;
				}
			}
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}