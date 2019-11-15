#include <bits/stdc++.h>
using namespace std;

int main() {
  int qq;
  scanf("%d", &qq);
  while (qq--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &a[i]);
    sort(a.rbegin(), a.rend());
    int ans = 1;
    for (int i = 1; i < n; ++i)
      ans = max(ans, min(i + 1, a[i]));
    printf("%d\n", ans);
  }
  return 0;
}