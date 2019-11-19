#include <cstdio>
#include <algorithm>

int main(void)
{
  int tests;
  scanf("%d", &tests);
  while (tests-- != 0) {
    int a, b, c, d, k;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
    a = (a + c - 1) / c;
    b = (b + d - 1) / d;
    if (a + b > k)
      printf("-1\n");
    else
      printf("%d %d\n", a, b);
  }
  return 0;
}
