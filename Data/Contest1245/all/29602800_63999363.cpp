#include <cstdio>
#include <cstring>

int main() {
  int T, n, a, b, c;
  static char s[110], t[110];
  scanf("%d", &T);
  while (T--) {
    memset(t, 0, sizeof t);
    scanf("%d", &n);
    scanf("%d%d%d", &a, &b, &c);
    scanf("%s", s + 1);
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
      if (s[i] == 'R' && b) --b, t[i] = 'P';
      if (s[i] == 'P' && c) --c, t[i] = 'S';
      if (s[i] == 'S' && a) --a, t[i] = 'R';
    }
    for (int i = 1; i <= n; ++i) sum += (t[i] != 0);
    for (int i = 1; i <= n; ++i) if (!t[i]) {
      if (a) --a, t[i] = 'R';
      else if (b) --b, t[i] = 'P';
      else --c, t[i] = 'S';
    }
    if (sum < (n + 1) >> 1) puts("NO");
    else puts("YES"), puts(t + 1);
  }
  return 0;
}