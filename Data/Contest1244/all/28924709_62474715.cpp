/*
  I_🧡🧡🧡_QMsh
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define x first
#define y second

using namespace std;
using namespace __gnu_pbds; // gp_hash_table<int, int> table;

template <typename T> void smin(T &a, const T &b) { a = (a < b ? a : b); }
template <typename T> void smax(T &a, const T &b) { a = (a > b ? a : b); }

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const int MAXN = 1e5 + 30;

int c[3][MAXN];
int color[MAXN];

vector <int> g[MAXN];

ll dfs(int u, int p, int my, int pr)
{
  color[u] = my;
  ll ret = c[my][u];
  for (int v : g[u])
  {
    if (v == p)
      continue;
    for (int i = 0; i < 3; i++)
    {
      if (i != my && i != pr)
        ret += dfs(v, u, i, my);
    }
  }

  return ret;
}

signed main()
{
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 1; j <= n; j++)
      cin >> c[i][j];
  }

  for (int i = 1; i < n; i++)
  {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int st = 1;
  for (int i = 1; i <= n; i++)
  {
    if (g[i].size() == 1)
      st = i;
    if (g[i].size() > 2)
      return cout << -1, 0;
  }

  pair <ll, pair <int, int>> best = {LLONG_MAX, {0, 0}};

  for (int c1 = 0; c1 < 3; c1++)
  {
    for (int c2 = 0; c2 < 3; c2++)
    {
      if (c1 == c2)
        continue;
      ll ans = c[c1][st];
      ans += dfs(g[st][0], st, c2, c1);
      smin(best, {ans, {c2, c1}});
    }
  }

  color[st] = best.second.second;
  dfs(g[st][0], st, best.second.first, best.second.second);
  cout << best.first << "\n";
  for (int i = 1; i <= n; i++)
    cout << color[i] + 1 << " ";

  return 0;
}