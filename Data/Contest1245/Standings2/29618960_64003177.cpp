/* Author: chenxiaoyan's girlfriend
 * Time: 2019-11-01 22:48:04
 */ // I love chenxiaoyan!
#include <bits/stdc++.h>
using namespace std;

static const long long mod = 1000000007;

char str[1000005];
int n;
long long ans = 1;
long long fib[1000005];
inline long long get_val(int num) {
  if (num < 2) return 1;
  return fib[num];
}

int main() {
  scanf("%s", str);
  n = strlen(str);
  fib[0] = fib[1] = 1;
  for (int i = 2; i <= n; ++i)
    fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
  if (count(str, str + n, 'm') || count(str, str + n, 'w')) {
    puts("0");
    return 0;
  }
  char last = '\0';
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (str[i] == 'u' || str[i] == 'n') {
      if (last != str[i]) {
        if (last == 'n' || last == 'u')
          ans = ans * get_val(cnt) % mod;
        cnt = 1, last = str[i];
      }
      else cnt++;
    }
    else {
      ans = ans * get_val(cnt) % mod;
      cnt = 1, last = str[i];
    }
  }
  if (last == 'n' || last == 'u') {
    ans = ans * get_val(cnt) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}
