#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int a, b, c, d, k;
  cin >> a >> b >> c >> d >> k;
  for(int x = 0; x <= a; ++x) {
    for(int y = 0; y <= b; ++y) {
      if(x + y <= k && c * x >= a && d * y >= b) {
        cout << x << ' ' << y << '\n';
        return;
      } 
    } 
  }
  cout << -1 << '\n';
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
