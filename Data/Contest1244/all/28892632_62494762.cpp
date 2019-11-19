#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 100005
#define INF 1e18

ll cost[MAX][3];
ll deg[MAX];
vector<int> adj[MAX];
vector<int> order;
bool flag = true;
vector<int> level[3];
int which[MAX];

void dfs(int u, int par)
{
    int cnt = 0;
    for(int i=0; i<adj[u].size(); i++){
        int nxt = adj[u][i];
        if(nxt == par) continue;
        cnt++;
    }
    if(cnt > 1){
        flag = false;
        return;
    }
    order.push_back(u);
    for(int i=0; i<adj[u].size(); i++){
        int nxt = adj[u][i];
        if(nxt == par) continue;
        dfs(nxt, u);
    }
}

int main()
{
    memset(deg, 0, sizeof deg);
    int n;
    scanf("%d", &n);
    for(int i=0; i<3; i++){
        for(int j=1; j<=n; j++){
            scanf("%lld", &cost[j][i]);
        }
    }
    for(int i=1; i<n; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    int root = -1;
    for(int i=1; i<=n; i++){
        if(deg[i] == 1) root = i;
    }
    dfs(root, -1);
    if(flag == false){
        cout << -1;
        return 0;
    }
    for(int i=0; i<order.size(); i++){
        int mod = i%3;
        level[mod].push_back(order[i]);
    }
    ll ans = INF;
    vector<int> V = {0, 1, 2};
    vector<int> temp = V;
    vector<int> stock;
    while(true){
        ll cur = 0;
        for(int i=0; i<temp.size(); i++){
            int col = temp[i];
            for(int j=0; j<level[i].size(); j++){
                int node = level[i][j];
                cur += cost[node][col];
            }
        }
        if(cur < ans){
            ans = cur;
            stock = temp;
        }
        next_permutation(temp.begin(), temp.end());
        if(temp == V) break;
    }
    cout << ans << endl;
    for(int i=0; i<3; i++){
        int col = stock[i];
        col = col+1;
        for(int j=0; j<level[i].size(); j++){
            int node = level[i][j];
            which[node] = col;
        }
    }
    for(int i=1; i<=n; i++) cout << which[i] << " ";
}

