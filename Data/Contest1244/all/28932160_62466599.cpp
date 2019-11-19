#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, n;
  string s;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    int l = 0, r = 0;
    for (int i = 0; i < n; ++i)
      if (s[i] == '0') l++;
      else break;
    for (int i = n - 1; i >= 0; --i)
      if (s[i] == '0') r++;
      else break;
    if (l == n && r == n) printf("%d\n", n);
    else printf("%d\n", n * 2 - min(l, r) * 2);
  }
  return 0;
}