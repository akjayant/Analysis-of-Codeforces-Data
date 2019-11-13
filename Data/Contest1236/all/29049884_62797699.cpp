#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<vector<int>> a(n, vector<int>(n));
  int x = 1;
  for (int j = 0; j < n; ++j)
    for (int i = 0; i < n; ++i)
      a[j % 2 == 0 ? i : n - 1 - i][j] = x++;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (j > 0)
        printf(" ");
      printf("%d", a[i][j]);
    }
    puts("");
  }
  return 0;
}