#include <cstdio>
#include <cstring>

const int MOD = 1000000007;
char s[100100];
long long f[100100];

int main() {

  scanf("%s", s);

  f[1] = 1;
  f[0] = 1;

  int n = strlen(s);

  for (int i = 2; i <= n; i++) {
    f[i] = (f[i-1] + f[i-2]) % MOD;
  }
  int i = 0;
  int res = 1;
  while (i < n) {
    if (s[i] == 'w' || s[i] == 'm') {
      res = 0;
      break;
    } else if (s[i] == 'u' || s[i] == 'n') {
      int j = i;
      while (j < n && s[j] == s[i]) j++;
      res = (res * f[j-i]) % MOD;
      i = j;
    } else {
      i++;
    }
  }
  printf("%d\n", res);



  return 0;
}
