#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const int P = 1e9 + 7;
void solve();
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
}
//
ll a[N];
void solve() {
  string s;
  cin >> s;
  int n = s.size();
  for (char &c : s) {
    if (c == 'm' || c == 'w') {
      cout << 0;
      return;
    }
  }
  ll ans = 1;
  a[1] = 1, a[2] = 2;
  for (int i = 3; i <= n; i++) {
    a[i] = a[i-2] + a[i-1];
    a[i] %= P;
  }
  for (int i = 0; i < n; i++) {
    int cnt = 1;
    while (i < n && i && s[i] == s[i-1] && s[i] == 'n') cnt++, i++;
    ans = ans * a[cnt] % P;
    cnt = 1;
    while (i < n && i && s[i] == s[i-1] && s[i] == 'u') cnt++, i++;
    ans = ans * a[cnt] % P;
  }
  cout << ans;
}
