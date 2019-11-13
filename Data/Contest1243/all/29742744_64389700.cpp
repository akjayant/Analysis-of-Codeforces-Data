#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;

int n;
char a[N], b[N];

void solve() {
  scanf("%d %s %s", &n, a, b);
  vector<int> v;
  for (int i = 0; i < n; ++i)
    if (a[i] != b[i])
      v.push_back(i);
  if (int(v.size()) != 2) {
    puts("No");
    return;
  }
  swap(a[v[0]], b[v[1]]);
  puts(strcmp(a, b) == 0 ? "Yes" : "No");
}

int main() {
  int qq;
  scanf("%d", &qq);
  while (qq--)
    solve();
  return 0;
}