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
const int N = 2000;
int n;
i64 a;
i64 x[N];
i64 y[N];
i64 c[N];
i64 k[N];
vector<pair<int, int>> v, e;
set<int> s;
int p[N];
int r[N];
i64 m[N];

i64 f(const pair<int, int>& z) {
  return (k[z.F] + k[z.S]) * (abs(x[z.F] - x[z.S]) + abs(y[z.F] - y[z.S]));
}

int findSet(int a) {
  if (a != p[a]) {
    p[a] = findSet(p[a]);
  }
  return p[a];
}

void unionSet(int a, int b) {
  int p_a = findSet(a);
  int p_b = findSet(b);
  if (p_a != p_b) {
    if (r[p_a] > r[p_b]) {
      p[p_b] = p_a;
      if (c[m[p_b]] < c[m[p_a]]) {
        m[p_a] = m[p_b];
      }
    } else {
      p[p_a] = p_b;
      if (c[m[p_a]] < c[m[p_b]]) {
        m[p_b] = m[p_a];
      }
      r[p_b] += r[p_b] == r[p_a];
    }
  }
}

int main() {
  cin >> n;
  iota(p, p + n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
    m[i] = i;
    a += c[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> k[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      v.emplace_back(j, i);
    }
  }
  sort(ALL(v), [](const auto& ll, const auto& rr) {
    return f(ll) < f(rr);
  });
  for (auto& it : v) {
    int ll = findSet(it.F);
    int rr = findSet(it.S);
    if (ll != rr) {
      if (a - c[m[ll]] - c[m[rr]] + min(c[m[ll]], c[m[rr]]) + f(it) < a) {
        a = a - c[m[ll]] - c[m[rr]] + min(c[m[ll]], c[m[rr]]) + f(it);
        unionSet(ll, rr);
        e.push_back(it);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    s.insert(m[findSet(i)]);
  }
  cout << a << '\n';
  cout << s.size() << '\n';
  for (int z : s) {
    cout << z + 1 << ' ';
  }
  cout << '\n';
  cout << e.size() << '\n';
  for (auto& it : e) {
    cout << it.F + 1 << ' ' << it.S + 1 << '\n';
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
