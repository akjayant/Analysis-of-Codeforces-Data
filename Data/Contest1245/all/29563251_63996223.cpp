#include <bits/stdc++.h>

using namespace std;

void solve() {
  int a, b;
  cin >> a >> b;
  if (__gcd(a, b) == 1) {
    cout << "Finite";
  } else {
    cout << "Infinite";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }

  return 0;
}