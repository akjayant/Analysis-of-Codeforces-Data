#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using P = pair<int, int>;
#define all(c) (c).begin(), (c).end()
const int INF = INT_MAX;
const ll LINF = LLONG_MAX;
const ll MOD = 1e9 + 7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int T, n, m;
  cin >> T;
  for (int x = 0; x < T; ++x) {
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
    }
    cin >> m;
    vector<int> q(m);
    for (int i = 0; i < m; ++i) {
      cin >> q[i];
    }
    vector<ll> cnt = {0, 0, 0, 0};
    for (int i = 0; i < n; ++i) {
      ++cnt[abs(p[i]) % 2];
    }
    for (int i = 0; i < m; ++i) {
      ++cnt[abs(q[i]) % 2 + 2];
    }
    ll ans = cnt[0] * cnt[2] + cnt[1] * cnt[3];
    cout << ans << endl;
  }
  return 0;
}
