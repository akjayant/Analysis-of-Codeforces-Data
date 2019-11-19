#include <bits/stdc++.h>

using namespace std;

template<typename S, typename T>
ostream& operator<<(ostream& out, const pair<S, T> p) {
    out << "(" << p.first << "," << p.second << ")";
    return out;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
    for (auto a: v)
        out << a << " ";
    return out;
}

template<typename T>
ostream& operator<<(ostream& out, const set<T>& S) {
    for (auto a: S)
        cout << a << " ";
    return out;
}

template<typename T>
ostream& operator<<(ostream& out, const multiset<T>& S) {
    for (auto a: S)
        cout << a << " ";
    return out;
}

template<typename S, typename T>
ostream& operator<<(ostream& out, const map<S, T>& M) {
    for (auto m: M)
        cout << "(" << m.first << "->" << m.second << ") ";
    return out;
}

template<typename S, typename T>
pair<S, T> operator+(pair<S, T> a, pair<S, T> b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

template<typename S, typename T>
pair<S, T> operator-(pair<S, T> a, pair<S, T> b) {
    return make_pair(a.first - b.first, a.second - b.second);
}

template<typename T>
struct WeightedGraph {
    struct Edge {
        int s;
        int t;
        T w;
        Edge(int s, int t, T w): s(s), t(t), w(w) {}
    };
    int n;
    int src;
    vector<Edge> edge;
    vector<vector<int>> E;
    vector<int> vis;
    vector<T> dist;
    vector<int> parent;
    T inf = numeric_limits<T>::max();
    int negative_cycle;

    void init(int n) {
        this-> n = n;
        edge.clear();
        E.resize(n);
        for (int i = 0; i < n; i++)
            E[i].clear();
        negative_cycle = 0;
    }

    void add_directed_edge(int s, int t, T w) {
        edge.emplace_back(s, t, w);
        E[s].push_back(edge.size() - 1);
    }

    void source_dijkstra(int src) {
        this->src = src;
        set<pair<T, int>> S;
        vis.assign(n, 0);
        dist.assign(n, inf);
        parent.assign(n, -1);
        vis[src] = 1;
        dist[src] = 0;
        parent[src] = -1;
        S.emplace(dist[src], src);
        while (!S.empty()) {
            int s = S.begin()->second;
            S.erase(S.begin());
            vis[s] = 2;
            for (int e: E[s]) {
                int t = edge[e].t;
                T w = edge[e].w;
                if (!vis[t]) {
                    vis[t] = 1;
                    dist[t] = dist[s] + w;
                    parent[t] = s;
                    S.emplace(dist[t], t);
                } else if (vis[t] == 1) {
                    if (dist[t] > dist[s] + w) {
                        S.erase(make_pair(dist[t], t));
                        dist[t] = dist[s] + w;
                        parent[t] = s;
                        S.emplace(dist[t], t);
                    }
                }
            }
        }
    }

    void source_prim(int src) {
        this->src = src;
        set<pair<T, int>> S;
        vis.assign(n, 0);
        dist.assign(n, inf);
        parent.assign(n, -1);
        vis[src] = 1;
        dist[src] = 0;
        parent[src] = -1;
        S.emplace(dist[src], src);
        while (!S.empty()) {
            int s = S.begin()->second;
            S.erase(S.begin());
            vis[s] = 2;
            for (int e: E[s]) {
                int t = edge[e].t;
                T w = edge[e].w;
                if (!vis[t]) {
                    vis[t] = 1;
                    dist[t] = w;
                    parent[t] = s;
                    S.emplace(dist[t], t);
                } else if (vis[t] == 1) {
                    if (dist[t] > w) {
                        S.erase(make_pair(dist[t], t));
                        dist[t] = w;
                        parent[t] = s;
                        S.emplace(dist[t], t);
                    }
                }
            }
        }
    }

    void source_bellman_ford(int src, bool set_infinity=false) {
        this->src = src;
        vis.assign(n, 0);
        dist.assign(n, inf);
        parent.assign(n, -1);
        vis[src] = 1;
        dist[src] = 0;

        for (int i = 0; i < n - 1; i++) {
            for (auto e: edge) {
                int s = e.s;
                int t = e.t;
                T w = e.w;
                if (dist[s] < inf && dist[t] > dist[s] + w) {
                    vis[t] = 1;
                    dist[t] = dist[s] + w;
                    parent[t] = s;
                }
            }
        }

        negative_cycle = 0;
        for (int cnt = 0; cnt < n; cnt++) {
            int x = -1;
            for (auto e: edge) {
                int s = e.s;
                int t = e.t;
                T w = e.w;
                if (dist[s] != -inf && dist[s] < inf && dist[t] > dist[s] + w) {
                    negative_cycle = 1;
                    x = t;
                    break;
                }
            }
            if (!set_infinity)
                break;
            if (x == -1)
                break;
            for (int i = 0; i < n; i++)
                x = parent[x];
            dist[x] = -inf;

            for (int i = 0; i < n - 1; i++) {
                for (auto e: edge) {
                    int s = e.s;
                    int t = e.t;
                    if (dist[s] == -inf) {
                        dist[t] = -inf;
                    }
                }
            }
        }
    }


    vector<T> query_dist() {
        return dist;
    }

    vector<int> query_route(int s) {
        vector<int> A;
        if (vis[s] == 0)
            return A;
        A.push_back(s);
        while (s != src) {
            s = parent[s];
            A.push_back(s);
            if (A.size() > n)
                break;
        }
        reverse(A.begin(), A.end());
        return A;
    }

    int query_negative_cycle() {
        return negative_cycle;
    }

    void dump_edge() {
        for (int i = 0; i < edge.size(); i++)
            cout << "edge[" << i << "]: (" << edge[i].s << ", " << edge[i].t  << ", " << edge[i].w << ")" << endl;
        for (int i = 0; i < E.size(); i++)
            cout << "E[" << i << "]: " << E[i] << endl;
    }

    void dump() {
        cout << "n: " << n << endl;
        cout << "src: " << src << endl;
        cout << "negative_cycle: " << negative_cycle << endl;
        for (int i = 0; i < vis.size(); i++)
            cout << "vis[" << i << "]: " << vis[i] << ", dist[" << i << "]: " << dist[i] << ", parent[" << i << "]: " << parent[i] << endl;
        for (int i = 0; i < n; i++)
            cout << "path[" << i << "]: " << query_route(i) << endl;
    }
};

WeightedGraph<long long> graph;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    vector<int> A, B, C, D;
    cin >> n;
    A.resize(n);
    B.resize(n);
    for (int i = 0; i < n; i++)
        cin >> A[i] >> B[i];
    C.resize(n);
    for (int i = 0; i < n; i++)
        cin >> C[i];
    D.resize(n);
    for (int i = 0; i < n; i++)
        cin >> D[i];
    /*
    cout << "n:"  << n << endl;
    cout << "A: " << A << endl;
    cout << "B: " << B << endl;
    cout << "C: " << C << endl;
    cout << "D; " << D << endl;
    */
    graph.init(n + 1);
    for (int i = 0; i < n; i++) {
        graph.add_directed_edge(0, i + 1, C[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long val = (0ll + D[i] + D[j]) * (abs(A[i] - A[j]) + abs(B[i] - B[j]));
            graph.add_directed_edge(i + 1, j + 1, val);
            graph.add_directed_edge(j + 1, i + 1, val);
        }
    }
    // graph.dump_edge();
    graph.source_prim(0);
    // graph.dump();
    long long weight = 0;
    vector<long long>& dist = graph.dist;
    vector<int>& parent = graph.parent;
    for (int i = 0; i <= n; i++)
        weight += dist[i];
    cout << weight << endl;
    vector<int> P;
    vector<pair<int,int>> E;
    for (int i = 1; i <= n; i++) {
        if (parent[i] == 0) {
            P.push_back(i);
        } else {
            E.emplace_back(i, parent[i]);
        }
    }
    cout << P.size() << endl;
    if (P.size())
        cout << P << endl;
    cout << E.size() << endl;
    for (auto e: E)
        cout << e.first << " " << e.second << endl;
    return 0;
}
