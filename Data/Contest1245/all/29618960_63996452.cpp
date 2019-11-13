/* Author: chenxiaoyan's girlfriend
 * Time: 2019-11-01 22:38:02
 */ // I love chenxiaoyan!
#include <bits/stdc++.h>
using namespace std;

int main() {
  int tests;
  scanf("%d", &tests);
  while (tests--) {
    int n, m;
    scanf("%d%d", &n, &m);
    if (__gcd(n, m) == 1) puts("Finite");
    else puts("Infinite");
  }
  return 0;
}
