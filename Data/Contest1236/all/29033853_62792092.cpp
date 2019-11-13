#include <bits/stdc++.h>
#ifdef local
  #include "debug.hpp"
#else
  #define debug(...) 0
#endif
using namespace std;

#define pb push_back
#define SZ(s) ((int)s.size())
#define all(vec) vec.begin(), vec.end()

using ll = long long;
template <class T> using V = vector<T>;

template <class T, class U>
bool chkmin(T& x, U y) {
  return (y < x) ? (x = y, true) : false;
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

int check(V<V<int>> &a) {
  int ans = 1000000;
  for (int i = 0; i < SZ(a); i++) {
    for (int j = 0; j < SZ(a); j++) {
      if (i == j) continue;
      int sum = 0;
      for (int k = 0; k < SZ(a); k++) {
        for (int t = 0; t < SZ(a); t++) {
          if (a[i][k] > a[j][t]) ++sum;
        }
      }
      ans = min(ans, sum);
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n; cin >> n;
  V<V<int>> ans(n);
  for (int i = 0; i < n; i++) {
    int l = i * n, r = l + n;
    if (i & 1) {
      for (int j = l; j < r; j++) {
        ans[j - l].pb(j + 1);
      }
    } else {
      for (int j = l; j < r; j++) {
        ans[r - j - 1].pb(j + 1);
      }
    }
  }
  debug(check(ans));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << ans[i][j] << " \n"[j == n - 1];
    }
  }
}