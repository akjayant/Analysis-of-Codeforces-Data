#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, n, m, x, p, q;
  cin >> t;
  while (t--) {
    cin >> n;
    p = q = 0;
    for (int i = 0; i < n; i++) {
      cin >> x;
      p += x & 1;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
      cin >> x;
      q += x & 1;
    }
    cout << (0ll + p) * (0ll + q) + (0ll + n - p) * (0ll + m - q) << '\n';
  }
  return 0;
} 