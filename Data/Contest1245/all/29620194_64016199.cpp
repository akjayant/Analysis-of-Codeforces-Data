/*#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")*/
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define Str(x) to_string(x)
#define len(s) (int)s.size()
#define int long long
typedef long long ll;
typedef long double lld;
typedef string str;
typedef unsigned long long ull;

const int MAXN = 5100;

struct rib
{
    int v, u;
    int c;
};


vector <pair<int, int> > v(MAXN);

vector <int> dsu(MAXN), sz(MAXN, 1);

int get(int a)
{
    return dsu[a] == a ? a : dsu[a] = get(dsu[a]);
}

void Union(int x, int y)
{
    if (sz[x] > sz[y])
        swap(x, y);
    dsu[x] = y;
    sz[y] += sz[x];
}

vector <rib> ribs;

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
        dsu[i] = i;
    vector <int> k(n), c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }

    vector <pair<int, pair<int, int>> > rib;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            int flex = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
            flex *= (k[i] + k[j]);
            rib.pb({flex, {i, j}});
        }
    }
    for (int i = 0; i < n; i++) {
        rib.pb({c[i], {i, n}});
    }


    sort(all(rib));
    int sum = 0;
    vector <int> first;
    vector <pair<int, int> > second;
    for (auto it:rib)
    {
        int x = get(it.second.first);
        int y = get(it.second.second);
        if (x != y)
        {
            sum += it.first;
            Union(x, y);
            if (it.second.second == n) {
                first.pb(it.second.first);
            } else {
                second.pb(it.second);
            }
        }
    }
    cout << sum << endl;
    cout << len(first) << endl;
    for (auto it : first)
        cout << it  + 1<< " ";
    cout << endl;
    cout << len(second) << endl;
    for (auto it : second)
        cout << it.first + 1<< " " << it.second + 1 << endl;
    return 0;
}
