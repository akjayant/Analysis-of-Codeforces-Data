#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') ans = max({ans, i + 1, n - i});
    }
    if (ans == 0) cout << n << endl;
    else cout << 2 * ans << endl;
  }
  return 0;
}

