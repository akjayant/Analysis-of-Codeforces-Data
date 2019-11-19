#pragma GCC optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void Main();
#ifdef ConanYu
#include "local.hpp"
#else
#define debug(...) do { } while(0)
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  Main();
}
#endif

const int N = 1111111;
int x[N], y[N];
int anc[N];
int fnd(int x) {
  return x == anc[x] ? x : anc[x] = fnd(anc[x]);
}

void Main() {
  ll n, k; cin >> n >> k;
  k -= n * (n + 1) / 2;
  if (k < 0) {
    cout << "-1\n";
    return;
  }
  for(int i = 0; i < n; i++) {
    x[i] = i + 1;
  }
  for(int i = 0; i <= n; i++) {
    anc[i] = i;
  }
  for (int i = 0; i < n; i++) {
    int v = min(n, x[i] + k);
    int a = fnd(v);
    y[i] = a;
    k -= max({0, a - x[i]});
    anc[a] = a - 1;
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += max({y[i], x[i]});
  }
  cout << ans << "\n";
  for (int i = 0; i < n; i++) {
    cout << x[i] << " \n"[i == n - 1];
  }
  for (int i = 0; i < n; i++) {
    cout << y[i] << " \n"[i == n - 1];
  }
}
