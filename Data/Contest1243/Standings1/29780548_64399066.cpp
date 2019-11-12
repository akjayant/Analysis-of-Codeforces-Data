#include <cstdio>
#include <cstring>

int main() {
  int T, n;
  static char s[10010], t[10010];
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    scanf("%s%s", s + 1, t + 1);
    int neq = 0;
    for (int i = 1; i <= n; ++i) neq += (s[i] != t[i]);
    if (neq == 0) { puts("Yes"); continue; }
    if (neq != 2) { puts("No"); continue; }
    int pos = 0;
    for (int i = 1; i <= n; ++i) if (s[i] != t[i]) {
      if (!pos) pos = i;
      else {
        puts(s[i] == s[pos] && t[i] == t[pos] ? "Yes" : "No");
        break;
      }
    }
  }
  return 0;
}