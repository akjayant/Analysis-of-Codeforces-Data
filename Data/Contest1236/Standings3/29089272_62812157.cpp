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

struct PozL {
  int i, j;

  bool operator < (PozL other) const {
    return this -> j < other.j;
  }
};

struct PozC {
  int i, j;

  bool operator < (PozC other) const {
    return this -> i < other.i;
  }
};

int dirI[] = {0, 1, 0, -1};
int dirJ[] = {1, 0, -1, 0};

struct Poz {
  int i, j, dir;
};

int main() {

#ifdef STEF
  freopen("input", "r", stdin);
  freopen("output", "w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n, m, k;
  cin >> n >> m >> k;

  vector < set < PozL > > lines(n + 1);
  vector < set < PozC > > cols(m + 1);

  for (int i = 1; i <= k; ++ i) {

    int a, b;
    cin >> a >> b;

    lines[a].insert({a, b});
    cols[b].insert({a, b});
  }

  int n1 = 1, m1 = 1;
  ll nI = n, mI = m;

  Poz d = {1, 1, 0};

  ll moved = 1;
  int cntErased = 0;

  while (true) {

    if (d.dir == 0) {

      if (lines[d.i].begin() != lines[d.i].end()) {
        auto st = *lines[d.i].begin();
        for (int j = st.j; j <= m; ++ j) {
          if (sz(cols[j]) != n - n1 + 1) {
            cout << "No\n";
            return 0;
          }
          for (int i = n1; i <= n; ++ i) {
            lines[i].erase({i, j});
            ++ cntErased;
          }
        }

        m = st.j - 1;
      }

      d.dir = 1;
      moved += m - d.j;
      d.j = m;
      ++ n1;
    }
    else if (d.dir == 1) {

      if (cols[d.j].begin() != cols[d.j].end()) {
        auto st = *cols[d.j].begin();
        for (int i = st.i; i <= n; ++ i) {
          if (sz(lines[i]) != m - m1 + 1) {
            cout << "No\n";
            return 0;
          }
          for (int j = m1; j <= m; ++ j) {
            cols[j].erase({i, j});
            ++ cntErased;
          }
        }

        n = st.i - 1;
      }

      d.dir = 2;
      moved += n - d.i;
      d.i = n;
      -- m;
    }
    else if (d.dir == 2) {
      if (lines[d.i].rbegin() != lines[d.i].rend()) {
        auto st = *lines[d.i].rbegin();
        for (int j = st.j; j >= m1; -- j) {
          if (sz(cols[j]) != n - n1 + 1) {
            cout << "No\n";
            return 0;
          }
          for (int i = n1; i <= n; ++ i) {
            lines[i].erase({i, j});
            ++ cntErased;
          }
        }

        m1 = st.j + 1;
      }

      d.dir = 3;
      moved += d.j - m1;
      d.j = m1;
      -- n;
    }
    else if (d.dir == 3) {
      if (cols[d.j].rbegin() != cols[d.j].rend()) {
        auto st = *cols[d.j].rbegin();
        for (int i = st.i; i >= n1; -- i) {
          if (sz(lines[i]) != m - m1 + 1) {
            cout << "No\n";
            return 0;
          }
          for (int j = m1; j <= m; ++ j) {
            cols[j].erase({i, j});
            ++ cntErased;
          }
        }

        n1 = st.i + 1;
      }

      d.dir = 0;
      moved += d.i - n1;
      d.i = n1;
      ++ m1;
    }

    if (moved + cntErased == nI * mI) {
      break;
    }
  }

  cout << "Yes\n";
}
