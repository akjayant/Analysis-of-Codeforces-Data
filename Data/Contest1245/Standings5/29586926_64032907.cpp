#include <bits/stdc++.h>
using namespace std;
class DSU
{
private:
  vector<int> parent, rank;

public:
  DSU(){};
  DSU(int sz)
  {
    parent.assign(sz, -1);
    rank.assign(sz, 0);
    for (int i = 0; i < sz; i++)
      parent[i] = i;
  }
  inline void makeSet(int v)
  {
    parent[v] = v;
    rank[v] = 0;
  }
  // O(1)
  inline int findSet(int v)
  {
    if (v == parent[v])
    {
      return v;
    }
    return parent[v] = findSet(parent[v]);
  }
  inline bool isSameSet(int u, int v)
  {
    return findSet(u) == findSet(v);
  }
  inline void unionSets(int a, int b)
  {
    a = findSet(a);
    b = findSet(b);
    if (a != b)
    {
      if (rank[b] > rank[a])
        swap(a, b);
      parent[b] = a;
      if (rank[a] == rank[b])
      {
        rank[a]++;
      }
    }
  }
};
struct Edge
{
  int u, v;
  long long w;
  Edge(){};
  Edge(int u, int v, long long w) : u(u), v(v), w(w){};
  bool operator<(Edge const &other) const
  {
    return w < other.w;
  }
};
vector<Edge> E;
vector<Edge> MST;
int n;
long long costTotal;
void kruskal()
{
  // O(E + E logE)
  sort(E.begin(), E.end());
  costTotal = 0;
  DSU dsu(n);
  MST.clear();
  int c = 1;
  for (auto &e : E)
  {
    if (!dsu.isSameSet(e.u, e.v))
    {
      costTotal += e.w;
      dsu.unionSets(e.u, e.v);
      MST.emplace_back(e);
      if (++c == n)
        break;
    }
  }
}
vector<set<int>> ad;
vector<long long> C, K;
vector<int> U;
int mndfs(int s, int p) {
  U[s] = 1;
  long long u = s;
  for (auto v : ad[s])
  {
    if (v == p)
      continue;
    int y = mndfs(v, s);
    if (C[y] < C[u]) {
      u = y;
    }
  }
  return u;  
}
long long dfs(int s, int p)
{
  long long u = C[s];
  for (auto v : ad[s])
  {
    if (v == p)
      continue;
    u = min(u, dfs(v, s));
  }
  return u;
}
int main()
{
  // read n
  cin >> n;
  vector<long long> X(n), Y(n);
  for (int i = 0; i < n; i++) {
    cin >> X[i] >> Y[i];
  }
  C.assign(n, 0);
  K.assign(n, 0);
  
  for (int i = 0; i < n; i++) {
    cin >> C[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> K[i];
  }  
  E.clear();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      E.emplace_back(i, j, (abs(X[i] - X[j]) + abs(Y[i] - Y[j])) * 1LL * (K[i] + K[j]));

    }
  }
  kruskal();
  ad.assign(n, set<int>());
  for (auto c : MST)
  {
    ad[c.u].insert(c.v);
    ad[c.v].insert(c.u);
  }
  sort(MST.rbegin(), MST.rend());
  vector<pair<int, int>> N;
  long long mn = 0;
  for (auto e : MST) {
    int mx = max(dfs(e.u, e.v), dfs(e.v, e.u));
    if (mx < e.w) {
      ad[e.u].erase(e.v);
      ad[e.v].erase(e.u);
    } else {
      N.emplace_back(e.u, e.v);
      mn += e.w;
    }
  }
  vector<int> V;
  U.assign(n, 0);
  for (int i = 0; i < n; i++)
  {
    if (U[i] == 0) {
      int x = mndfs(i, -1);
      V.push_back(x);
      mn += C[x];
    }
  }
  cout << mn << "\n";
  int na = V.size();
  cout << na << '\n';
  for (int i = 0; i < na; i++) {
    cout << V[i] + 1 << ' ';
  }
  if (na)
    cout << "\n";
  na = N.size();
  cout << na << "\n";
  for (int i = 0; i < na; i++) {
    cout << N[i].first + 1 << ' ' << N[i].second + 1 << "\n";
  }  
  return 0;
}