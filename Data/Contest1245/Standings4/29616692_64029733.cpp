#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cassert>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cmath>

#ifdef DEBUG
#define dbg(fmt, args...) fprintf(stderr, fmt, ##args)
#else
#define dbg(fmt, args...)
#endif
#define REPS(i, s, n) for(int (i) = (s); (i) < (int)(n); ++(i))
#define REPRS(i, e, n) for(int (i) = (int)(n) - 1; (i) >= e; --(i))
#define REPR(i, n) REPRS(i, 0, n)
#define REP(i, n) REPS(i, 0, n)
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define x first
#define y second
#define INFI 1234567890
#define INFL 1234567890123456789LL
typedef double dbl;
typedef long double ldbl;
typedef long long ll;

using namespace std;

const int MAXN = 5000;
int n;
ll answer = 0;
ll k[MAXN], c[MAXN], x[MAXN], y[MAXN];
ll rank0[MAXN], parent[MAXN];
ll w[MAXN];
int loc[MAXN];

void make_set (int v) {
  parent[v] = v;
  rank0[v] = 0;
}
 
int find_set (int v) {
  if (v == parent[v])
    return v;
  return parent[v] = find_set (parent[v]);
}
 
void union_sets (int a, int b) {
  a = find_set (a);
  b = find_set (b);
  if (a != b) {
    if (rank0[a] < rank0[b])
      swap (a, b);
    parent[b] = a;
    if (rank0[a] == rank0[b])
      ++rank0[a];
  }
}

int main() {
#ifdef DEBUG
  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    set<int> res_v;
    vector<pair<int, int> > res_e;
    cin >> n;
    REP(i, n) {
      res_v.insert(i);
      cin >> x[i] >> y[i];
    }
    REP(i, n) {
      cin >> c[i];
      make_set(i);
      w[i] = c[i];
      answer += c[i];
      loc[i] = i;
    }
    REP(i, n) {
      cin >> k[i];
    }
    vector<pair<ll, pair<int, int> > > edges;
    REP(i, n) {
      REP(j, n) {
        if (j >= i) break;
        ll dist = abs(x[i] - x[j]) + abs(y[i] - y[j]);
        dist *= (k[i] + k[j]);
        edges.push_back(make_pair(dist, make_pair(i, j)));
      }
    }
    sort(edges.begin(), edges.end());
    REP(i, edges.size()) {
      ll dist = edges[i].first;
      int a = find_set(edges[i].second.first);
      int b = find_set(edges[i].second.second);
      if (a == b) continue;
      ll diff = dist - max(w[loc[a]], w[loc[b]]);
      if (diff < 0) {
        union_sets(a, b);
        if (w[loc[a]] < w[loc[b]]) {
          res_v.erase(loc[b]);
          loc[find_set(a)] = loc[a];
        } else {
          res_v.erase(loc[a]);
          loc[find_set(a)] = loc[b];
        }
        answer += diff;
        res_e.push_back(edges[i].second);
      }
    }
    cout << answer << '\n';
    cout << res_v.size() << '\n';
    for (auto it = res_v.begin(); it != res_v.end(); ++it) {
      cout << *it + 1 << " \n"[next(it) == res_v.end()];
    }
    cout << res_e.size() << '\n';
    for (auto e : res_e) {
      cout << e.first + 1 << " " << e.second + 1 << '\n';
    }
    return 0;
}
