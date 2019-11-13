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
const i64 MOD = 1000000007;
i64 n, m;

i64 pow(i64 a, i64 k) {
  i64 r = 1;
  while (k) {
    if (k & 1) r = (r * a) % MOD;
    a = (a * a) % MOD;
    k >>= 1;
  }
  return r;
}

int main() {
  cin >> n >> m;
  cout << pow((MOD + pow(2, m) - 1) % MOD, n) << '\n';
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
