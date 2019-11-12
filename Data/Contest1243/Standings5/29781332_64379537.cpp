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
const int K = 26;
int k, n;
string s, t;
int a[K];

int main() {
  cin >> k;
  while (k--) {
    fill(a, a + K, 0);
    cin >> n >> s >> t;
    for (char x : s) {
      ++a[x - 'a'];
    }
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      if (s[i] != t[i]) {
        v.push_back(i);
      }
    }
    if (v.empty()) {
      bool ok = false;
      for (int i = 0; !ok && i < K; ++i) {
        ok = a[i] > 1;
      }
      if (ok) {
        cout << "Yes\n";
      } else {
        cout << "No\n";
      }
    } else if (v.size() == 2) {
      if (s[v[0]] == s[v[1]] && t[v[1]] == t[v[0]]) {
        cout << "Yes\n";
      } else {
        cout << "No\n";
      }
    } else {
      cout << "No\n";
    }
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
