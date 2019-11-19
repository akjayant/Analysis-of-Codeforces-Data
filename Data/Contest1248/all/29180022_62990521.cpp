#include <cstdio>
#include <algorithm>
const int maxn = 100010;

int a[maxn];

int main() {
  int n; static long long x, y;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  std::sort(a + 1, a + n + 1);
  for (int i = 1; i <= n / 2; ++i) x += a[i];
  for (int i = n / 2 + 1; i <= n; ++i) y += a[i];
  printf("%I64d\n", x * x + y * y);
  return 0;
}