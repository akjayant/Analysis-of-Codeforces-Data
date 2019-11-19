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
  ll n;
  cin >> n;
  string s;
  cin >> s;
  ll mini = n - 1, maxi = -1;
  REP(i, n) {
    if (s[i] == '1') {
      mini = i;
      break;
    }
  }
  IREP(i, n) {
    if (s[i] == '1') {
      maxi = i;
      break;
    }
  }
  if (maxi == -1) {
    cout << n << endl;
    return;
  }
  cout << 2 * max(maxi + 1, n - mini) << endl;
}

int main() {
  ll t;
  cin >> t;
  while (t--) solve();
}