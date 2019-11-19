
#include <bits/stdc++.h>

#define ln                '\n'
#define all(dat)           dat.begin(), dat.end()
#define loop(i, to)        for (int i = 0; i < to; ++i)
#define cont(i, to)        for (int i = 1; i <= to; ++i)
#define circ(i, fm, to)    for (int i = fm; i <= to; ++i)
#define foreach(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)

typedef long long          num;

using namespace std;

const int nsz = 2e3;
int n, x[nsz + 5], y[nsz + 5];
num c[nsz + 5], w[nsz + 5], ans;
vector<int> a;
vector< pair<int, int> > b;

struct edge {
    int u, v;
    num w;
    
    edge() {}
    
    edge(int u, int v, num w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
vector<edge> e;

struct union_find {
    int pr[nsz + 5];
    
    void inline init() {
        cont (u, n) {
            pr[u] = u;
        }
    }
    
    int qry(int u) {
        return pr[u] == u ? u : pr[u] = qry(pr[u]);
    }
    
    bool inline unite(int u, int v) {
        int pu = qry(u), pv = qry(v);
        if (pu == pv)  return 0;
        if (rand() & 1) {
            swap(pu, pv);
        }
        pr[pv] = pu;
        return 1;
    }
};
union_find uf;

bool inline cmp(edge a, edge b) {
    return a.w < b.w;
}

void inline kruskal() {
    sort(all(e), cmp);
    uf.init();
    loop (i, e.size()) {
        int u = e[i].u, v = e[i].v;
        num w = e[i].w;
        if (uf.unite(u, v)) {
            ans += w;
            if (!u || !v) {
                a.push_back(u | v);
            } else {
                b.push_back(make_pair(u, v));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    cont (i, n) {
        cin >> x[i] >> y[i];
    }
    cont (u, n) {
        cin >> c[u];
        e.push_back(edge(0, u, c[u]));
    }
    cont (u, n) {
        cin >> w[u];
    }
    cont (u, n) {
        cont (v, n) {
            if (u == v)  continue;
            num dis = abs(x[u] - x[v]) + abs(y[u] - y[v]);
            dis *= w[u] + w[v];
            e.push_back(edge(u, v, dis));
        }
    }
    kruskal();
    cout << ans << ln;
    sort(all(a));
    cout << a.size() << ln;
    loop (i, a.size()) {
        cout << a[i] << ' ';
    }
    cout << ln;
    cout << b.size() << ln;
    loop (i, b.size()) {
        cout << b[i].first << ' ' << b[i].second << ln;
    }
}