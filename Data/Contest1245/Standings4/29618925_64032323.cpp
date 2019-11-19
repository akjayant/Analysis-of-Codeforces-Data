#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define MP make_pair
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= end; --i)
#define arep(i, c) for (auto i = (c).begin(); i != (c).end(); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<ll, pair<int, int>>;

ll prim(const vector<vector<P>>& graph, vector<int>& power_station, vector<pair<int, int>>& edges, int start) {
    ll res = 0;
    vector<bool> visited(graph.size(), false);
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(MP(0, MP(start, -1)));
    while (!pq.empty()) {
        P now = pq.top();
        ll cost = now.first;
        int node = now.second.first;
        int parent = now.second.second;
        pq.pop();
        if (visited[node]) continue;
        visited[node] = true;
        if (parent < 0) power_station.push_back(node);
        else edges.push_back(MP(parent, node));
        res += cost;
        rep(i, 0, graph[node].size()) {
            if (!visited[graph[node][i].second.first]) {
                pq.push(graph[node][i]);
            }
        }
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<ll> X(N), Y(N);
    rep(i, 0, N) cin >> X[i] >> Y[i];
    vector<ll> C(N), K(N);
    rep(i, 0, N) cin >> C[i];
    rep(i, 0, N) cin >> K[i];
    vector<vector<P>> graph(N);
    rep(i, 0, N) rep(j, i + 1, N) {
        ll cost = (K[i] + K[j]) * (abs(X[i] - X[j]) + abs(Y[i] - Y[j]));
        graph[i].push_back(MP(cost, MP(j, i)));
        graph[j].push_back(MP(cost, MP(i, j)));
        graph[i].push_back(MP(C[j], MP(j, -1)));
        graph[j].push_back(MP(C[i], MP(i, -1)));
    }
    int min_node = min_element(all(C)) - C.begin();
    vector<int> power_station;
    vector<pair<int, int>> edges;
    ll min_cost = prim(graph, power_station, edges, min_node) + C[min_node];
    cout << min_cost << endl;
    cout << power_station.size() << endl;
    rep(i, 0, power_station.size()) {
        cout << power_station[i] + 1 << " \n"[i + 1 == power_station.size()];
    }
    cout << edges.size() << endl;
    rep(i, 0, edges.size()) {
        cout << edges[i].first + 1 << ' ' << edges[i].second + 1 << endl;
    }
    return 0;
}