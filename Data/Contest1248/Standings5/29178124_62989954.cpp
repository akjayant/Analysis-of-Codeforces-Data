#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int a[1000000];
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  ll x = 0, y = 0;
  int i;
  for (i = 0; i < n / 2; ++i) {
    x += a[i];
  }
  for (; i < n; ++i) {
    y += a[i];
  }
  ll ans = x * x + y * y;
  cout << ans << "\n";
}
