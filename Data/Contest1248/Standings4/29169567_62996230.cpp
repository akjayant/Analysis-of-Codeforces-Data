#include <cstdio>
#include <algorithm>

#define int long long

const int N = 100010;
const int MOD = 1e9 + 7;

int f[N];

signed main() {
  int n, m;
  scanf("%lld%lld", &n, &m);
  int nm = std::max(n, m);
  f[1] = 1;
  f[2] = 2;
  for (int i = 3; i <= nm; ++i)
    f[i] = (f[i - 1] + f[i - 2]) % MOD;
  printf("%lld\n", (f[n] + f[m] - 1) * 2 % MOD);
  return 0;
}