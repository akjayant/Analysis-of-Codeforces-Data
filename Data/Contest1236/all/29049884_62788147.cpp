#include <bits/stdc++.h>
using namespace std;

int main() {
  int qq;
  scanf("%d", &qq);
  while (qq--) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int ans = 0;
    for (int i = 0; i <= a && i * 2 <= b; ++i)
      ans = max(ans, 3 * i + min(b - 2 * i, c / 2) * 3);
    printf("%d\n", ans);
  }
  return 0;
}