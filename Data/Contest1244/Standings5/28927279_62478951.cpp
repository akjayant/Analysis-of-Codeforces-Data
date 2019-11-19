#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <string.h>
#include <fstream>
#include <math.h>
#include <limits>
#include <set>
#include <map>
#include <sstream>
#include <stdio.h>
#include <time.h>
#include <memory.h>
#include <cassert>
#include <complex>
#include <unordered_set>
#include <unordered_map>
using namespace std;
 
#define rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
#define repd(i, n) for (int i = (n)-1; i >= 0; --i)
#define _fill(a, x) memset((a), (x), sizeof((a)))
#define DEB(k) cerr<<"debug: "#k<<"="<<k<<endl;
#define all(c) (c).begin(), (c).end()
#define mp(a, b) make_pair(a, b)
#define l(c) (int)((c).size())
#define sqr(a) ((a)*(a))
#define inf 0x7f7f7f7f
#define pb push_back
#define x first
#define y second
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define INF2 1000000000000000000LL

int n;
int p[3][100007];
int col[100007];
vector<int> g[100007];

ll ans = INF2;
int colAns[100007];

void go(int v, int par, int gpar, int depth, ll cost) {
  if (depth == n) {
    return;
  }
  rep(cc, 3) {
    if (par != -1 && col[par] == cc) continue;
    if (gpar != -1 && col[gpar] == cc) continue;
    col[v] = cc;
    ll cost2 = cost + p[cc][v];
    if (depth == n-1) {
      if (cost2 < ans) {
        ans = cost2;
        rep(i, n) colAns[i] = col[i];
      }
    } else {
      rep(i, l(g[v])) {
        int v2 = g[v][i];
        if (v2 == par) continue;
        go(v2, v, par, depth+1, cost + p[cc][v]);
      }
    }
  }
}

void solution()
{
  scanf("%d", &n);
  rep(i, n) scanf("%d", p[0]+i);
  rep(i, n) scanf("%d", p[1]+i);
  rep(i, n) scanf("%d", p[2]+i);
  rep(i, n-1) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--, b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  int root = -1;
  int nr = 0;
  rep(i, n) {
    if (l(g[i]) == 1) {
      root = i;
      nr++;
    } else if (l(g[i]) > 2) {
      nr = 100;
    }
  }
  if (nr != 2) {
    cout << "-1" << endl;
    return;
  }
  go(root, -1, -1, 0, 0);
  if (ans == INF2) {
    ans = -1;
  }
  cout << ans << endl;
  rep(i, n) {
    cout << (colAns[i]+1) << " ";
  }
  cout << endl;
}
 
int main()
{
#ifdef LOCAL
  freopen("input.txt", "rt", stdin);
  //freopen("output.txt", "wt", stdout);
#endif
  solution();
  return 0;
}