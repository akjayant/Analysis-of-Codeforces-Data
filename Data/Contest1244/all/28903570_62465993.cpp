#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a, b, c, d, k;
  scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
  int need_pen = (a + c - 1) / c;
  int need_pencil = (b + d - 1) / d;
  if (need_pen + need_pencil <= k)
    printf("%d %d\n", need_pen, need_pencil);
  else
    puts("-1");
}

int main() {
  int qq;
  scanf("%d", &qq);
  while (qq--)
    solve();
  return 0;
}