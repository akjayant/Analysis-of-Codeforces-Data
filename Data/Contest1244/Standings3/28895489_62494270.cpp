#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N = 2e5 + 5, MOD = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, c[4][N], deg[N], a[5], vis[N], col[N], cnt;
vector<int> adj[N];

void dfs(int nd){
    vis[nd] = a[cnt];
    cnt++;
    cnt %= 3;
    if(cnt == 0)    cnt = 3;
    for(auto u: adj[nd]){
        if(!vis[u]){
            dfs(u);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i = 1; i <= n; i++) cin>>c[1][i];
    for(int i = 1; i <= n; i++) cin>>c[2][i];
    for(int i = 1; i <= n; i++) cin>>c[3][i];

    for(int i = 1; i < n; i++){
        int u, v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
        deg[u]++;
        deg[v]++;
    }

    for(int i = 1; i <= n; i++){
        if(deg[i] >= 3){
            cout<<-1;
            return 0;
        }
    }
    int start = -1, next = -1, ans = LLONG_MAX;
    for(int i = 1; i <= n; i++){
        if(deg[i] == 1){
            start = i;
            break;
        }
    }
    next = adj[start][0];

    if((start == -1) or (next == -1)) assert(0);

    a[1] = 1, a[2] = 2, a[3] = 3;

    do{
        memset(vis, 0, sizeof(vis));
        vis[start] = a[1];//, vis[next] = a[2];
        cnt = 2;
        dfs(next);
        int tmp = 0;
        for(int i = 1; i <= n; i++){
            tmp += c[vis[i]][i];
            /*cout<<vis[i]<<" "<<i<<" ";
            cout<<c[vis[i]][i]<<" ";
            cout<<endl;*/
        }
        ans = min(ans, tmp);
        //for(int i = 1; i <= 3; i++) cout<<a[i]<<" ";
        //cout<<endl;
    }while(next_permutation(a + 1, a + 4));

    cout<<ans<<endl;

    a[1] = 1, a[2] = 2, a[3] = 3;
    do{
        memset(vis, 0, sizeof(vis));
        vis[start] = a[1];//, vis[next] = a[2];
        cnt = 2;
        dfs(next);
        int tmp = 0;
        for(int i = 1; i <= n; i++){
            tmp += c[vis[i]][i];
            /*cout<<vis[i]<<" "<<i<<" ";
            cout<<c[vis[i]][i]<<" ";
            cout<<endl;*/
        }
        if(tmp == ans){
            for(int i = 1; i <= n; i++) cout<<vis[i]<<" ";
            return 0;
        }
        //ans = min(ans, tmp);
        //for(int i = 1; i <= 3; i++) cout<<a[i]<<" ";
        //cout<<endl;
    }while(next_permutation(a + 1, a + 4));


    return 0;
}
