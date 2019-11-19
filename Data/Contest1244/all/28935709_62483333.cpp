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
	int n;
	cin >> n;

	vector<vector<int>> c(3 + 1, vector<int>(n + 1));
	for1 (i, 3)
	{
		for1 (j, n)
		{
			cin >> c[i][j];
		}
	}

    vector<vector<int>> edges(n + 1);
    rep (_, n - 1)
    {
    	int a, b;
    	cin >> a >> b;

    	edges[a].push_back(b);
    	edges[b].push_back(a);
    }

    for1 (i, n)
    {
    	if (edges[i].size() > 2)
		{
			cout << -1;
			return;
		}
    }

    vector<int> g(n + 1);
    int s;
    for1 (i, n)
    {
    	if (edges[i].size() == 1)
		{
			s = i;
			break;
		}
    }

    g[s] = 1;
    bool changed = true;
    while (changed)
	{
		changed = false;
        for (int n: edges[s])
		{
			if (!g[n])
			{
				changed = true;
				g[n] = g[s] % 3 + 1;
				s = n;
//cout << n << " " << g[n] << endl;
				break;
			}
		}
	}

    vector<vector<long long>> gc(3 + 1, vector<long long>(3 + 1));
		// [group][colour] = cost
    for1 (i, n)
    {
        int group = g[i];
        for1 (j, 3) // colour
        {
        	gc[group][j] += c[j][i];
        }
    }

    int perm[][4] =
    {
		{0, 1, 2, 3},
		{0, 1, 3, 2},
		{0, 2, 1, 3},
		{0, 2, 3, 1},
		{0, 3, 1, 2},
		{0, 3, 2, 1}
    }; // [p][group] = colour

    int p = -1;
    long long cost = 100000000000001ll;

    rep (i, 6)
    {
        long long c = 0;
        for1 (j, 3) // group
        {
        	c += gc[j][perm[i][j]];
//cout << perm[i][j] << " ";
        }
//cout << endl;

        if (c < cost)
		{
			cost = c;
			p = i;
		}
    }

//cout << gc[1][perm[p][1]] << gc[2][perm[p][2]] << gc[3][perm[p][3]] << endl;

    cout << cost << "\n";
    for1 (i, n)
    {
        cout << perm[p][g[i]] << " ";
    }
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
