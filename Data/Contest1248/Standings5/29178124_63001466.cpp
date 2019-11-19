#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr ll MOD = 1e9 + 7;

ll fib(ll n) {
  if (n < 2) return 1;
  ll f_n_2 = 1, f_n_1 = 1, f_n;
  for (int i = 2; i <= n; ++i) {
    f_n = (f_n_2 + f_n_1) % MOD;
    f_n_2 = f_n_1;
    f_n_1 = f_n;
  }
  return f_n;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  ll ans = (2 * (fib(n) + fib(m) - 1)) % MOD;
  cout << ans << "\n";
}
