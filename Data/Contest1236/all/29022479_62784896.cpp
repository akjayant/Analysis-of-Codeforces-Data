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
    int a, b, c; cin >> a >> b >> c;
    int ans = 0;
    for(int i = 0; i <= a; i++) {
      if(i * 2 > b) {
        break;
      }
      ans = max(ans, i * 3 + min(b - 2 * i, c / 2) * 3);
    }
    cout << ans << "\n";
  }
}
