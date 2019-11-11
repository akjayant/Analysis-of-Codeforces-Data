#include <bits/stdc++.h>

using namespace std;

int main() {
  int t; cin >> t;

  while(t--) {
    int a, b; cin >> a >> b;

    cout << (__gcd(a,b) == 1 ? "Finite" : "Infinite") << endl;
  }

  return 0;
}
