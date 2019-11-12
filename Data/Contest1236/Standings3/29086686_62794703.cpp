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

int n, m;

int binpow(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = res * 1ll * a % INF;
    a = a * 1ll * a % INF;
    b /= 2;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

#ifdef Local
  freopen(".in", "r", stdin);
#else
  // freopen("sum.in", "r", stdin);
  // freopen("sum.out", "w", stdout);
#endif
  cin >> n >> m;
  cout << binpow((binpow(2, m) - 1 + INF) % INF, n) << endl;

  return 0;
}