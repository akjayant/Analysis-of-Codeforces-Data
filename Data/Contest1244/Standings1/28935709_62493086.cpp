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

int n, k;

inline int& inc(int& i)
{
	++i;
	if (i == n)
	{
		i = 0;
	}
	return i;
}

inline int& dec(int& i)
{
	--i;
	if (i == -1)
	{
		i = n - 1;
	}
	return i;
}

inline int add(int i, int j)
{
	int r = i + j;
	if (r >= n)
	{
		r -= n;
	}
	return r;
}

inline int sub(int i, int j)
{
	int r = i - j;
	if (r < 0)
	{
		r += n;
	}
	return r;
}

const char MASK = 'W' ^ 'B';

inline void solve()
{
	cin >> n >> k;

    string s;
    cin >> s;

    vector<int> dub;

	for (int i = 0; i < n; ++i)
	{
        int j = add(i, 1);
		if (s[i] == s[j])
		{
			dub.push_back(i);
		}
	}

    if (dub.empty())
	{
        if (k & 1)
		{
            for (char c: s)
			{
				c ^= MASK;
				cout << c;
			}
			return;
		}

		cout << s;
		return;
	}

    dub.push_back(dub.front());

    for (int i = 0; i < dub.size() - 1; ++i)
	{
		int j = i + 1;

		int l = dub[i];
		inc(l);
		int r = dub[j];

        if (s[l] == s[r])
		{
			char c = s[l];
            for (int _ = 0; _ < k && l != r; ++_)
			{
				inc(l);
				dec(r);
				s[l] = c;
				s[r] = c;
			}

			while (l != r)
			{
				inc(l);
				dec(r);
				c ^= MASK;
				s[l] = c;
				s[r] = c;
			}
		}
		else
		{
			char lc = s[l];
			char rc = s[r];

			for (int _ = 0; _ < k && add(l, 1) != r; ++_)
			{
				inc(l);
				dec(r);
				s[l] = lc;
				s[r] = rc;
//cout << s << endl;
			}

			while (add(l, 1) != r)
			{
				inc(l);
				dec(r);
				lc ^= MASK;
				rc ^= MASK;
				s[l] = lc;
				s[r] = rc;
			}

		}
	}

	cout << s;
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
