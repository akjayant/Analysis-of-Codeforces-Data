#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);

  int t;
  cin >> t;

  vector<int> c(100 * 1000);

  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << (gcd(a, b) == 1 ? "Finite" : "Infinite") << '\n';
  }
}