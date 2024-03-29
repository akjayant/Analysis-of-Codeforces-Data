#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  string s;
  cin >> s;
  string ans(n, 'T');
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'R') {
      if (b) {
        ++cnt;
        ans[i] = 'P';
        --b;
      }
    } else if (s[i] == 'P') {
      if (c) {
        ++cnt;
        --c;
        ans[i] = 'S';
      }
    } else {
      if (a) {
        ++cnt;
        --a;
        ans[i] = 'R';
      }
    }
  }
  if (cnt >= (n + 1) / 2) {
    cout << "YES";
    for (int i = 0; i < n; ++i) {
      if (ans[i] == 'T') {
        if (a) {
          ans[i] = 'R';
          --a;
        } else if (b) {
          --b;
          ans[i] = 'P';
        } else if (c) {
          --c;
          ans[i] = 'S';
        }
      }
    }
    cout << '\n' << ans;
  } else {
    cout << "NO";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }

  return 0;
}