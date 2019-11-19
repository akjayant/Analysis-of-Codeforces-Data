#include <bits/stdc++.h>
using namespace std;

const int N = 1234;

int n;
char a[N];

void solve() {
  scanf("%d %s", &n, a);
  int ans = n;
  for (int i = 0; i < n; ++i) {
    int l = i + 1;
    int r = n - i;
    if (a[i] == '1')
      ans = max(ans, max(2 * l, 2 * r));
  }
  printf("%d\n", ans);
}

int main() {
  int qq;
  scanf("%d", &qq);
  while (qq--)
    solve();
  return 0;
}