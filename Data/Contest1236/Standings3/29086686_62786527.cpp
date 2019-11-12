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

int n, a[333][333];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

#ifdef Local
  freopen(".in", "r", stdin);
#else
  // freopen("sum.in", "r", stdin);
  // freopen("sum.out", "w", stdout);
#endif
  cin >> n;
  int cnt = 0;
  for (int j = 1; j <= n; ++j) {
    for (int i = 1; i <= n; ++i) {
      int cur = i;
      if (j % 2 == 0) cur = n - i + 1;
      a[cur][j] = ++cnt;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << a[i][j] << ' ';
    }
    cout << endl;
  }

  return 0;
}