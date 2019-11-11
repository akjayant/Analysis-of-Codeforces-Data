#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int a, b;
    cin >> a >> b;
    if (__gcd(a, b) == 1) {
      cout << "Finite\n";
    } else {
      cout << "Infinite\n";
    }
  }

  return 0;
}
