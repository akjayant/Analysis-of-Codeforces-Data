#pragma GCC optimize("O3")

# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_set>
# include <unordered_map>
 
#define LL long long
#define LD long double
//#define create(a,b,c,d) mp(a,mp(b,mp(c,d)))
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define opt ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define _sz(x) (int)x.size()
#define _all(x) x.begin(),x.end()
#define ld long double
#define lb(x, v) lower_bound(_all(x),v)
#define el '\n'
#define eb emplace_back

using namespace std;
const LL N = 150, INF = 1e9;

inline void solve()
{
	string s, t;
	LL n;
	cin >> n >> s >> t;
	vector<pair<LL, LL> > ans;
	for(LL i = 0; i < n; i++)
	{
		if(s[i] == t[i])
			continue;
		LL pos1 = -1;
		for(LL j = i+1; j < n; j++)
		{
			if(s[j] == t[j])
				continue;
			if(s[i] == s[j])
			{
				pos1 = j;
				break;
			}
		}
		if(pos1 != -1)
		{
			//cout << s << " " << t << " 1" << el;
			swap(s[pos1], t[i]);
			ans.pb(mp(pos1, i));
			continue;
		}
		for(LL j = i+1; j < n; j++)
		{
			if(s[j] == t[j])
				continue;
			if(t[i] == t[j])
			{
				pos1 = j;
				break;
			}
		}
		if(pos1 != -1)
		{
			//cout << s << " " << t << " 2" << el;
			swap(s[i], t[pos1]);
			ans.pb(mp(i, pos1));
			continue;
		}
		for(LL j = i+1; j < n; j++)
		{
			if(s[j] == t[j])
				continue;
			if(s[i] == t[j])
			{
				pos1 = j;
				break;
			}
		}
		if(pos1 != -1)
		{
			//cout << s << " " << t << " 3" << el;
			swap(s[n-1], t[pos1]);
			swap(s[n-1], t[i]);
			ans.pb(mp(n-1, pos1));
			ans.pb(mp(n-1, i));
			continue;
		}
		for(LL j = i+1; j < n; j++)
		{
			if(s[j] == t[j])
				continue;
			if(s[j] == t[i])
			{
				pos1 = j;
				break;
			}
		}
		if(pos1 != -1)
		{
			//cout << s << " " << t << " 4" << el;
			swap(t[n-1], s[pos1]);
			swap(t[n-1], s[i]);
			ans.pb(mp(pos1, n-1));
			ans.pb(mp(i, n-1));
			continue;
		}
	}
	if(s == t)
	{
		cout << "Yes" << el << _sz(ans) << el;
		for(LL i = 0; i < _sz(ans); i++)
		{
			cout << ans[i].ff+1 << " " << ans[i].ss+1 << el;
		}
	}
	else
	{
		cout << "No" << el;
	}
}

int main()
{
	LL test_count = 1;
	cin >> test_count;
	for(LL test = 0; test < test_count; test++)
	{
		solve();
	}
}

/*
a c a
c a c
No

a c
*/