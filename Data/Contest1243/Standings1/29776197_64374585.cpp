#include <bits/stdc++.h>
using namespace std;

int c[1005];

int main (void) {
  int kase;
  scanf("%d", &kase);
  while (kase--) {
    memset(c, 0, sizeof(c));

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      int val;
      scanf("%d", &val);
      c[val] ++;
    }
    int ans = 0;
    for (int i = n; i >= 1; i--) {
      c[i] += c[i + 1];
      if (c[i] >= i) ans = max(ans, i);
    }
    printf("%d\n", ans);
  }
}