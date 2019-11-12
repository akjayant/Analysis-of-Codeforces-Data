#include <bits/stdc++.h>

#define eb emplace_back
#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define ull unsigned long long
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int INF = (int)1e9 + 7;
const int N = (int)7070 + 7;
const int MAXN = (int)5e5 + 228;

using namespace std;

int n, dp[101][101][101];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

#ifdef Local
  freopen(".in", "r", stdin);
#else
  // freopen("sum.in", "r", stdin);
  // freopen("sum.out", "w", stdout);
#endif
  for (int a = 0; a <= 100; ++a) {
    for (int b = 0; b <= 100; ++b) {
      for (int c = 0; c <= 100; ++c) {
        if (a >= 1 && b >= 2)
          dp[a][b][c] = max(dp[a][b][c], dp[a - 1][b - 2][c] + 3);
        if (b >= 1 && c >= 2)
          dp[a][b][c] = max(dp[a][b][c], dp[a][b - 1][c - 2] + 3);
      }
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    cout << dp[a][b][c] << endl;
  }

  return 0;
}