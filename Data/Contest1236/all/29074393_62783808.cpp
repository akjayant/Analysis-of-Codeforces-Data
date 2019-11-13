#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;

#define all(x) (x).begin(), (x).end()
#define size(x) (ll)x.size()
#define x first
#define y second
#define chkmax(x, y) x = max(x, y)
#define chkmin(x, y) x = min(x, y)
#define pb emplace_back
#define od  (x) ((x)&1)
mt19937_64 gen;

void run() {
  int q = 1;
  cin >> q;
  while (q--) {
      
    int a, b, c;
    cin >> a >> b >> c;
    int res = 0;
    for(int i = 0; i <= 100; i++) {
      for(int j = 0; j <= 100; j++) {
        if (i <= a && i * 2 + j <= b && j * 2 <= c) {
          chkmax(res, 3 * (i + j));
        }
      }
    }
    cout << res << endl;
  }
}

signed main() {
#ifdef kek
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  gen.seed(time(0));
#endif // kek
  ios::sync_with_stdio(0);
  cin.tie(0);
  run();
}
