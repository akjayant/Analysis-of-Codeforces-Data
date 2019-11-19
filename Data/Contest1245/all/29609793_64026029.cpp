#include <bits/stdc++.h>
using namespace std;

#define sc(x) scanf("%d",&x);
#define rep(x ,n) for(int x=0; x<n; x++)
#define ll long long
#define finish(x) return cout << x << endl,0;
#define scarr(a,n) for(int x=0; x<n; x++)scanf("%d",&a[x]);

#define MAX_N 2003

int par[MAX_N] ,mi[MAX_N] ,mi_idx[MAX_N];
int fnd(int u){
    return par[u] = par[u] == u ? u : fnd(par[u]);
}

int n;
int x[MAX_N] ,y[MAX_N];
int c[MAX_N] ,k[MAX_N];
long long wire[MAX_N][MAX_N];

int main()
{
    sc(n)
    for(int i=0; i<n; i++){
        sc(x[i])sc(y[i])}
    long long ans = 0LL;
    for(int i=0; i<n; i++){
        sc(c[i])
        ans += c[i];
        mi[i] = c[i] ,par[i] = i ,mi_idx[i] = i;
    }
    for(int i=0; i<n; i++)
        sc(k[i])

    vector <pair<long long ,pair<int ,int>>> edgs;
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
        edgs.push_back({1LL*(abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]) ,{i ,j}});

    sort(edgs.begin() ,edgs.end());

    vector <pair<int ,int>> ans_eds;
    int inv = n;
    for(auto&e : edgs){
        long long we = e.first;
        int u = e.second.first ,v = e.second.second;

        int fu = fnd(u) ,fv = fnd(v);
        if(fu == fv) continue;

        if(max(mi[fu] ,mi[fv]) > we){
            ans += we - max(mi[fu] ,mi[fv]);
            par[fu] = fv;
            if(mi[fu] < mi[fv])
                mi_idx[fv] = mi_idx[fu] ,mi[fv] = mi[fu];
            ans_eds.push_back({u+1 ,v+1});
            inv--;
        }
    }

    printf("%I64d\n",ans);
    printf("%d\n",inv);
    for(int i=0; i<n; i++)
        if(i == fnd(i))
            printf("%d\n",mi_idx[i]+1);
    printf("%d\n",ans_eds.size());
    for(auto&p : ans_eds)
        printf("%d %d\n",p.first ,p.second);
}