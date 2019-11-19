#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < n; i++)
const int N = 1 << 20;
int main() {
#ifdef local
  freopen("in.txt", "r", stdin);
#endif // local
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int _; cin >> _;
  while(_--) {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    int x = (a + c - 1) / c;
    int y = (b + d - 1) / d;
    if(x + y <= k) cout << x << ' ' << y << '\n';
    else cout << -1 << '\n';
  }
  return 0;
}
