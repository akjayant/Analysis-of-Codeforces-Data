#include <algorithm>
#include <cstdio>

#define int long long

const int N = 1000010;

int n;
int a[N];
int x, y;

signed main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%lld", &a[i]);
  std::sort(a + 1, a + n + 1);
  for (int i = 1; i <= n / 2; ++i)
    x += a[i];
  for (int i = n / 2 + 1; i <= n; ++i)
    y += a[i];
  printf("%lld\n", x * x + y * y);
  return 0;
}