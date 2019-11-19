#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int test = 0; test < t; test++) {
    int n;
    cin >> n;

    string s;
    cin >> s;
    int ans = n;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        ans = max(ans, max(max((i + 1) * 2, (n - i) * 2), n + 1));
      }
    }
    cout << ans << '\n';
  }
}