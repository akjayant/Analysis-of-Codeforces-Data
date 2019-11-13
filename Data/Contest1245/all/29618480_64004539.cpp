#include <cstdio>
#include <string>

using namespace std;

char s[109];

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, a, b, c;
    scanf("%d%d%d%d%s", &n, &a, &b, &c, s);
    string ans(n, '?');
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'S' && a > 0) {
        ans[i] = 'R';
        --a;
      } else
      if (s[i] == 'R' && b > 0) {
        ans[i] = 'P';
        --b;
      } else
      if (s[i] == 'P' && c > 0) {
        ans[i] = 'S';
        --c;
      }
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (ans[i] != '?') {
        ++cnt;
      }
    }
    if (cnt < (n + 1) / 2) {
      puts("NO");
      continue;
    }
    puts("YES");
    for (int i = 0; i < n; ++i) {
      if (ans[i] != '?') {
        continue;
      }
      if (a > 0) {
        ans[i] = 'R';
        --a;
      } else
      if (b > 0) {
        ans[i] = 'P';
        --b;
      } else {
        ans[i] = 'S';
        --c;
      }
    }
    puts(ans.c_str());
  }
}
