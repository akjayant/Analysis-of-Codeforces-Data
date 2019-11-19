#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define IFOR(i, m, n) for (ll i = n - 1; i >= m; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define FOREACH(x, a) for (auto&(x) : (a))
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

void solve() {
  ll a, b, c, d, k;
  cin >> a >> b >> c >> d >> k;
  ll ans1 = 1e18, ans2 = 1e18, mini = 1e18;
  REP(i, k + 1) REP(j, k - i + 1) {
    if (c * i >= a && d * j >= b && i + j < mini) {
      ans1 = min(ans1, i);
      ans2 = min(ans2, j);
      mini = min(mini, i + j);
    }
  }
  if (mini == 1e18) {
    cout << -1 << endl;
  } else {
    cout << ans1 << " " << ans2 << endl;
  }
}

int main() {
  ll t;
  cin >> t;
  while (t--) solve();
}