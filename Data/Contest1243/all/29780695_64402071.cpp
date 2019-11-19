#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <tuple>
#include <unordered_set>

using namespace std;

using ll = long long;
const ll maxn = 1e5 + 5;

vector<unordered_set<int>> G;
set<int> used;

void go(int v) {
  // clog << v << endl;
  used.erase(v);

  const auto& asd = G[v];

  /*
  clog << "asd: ";
  for (auto x : asd) {
    clog << x  + 1 << ' ';
  }
  clog << endl;
  */

  while (!used.empty() && asd.find(*used.begin()) == asd.end()) {
    go(*used.begin());
  }
  for (auto to : asd) {
    bool ok = true;
    while (ok) {
      ok = false;
      if (!used.empty()) {
        auto next = used.upper_bound(to);
        if (next != used.end()) {
          if (asd.find(*next) == asd.end()) {
            ok = true;
            go(*next);
          }
        }
      }
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  G.resize(n);

  for (int i = 0; i < n; ++i) {
    used.insert(i);
  }

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    G[a].insert(b);
    G[b].insert(a);
  }

  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (used.find(i) != used.end()) {
      ++cnt;
      go(i);
//      clog << endl;
    }
  }
  cout << cnt - 1 << endl;
}
