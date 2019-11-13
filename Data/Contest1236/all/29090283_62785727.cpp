#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int a,b,c;
    cin >> a >> b >> c;
    int ans = 0;
    while(c > 1 && b > 0) {
      c -= 2;
      b -= 1;
      ans += 3;
    }
    while( b > 1 && a > 0) {
      b -= 2;
      a -= 1;
      ans += 3;
    }
    cout << ans << '\n';
  }
  return 0;
}