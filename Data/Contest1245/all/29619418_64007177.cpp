#include <cstdio>


int main() {

  int cases;

  scanf("%d", &cases);
  char s[1000];
  char res[1000];
  while (cases--) {
    int a, b, c, n;
    scanf("%d", &n);
    scanf("%d%d%d", &a, &b, &c);
    scanf("%s", s);

    int win = 0;

    for (int i = 0; s[i]; i++) {
      res[i] = 'X';
      if (s[i] == 'R') {
        if (b > 0) {
          b--;
          win++;
          res[i] = 'P';
        }
      } else if (s[i] == 'P') {
        if (c > 0) {
          c--;
          win++;
          res[i] = 'S';
        }
      } else if (s[i] == 'S') {
        if (a > 0) {
          a--;
          win++;
          res[i] = 'R';
        }
      }
    }
    res[n] = 0;
    for (int i = 0; i < n; i++) {
      if (res[i] == 'X') {
        if (a > 0) {
          a--;
          res[i] = 'R';
        } else if (b > 0) {
          b--;
          res[i] = 'P';
        } else {
          c--;
          res[i] = 'S';
        }
      }
    }
    if (2 * win >= n) {
      printf("YES\n");
      printf("%s\n", res);
    } else {
      printf("NO\n");
    }
  }

  return 0;
}
