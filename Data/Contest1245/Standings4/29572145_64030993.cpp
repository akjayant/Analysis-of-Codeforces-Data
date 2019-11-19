// Author: Kamil Nizinski
#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define dbg_arr(arr_name, first, last)
#define dbg(...)
#define cerr if (false) cerr
#define speed_of_cin_and_cout ios_base::sync_with_stdio(0), cin.tie(0)
#define local if (false)
#else
#include "debug.h"
#define dbg_arr(arr_name, first, last) cerr << "[" << #arr_name << "[" << #first << " = " << first << " .. " << #last << " = " << last << ")]: " << to_string(arr_name, first, last) << endl
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define speed_of_cin_and_cout
#define local
#endif
#define ft first
#define sd second
#define psb push_back
#define sz(a) static_cast<int>(a.size())
using namespace std;
typedef int64_t LL;
typedef uint64_t LLU;
typedef double DD;
typedef pair<int, int> PII;
const int kMaxN = 2007;
int n;
LL adj[kMaxN][kMaxN]; // adjacency matrix of graph
const LL INF = LL{2000000000000000007}; // weight INF means there is no edge
struct Edge {
    LL w = INF;
    int to = -1;
};

void prim() {
    vector<PII> result_edges;
    vector<int> result_builds;
    LL total_weight = LL{0};
    vector<bool> selected(n, false);
    vector<Edge> min_e(n);
    min_e[0].w = LL{0};

    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w))
                v = j;
        }

        if (min_e[v].w == INF) {
            cout << "No MST!" << endl;
            exit(0);
        }

        selected[v] = true;
        total_weight += min_e[v].w;
        if (min_e[v].to != -1) {
          if (v == 0 || min_e[v].to == 0) result_builds.emplace_back((v == 0 ? min_e[v].to : v));
          else result_edges.emplace_back(v, min_e[v].to);
        }
//             cout << v << " " << min_e[v].to << endl;

        for (int to = 0; to < n; ++to) {
            if (adj[v][to] < min_e[to].w)
                min_e[to] = {adj[v][to], v};
        }
    }

    cout << total_weight << "\n";
    cout << sz(result_builds) << "\n";
    for (int u : result_builds) cout << u << " ";
    cout << "\n";
    cout << sz(result_edges) << "\n";
    for (PII e : result_edges) cout << e.ft << " " << e.sd << "\n";
}
void solve() {
  cin >> n;
  n++;
  int x[n], y[n], c[n], k[n];
  for (int i = 1; i < n; i++) cin >> x[i] >> y[i];
  for (int i = 1; i < n; i++) cin >> c[i];
  for (int i = 1; i < n; i++) cin >> k[i];
  for (int u = 1; u < n; u++) {
    adj[0][u] = adj[u][0] = c[u];
    adj[u][u] = INF;
    for (int v = u + 1; v < n; v++) adj[u][v] = adj[v][u] = LL{1} * (abs(x[u] - x[v]) + abs(y[u] - y[v])) * (k[u] + k[v]);
  }
  prim();
  /*for (auto e : result_edges) if (e.ft == 0) cout << e.sd << " ";
  for (auto e : result_edges) if (e.sd == 0) cout << e.ft << " ";
  cout << "\n";
  for (auto e : result_edges) if (e.ft != 0 && e.sd != 0) cout << e.ft << " " << e.sd << "\n";*/
}

int main()
{
  speed_of_cin_and_cout;
  int t = 1;
//   cin >> t;
  while (t--) solve();
  return 0;
}