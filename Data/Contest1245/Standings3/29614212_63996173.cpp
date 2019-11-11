#include <bits/stdc++.h>
#define MAXN 1024
#define int long long
using namespace std;

int t, a, b;

int gcd(int a, int b) {
  return (b==0) ? a : gcd(b, a%b);
}

signed main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> a >> b;
    if (gcd(a, b) == 1) cout << "Finite" << '\n';
    else cout << "Infinite" << '\n';
  }
  return 0;
}