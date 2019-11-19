#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

class dsu {
public:
  dsu(int n) {
    node_size = n;
    parent = vector<int>(n + 1);
    sz = vector<int>(n + 1);
    makeSet();
  }
  int find(int vertex) {
    if(vertex == parent[vertex]) {
      return vertex;
    } else {
      return parent[vertex] = find(parent[vertex]);
    }
  }
  void unite(int u, int v) {
    parent[u] = v;
    sz[v] += sz[u];
    sz[u] = 0;
  }
private:
  int node_size;
  vector<int> parent;
  vector<int> sz;
  void makeSet(){
    for(int i = 1; i <= node_size; ++i) {
      parent[i] = i;
      sz[i] = 1;
    }
  }
};

vector<pair<long long, pair<int, int>>> edges;

class kruskal {
public:
  kruskal(int n) {
    node_size = n;
    tot_weight = 0;
    sort(edges.begin(), edges.end());
    construct();
  }
  inline long long getWeight() {return tot_weight;}
  inline vector<pair<long long, pair<int, int>>> getMST() {return mst;}
private:
  int node_size;
  long long tot_weight;
  vector<pair<long long, pair<int, int>>> mst;
  void construct(){
    dsu d(node_size);
    for(auto e: edges) {
      int w = e.first;
      int u = e.second.first;
      int v = e.second.second;
      int u_par = d.find(u);
      int v_par = d.find(v);
      if(u_par != v_par) {
        tot_weight += w;
        mst.emplace_back(e);
        d.unite(u_par, v_par);
      }
    }
  }  
};

int cost[N];
int wgt[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n; cin >> n;
  vector<pair<int,int>> points(n + 1);
  for(int i = 1; i <= n; ++i) {
    cin >> points[i].first >> points[i].second;
  }
  for(int i = 1; i <= n; ++i) {
    cin >> cost[i];
  }
  for(int i = 1; i <= n; ++i) {
    cin >> wgt[i];
  }
  int nodes = n + 1;
  for(int i = 1; i <= n; ++i) {
    for(int j = i + 1; j <= n; ++j) {
      long long dist = abs(points[i].first - points[j].first) + abs(points[i].second - points[j].second);
      long long wt = 1LL * dist * (wgt[i] + wgt[j]);
      edges.push_back({wt, {i, j}});
    }
  }
  for(int i = 1; i <= n; ++i) {
    edges.push_back({cost[i], {i, n + 1}});
  }
  kruskal krs(n + 1);
  cout << krs.getWeight() << '\n';
  vector<int> stations;
  vector<pair<int,int>> con;
  auto mst = krs.getMST();
  for(auto p: mst) {
    int u = p.second.first;
    int v = p.second.second;
    if(u != n + 1 && v != n + 1) {
      con.emplace_back(u, v);
    } else {
      if(u == n + 1) swap(u, v);
      stations.emplace_back(u);
    }
  }
  cout << stations.size() << '\n';
  for(auto x: stations) {
    cout << x << " ";
  }
  cout << '\n';
  cout << con.size() << "\n";
  for(auto p: con) {
    cout << p.first << " " << p.second << "\n";
  }
}