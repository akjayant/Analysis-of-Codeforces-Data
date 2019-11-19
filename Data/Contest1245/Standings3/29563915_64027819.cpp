#include <algorithm>
#include <iostream>
#include <iomanip>
#include <utility>
#include <cstdlib>
#include <cstdint>
#include <cstdio>
#include <vector>
#include <string>
#include <deque>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <cstring>
#include <assert.h>
#include <chrono>
#include <random>
#include <functional>
#include <bitset>
#include <iterator>

using namespace std;

using ll = long long;

const int MOD = (int)(1e9 + 7);
const double PI = 3.14159265358979323846;

string S;

const int MAXN = 2010;

int dsu[MAXN];
int opt[MAXN];

int F(int x) {
  if (dsu[x] == x) return x;
  return dsu[x] = F(dsu[x]);
}

int X[MAXN];
int Y[MAXN];

int main()
{
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    dsu[i] = i;
  for (int i = 0; i < n; i++)
    cin >> X[i] >> Y[i];
  vector<tuple<ll, int, int> > E;
  vector<int> C(n), K(n);
  for (int i = 0; i < n; i++) {
    cin >> C[i];
    opt[i] = C[i];
  }
  for (int i = 0; i < n; i++)
    cin >> K[i];
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ll cst = 1LL * (K[i] + K[j]) * (abs(X[i] - X[j]) + abs(Y[i] - Y[j]));
      E.emplace_back(cst, i, j);
    } 
  }
  sort(E.begin(), E.end());
  ll tot = 0;
  vector<int> power;
  vector<pair<int, int> > conns;
  for (int i = 0; i < E.size(); i++) {
    ll cst;
    int src, dest;
    tie(cst, src, dest) = E[i];
    int ps = F(src);
    int pd = F(dest);
    if (ps != pd && opt[ps] + opt[pd] >= cst + min(opt[ps], opt[pd])) {
      conns.emplace_back(src, dest);
      dsu[ps] = pd;
      opt[pd] = min(opt[pd], opt[ps]);
      tot += cst;
    }
  }
  vector<int> take(n, -1);
  for (int i = 0; i < n; i++) {
    int x = F(i);
    if (take[x] == -1 || (C[i] < C[take[x]])) {
      take[x] = i;
    }
  }
  for (int i = 0; i < n; i++) {
    if (take[i] != -1) {
      power.push_back(take[i]);
      tot += C[take[i]];
    }
  }
  cout << tot << '\n';
  cout << power.size() << '\n';
  for (int x : power)
    cout << ++x << ' ';
  cout << '\n';
  cout << conns.size() << '\n';
  for (auto [s, t] : conns) 
    cout << ++s << ' ' << ++t << '\n';
  cout << '\n';
  return 0;
}
