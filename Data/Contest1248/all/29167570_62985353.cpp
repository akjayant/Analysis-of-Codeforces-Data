#include <bits/stdc++.h>
  
using namespace std;
  
typedef long long ll;
  
int main() {
  ios::sync_with_stdio(0); cin.tie(nullptr);
  int n; cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  ll x = 0, y = 0;
  sort(a.begin(), a.end());
  for (int i = 0, j = n - 1; i <= j; ++i, --j) {
    if (i == j) {
      y += a[i];
    } else {
      y += a[j];
      x += a[i];
    }
  }
  cout << x * x + y * y << endl;
  return 0;
}