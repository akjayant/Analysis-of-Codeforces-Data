#include <bits/stdc++.h>
using namespace std;

#define lint long long

int main (void) {
  lint n;
  scanf("%lld", &n);
  lint m = n;

  for (lint i = 2; i * i <= m; i++) {
    if (m % i == 0) {
      n = __gcd(n, i);
      while (m % i == 0) {
        m /= i;
      }
    }
  }
  if (m != 1) n = __gcd(n, m);
  printf("%lld\n", n);
}