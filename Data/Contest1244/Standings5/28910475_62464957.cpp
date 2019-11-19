#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    bool can = false;
    for (int pens = 1; pens < k; pens++) {
      if (pens * c >= a && (k - pens) * d >= b) {
        can = true;
        cout << pens << " " << k - pens << endl;
        break;
      }
    }
    if (!can) cout << -1 << endl;
  }
  return 0;
}

