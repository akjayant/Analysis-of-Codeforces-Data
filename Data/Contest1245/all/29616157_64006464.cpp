#include <bits/stdc++.h>
using namespace std;

const long long md = 1e9 + 7;

long long fib[200010];

void init() {
  fib[1] = 1;
  fib[2] = 2;
  for(int i = 3; i < 200010; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
    fib[i] %= md;
  }
}

int main() {
  init();
  string s; cin >> s;
  for(auto c: s) {
    if(c == 'm' || c == 'w') {
      printf("0\n");
      return 0;
    }
  }
  int ncnt = 0, ucnt = 0;
  long long ans = 1;
  for(int i = 0; i < (int)s.size(); i++) {
    if(s[i] == 'n') {
      if(ucnt) {
        ans *= fib[ucnt];
        ans %= md;
        ucnt = 0;
      }
      ncnt++;
    } else if(s[i] == 'u') {
      if(ncnt) {
        ans *= fib[ncnt];
        ans %= md;
        ncnt = 0;
      }
      ucnt++;
    } else {
      if(ncnt) {
        ans *= fib[ncnt];
        ans %= md;
        ncnt = 0;
      }
      if(ucnt) {
        ans *= fib[ucnt];
        ans %= md;
        ucnt = 0;
      }
    }
  }
  if(ncnt) {
    ans *= fib[ncnt];
    ans %= md;
    ncnt = 0;
  }
  if(ucnt) {
    ans *= fib[ucnt];
    ans %= md;
    ucnt = 0;
  }
  printf("%lld\n", ans);
  return 0;
}
