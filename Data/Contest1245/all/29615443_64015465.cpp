#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const int P = 1e9 + 7;
void solve();
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
}
//
char ans[N];
void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n, a, b, c;
    string s;
    cin >> n;
    cin >> a >> b >> c;
    cin >> s;
    int cnt = 0, aa = 0, bb = 0, cc = 0;
    for (int i = 0; i < n; i++) {
      char ch = s[i];
      ans[i] = 0;
      if (ch == 'R' && b > bb) bb++, cnt++, ans[i] = 'P';
      else if (ch == 'P' && c > cc) cc++, cnt++, ans[i] = 'S';
      else if (ch == 'S' && a > aa) aa++, cnt++, ans[i] = 'R';
    }
    if (cnt * 2 >= n) {
      cout << "YES\n";
      ans[n] = 0;
      for (int i = 0; i < n; i++) {
        if (!ans[i]) {
          if (aa < a) ans[i] = 'R', aa++;
          else if (bb < b) ans[i] = 'P', bb++;
          else if (cc < c) ans[i] = 'S', cc++;
        }
      }
      cout << ans << '\n';
    } else {
      cout << "NO\n";
    }
  }
}
