#include <cstdio>
#include <algorithm>

int main(void)
{
  int tests;
  scanf("%d", &tests);
  while (tests-- > 0) {
    int n;
    static char s[1005];
    scanf("%d%s", &n, s);
    int ans = n;
    for (int i = 0; i < n; ++i)
      if (s[i] == '1') {
        ans = std::max(ans, (i * 2 + 2));
        ans = std::max(ans, ((n - i) * 2));
      }
    printf("%d\n", ans);
  }
  return 0;
}
