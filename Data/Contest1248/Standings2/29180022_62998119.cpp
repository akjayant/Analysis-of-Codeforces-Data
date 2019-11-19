#include <cstdio>
#include <cstring>
#include <algorithm>
const int maxn = 510;

char s[maxn], stk[maxn];

int main() {
  int n, res, ans = -1, l, r;
  scanf("%d%s", &n, s + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      for (int t = 1; t <= n; ++t) stk[t] = s[t];
      std::swap(stk[i], stk[j]);
      int p = 1, m = n, top = 0;
      while (p <= m) {
        if (stk[p] == ')') {
          --top;
          if (top < 0) {
            res = 0;
            while (p <= m && top < 0) {
              if (stk[m] == ')') --top, --m;
              else ++top, --m;
            }
          }
        } else ++top;
        ++p;
        if (top == 0) ++res;
      }
      if (top) res = 0;
      if (res > ans) l = i, r = j, ans = res;
      res = 0;
    }
  }
  printf("%d\n%d %d\n", ans, l, r);
  return 0;
}