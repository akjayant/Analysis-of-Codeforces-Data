#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

struct Edge {
  int u;
  int v;
  ll cost;
  Edge(int u1, int v1, ll cost1) {
    u = u1; v = v1; cost = cost1;
  }
};

struct Edge_cmp {
  bool operator()(const Edge& l, const Edge& r) {
    return l.cost > r.cost;
  }
};

#define MAX_SIZE 100000
int parent[MAX_SIZE],rankz[MAX_SIZE];

void Make_Set(const int x){
    parent[x] = x; rankz[x] = 0;
}

int Find(const int x){
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(const int x, const int y){
    int PX = Find(x),PY = Find(y);
    
    if(rankz[PX] > rankz[PY]) parent[PY] = PX;
    else{
        parent[PX] = PY;
        if(rankz[PX]==rankz[PY]) ++rankz[PY];
    }
}


int main(int argc, char** argv) {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<pair<ll, ll>> nodes(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;

    nodes[i] = make_pair(x, y);
  }

  vector<ll> power(n);
  for (int i = 0; i < n; i++) {
    cin >> power[i];
  }
  vector<ll> wire(n);
  for (int i = 0; i < n; i++) {
    cin >> wire[i];
  }

  int real_n = n + 1;
  priority_queue<Edge, vector<Edge>, Edge_cmp> pq;
  // Add edges between normal nodes.
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ll wire_len = abs(nodes[i].first - nodes[j].first) + abs(nodes[i].second - nodes[j].second);
      ll km_cost = wire[i] + wire[j];
      ll total_cost = wire_len * km_cost;
      pq.push(Edge(i, j, total_cost));
    }
  }
  // Add edges from supernode.
  for (int i = 0; i < n; i++) {
    pq.push(Edge(n, i, power[i]));
  }

  // while (!pq.empty()) {
  //   cout << pq.top().cost << " " << pq.top().u << " " << pq.top().v << endl;
  //   pq.pop();
  // }

  // unordered_set<int> included;
  ll final_cost = 0;
  vector<int> power_stations_to_build;
  vector<pair<int, int>> edges_to_build;

  for (int i = 0; i < n + 1; i++) {
    Make_Set(i);
  }
  int num_sets = n + 1;

  while (num_sets > 1) {
    const Edge e = pq.top();
    // cout << pq.top().cost << " " << pq.top().u << " " << pq.top().v << endl;
    pq.pop();
    // if (included.count(e.u) && included.count(e.v)) {
    //   // cout << "skipping: " << e.u << " " << e.v << endl;
    //   continue;
    // }
    // // cout << "inserting: " << e.u << " " << e.v << " cost:" << e.cost << endl;
    // included.insert(e.u);
    // included.insert(e.v);
    if (Find(e.u) == Find(e.v)) {
      continue;
    }
    Union(e.u, e.v);
    num_sets--;
    final_cost += e.cost;

    if (e.u == n) {
      power_stations_to_build.push_back(e.v);
    } else {
      edges_to_build.push_back(make_pair(e.u, e.v));
    }
  }

  cout << final_cost << endl;
  cout << power_stations_to_build.size() << endl;
  for (int p : power_stations_to_build) {
    cout << p + 1 << " ";
  }
  cout << endl;
  cout << edges_to_build.size() << endl;
  for (auto p : edges_to_build) {
    cout << p.first + 1 << " " << p.second + 1 << endl;
  }



  return 0;
}
