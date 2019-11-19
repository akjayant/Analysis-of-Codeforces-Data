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

  ll n, p, w, d;

  while(cin >> n >> p >> w >> d) {
    bool flag = false;
    for(ll y=0; y<w; y++) {
      if((y*d) % w == p%w) {
        ll x = (p - y*d+w*1000000000000L)%w;
        if((p-(x*w+y*d) < 0)) continue;

        x += (p-(x*w+y*d))/w;
        if(x*w+y*d == p && x + y <= n) {
          cout << x << ' ' << y << ' ' << n - x - y << endl;
          flag = true;
          break;
        }
      }
    }
    if(!flag) cout << -1 << endl;
  }


  return 0;
}