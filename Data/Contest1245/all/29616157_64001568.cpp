#include <bits/stdc++.h>
using namespace std;

int n;
// r, p, s
int a, b, c;
char output[110];

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    memset(output, 0, sizeof output);
    scanf("%d%d%d%d", &n, &a, &b, &c);
    string s; cin >> s;

    for(int i = 0; i < n; i++) {
      char ch = s[i];
      if(ch == 'R') {
        if(b > 0) {
          b--;
          output[i] = 'P';
        }
      } else if(ch == 'P') {
        if(c > 0) {
          c--;
          output[i] = 'S';
        }
      } else {
        if(a > 0) {
          a--;
          output[i] = 'R';
        }
      }
    }
    int cnt = 0;
    for(int i = 0; i < n ;i++) {
      if(!output[i]) {
        if(a > 0) {a--; output[i] = 'R';}
        else if(b > 0) {b--; output[i] = 'P';}
        else if(c > 0) {c--; output[i] = 'S';}
      } else {
        cnt++;
      }
    }
    if(cnt >= n / 2 + !!(n % 2)) {
      printf("YES\n");
      printf("%s\n", output);
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
