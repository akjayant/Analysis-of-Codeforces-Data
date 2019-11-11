#include <bits/stdc++.h>

using namespace std;

int n, R, P, S;
char answer[105];

void InOutPut() {
   cin >> n;
   cin >> R >> P >> S;
   string Bob;
   cin >> Bob;
   Bob = ' ' + Bob;
   int needed = (n + 1) / 2;
   for (int i = 1; i <= n; i++) {
      answer[i] = '*';
   }
   int res = 0;
   for (int i = 1; i <= n; i++) {
      if (Bob[i] == 'S' && R > 0) {
         R--;
         res++;
         answer[i] = 'R';
      }
      if (Bob[i] == 'R' && P > 0) {
         P--;
         res++;
         answer[i] = 'P';
      }
      if (Bob[i] == 'P' && S > 0) {
         S--;
         res++;
         answer[i] = 'S';
      }
   }
   if (res < needed) {
      cout << "NO\n";
      return;
   }
   cout << "YES\n";
   for (int i = 1; i <= n; i++) {
      if (answer[i] == '*') {
         if (R > 0) {
            answer[i] = 'R';
            R--;
            continue;
         }
         if (P > 0) {
            answer[i] = 'P';
            P--;
            continue;
         }
         if (S > 0) {
            answer[i] = 'S';
            S--;
            continue;
         }
      }
   }
   for (int i = 1; i <= n; i++) {
      cout << answer[i];
   }
   cout << "\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   ///freopen ("test.inp", "r", stdin);
   ///freopen ("test.out", "w", stdout);

   int T;
   cin >> T;
   for (int i = 1; i <= T; i++) {
      InOutPut();
   }

   return 0;
}
