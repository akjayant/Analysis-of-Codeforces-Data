#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  long long n, p;
  int d, w;
  cin >> n >> p >> w >> d;
  for (int y = 0; y <= w; ++y) {
      if (1ll * y * d <= p and (p - 1ll * y * d) % w == 0) {
        long long x = (p - 1ll * y * d) / w;
        if (x + y <= n) {
          cout << x << ' ' << y << ' ' << n - x - y;
          return 0;
        }
      }
  }
  cout << -1;

  return 0;
}