#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define debug(n1) cout << n1 << endl;
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

using namespace std;

const string __sep = "\n";

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (size_t tt = 0; tt < t; tt++) {
    int n;
    cin >> n;
    int r, p, s;
    cin >> r >> p >> s;
    int r2, p2, s2;
    r2 = p2 = s2 = 0;
    int win = 0;
    vector<char> bob;
    vector<char> ans(n, 0);
    for (int i = 0; i < n ; ++i) {
      char c;
      cin >> c;
      bob.push_back(c);
      if (c == 'R') {
        r2++;
        if (p > 0) {
          ++win;
          p--;
          ans[i] = 'P';
        }
      }
      else if (c == 'P') {
        p2++;
        if (s > 0) {
          ++win;
          s--;
          ans[i] = 'S';
        }
      } else {
        s2++;
        if (r > 0) {
          --r;
          ++win;
          ans[i] = 'R';
        }
      }
    }
    if (win >= (n + 1) / 2) {
      cout << "YES" << "\n";
      for (int i = 0; i < n ; ++i) {
        if (ans[i] != 0) continue;
        char c = bob[i];
        if (c == 'R') {
          assert (p == 0);
          if (r > 0) {
            r--;
            ans[i] = 'R';
          }
        }
        else if (c == 'P') {
          assert (s == 0);
          if (p > 0) {
            p--;
            ans[i] = 'P';
          }
        } else {
          assert (r == 0);
          if (s > 0) {
            s--;
            ans[i] = 'S';
          }
        }
      }
      for (int i = 0; i < n ; ++i) {
        if (ans[i] != 0) continue;
        if (r > 0) {
          r--;
          ans[i] = 'R';
        } else if (p > 0) {
          p--;
          ans[i] = 'P';
        } else if (s > 0) {
          s--;
          ans[i] = 'S';
        }
      }
      assert (s == 0 && p == 0 && r == 0);
      for (int i = 0 ;i < n ; ++i) cout << ans[i];
      cout << "\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
