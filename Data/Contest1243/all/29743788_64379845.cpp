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
  for (size_t tt = 0; tt < t; ++tt) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    if (s == t) {
      cout << "YES\n";
    } else {
      int x = 0;
      while (s[x] == t[x]) ++x;
      int first = x;
      x++;
      while (x < n && s[x] == t[x]) ++x;
      if (x == n) {
        cout << "NO\n";
        continue;
      }
      int second = x;
      ++x;
      while (x < n && s[x] == t[x]) ++x;
      if (x < n) {
        cout << "NO\n";
        continue;
      }
      if (s[first] == s[second] && t[first] == t[second]) cout << "YES\n";
      else cout << "NO\n";
    }
  }

  return 0;
}
