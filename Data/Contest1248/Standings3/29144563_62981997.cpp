#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  sort(a.rbegin(), a.rend());
  long long x = 0, y = 0;
  for (int i = 0; i < n; ++i)
    if (i < (n + 1) / 2)
      x += a[i];
    else
      y += a[i];
  printf("%lld\n", x * x + y * y);
  return 0;
}