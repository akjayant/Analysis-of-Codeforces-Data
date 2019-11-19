#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <string>
#include <iterator>
#include <cmath>

using namespace std;
vector<long long> x, y;

inline long long dist(int i, int j)
{
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

int main()
{
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<pair<long long, pair<int, int>>> g;
    g.reserve((n + 1) * (n + 1));
    x.resize(n + 1);
    y.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> x[i] >> y[i];
    for (int i = 1; i <= n; ++i) {
        long long c;
        cin >> c;
        g.push_back({ c, { 0, i } });
    }
    vector<long long> k(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> k[i];
    for (int i = 1; i <= n - 1; ++i)
        for (int j = i + 1; j <= n; ++j)
            g.push_back({ (k[i] + k[j]) * dist(i, j), { i, j } });
    vector<pair<int, int>> res;
    long long cost = 0;
    res.reserve(n);
    sort(g.begin(), g.end());
    vector<int> tree_id(n + 1);
    for (int i = 0; i <= n; ++i)
        tree_id[i] = i;
    for (int i = 0; i < g.size(); ++i)
    {
        int a = g[i].second.first, b = g[i].second.second;
        long long l = g[i].first;
        if (tree_id[a] != tree_id[b])
        {
            cost += l;
            res.push_back(make_pair(a, b));
            int old_id = tree_id[b], new_id = tree_id[a];
            for (int j = 0; j <= n; ++j)
                if (tree_id[j] == old_id)
                    tree_id[j] = new_id;
        }
    }
    cout << cost << '\n';
    int b = 0;
    vector<int> ans;
    for (auto e : res)
        if (e.first == 0) {
            ++b;
            ans.push_back(e.second);
        }
    cout << b << '\n';
    for (auto h : ans)
        cout << h << ' ';
    cout << '\n';
    cout << res.size() - b << '\n';
    for (auto e : res)
        if (e.first != 0)
            cout << e.first << ' ' << e.second << '\n';
    return 0;
}