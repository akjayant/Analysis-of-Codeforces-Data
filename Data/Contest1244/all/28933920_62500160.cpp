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

int x[1010101], y[1010101];
int anc[1010101];

int find(int x) {
  return x == anc[x] ? x : anc[x] = find(anc[x]);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  ll n, k; cin >> n >> k;
  k -= n * (n + 1) / 2;
  if (k < 0) {
    cout << "-1\n";
    return 0;
  }
  iota(x, x + n, 1);
  iota(anc, anc + 1 + n, 0);
  for (int i = 0; i < n; i++) {
    int v = min(n, x[i] + k);
    int a = find(v);
    y[i] = a, k -= max(0, a - x[i]);
    anc[a] = a - 1;
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += max(x[i], y[i]);
  }
  cout << ans << "\n";
  for (int i = 0; i < n; i++) {
    cout << x[i] << " \n"[i == n - 1];
  }
  for (int i = 0; i < n; i++) {
    cout << y[i] << " \n"[i == n - 1];
  }
}