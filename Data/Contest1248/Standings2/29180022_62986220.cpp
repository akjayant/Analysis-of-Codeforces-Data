#include <cmath>
#include <queue>
#include <cstdio>
#include <cctype>
#include <algorithm>

int main() {
  int T, n, x, a[2]; long long ans;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    a[0] = a[1] = 0, ans = 0;
    for(int i = 1; i <= n; ++i) scanf("%d", &x), a[x & 1]++;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &x), ans = ans + a[x & 1];
    printf("%I64d\n", ans);
  }
  return 0;
}