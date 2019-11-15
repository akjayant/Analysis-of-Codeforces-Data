#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int n;
char a[N], b[N];

void solve() {
  scanf("%d %s %s", &n, a, b);
  vector<pair<int, int>> ans;
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      for (int j = i + 1; j < n; ++j) {
        if (a[j] == b[i]) {
          swap(a[j], b[j]);
          swap(b[j], a[i]);
          ans.emplace_back(j, j);
          ans.emplace_back(i, j);
          break;
        }
        if (b[j] == b[i]) {
          swap(a[i], b[j]);
          ans.emplace_back(i, j);
          break;
        }
      }
    }
  }
  if (strcmp(a, b) != 0) {
    puts("No");
    return;
  }
  puts("Yes");
  printf("%d\n", int(ans.size()));
  for (auto p : ans)
    printf("%d %d\n", p.first + 1, p.second + 1);
}

int main() {
  int qq;
  scanf("%d", &qq);
  while (qq--)
    solve();
  return 0;
}