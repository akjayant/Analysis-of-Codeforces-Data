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

const ll MOD = 1e9 + 7;

vector<pair<char, ll>> RunLengthCompression(const string& s) {
  ll cur = 1;
  ll n = SZ(s);
  vector<pair<char, ll>> run;
  REP(i, n - 1) {
    if (s[i] == s[i + 1]) {
      cur++;
      continue;
    }
    run.push_back(make_pair(s[i], cur));
    cur = 1;
  }
  run.push_back(make_pair(s[n - 1], cur));
  return run;
}

int main() {
  string s;
  cin >> s;
  auto run = RunLengthCompression(s);
  ll ans = 1;
  ll n = SZ(run);
  ll m = SZ(s);
  vector<ll> dp(m + 1, 0);
  dp[0] = 1, dp[1] = 1;
  FOR(i, 2, m + 1) { dp[i] = (dp[i - 1] + dp[i - 2]) % MOD; }
  REP(i, n) {
    char c = run[i].first;
    ll x = run[i].second;
    if (c == 'm' || c == 'w') {
      cout << 0 << endl;
      return 0;
    }
    if (c != 'u' && c != 'n') {
      continue;
    }
    (ans *= dp[x]) %= MOD;
  }
  cout << ans << endl;
}