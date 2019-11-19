#include <bits/stdc++.h>

using namespace std;

void solve() {
  int a, b, c, d, k;
  cin >> a >> b >> c >> d >> k;
  int x = (a + c - 1) / c, y = (b + d - 1) / d;
  if (x + y > k) {
    cout << -1;
  } else {
    cout << x << ' ' << y;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }

  return 0;
}