#include <bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
//template<typename key, typename val>
//using ordered_tree =
//  tree<key, val, greater<>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long int64;
typedef complex<double> comp;
const double pi = 3.14159265358979323846;
const int inf = (int)1e+9 + 2;
const int64 inf64 = (int64)1e+18 + 2;
const double dinf = 1e+20;
const int mod = 1'000'000'007;//998244353;
const int base = 2187;
const double eps = 1e-8;
const int N = 100'000;
const int LOGN = 19;

int n, m, k;

void solve(int test) {
  cin >> n >> m >> k;
  vector<set<int>> r(n), c(m);
  for (int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    r[x].insert(y);
    c[y].insert(x);
  }
  int64 total = 1;
  int x = 0, y = 0;
  bool ok = true;
  int x_min = 0, x_max = n;
  int y_min = -1, y_max = m;
  for (int dir = 0, not_moved = 0; ok; dir = (dir + 1) % 4) {
    int to;
    switch (dir) {
      case 0: {
        auto it = r[x].upper_bound(y);
        if (it == r[x].end()) {
          to = y_max;
        } else {
          to = min(*it, y_max);
        }
        not_moved += to - y - 1 == 0;
        total += to - y - 1;
        y = to - 1;
        y_max = min(y, y_max);
        break;
      }
      case 1: {
        auto it = c[y].upper_bound(x);
        if (it == c[y].end()) {
          to = x_max;
        } else {
          to = min(*it, x_max);
        }
        not_moved += to - x - 1 == 0;
        total += to - x - 1;
        x = to - 1;
        x_max = min(x, x_max);
        break;
      }
      case 2: {
        auto it = r[x].upper_bound(y);
        if (it == r[x].begin()) {
          to = y_min;
        } else {
          to = max(*--it, y_min);
        }
        not_moved += y - to - 1 == 0;
        total += y - to - 1;
        y = to + 1;
        y_min = max(y, y_min);
        break;
      }
      case 3: {
        auto it = c[y].upper_bound(x);
        if (it == c[y].begin()) {
          to = x_min;
        } else {
          to = max(*--it, x_min);
        }
        not_moved += x - to - 1 == 0;
        total += x - to - 1;
        x = to + 1;
        x_min = max(x, x_min);
        break;
      }
    }
    ok &= not_moved < 2;
    ok &= x_min <= x && x <= x_max
       && y_min <= y && y <= y_max;
    if (total >= n * 1ll * m - k) {
      break;
    }
    not_moved = 1;
  }
  if (ok && total >= n * 1ll * m - k) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}

void precalc() {
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  precalc();
  int test = 1;
  //cin >> test;
  //auto start = chrono::high_resolution_clock::now();
  for (int i = 1; i <= test; ++i) {
    solve(i);
  }
  //cerr << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start).count() << '\n';
  return 0;
}


