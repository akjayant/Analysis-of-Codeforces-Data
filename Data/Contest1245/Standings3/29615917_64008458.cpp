#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
int n;
string st;
int F[maxn];

void Input() {
   cin >> st;
   n = st.size();
   st = ' ' + st;
   for (int i = 1; i <= n; i++) {
      if (st[i] == 'm' || st[i] == 'w') {
         cout << 0 << "\n";
         exit(0);
      }
   }
}

void Output() {
   F[0] = 1;
   for (int i = 1; i <= n; i++) {
      F[i] = F[i - 1];
      if (i == 1) continue;
      if (st[i] == st[i - 1]) {
         if (st[i] == 'n' || st[i] == 'u') {
            F[i] = (F[i] + F[i - 2]) % mod;
         }
      }
   }
   cout << F[n] << "\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   ///freopen ("test.inp", "r", stdin);
   ///freopen ("test.out", "w", stdout);

   Input(); Output();

   return 0;
}
