#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef double dl;

#ifdef DEBUG
#include "../debug.h"
#else
#define debug(...) 42
#define cerr if(0) cout
#define endl '\n'
#endif

#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()

const int inf = (int) 1.01e9;
const ll infll = (ll) 1.01e18;
const ld eps = 1e-9;
const ld pi = acos((ld) -1.0);
const int mod = (int) 1e9 + 7;

void solve() {
  int n; cin >> n;
  string s, t; cin >> s >> t;
  vector<int> m;
  vector<int> f(26);
  for(int i = 0; i < n; ++i) {
    if(s[i] != t[i]) {
      m.PB(i);
      f[s[i] - 'a']++;
      f[t[i] - 'a']++;
    }
  }
  for(int x: f) if(x % 2) {
    cout << "No\n";
    return;
  }
  int x = SZ(m);
  vector<pair<int, int>> res;
  for(int i = 0; i < x; ++i) {
    if(s[m[i]] == t[m[i]]) continue;
    bool done = false;
    for(int j = i + 1; j < x; ++j) {
      auto a = m[i], b = m[j];
      if(t[a] == t[b]) {
        res.EB(a, b);
        swap(s[a], t[b]);
        done = true;
        break;
      }
    }
    if(done) continue;
    for(int j = i + 1; j < x; ++j) {
      auto a = m[i], b = m[j];
      if(t[a] == s[b]) {
        res.EB(b, b);
        swap(s[b], t[b]);
        res.EB(a, b);
        swap(s[a], t[b]);
        done = true;
        break;
      }
    }
    if(!done) {
      cout << "No\n";
      return;
    }
  }
  assert(SZ(res) <= 2 * n);
  cout << "Yes\n" << SZ(res) << '\n';
  for(auto x: res) cout << x.first + 1 << ' ' << x.second + 1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
