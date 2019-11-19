#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000 * 1000 * 1000 + 7;

long long n, m;
vector<long long> fib;

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  fib.resize(max(n, m) + 1);
  fib[0] = 1;
  fib[1] = 1;
  for (int i = 2; i < fib.size(); ++i) {
    fib[i] = (fib[i-1] + fib[i-2]) % MOD;
  }

  long long res = ((fib[n] + fib[m]) * 2LL + MOD - 2LL) % MOD;
  cout << res << endl;

  return 0;
}
