#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define all(x) x.begin(), x.end()
using namespace std; const LD EPS = 1e-9L;
const int N = 100 + 5, LOGN = 20, inf = 1e9, mod = 998244353;
/****************************************************************/
int dp[N][N][N];
int f(int a, int b, int c) {
      if (min({ a, b, c }) < 0) return -inf;
      int &ans = dp[a][b][c]; if (ans != -1) return ans;
      ans = 0;
      return ans = max(ans, 3 + max(f(a - 1, b - 2, c), f(a, b - 1, c - 2)));
}
int main() {
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      memset(dp, -1, sizeof(dp));
      int tc; cin >> tc;
      while (tc--) {
            int a, b, c; cin >> a >> b >> c;
            cout << f(a, b, c) << '\n';
      }
}