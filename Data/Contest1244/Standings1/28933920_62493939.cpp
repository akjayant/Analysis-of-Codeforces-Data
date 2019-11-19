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

int a[101010];
ll sum[101010];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n; cin >> n;
  ll k; cin >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    sum[i] = a[i] + sum[i - 1];
  }
  int ans = a[n] - a[1];
  for (int i = 1; i <= n; i++) {
    ll remain = k - ((ll)(i - 1) * a[i] - sum[i - 1]);
    if (remain < 0) continue;

    int low = a[i], high = a[n];
    while (low < high) {
      int mid = (low + high) / 2;
      int pos = upper_bound(a + 1, a + 1 + n, mid) - a;
      ll need = (sum[n] - sum[pos - 1]) - (ll)(n - pos + 1) * mid;
      if (remain >= need) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    ans = min(ans, high - a[i]);
  }
  for (int i = n; i >= 1; i--) {
    ll remain = k - ((sum[n] - sum[i]) - (ll)(n - i) * a[i]);
    if (remain < 0) continue;

    int low = a[1], high = a[i];
    while (low < high) {
      int mid = (low + high + 1) / 2;
      int pos = lower_bound(a + 1, a + 1 + n, mid) - a;
      ll need = (ll)(pos - 1) * mid - sum[pos - 1];
      if (remain >= need) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }
    ans = min(ans, a[i] - low);
  }
  cout << ans << "\n";
}