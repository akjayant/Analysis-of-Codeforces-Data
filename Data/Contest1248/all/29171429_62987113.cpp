#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

const ll mod = 1e9+7;

ll solve(ll n) {
  vector<vector<ll> > dp(2, vector<ll>(n, 0));
  dp[1][0] = 0;
  dp[0][0] = 1;
  for (int i = 1; i < n; i++) {
    dp[0][i] = (dp[0][i-1] + dp[1][i-1])%mod;
    dp[1][i] = dp[0][i-1];
  }
  return 2*(dp[0][n-1] + dp[1][n-1])%mod;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.precision(20);
  ll n, m;
  cin >> n >> m;
  cout << (solve(n)+solve(m)+mod-2)%mod << endl;
}

