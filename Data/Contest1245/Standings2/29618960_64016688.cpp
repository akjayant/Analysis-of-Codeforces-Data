/* Author: chenxiaoyan's girlfriend
 * Time: 2019-11-01 22:57:15
 */ // I love chenxiaoyan!
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int n;
long long ans;
pair<int, int> a[2005];
long long c[2005], ck[2005];
vector<pair<long long, pair<int, int> > > e;

int fa[4005];
bool has[10000000];
int fnd(int x) {
  return fa[x] == x ? x : fa[x] = fnd(fa[x]);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d %d", &a[i].first, &a[i].second);
  for (int i = 1; i <= n; ++i) scanf("%lld", c + i);
  for (int i = 1; i <= n; ++i) scanf("%lld", ck + i);
  for (int i = 1; i <= n; ++i) {
    e.push_back({c[i], {i, i + n}});
  }
  for (int i = n + 1; i <= n + n; ++i)
    for (int j = i + 1; j <= n + n; ++j)
      e.push_back({0, {i, j}});
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      e.push_back({1LL * (abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second)) * (ck[i] + ck[j]), {i, j}});
    }
  }
  sort(e.begin(), e.end());
  for (int i = 1; i <= n * 2; ++i)
    fa[i] = i;
  long long answ = 0;
  for (int i = 0; i < (int)e.size(); ++i) {
    int u = e[i].second.first, v = e[i].second.second;
    long long w = e[i].first;
    if (fnd(u) != fnd(v)) {
      fa[fnd(u)] = fnd(v);
      has[i] = true;
      answ += w;
    }
  }
  printf("%lld\n", answ);
  vector<pair<int, int> > ansp;
  vector<int> ans;
  for (int i = 0; i < (int)e.size(); ++i) {
    if (has[i]) {
      int u = e[i].second.first;
      int v = e[i].second.second;
      if (u > n && v > n) continue;
      if (u > n || v > n) {
        ans.push_back(u > n ? v : u);
      }
      else ansp.push_back(make_pair(u, v));
    }
  }
  printf("%lu\n", ans.size());
  for (int i = 0; i < (int)ans.size(); ++i)
    printf("%d%c", ans[i], " \n"[i == (int)ans.size() - 1]);
  printf("%lu\n", ansp.size());
  for (int i = 0; i < (int)ansp.size(); ++i)
    printf("%d %d%c", ansp[i].first, ansp[i].second, " \n"[i == (int)ansp.size() - 1]);
  return 0;
}
