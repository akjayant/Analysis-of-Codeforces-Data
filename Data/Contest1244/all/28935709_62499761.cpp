/**
	© 2017-2019 Tai-Yuan Kuo All Rights Reserved.
*/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define for0(i, n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
#define rfor0(i, n) for(int i = n - 1; i >= 0; --i)
#define rfor1(i, n) for(int i = n; i > 0; --i)
#define all(it, a) for(auto it = (a).begin(); it != (a).end(); ++it)
#define rall(it, a) for(auto it = (a).rbegin(); it != (a).rend(); ++it)
#define rep for0

stringstream output;

/** Actually outputs the result and end the program.*/
inline void eOP();

inline void solve()
{
	#define int long long
	long long n, k;
	cin >> n >> k;

    map<int,int> cnt;
    rep (_, n)
    {
    	int a;
    	cin >> a;
    	++cnt[a];
    }

    vector<pair<int,int>> asdf(cnt.begin(), cnt.end());
	int l = 0;
	int r = asdf.size() - 1;

    while (l != r)
	{
		if (asdf[l].second < asdf[r].second)
		{
			int d = min((long long)asdf[l + 1].first - asdf[l].first, k / asdf[l].second);
			if (!d)
			{
				break;
			}

            if (d == asdf[l + 1].first - asdf[l].first)
			{
				k -= d * asdf[l].second;
				asdf[l + 1].second += asdf[l].second;
				++l;
				continue;
			}
			k -= d * asdf[l].second;
			asdf[l].first += d;
		}
		else
		{
			int d = min((long long)asdf[r].first - asdf[r - 1].first, k / asdf[r].second);
			if (!d)
			{
				break;
			}

            if (d == asdf[r].first - asdf[r - 1].first)
			{
				k -= d * asdf[r].second;
				asdf[r - 1].second += asdf[r].second;
				--r;
				continue;
			}
			k -= d * asdf[r].second;
			asdf[r].first -= d;
		}
	}

	cout << (asdf[r].first - asdf[l].first);
	#undef int
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	size_t t = 1;
	//cin >> t;
	rep (i, t)
	{
		solve();
	}

	eOP();
}

inline void eOP()
{
	cout << output.str();
	output.str(string());
	exit(0);
}
