#include <bits/stdc++.h>
// #include "debug.hpp"
using namespace std;

#define pb push_back
#define SZ(s) ((int)s.size())
#define all(vec) vec.begin(), vec.end()

using ll = long long;
template <class T> using V = vector<T>;

template <class T, class U>
bool chkmin(T& x, U y) {
  return (x > y) ? (x = y, true) : false;
}
template <class T, class U>
bool chkmax(T& x, U y) {
  return (x < y) ? (x = y, true) : false;
}
int add(int x, int y, int mod) {
  x += y;
  return (x >= mod) ? (x - mod) : x;
}
int sub(int x, int y, int mod) {
  x -= y;
  return (x < 0) ? (x + mod) : x;
}
int mul(int x, int y, int mod) {
  return (ll)x * y % mod;
}
int qpow(int a, int t, int mod) {
  int b = 1;
  for (; t > 0; t >>= 1, a = mul(a, a, mod)) {
    if (t & 1) b = mul(b, a, mod);
  }
  return b;
}


int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int T; cin >> T;
  while (T--) {
    int a, b, c, d, k; cin >> a >> b >> c >> d >> k;
    int x = (a - 1) / c + 1, y = (b - 1) / d + 1;
    if (x + y <= k) cout << x << " " << y << "\n";
    else cout << "-1\n";
  }
}