#pragma GCC optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void Main();
#ifdef ConanYu
#include "local.hpp"
#else
#define debug(...) do { } while(0)
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  Main();
}
#endif

void Main() {
  int T; cin >> T;
  while(T--) {
    int n; cin >> n;
    string s; cin >> s;
    int ans = n;
    for(int i = 0; i < n; i++) {
      if(s[i] == '1') {
        ans = max({ans, (i + 1) * 2, (n - i) * 2});
      }
    }
    cout << ans << "\n";
  }
}
