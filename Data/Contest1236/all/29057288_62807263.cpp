#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <memory.h>
#include <stdio.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
// #pragma comment(linker, "/STACK:667177216")
#define ll long long
#define ull unsigned long long
#define INF 1000000007
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mp make_pair
#define vI vector<int>
#define vvI vector<vector<int>>
#define vLL vector<LL>
#define vS vector<string>
#define fori(i, n) for (int(i) = 0; (i) < n; (i)++)
#define forn(it, from, to) for (int(it) = from; (it) < to; (it)++)
#define forI(tmp) for (auto(it) = (tmp).begin(); (it) != (tmp).end(); (it)++)
#define PI 3.14159265356
#define LD long double
#define sc(a) scanf("%d", &(a))
#define scLL(a) scanf("%I64d", &(a))
#define mems(a, val) memset(a, val, sizeof(a))
#define sz(a) (int)(a).size()
typedef long long LL;
using namespace std;
const LL MOD = 1000000000 + 7;
const LL MAXN = 2 * 100000 + 100;

LL bpow(LL a, LL p) {
  if (p == 0) return 1;
  LL tmp = bpow(a, p >> 1);
  tmp *= tmp;
  tmp %= MOD;
  if (p & 1) tmp *= a;
  tmp %= MOD;
  return tmp;
}

int main() {
#ifdef ONLINE_JUDGE
  // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  LL n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> rows(n + 1), cols(m + 1);
  set<pair<int, int>> walls;
  int x = 1, y = 1;
  forn(i, 0, k) {
    int r, c;
    cin >> r >> c;
    walls.insert(mp(r, c));
    rows[r].push_back(c);
    cols[c].push_back(r);
  }

  forn(i, 0, n + 1) {
    rows[i].push_back(0);
    rows[i].push_back(m + 1);
    sort(all(rows[i]));
  }
  forn(i, 0, m + 1) {
    cols[i].push_back(0);
    cols[i].push_back(n + 1);
    sort(all(cols[i]));
  }

  vector<char> used_row(n + 2), used_col(m + 2);

  used_row[0] = used_row[n + 1] = used_col[0] = used_col[m + 1] = 1;

  set<int> dead_row, dead_col;
  dead_row.insert(0);
  dead_row.insert(n + 1);
  dead_col.insert(0);
  dead_col.insert(m + 1);

  LL need = n * m - 1;
  need -= k;
  if (need == 0) {
    cout << "Yes";
    return 0;
  }
  int dir = 0;
  int step = 0;
  while (true) {
    step++;
    if (dir == 0) {
      int last_y = *upper_bound(all(rows[x]), y);
      last_y = min(last_y, *dead_col.upper_bound(y));

      need -= last_y - y - 1;
      dir = 1;
      y = last_y - 1;
      dead_row.insert(x);
      if (walls.count(mp(x + 1, last_y - 1)) || dead_row.count(x + 1)) break;

      if (x == 1 && y == 1 && step != 1) break;
      continue;
    }
    if (dir == 1) {
      int last_x = *upper_bound(all(cols[y]), x);
      last_x = min(last_x, *dead_row.upper_bound(x));

      need -= last_x - x - 1;
      dir = 2;
      x = last_x - 1;
      dead_col.insert(y);

      // if (last_x == x + 1) {
      if (walls.count(mp(last_x - 1, y - 1)) || dead_col.count(y - 1)) break;
      //}

      if (x == 1 && y == 1) break;
      continue;
    }

    if (dir == 2) {
      int last_y = *(--lower_bound(all(rows[x]), y));
      last_y = max(last_y, *(--dead_col.lower_bound(y)));

      need -= y - last_y - 1;
      dir = 3;
      y = last_y + 1;
      dead_row.insert(x);
      // if (last_y + 1 == y) {
      if (walls.count(mp(x - 1, last_y + 1)) || dead_row.count(x - 1)) break;
      //}

      if (x == 1 && y == 1) break;

      continue;
    }

    if (dir == 3) {
      int last_x = *(--upper_bound(all(cols[y]), x));
      last_x = max(last_x, *(--dead_row.lower_bound(x)));

      need -= x - last_x - 1;
      dir = 0;
      x = last_x + 1;
      dead_col.insert(y);

      if (walls.count(mp(last_x + 1, y + 1)) || dead_col.count(y + 1)) break;
      if (x == 1 && y == 1) break;

      continue;
    }
  }

  if (x == 1 && y == 1) need++;
  if (need == 0)
    cout << "Yes";
  else
    cout << "No";

  return 0;
}