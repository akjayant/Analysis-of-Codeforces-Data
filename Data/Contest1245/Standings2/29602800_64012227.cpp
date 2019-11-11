#include <cstdio>
#include <cstring>
const int maxn = 100010;
const int mod = 1000000007;

int inline pls(int a, int b) { int m = a + b; return m < mod ? m : m - mod; }

char s[maxn];
int f[maxn];

int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  f[0] = 1;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == 'w' || s[i] == 'm') return puts("0"), 0;
    f[i] = f[i - 1];
    if (s[i] == s[i - 1] && (s[i] == 'u' || s[i] == 'n')) f[i] = pls(f[i], f[i - 2]);
  }
  printf("%d\n", f[n]);
  return 0;
}
