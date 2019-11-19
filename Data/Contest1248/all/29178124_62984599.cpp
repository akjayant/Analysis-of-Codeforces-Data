#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt, p, q;
  ll n, m;
  cin >> tt;
  while (tt--) {
    cin >> n;
    ll odd_p = 0;
    for (int i = 0; i < n; ++i) {
      cin >> p;
      if (p & 1) odd_p++;
    }
    cin >> m;
    ll odd_q = 0;
    for (int i = 0; i < m; ++i) {
      cin >> q;
      if (q & 1) odd_q++;
    }
    ll ans = (n - odd_p) * (m - odd_q);
    ans += odd_p * odd_q;
    cout << ans << "\n";
  }
}
