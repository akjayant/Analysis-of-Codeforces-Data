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
  int n; ll k; cin >> n >> k;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(all(a));
  int p = 0, q = n - 1;
  while(p < n && a[p] == a[0]) p++; p--;
  while(q >= 0 && a[q] == a[n-1]) q--; q++;
  if(p >= q) return cout << 0 << endl, 0;
  int ans = a[n - 1] - a[0];
  while(p < q && k > 0) {
    int dp = p + 1, dq = n - q;
    if(dp < dq) {
      int dx = a[p+1] - a[p];
      if(k >= (ll) dx * dp){
        k -= (ll) dx * dp;
        ans -= dx;
        int tp = ++p;
        while(p <= q && a[tp] == a[p]) p++; p--;
      } else {
        ans -= k / dp;
        break;
      }
      //cout << ans << '\n';
    } else {
      int dx = a[q] - a[q-1];
      if(k >= (ll) dx * dq) {
        k -= (ll) dx * dq;
        ans -= dx;
        int tq = --q;
        while(p <= q && a[tq] == a[q]) q--; q++;
      } else {
        ans -= k / dq;
        break;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
