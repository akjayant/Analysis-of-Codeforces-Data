#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, a, b, c, d, k;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c >> d >> k;
    int x = (a - 1) / c + 1, y = (b - 1) / d + 1;
    if (x + y <= k) printf("%d %d\n", x, y);
    else printf("%d\n", -1);
  }
  return 0;
}