#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cassert>

using namespace std;


const int maxn = 1e6 + 5;

int main() {
  int q;
  cin >> q;

  for (int qq = 0; qq < q; ++qq) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<int> qwe;
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i]) {
        qwe.push_back(i);
      }
    }
    map<int, int> cnt;
    for (auto i : qwe) {
      ++cnt[a[i]];
      ++cnt[b[i]];
    }

    bool ok = true;
    for (auto [x, c] : cnt) {
      if (c % 2) {
        ok = false;
      }
    }
    if (!ok) {
      cout << "No\n";
      continue;
    }

    vector<pair<int, int>> ans;
    for (auto i : qwe) {
      if (b[i] != a[i]) {
        for (auto j : qwe) {
          if (j > i && a[j] == a[i]) {
            ans.emplace_back(j, i);
            swap(a[j], b[i]);
            break;
          }
        }
      }

      if (b[i] != a[i]) {
        for (auto j : qwe) {
          if (j > i && b[j] == a[i]) {
            ans.emplace_back(qwe.back(), j);
            swap(a[qwe.back()], b[j]);
            ans.emplace_back(qwe.back(), i);
            swap(a[qwe.back()], b[i]);
            break;
          }
        }
      }
    }

    cout << "Yes\n";
    cout << ans.size() << endl;
    for (auto [x, y] : ans) {
      cout << x + 1 << ' ' << y + 1 << endl;
    }
  }
}
