#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);

  string s;
  cin >> s;

  int n = s.size();
  int ans = 1;
  int const M = 1000 * 1000 * 1000 + 7;
  vector<int> f(n + 10);
  f[1] = 1;
  for (int i = 2; i < n + 10; ++i) {
    f[i] = f[i - 1] + f[i - 2];
    if (f[i] >= M) f[i] -= M;
  }
  for (int i = 0, j = 0; i < n; i = j) {
    while (j < n && s[i] == s[j]) ++j;
    auto c = s[i];
    if (c == 'u' || c == 'n') {
      int k = j - i;
      ans = 1ll * ans * f[k + 1] % M;
    } else if(c == 'w' || c == 'm') {
      ans = 0;
    }
  }
  cout << ans;
}