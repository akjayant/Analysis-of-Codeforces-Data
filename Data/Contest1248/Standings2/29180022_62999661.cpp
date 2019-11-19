#include <cstdio>
const int maxn = 100010;
const int mod = 1000000007;

int inline pls(int a, int b) { int m = a + b; return m < mod ? m : m - mod; }
int inline dec(int a, int b) { int m = a - b; return m < 0 ? m + mod : m; }
int inline mul(int a, int b) { return 1ll * a * b % mod; }

int f[maxn], g[maxn];

int main() {
  static int n, m, ans;
  scanf("%d%d", &n, &m);
  f[1] = 2, f[2] = 4, g[1] = 0, g[2] = 2;
  for (int i = 3; i <= n; ++i) f[i] = pls(f[i - 1], f[i - 2]);
  for (int i = 3; i <= m; ++i) g[i] = pls(g[i - 1], g[i - 2]);
  for (int i = 1; i <= m; ++i) ans = pls(ans, g[i]);
  printf("%d\n", pls(f[n], ans));
  return 0;
}