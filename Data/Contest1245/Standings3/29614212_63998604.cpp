#include <bits/stdc++.h>
#define MAXN 1024
#define int long long
using namespace std;

int t, n;
int R, P, S, cnt;
string s, ans;

signed main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n >> R >> P >> S >> s;
    ans = "";
    cnt = 0;
    for (int j = 0; j < n; j++) {
      if (s[j] == 'S' && R) R--, ans += 'R', cnt++;
      else if (s[j] == 'R' && P) P--, ans += 'P', cnt++;
      else if (s[j] == 'P' && S) S--, ans += 'S', cnt++; 
      else ans += '?';
    }
    if (cnt >= (n+1)/2) {
      cout << "YES" << '\n';
      for (int j = 0; j < n; j++) {
        if (ans[j] == '?') {
          if (R) R--, ans[j] = 'R';
          else if (P) P--, ans[j] = 'P';
          else if (S) S--, ans[j] = 'S';
        }
      }
      cout << ans << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}