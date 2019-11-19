#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;
template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  ll n; cin >> n;
  ll rt = -1;
  for(ll i=2;i*i<=n;++i) {
    ll now = n;
    while(now % i == 0) now /= i;
    if(now == 1) {
      now = i;
      bool ok = true;
      for(ll j=2;j*j<=i;++j) {
        if(i % j == 0) {
          ok = false;
          break;
        }
      }
      if(ok) {
        rt = i;
        break;
      }
    }
  }
  if(rt != -1) {
    cout << rt << endl;
    return 0;
  }
  bool ok = true;
  for(ll i=2;i*i<=n;++i) {
    if(n % i == 0) {
      ok = false;
      break;
    }
  }
  if(ok) {
    cout << n << endl;
  } else {
    cout << 1 << endl;
  }
}
