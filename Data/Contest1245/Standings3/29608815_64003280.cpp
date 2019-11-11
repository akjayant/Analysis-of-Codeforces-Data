#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n, r, s, p, R = 0, S = 0, P = 0;
    string str;
    cin >> n >> r >> p >> s >> str;
    for (auto i : str) {
      if (i == 'R') {
        R++;
      } else if (i == 'S') {
        S++;
      } else {
        P++;
      }
    }
    if (2 * (min(r, S) + min(s, P) + min(p, R)) < n) {
      cout << "NO\n";
      continue;
    }
    string res;
    for (int i = 0; i < n; ++i) {
      res += '?';
    }
    for (int i = 0; i < n; ++i) {
      if (str[i] == 'R' && p > 0) {
        res[i] = 'P';
        p--;
      } else if (str[i] == 'S' && r > 0) {
        res[i] = 'R';
        r--;
      } else if (str[i] == 'P' && s > 0) {
        res[i] = 'S';
        s--;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (res[i] == '?') {
        if (r > 0) {
          r--;
          res[i] = 'R';
        } else if (s > 0) {
          s--;
          res[i] = 'S';
        } else {
          p--;
          res[i] = 'P';
        }
      }
    }
    cout << "YES\n";
    cout << res << "\n";
  }

  return 0;
}
