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
int t, n, k, a, b, c;
string s, r;

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> a >> b >> c >> s;
    k = 0;
    for (char& x : s) {
      if (x == 'R') {
        if (b != 0) {
          --b;
          ++k;
          x = 'P';
        } else {
          x = 'X';
        }
      } else if (x == 'P') {
        if (c != 0) {
          --c;
          ++k;
          x = 'S';
        } else {
          x = 'X';
        }
      } else {
        if (a != 0) {
          --a;
          ++k;
          x = 'R';
        } else {
          x = 'X';
        }
      }
    }
    for (char& x : s) {
      if (x == 'X') {
        if (a != 0) {
          x = 'R';
          --a;
        } else if (b != 0) {
          x = 'P';
          --b;
        } else {
          x = 'S';
          --c;
        }
      }
    }
    if (k >= (n + 1) / 2) {
      cout << "YES\n" << s << '\n';
    } else {
      cout << "NO\n";
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
