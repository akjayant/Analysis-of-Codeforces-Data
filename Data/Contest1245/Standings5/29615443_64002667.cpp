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
void solve() {
  int n, x, y;
  cin >> n;
  while (n--) {
    cin >> x >> y;
    cout << (__gcd(x, y) == 1 ? "Finite\n" : "Infinite\n");
  }
}
