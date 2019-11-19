#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
#define pb push_back

typedef long long ll;
typedef pair<int,int> pi;
const int MAXN = (int)1e5+7;

int mark[MAXN];
vector<int> G[MAXN];
int deg[MAXN];
ll co[4][MAXN],ans;

ll dfs(int u,int fa,int now) {
    ll res = 0;
    mark[u] = now;
    res += co[now][u];
    int to;
    if (mark[fa] != 1 && mark[u] != 1) to = 1;
    if (mark[fa] != 2 && mark[u] != 2) to = 2;
    if (mark[fa] != 3 && mark[u] != 3) to = 3;

    for(int v:G[u]) {
        if (v == fa) continue;
        res += dfs(v,u,to);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ans = 1e18;
    int c1,c2;

    int N;
    cin >> N;
    rep(i,1,3) {
        rep(j,1,N) {
            cin >> co[i][j];
        }
    }
    int mx = 0;
    int u,v;
    rep(i,1,N-1) {
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
        deg[u] ++;
        deg[v] ++;
        mx = max(mx,deg[u]);
        mx = max(mx,deg[v]);
    }
    if (mx > 2) {
        cout << -1 << endl;
    }else {
        rep(i,1,3) {
            rep(j,1,3) {
                if (i==j) continue;
                mark[u] = i;
                mark[v] = j;
                ll res3 = co[i][u] + co[j][v];
                int now = 0;
                if (i != 1 && j != 1) now = 1;
                if (i != 2 && j != 2) now = 2;
                if (i != 3 && j != 3) now = 3;
                ll res1=0,res2=0;
                for(int vv:G[u]) {
                    if (vv==v) continue;
                    res1 = dfs(vv,u,now);
                }
                for(int vv:G[v]) {
                    if (vv==u) continue;
                    res2 = dfs(vv,v,now);
                }
                if (res1+res2+res3 < ans) {
                    ans = res1+res2+res3;
                    c1 = i;
                    c2 = j;
                }
            }
        }
        int i = c1,j = c2;
        mark[u] = i;
        mark[v] = j;
        ll res3 = co[i][u] + co[j][v];
        int now = 0;
        if (i != 1 && j != 1) now = 1;
        if (i != 2 && j != 2) now = 2;
        if (i != 3 && j != 3) now = 3;
        ll res1,res2;
        for(int vv:G[u]) {
            if (vv==v) continue;
            res1 = dfs(vv,u,now);
        }
        for(int vv:G[v]) {
            if (vv==u) continue;
            res2 = dfs(vv,v,now);
        }
        cout << ans << endl;
        rep(i,1,N) {
            cout << mark[i] << " ";
        }cout << endl;
    }
}
