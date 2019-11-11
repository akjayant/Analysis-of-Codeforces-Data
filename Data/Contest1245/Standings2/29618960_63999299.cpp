/* Author: chenxiaoyan's girlfriend
 * Time: 2019-11-01 22:40:21
 */ // I love chenxiaoyan!
#include <bits/stdc++.h>
using namespace std;

int main() {
  int tests;
  scanf("%d", &tests);
  static char str[105];
  static char ans[105];
  while (tests--) {
    int n, a, b, c;
    scanf("%d", &n);
    scanf("%d%d%d", &a, &b, &c);
    scanf("%s", str);
    int cs = 0, cr = 0, cp = 0;
    for (int i = 0; i < n; ++i) {
      cs += (str[i] == 'P');
      cr += (str[i] == 'S');
      cp += (str[i] == 'R');
    }
    int tot = min(a, cr) + min(b, cp) + min(c, cs);
    if (tot < (n + 1) / 2) puts("NO");
    else {
      puts("YES");
      ans[n] = 0;
      for (int i = 0; i < n; ++i) {
        if (str[i] == 'P' && c) {
          c--;
          ans[i] = 'S';
          continue;
        }
        if (str[i] == 'S' && a) {
          a--;
          ans[i] = 'R';
          continue;
        }
        if (str[i] == 'R' && b) {
          b--;
          ans[i] = 'P';
          continue;
        }
        ans[i] = '?';
      }
      for (int i = 0; i < n; ++i) {
        if (ans[i] == '?') {
          if (a) ans[i] = 'R', --a;
          else if (b) ans[i] = 'P', --b;
          else if (c) ans[i] = 'S', --c;
          else assert(false);
        }
      }
      puts(ans);
    }
  }
  return 0;
}
