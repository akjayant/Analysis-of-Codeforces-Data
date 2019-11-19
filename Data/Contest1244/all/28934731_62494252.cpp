/// Radoslaw Mysliwiec 2019
#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB emplace_back
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;

constexpr ll INF = 1e17 + 1;

int n;
int dp[100100][10];
ll cost[100100][10];
ll res[6];
vi adj[100100];
vi mozliwosci[6] = {{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}};
int start;
bool vis[100100];

void dfs(int s){
    if(vis[s]) return;
    vis[s] = true;
    if (adj[s].size() == 1)
        start = s;

    for (auto u: adj[s])
        dfs(u);
}

void dfs_tree(int V, int pV, int stage, int stage2){
    dp[V][stage] = mozliwosci[stage][stage2 % 3];
    for (auto u: adj[V]){
        if (u == pV) continue;
        dfs_tree(u,V,stage,stage2+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; ++i)
        cin >> cost[i][1];
    for (int i=1; i<=n; ++i)
        cin >> cost[i][2];
    for (int i=1; i<=n; ++i)
        cin >> cost[i][3];
    int a, b;
    for (int i=1; i<n; ++i){
        cin >> a >> b;
        adj[a].PB(b);
        adj[b].PB(a);
    }
    for (int i=1; i<=n; ++i){
        if (adj[i].size() > 2){
            cout << -1 << endl;
            return 0;
        }
    }

    dfs(1);

    for (int i=0; i<6; ++i)
        dfs_tree(start,0,i,0);

    for (int x=1; x<=n; ++x)
    for (int i=0; i<6; ++i){
        res[i] += cost[x][dp[x][i]];
    }
    pll wynik = {1e17,0};
    for (int i=0; i<6; ++i){
        if (res[i] < wynik.F){
            wynik.F = res[i];
            wynik.S = i;
        }
    }
    cout << wynik.F << endl;
    for (int i=1; i<=n; ++i)
        cout << dp[i][wynik.S] << ' ';
}
