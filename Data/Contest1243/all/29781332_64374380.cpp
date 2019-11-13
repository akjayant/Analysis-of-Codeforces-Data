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
const int N = 1000;
int k, n, r;
int a[N];

int main() {
  cin >> k;
  while (k--) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a, a + n);
    reverse(a, a + n);
    r = 0;
    for (int i = 0; i < n; ++i) {
      r = max(r, min(i + 1, a[i]));
    }
    cout << r << '\n';
  }
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
