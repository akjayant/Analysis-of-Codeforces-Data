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
    for (char x : t) {
      ++a[x - 'a'];
    }
    bool ok = true;
    for (int i = 0; ok && i < K; ++i) {
      if (a[i] & 1) ok = false;
      a[i] /= 2;
    }
    if (!ok) {
      cout << "No\n";
      continue;
    }
    vector<pair<int, int>> b;
    /*for (int i = 0; i < n; ++i) {
      if (a[s[i] - 'a'] != 0) {
        --a[s[i] - 'a'];
      } else {
        int id = -1;
        for (int j = 0; j < K; ++j) {
          if (a[j] != 0 && !p[j].empty()) {
            id = j;
            break;
          }
        }
        assert(id != -1);
        int x = p[id].back();
        b.emplace_back(i, x);
        --a[id];
        p[id].pop_back();
        p[s[i] - 'a'].push_back(x);
        t[x] = s[i];
        s[i] = char('a' + id);
      }
    }*/
    for (int i = 0; i < n; ++i) {
      if (s[i] != t[i]) {
        if (a[s[i] - 'a'] != 0) {
          --a[s[i] - 'a'];
          int id = -1;
          for (int j = i + 1; j < n; ++j) {
            if (s[j] == s[i]) {
              id = j;
              break;
            }
          }
          if (id != -1) {
            b.emplace_back(id, i);
            swap(s[id], t[i]);
            continue;
          }
          for (int j = i + 1; j < n; ++j) {
            if (t[j] == s[i]) {
              id = j;
              break;
            }
          }
          if (id != -1) {
            b.emplace_back(id, id);
            b.emplace_back(id, i);
            swap(s[id], t[id]);
            swap(s[id], t[i]);
            continue;
          }
        } else {
          --a[t[i] - 'a'];
          int id = -1;
          for (int j = i + 1; j < n; ++j) {
            if (t[j] == t[i]) {
              id = j;
              break;
            }
          }
          if (id != -1) {
            b.emplace_back(i, id);
            swap(s[i], t[id]);
            continue;
          }
          for (int j = i + 1; j < n; ++j) {
            if (s[j] == t[i]) {
              id = j;
              break;
            }
          }
          if (id != -1) {
            b.emplace_back(id, id);
            b.emplace_back(i, id);
            swap(s[id], t[id]);
            swap(s[i], t[id]);
            continue;
          }
        }
      }
    }
    cout << "Yes\n" << b.size() << '\n';
    for (auto& it : b) {
      cout << it.F + 1 << ' ' << it.S + 1 << '\n';
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
