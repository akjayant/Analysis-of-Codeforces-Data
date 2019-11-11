#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    int r, p, s;
    cin >> r >> p >> s;
    string w;
    cin >> w;
    int br = 0;
    int bp = 0;
    int bs = 0;
    for (auto c : w) {
      if (c == 'R')
        br++;
      else if (c == 'P')
        bp++;
      else
        bs++;
    }
    int wr = min(r, bs);
    int wp = min(p, br);
    int ws = min(s, bp);
    int cnt = wr + wp + ws;
    bool can = cnt >= (n + 1) / 2;
    cout << (can ? "YES" : "NO") << '\n';
    if (can) {
      for (auto& c : w) {
        if (c == 'R') {
          if (wp) {
            c = 'P';
            p--;
            wp--;
          } else if (wr != r) {
            c = 'R';
            r--;
          } else {
            c = 'S';
            s--;
          }
        } else if (c == 'P') {
          if (ws) {
            c = 'S';
            s--;
            ws--;
          } else if (wr != r) {
            c = 'R';
            r--;
          } else {
            c = 'P';
            p--;
          }
        } else {
          if (wr) {
            c = 'R';
            r--;
            wr--;
          } else if (ws != s) {
            c = 'S';
            s--;
          } else {
            c = 'P';
            p--;
          }
        }
      }
      cout << w << '\n';
    }
  }
}