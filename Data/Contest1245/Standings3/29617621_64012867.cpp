#include <bits/stdc++.h>
//#define TASK "file"

#define F first
#define S second
#define ALL(x) (x).begin(), (x).end()

using namespace std;
typedef long long i64;
typedef long double dbl;
const dbl PI = acos(-1.0L);
const dbl EPS = 1e-12L;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

namespace task {
const int N = 100001;
const i64 MOD = 1000000007;
i64 f[N];
string s;
int n, k;
vector<int> v;
i64 r;

int main() {
  f[1] = 1;
  for (int i = 2; i < N; ++i) {
    f[i] = (f[i - 1] + f[i - 2]) % MOD;
  }
  cin >> s;
  char p = '$';
  for (char x : s) {
    if (x == 'm' || x == 'w') {
      cout << 0 << '\n';
      return 0;
    }
    if (x == 'n' || x == 'u') {
      if (p == x) {
        ++k;
      } else {
        if (k != 0) {
          v.push_back(k);
        }
        k = 1;
      }
    } else {
      if (k != 0) {
        v.push_back(k);
      }
      k = 0;
    }
    p = x;
  }
  if (k != 0) {
    v.push_back(k);
  }
  r = 1;
  for (int x : v) {
    r = (r * (f[x] + f[x - 1])) % MOD;
  }
  cout << r << '\n';
  return 0;
}
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(11);
  cout.setf(ios::fixed);
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#elif defined(TASK)
  freopen(TASK".in", "r", stdin);
  freopen(TASK".out", "w", stdout);
#endif
  return task::main();
}
