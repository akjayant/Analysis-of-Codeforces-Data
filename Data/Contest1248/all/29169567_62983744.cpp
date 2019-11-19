#include <cstdio>

#define int long long

const int N = 100010;

int t, n, m;
int p[N], q[N];
int ans;
int a1, a2;

signed main() {
  scanf("%lld", &t);
  while (t--) {
    ans = 0;
    a1 = a2 = 0;
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &p[i]);
      if (p[i] & 1)
        ++a1;
      else
        ++a2;
    }
    scanf("%lld", &m);
    for (int i = 1; i <= m; ++i) {
      scanf("%lld", &q[i]);
      if (q[i] & 1)
        ans += a1;
      else
        ans += a2;
    }
    printf("%lld\n", ans);
  }
  return 0;
}