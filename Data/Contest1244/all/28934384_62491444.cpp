#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector <int> vi;

#define pb push_back
#define mp make_pair

template <class T> inline T sqr(const T& x) { return x * x; }
template <class T> inline void updMin(T& a, const T& b) { if (b < a) a = b; }
template <class T> inline void updMax(T& a, const T& b) { if (b > a) a = b; }

const int M = 1000000007;
const int M2 = 1000000009;
const int maxn = 200005;

bool used[maxn][4][4];
ll mas[maxn][4][4];
int cost[maxn][3];
int res[maxn];

vector<int> a[maxn];
int n;

ll f(int v, int c, int pc, int p = -1) {
  if (v == -1 || v == p) {
    return 0;
  }

  if (c < 0) {
    return 1000000000000000000L;
  }

  if (used[v][c][pc]) {
    return mas[v][c][pc];
  }

  used[v][c][pc] = 1;
  mas[v][c][pc] = cost[v][c];

  int c1 = 0, c2 = 1;
  if (c == c1) {
    c1 = 2; 
  } else if (c == c2) {
    c2 = 2; 
  }

  if (pc == c1) {
    c1 = -1;
  } else if (pc == c2) {
    c2 = -1;
  }

  int u1 = -1, u2 = -1;
  for (int i = 0; i < a[v].size(); i++) {
    if (a[v][i] == p) {
      continue;
    }

    if (u1 == -1) {
      u1 = a[v][i];
    } else if (u2 == -1) {
      u2 = a[v][i];
    } else {
      return  mas[v][c][pc] = 1000000000000000000L;
    }
  }

  ll t1 = f(u1, c1, c, v) + f(u2, c2, c, v);
  ll t2 = f(u1, c2, c, v) + f(u2, c1, c, v);

  return mas[v][c][pc] = mas[v][c][pc] + min(t1, t2);
}

void ans(int v, int c, int pc, int p = -1) {
  if (v == -1 || v == p) {
    return;
  }

  res[v] = c;

  int c1 = 0, c2 = 1;
  if (c == c1) {
    c1 = 2; 
  } else if (c == c2) {
    c2 = 2; 
  }

  if (pc == c1) {
    c1 = -1;
  } else if (pc == c2) {
    c2 = -1;
  }

  int u1 = -1, u2 = -1;
  for (int i = 0; i < a[v].size(); i++) {
    if (a[v][i] == p) {
      continue;
    }

    if (u1 == -1) {
      u1 = a[v][i];
    } else if (u2 == -1) {
      u2 = a[v][i];
    } 
  }

  ll t1 = f(u1, c1, c, v) + f(u2, c2, c, v);
  ll t2 = f(u1, c2, c, v) + f(u2, c1, c, v);

  if (t1 < t2) {
    ans(u1, c1, c, v);
    ans(u2, c2, c, v);
  } else {
    ans(u1, c2, c, v);
    ans(u2, c1, c, v);
  }
}

int main()
{

  scanf("%d", &n);

  for (int c = 0; c < 3; c++) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &cost[i][c]);
    }
  }

  for (int i = 0; i < n - 1; i++) {
    int x, y; 
    scanf("%d %d", &x, &y);
    x--, y--; 
    a[x].pb(y);
    a[y].pb(x);
  }

  int mem = -1;
  for (int i = 0; i < n; i++) {
    if (a[i].size() == 1) {
      mem = i;
    }
  }

  for (int i = 0; i < n; i++) {
    if (a[i].size() > 2) {
      cout << -1 << endl;
      return 0;
    }
  }

  ll anss = 1000000000000000000L;
  int memc = -1;
  for (int i = 0; i < 3; i++) {
    ll t = f(mem, i, 3, -1);
    
    if (t < anss) {
      anss = t;
      memc = i;
    }
  }

  if (anss > 100000000000000000L) {
    cout << -1 << endl;
    return 0;
  }

  cout << anss << endl; 
  ans(mem, memc, 3, -1);

  for (int i = 0; i < n; i++) {
    cout << res[i] + 1 << " ";
  }
  cout << endl;

  return 0;
}