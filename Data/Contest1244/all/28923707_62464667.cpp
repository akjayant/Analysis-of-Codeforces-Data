#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

int main(int argc, char **argv) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int a, b, c, d, k; cin >> a >> b >> c >> d >> k;
    bool flag = false;
    for(int x=0; x<=100; x++) for(int y=0; y<=k-x; y++) {
      if(x*c >= a && y*d >= b) {
        cout << x << ' ' << y << '\n';
        flag = true;
        break;
      }
      if(flag) break;
    }
    if(!flag) cout << -1 << endl;

  }

  return 0;
}