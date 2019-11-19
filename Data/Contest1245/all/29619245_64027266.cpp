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

struct Loc {
  int i, j;
};

struct Edge {
  ll c;
  int to = 0;
};

ll getCost(int x, int y, vector < ll > &k, vector < Loc > &location) {
  return (k[x] + k[y]) * (1ll * (abs(location[x].i - location[y].i) + abs(location[x].j - location[y].j)));
}

int main() {

#ifdef STEF
  freopen("input", "r", stdin);
  freopen("output", "w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n;
  cin >> n;

  vector < Loc > location(n + 1);
  for (int i = 1; i <= n; ++ i) {
    cin >> location[i].i >> location[i].j;
  }

  vector < Edge > minEdge(n + 1);
  for (int i = 1; i <= n; ++ i) {
    cin >> minEdge[i].c;
  }

  vector < ll > k(n + 1);
  for (int i = 1; i <= n; ++ i) {
    cin >> k[i];
  }

  vector < int > chosePow;
  vector < pii > connections;
  vector < bool > used(n + 1);
  used[0] = true;

  ll totalCost = 0;

  for (int i = 1; i <= n; ++ i) {

    int curNode = -1;
    for (int j = 1; j <= n; ++ j) {
      if (not used[j] and (curNode == -1 or minEdge[j].c < minEdge[curNode].c)) {
        curNode = j;
      }
    }

    if (curNode == -1) break;

    used[curNode] = true;
    totalCost += minEdge[curNode].c;
    if (minEdge[curNode].to == 0) {
      chosePow.push_back(curNode);
    }
    else {
      connections.push_back({curNode, minEdge[curNode].to});
    }

    for (int j = 1; j <= n; ++ j) {
      if (used[j]) continue;

      ll aux = getCost(curNode, j, k, location);
      if (aux < minEdge[j].c) {
        minEdge[j] = {aux, curNode};
      }
    }
  }

  cout << totalCost << '\n';
  cout << sz(chosePow) << '\n';
  for (auto x : chosePow) cout << x << ' ';
  cout << '\n';
  cout << sz(connections) << '\n';
  for (auto x : connections) cout << x.first << ' ' << x.second << '\n';
}
