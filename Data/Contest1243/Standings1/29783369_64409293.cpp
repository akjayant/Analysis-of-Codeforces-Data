#include <cstdio>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

const int N = 100'009;

vector<int> g[N];
int q[N];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    g[i].clear();
  }
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x;
    --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  set<int> s;
  for (int i = 0; i < n; ++i) {
    s.insert(i);
  }
  int ans = n - 1;
  for (int from = 0; from < n; ++from) {
    if (s.count(from) == 0) {
      continue;
    }
    s.erase(from);
    q[0] = from;
    int qt = 1;
    for (int qh = 0; qh < qt; ++qh) {
      int x = q[qh];
      vector<int> w;
      for (int y : g[x]) {
        if (s.count(y) != 0) {
          w.push_back(y);
          s.erase(y);
        }
      }
      while (!s.empty()) {
        q[qt++] = *s.begin();
        s.erase(s.begin());
      }
      for (int e : w) {
        s.insert(e);
      }
    }
    ans -= qt - 1;
  }
  printf("%d\n", ans);
}
