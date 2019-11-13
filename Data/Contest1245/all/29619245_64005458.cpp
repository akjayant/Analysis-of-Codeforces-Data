// By Stefan Radu

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <string>
#include <cctype>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define sz(x) (int)(x).size()

typedef pair < int, int > pii;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;

int main() {

#ifdef STEF
  freopen("input", "r", stdin);
  freopen("output", "w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int t;
  cin >> t;

  while (t --) {

    int n; cin >> n;

    int r, p, s;
    cin >> r >> p >> s;

    string st; cin >> st;

    int rB = 0, pB = 0, sB = 0;
    for (char c : st) {
      if (c == 'R') ++ rB;
      else if (c == 'P') ++ pB;
      else ++ sB;
    }

    int ans = min(r, sB) + min(p, rB) + min(s, pB);

    string strAns = st;
    for (auto &x : strAns) x = 'a';

    if (ans >= ceil((double)n / 2.0)) {
      cout << "YES\n";
      for (int i = 0; i < sz(st); ++ i) {
        auto c = st[i];
        if (c == 'R' and p > 0) {
          strAns[i] = 'P';
          -- p;
        }
        else if (c == 'P' and s > 0) {
          strAns[i] = 'S';
          -- s;
        }
        else if (c == 'S' and r > 0) {
          strAns[i] = 'R';
          -- r;
        }
      }

      for (auto &x : strAns) {
        if (x == 'a') {
          if (r) {
            x = 'R';
            -- r;
          }
          else if (p) { 
            x = 'P';
            -- p;
          }
          else if (s) {
            x = 'S';
            -- s;
          }
        }
      }

      cout << strAns << '\n';
    }
    else {
      cout << "NO\n";
    }
  }
}
