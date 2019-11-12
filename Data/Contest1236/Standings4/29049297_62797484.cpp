#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define all(x) x.begin(), x.end()
using namespace std; const LD EPS = 1e-9L;
const int N = 300 * 300 + 5, LOGN = 20, inf = 1e9, mod = (int)1e9 + 7;
/****************************************************************/
int group[N];
int main() {
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      int n; cin >> n;
      bool reverse = false;
      for (int i = 1; i <= n; ++i) {
            int cnt = 1;
            int st = (i - 1) * n + 1, en = st + n - 1;
            if (reverse) for (int j = st; j <= en; ++j) group[j] = cnt++;
            else for (int j = en; j >= st; --j) group[j] = cnt++;
            reverse = !reverse;
      }

      for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n * n; ++j) if (group[j] == i) cout << j << ' ';
            cout << '\n';
      }
      cout << '\n';
}