#include <cstdio>
#include <algorithm>

const int SIZE = (int)2e5+5;

int n;
long long k, a[SIZE];

int main(void)
{
  scanf("%d%I64d", &n, &k);
  for (int i = 1; i <= n; ++i)
    scanf("%I64d", &a[i]);
  std::sort(a + 1, a + 1 + n);
  int ll = 1, lr = 1, rl = n, rr = n;
  for (int i = 1; i <= n; ++i)
    if (a[i] == a[1])
      lr = i;
    else
      break;
  for (int i = n; i >= 1; --i)
    if (a[i] == a[n])
      rl = i;
    else
      break;
  long long max = a[n], min = a[1];
  while (k > 0) {
    if (max == min)
      break;
    if ((lr - ll + 1) > (rr - rl + 1)) {
      if ((a[rl] - a[rl - 1]) * (rr - rl + 1) > k) {
        max = a[rl] - k / (rr - rl + 1);
        break;
      } else {
        max = a[rl - 1];
        k -= (a[rl] - a[rl - 1]) * (rr - rl + 1);
        --rl;
      }
    } else {
      if ((a[lr + 1] - a[lr]) * (lr - ll + 1) > k) {
        min = a[lr] + k / (lr - ll + 1);
        break;
      } else {
        min = a[lr + 1];
        k -= (a[lr + 1] - a[lr]) * (lr - ll + 1);
        ++lr;
      }
    }
  }
  printf("%I64d\n", max - min);
  return 0;
}
