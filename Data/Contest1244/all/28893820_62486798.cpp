#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 1e5+10;

int n, ini1, ini2, cost[3][maxn], color[6][maxn], aux, ans = 1000000000000000000, id, ansid, deg[maxn];

vector<int> grafo[maxn];

bool ok = true;

void dfs(int u, int p, int last1, int last2){
    aux += cost[3-last1-last2][u];
    color[id][u] = 3-last1-last2;
    for(int i=0; i<grafo[u].size(); i++){
        int v = grafo[u][i];
        if(v==p) continue;
        dfs(v, u, 3-last1-last2, last1);
    }
}

main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> n;

    for(int j=0; j<3; j++){
        for(int i=1; i<=n; i++){
            cin >> cost[j][i];
        }
    }

    for(int i=1; i<n; i++){
        int a, b;

        cin >> a >> b;

        ini1=a, ini2=b;

        grafo[a].push_back(b);
        grafo[b].push_back(a);

        deg[a]++;
        deg[b]++;

        if(deg[a]>2 or deg[b]>2) ok = false;
    }

    if(!ok){
        cout << -1 << endl;
        return 0;
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i==j)continue;
            aux = 0;
            aux += cost[i][ini1];
            aux += cost[j][ini2];
            color[id][ini1] = i;
            color[id][ini2] = j;
            for(int k=0; k<grafo[ini1].size(); k++){
                int v = grafo[ini1][k];
                if(v!=ini2) dfs(v, ini1, i, j);
            }
            for(int k=0; k<grafo[ini2].size(); k++){
                int v = grafo[ini2][k];
                if(v!=ini1) dfs(v, ini2, j, i);
            }
            if(ans>aux){
                ans = aux;
                ansid = id;
            }
            id++;
        }
    }

    cout << ans << endl;

    for(int i=1; i<=n; i++){
        cout << color[ansid][i]+1 << " ";
    }

    return 0;
}
