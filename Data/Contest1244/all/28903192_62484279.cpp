#include <bits/stdc++.h>

#pragma GCC optimize("O3")

#define f first
#define s second
#define p push
#define pb push_back
#define ll long long
#define ld long double

using namespace std;

const ll N = 2e5 + 2, inf = 1e18 + 10;

ll c[3][N], cn[N], now, ansa[N];
vector<int> a[N];

bool check(int u, int p){
    if(a[u].size() > 2)
        return false;
    bool f = true;
    for(int j = 0; j < a[u].size(); ++j)
        if(a[u][j] != p)
            f &= check(a[u][j], u);
    return f;
}

void dfs(int u, int pr){
    for(int v = 0; v < a[u].size(); ++v){
        if(a[u][v] != pr){
            int col = 3 - cn[u] - cn[pr];
            cn[a[u][v]] = col;
            now += c[col][a[u][v]];
            dfs(a[u][v], u);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < n; ++j)
            cin >> c[i][j];
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        a[u - 1].pb(v - 1);
        a[v - 1].pb(u - 1);
    }
    if(!check(0, -1)){
        cout << -1;
        return 0;
    }
    int root, rot;
    for(int i = 0; i < n; ++i)
        if(a[i].size() == 1){
            root = i;
            rot = a[i][0];
            break;
        }
    ll ans = inf;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if(i == j)
                continue;
            cn[root] = i;
            cn[rot] = j;
            now = c[i][root] + c[j][rot];
            dfs(rot, root);
            if(now < ans){
                ans = now;
                for(int q = 0; q < n; ++q)
                    ansa[q] = cn[q];
            }
        }
    }
    cout << ans << "\n";
    for(int i = 0; i < n; ++i)
        cout << ansa[i] + 1 << " ";
}
