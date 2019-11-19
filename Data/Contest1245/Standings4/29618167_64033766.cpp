#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 4000006;
ll kk[N], cc[N];
struct DSU{
    vector<int> par, size, cst, srcst;
    int CC;
    DSU(int n){
        CC = n;
        par.resize(n+1);
        size.assign(n+1, 1);
        iota(par.begin(), par.end(), 0);
        cst.resize(n+1);
        srcst.resize(n+1);
        iota(srcst.begin(), srcst.end(), 0);
        for(int i=0; i<n; i++){
            cst[i] = cc[i];
        }
    }
    int root(int a){
        return par[a] == a ? a: par[a] = root(par[a]);
    }
    int unite(int a,int b){
        a = root(a);
        b = root(b);
        if(a == b) return 0;
        if(size[a] < size[b]) swap(a,b);

        int c, s, oc;
        if(cst[a] < cst[b]) oc = cst[b], c = cst[a], s = srcst[a];
        else oc = cst[a], c = cst[b], s = srcst[b];

        par[b] = a;
        size[a] += size[b];
        cst[a] = c;
        srcst[a] = s;
        --CC;
        return oc;
    }
    bool same(int a,int b){
        return root(a) == root(b);
    }
};

int main() {
    int n;
    scanf("%d", &n);
    vector< pair<int, int> > vp(n);
    for(int i=0; i<n; i++)
        scanf("%d %d", &vp[i].first, &vp[i].second);

    long long res = 0;
    int best = 0;
    for(int i=0; i<n; i++) {
        scanf("%lld", cc + i);
        res += cc[i];
    }
    for(int i=0; i<n; i++)
        scanf("%lld", kk + i);


    DSU dsu(n);

    vector< pair<ll, pair<int, int> > > edgelist;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            ll cur =1ll * (abs(vp[i].first - vp[j].first) + abs(vp[i].second - vp[j].second)) * (kk[i] + kk[j]);
            edgelist.push_back({cur, {i, j}});
        }
    }
    long long cur = res;
    sort(edgelist.begin(), edgelist.end());
    vector<pair<int, int> > eds;
    for(int i=0; i<edgelist.size(); i++){
        int a = dsu.root(edgelist[i].second.first);
        int b = dsu.root(edgelist[i].second.second);
        if(a == b) continue;

        if(edgelist[i].first > dsu.cst[a] && edgelist[i].first > dsu.cst[b])
            continue;
        cur -= dsu.unite(a, b);
        cur += edgelist[i].first;
        eds.push_back({edgelist[i].second.first+1, edgelist[i].second.second+1});
        if(cur < res){
            res = cur;
            best = eds.size();
        }
    }
    printf("%lld\n", res);
    printf("%d\n", dsu.CC);
    for(int i=0; i<n; i++){
        if(dsu.par[i] == i)
            printf("%d ", dsu.srcst[i] + 1);
    }
    puts("");
    printf("%d\n", best);
    for(int i=0; i<best; i++){
        printf("%d %d\n", eds[i].first, eds[i].second);
    }
    return 0;
}
