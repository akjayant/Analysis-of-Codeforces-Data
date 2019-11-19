#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+5;

int n, deg[N], color[N];
ll c[3][N];
vector<int> adj[N];

ll calc(int s1, int s2, int cs1, int cs2) {
    ll res=c[cs1][s1]+c[cs2][s2];
    while (deg[s2]>1) {
        int nxt=-1;
        for (int v: adj[s2]) {
            if (v!=s1) nxt=v;
        }
        int nxc=3-cs1-cs2;
        s1=s2; s2=nxt;
        cs1=cs2; cs2=nxc;
        res+=c[cs2][s2];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin>>n;
    for (int i=0; i<3; ++i)
        for (int j=1; j<=n; ++j) cin>>c[i][j];
    for (int i=1; i<n; ++i) {
        int u,v; cin>>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        ++deg[u]; ++deg[v];
    }

    int start=-1;
    for (int i=1; i<=n; ++i) {
        if (deg[i]>2) {
            cout<<"-1";
            return 0;
        }
        if (deg[i]==1) start=i;
    }

    int s1=start, s2=adj[s1][0];
    ll res=1e18, cs1, cs2;
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            if (i!=j) {
                ll cres=calc(s1, s2, i, j);
                if (cres<res) {
                    res=cres;
                    cs1=i;
                    cs2=j;
                }
            }
        }
    }

    color[s1]=cs1;
    color[s2]=cs2;
    while (deg[s2]>1) {
        int nxt=-1;
        for (int v: adj[s2]) if (v!=s1) nxt=v;
        int nxc=3-cs1-cs2;
        s1=s2; s2=nxt;
        cs1=cs2; cs2=nxc;
        color[s2]=cs2;
    }

    cout<<res<<"\n";
    for (int i=1; i<=n; ++i) cout<<(color[i]+1)<<" ";
    return 0;
}