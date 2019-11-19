#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
void out (long long a, long long b, long long c) {
  cout << a << " " << b << " " << c << '\n';
  exit(0);
}
void err() {
  cout << -1 << '\n';
  exit(0);
}
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  //c
  long long n, p, w, d;
  cin >> n >> p >> w >> d;
  long long k = p / w;
  for (long long x = k, i = 0; x >= 0 && i <= d; i++, x--) {
    if ((p - w * x) % d == 0) {
      if (x + (p - w * x) / d <= n) out(x, (p - w * x) / d, n - x - (p - w * x) / d);
    }
  }
  err();
  return 0;
}