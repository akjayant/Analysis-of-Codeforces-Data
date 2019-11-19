#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b) do { cout << "["; for (int count = (a);count < (b);++count) cout << ary[count] << ((b)-1 == count ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

struct UnionFind {
private:
    vector<int> par,sizes;
public:
    UnionFind (int n) {
        par.resize(n);
        sizes = vector<int>(n,1);
        for (int i = 0;i < n;++i) par[i] = i;
    }

    int find(int x) {
        if (par[x] == x) return x;
        else return par[x] = find(par[x]);
    }

    void unite(int x,int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (sizes[x] < sizes[y]) swap(x,y);
        par[y] = x;
        sizes[x] += sizes[y];
    }

    bool same(int x,int y) {
        return find(x) == find(y);
    }

    int size(int x) {
        return sizes[find(x)];
    }
};

struct edge {
    int s,t;
    ll c;
    bool operator<(const edge& a) const {
        return c < a.c;
    }
};
int main() {
    int n;
    cin >> n;
    vector<ll> x(n),y(n);
    vector<ll> c(n),k(n);
    vector<edge> a;
    UnionFind uf(2000);
    for (int i = 0;i < n;++i) scanf("%d%d",&x[i],&y[i]);
    for (int i = 0;i < n;++i) scanf("%lld",&c[i]);
    for (int i = 0;i < n;++i) scanf("%lld",&k[i]);
    for (int i = 0;i < n;++i) a.push_back(edge{i,i,c[i]});
    for (int i = 0;i < n;++i) for (int j = i+1;j < n;++j) a.push_back(edge{i,j,(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]))});
    sort(a.begin(),a.end());
    int m = a.size();
    ll sum = 0;
    vector<int> ans1;
    vector<P> ans2;
    vector<bool> b(n,false);
    for (int i = 0;i < m;++i) {
        if (uf.same(a[i].s,a[i].t) && a[i].s != a[i].t) continue;
        if (b[uf.find(a[i].s)] && b[uf.find(a[i].t)]) continue;
        if (a[i].s == a[i].t) {
            ans1.push_back(a[i].s);
            b[uf.find(a[i].s)] = true;
        }
        else ans2.push_back(P(a[i].s,a[i].t));
        sum += a[i].c;
        b[uf.find(a[i].s)] = (b[uf.find(a[i].s)] || b[uf.find(a[i].t)]);
        b[uf.find(a[i].t)] = b[uf.find(a[i].s)];
        uf.unite(a[i].s,a[i].t);
    }
    cout << sum << endl;
    int s1 = ans1.size(),s2 = ans2.size();
    cout << s1 << endl;
    sort(ans1.begin(),ans1.end());
    for (int i = 0;i < s1;++i) cout << ans1[i]+1 << " \n"[i == s1-1];
    cout << s2 << endl;
    for (int i = 0;i < s2;++i) cout << ans2[i].first+1 << " " << ans2[i].second+1 << "\n";
}