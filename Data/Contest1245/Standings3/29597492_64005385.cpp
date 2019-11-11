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
  vector<ll> hand(3, 0);
  ll a, b, c;
  cin >> a >> b >> c;
  hand[0] = a;
  hand[1] = c;
  hand[2] = b;
  string s;
  cin >> s;
  vector<ll> cnt(3, 0);
  map<char, ll> p;
  p['R'] = 0, p['S'] = 1, p['P'] = 2;
  string t = "RSP";
  REP(i, n) { cnt[p[s[i]]]++; }
  ll win = 0;
  REP(i, 3) { win += min(hand[i], cnt[(i + 1) % 3]); }
  if (win < (n + 1) / 2) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  vector<char> ans(n, '?');
  REP(i, n) {
    if (hand[(p[s[i]] + 2) % 3] > 0) {
      ans[i] = t[(p[s[i]] + 2) % 3];
      hand[(p[s[i]] + 2) % 3]--;
    }
  }
  REP(i, n) {
    if (ans[i] == '?') {
      REP(j, 3) if (hand[j] > 0) {
        ans[i] = t[j];
        hand[j]--;
        break;
      }
    }
  }
  REP(i, n) { cout << ans[i]; }
  cout << "\n";
}

int main() {
  ll t;
  cin >> t;
  while (t--) solve();
}