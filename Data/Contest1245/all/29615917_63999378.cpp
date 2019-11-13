#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   ///freopen ("test.inp", "r", stdin);
   ///freopen ("test.out", "w", stdout);

   int T;
   cin >> T;
   for (int i = 1; i <= T; i++) {
      int a, b;
      cin >> a >> b;
      if (__gcd(a, b) == 1) {
         cout << "Finite\n";
      }
      else cout << "Infinite\n";
   }

   return 0;
}
