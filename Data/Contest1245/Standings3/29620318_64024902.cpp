#include "bits/stdc++.h"
#define REP(i, n) for(int i = 0; i < int(n); i++)
#define FOR(i,n,m) for(int i = int(n); i < int(m); i++)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 6;
const ll LLINF = 1e18 + 1;

// 最小全域木 O(ElogV)?
// verify : https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A
template<typename T>
struct Prim {
private:
    struct Edge{
        T cost;
        int to;
        bool operator>(const Edge e)const {
            return this->cost > e.cost;
        }
        bool operator<(const Edge e)const {
            return this->cost < e.cost;
        }
    };
    int V; // 頂点数
    vector<vector<Edge>> G;
public:
    vector<vector<int>> connected;
    Prim(int V) : V(V) {
        connected.resize(V);
        G.resize(V);
    }

    void add_edge(int from, int to, T weight) {
        G[from].push_back({weight,to});
        G[to].push_back({weight,from});
    }

    T build() {
        T res = 0;
        vector<bool> used(V, false);
        typedef pair<Edge,int> P;
        priority_queue<P, vector<P>, greater<P>> pq;
        for (const Edge &e : G[0]) {
            pq.push({e,0});
        }
        used[0] = true;
        while (!pq.empty()) {
            auto ee = pq.top(); pq.pop();
            auto e = ee.first;
            auto par = ee.second;//parent
            if (used[e.to]) continue;
            used[e.to] = true;
            connected[e.to].push_back(par);
            connected[par].push_back(e.to);
            res += e.cost;
            for (const Edge &u : G[e.to]) {
                if (used[u.to]) continue;
                pq.push({u,e.to});
            }
        }
        return res;
    }
};

int main() {
    int n;cin >> n;
    Prim<ll> G(n+1);
    vector<pair<int,int>> point(n);
    vector<ll> k(n);
    REP(i,n) {
        scanf("%d %d",&point[i].first,&point[i].second);
    }
    REP(i,n) {
        ll c;
        scanf("%lld",&c);
        G.add_edge(n,i,c);
    }
    REP(i,n) scanf("%lld",&k[i]);
    REP(i,n-1) {
        FOR(j,i+1,n) {
            G.add_edge(i,j,(k[i]+k[j])*(abs(point[i].first-point[j].first)+abs(point[i].second-point[j].second)));
        }
    }
    cout << G.build() << endl;
    cout << G.connected[n].size() << endl;
    REP(i,G.connected[n].size()) {
        cout << G.connected[n][i]+1 << " ";
    }
    cout << endl;
    ll cnt = 0;
    REP(i,n) {
        REP(j,G.connected[i].size()) {
            if (G.connected[i][j] < i) cnt++;
        }
    }
    cout << cnt << endl;
    REP(i,n) {
        REP(j,G.connected[i].size()) {
            if (G.connected[i][j] < i) {
                cout << G.connected[i][j]+1 << " " << i+1 << endl;
            }
        }
    }
    return 0;
}