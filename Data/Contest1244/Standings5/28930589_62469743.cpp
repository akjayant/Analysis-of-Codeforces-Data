#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  int mn = n, mx = 0;
  for(int i = 0; i < n; ++i) {
    if(s[i] == '1') {
      mn = min(mn, i);
      mx = max(mx, i);
    }
  }
  if(mn == n) {
    cout << n << '\n';
    return;
  }
  if(mx < n - mn - 1) {
    cout << 2 * (n - mn) << '\n';
  } else {
    cout << 2 * (mx + 1) << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt = 1;
  cin >> tt;
  for(int t = 1; t <= tt; ++t) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
