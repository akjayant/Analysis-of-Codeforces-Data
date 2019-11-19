#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> x, y, c, k;

struct edge {
    int from;
    int to;
    long long cost;
};

vector<edge> prim() {
    vector<bool> used(n, false);
    auto compare = [](const edge &lhs, const edge &rhs){ return lhs.cost > rhs.cost; };
    priority_queue<edge, vector<edge>, decltype(compare)> que(compare);
    
    for(int i=0; i<n; ++i) que.push({-1, i, c[i]});

    vector<edge> edgelist;
    while(!que.empty()) {
        edge e = que.top(); que.pop();
        if(used[e.to]) continue;
        
        edgelist.push_back(e);
        used[e.to] = true;
        for(int v = 0; v < n; ++v){
            if(used[v]) continue;
            que.push({e.to, v, (k[e.to] + k[v]) * (abs(x[e.to] - x[v]) + abs(y[e.to] - y[v]))});
        }
    }

    return edgelist;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    x.resize(n); y.resize(n);
    c.resize(n); k.resize(n);
    for(int i=0; i<n; ++i) cin >> x[i] >> y[i];
    for(int i=0; i<n; ++i) cin >> c[i];
    for(int i=0; i<n; ++i) cin >> k[i];

    auto res = prim();
    long long sum = 0;
    for(edge tmp : res) sum += tmp.cost;
    cout << sum << '\n';

    int v = 0, e = 0;
    for(edge tmp : res) {
        if(tmp.from == -1) ++v;
        else ++e; 
    }

    cout << v << '\n';
    for(edge tmp : res) {
        if(tmp.from == -1) {
            cout << tmp.to + 1;
            --v;
            cout << (v > 0 ? ' ' : '\n');
        }
    }

    cout << e << '\n';
    for(edge tmp : res) {
        if(tmp.from != -1) cout << tmp.from + 1 << ' ' << tmp.to + 1 << '\n';
    }
}