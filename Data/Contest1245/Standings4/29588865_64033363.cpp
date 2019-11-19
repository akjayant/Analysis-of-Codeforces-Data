#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;

#define MAX_E 5000000

struct UnionFind{
    vector<int> par;
    vector<int> siz;

    UnionFind(int n){
        init(n);
    }

    void init(int n){
        par.resize(n);
        siz.resize(n);
        for(int i = 0; i < n; i++){
            par[i] = i;
            siz[i] = 1;
        }
    }

    int root(int x){
        if(par[x] == x) return x;
        else return par[x] = root(par[x]);
    }

    void unite(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
    }

    bool same(int x, int y){
        return root(x) == root(y);
    }

    int size(int x){
        return siz[root(x)];
    }
};

struct edge { int u, v; ll cost; };//辺の張り型 : es[i] = edge{u, v, cost}

bool comp(const edge& e1, const edge& e2){
    return e1.cost < e2.cost;//不等号を逆にすると、最大全域木を求められる,
}

edge es[MAX_E];
int V, E;
vector<int> ans1;
vector<P> ans2;

ll kruskal(){
    sort(es, es + E, comp);
    UnionFind uf(V);
    ll res = 0;
    for(int i = 0; i < E; i++){
        edge e = es[i];
        if(!uf.same(e.u, e.v)){
            int a = e.u, b = e.v;
            if(a > b){
                swap(a, b);
            }
            if(a == 0){
                ans1.push_back(b);
            }else{
                ans2.push_back(P(a, b));
            }
            uf.unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}

signed main(){
    int n;
    cin >> n;
    V = n + 1;
    int x[n],y[n];
    REP(i,n){
        cin >> x[i] >> y[i];
    }
    ll c,k[n];
    REP(i,n){
        cin >> c;
        es[E] = edge{0, i + 1, c};
        E++;
    }
    REP(i,n){
        cin >> k[i];
    }
    REP(i,n){
        for(int j = i + 1; j < n; j++){
            es[E] = edge{i + 1, j + 1, (abs(x[i] - x[j]) + abs(y[i] - y[j])) * (k[i] + k[j])};
            E++;
        }
    }
    cout << kruskal() << endl;
    cout << ans1.size() << endl;
    REP(i,ans1.size()){
        cout << ans1[i];
        if(i != ans1.size() - 1){
            cout << " ";
        }else{
            cout << endl;
        }
    }
    cout << ans2.size() << endl;
    REP(i,ans2.size()){
        cout << ans2[i].first << " " << ans2[i].second << endl;
    }
    return 0;
}