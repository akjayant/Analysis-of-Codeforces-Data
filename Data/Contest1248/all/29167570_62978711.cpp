#include <bits/stdc++.h>
  
using namespace std;
  
typedef long long ll;
  
int main() {
  ios::sync_with_stdio(0); cin.tie(nullptr);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    map<int, ll> p;
    ll ans = 0;
    ll imp = 0, par = 0;
    for (int i = 0; i < n; ++i) {
      int x; cin >> x;
      ans += p[x];
      p[x]++;
      imp += (x % 2 == 1);
      par += (x % 2 == 0);
    }
    int m; cin >> m;
    map<int, ll> qq;
    for (int i = 0; i < m; ++i) {
      int x; cin >> x;
      ans += qq[x];
      qq[x]++;
      if (x % 2) ans += imp;
      else ans += par;
    }
    cout << ans << endl;
  }
  return 0;
}