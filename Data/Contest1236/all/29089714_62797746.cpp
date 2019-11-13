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
const int N = 300;
int n;
vector<int> v[N];

int main() {
  cin >> n;
  for (int i = 0, a = 1; i < n * n / 2; ++i) {
    v[i % n].push_back(a);
    a += 2;
  }
  for (int i = 0, a = 2; i < n * n / 2; ++i) {
    v[(n * n - 1 - i) % n].push_back(a);
    a += 2;
  }
  if (n & 1) {
    v[(n * n / 2) % n].push_back(n * n);
  }
  for (int i = 0; i < n; ++i) {
    for (int x : v[i]) {
      cout << x << ' ';
    }
    cout << '\n';
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
