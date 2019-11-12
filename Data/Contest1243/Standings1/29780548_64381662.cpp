#include <cstdio>
#include <algorithm>
const int maxn = 100010;

int a[maxn];

int main() {
  int T, n;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    std::sort(a + 1, a + 1 + n);
    for (int i = n; i; --i) {
      int o = std::lower_bound(a + 1, a + 1 + n, i) - a;
      if (n - o + 1 >= i) {
        printf("%d\n", i); break;
      }
    }
  }
  return 0;
}
