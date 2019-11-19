#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100000;
vector<int> g[MAX_N];
bool used[MAX_N];
int cost_color[MAX_N][3];
vector<int> path;

void dfs(int v){
    if(used[v])
        return;
    used[v] = true;
    path.push_back(v);
    for(int w : g[v])
        dfs(w);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int c = 0; c < 3; c++){
        for(int i = 0; i < n; i++)
            cin >> cost_color[i][c];
    }
    if(n == 1){
        cout << min(min(cost_color[0][0], cost_color[0][1]), cost_color[0][2]);
        return 0;
    }
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 0; i < n; i++){
        if(g[i].size() >= 3){
            cout << -1;
            return 0;
        }
    }
    for(int i = 0; i < n; i++){
        if(g[i].size() == 1){
            dfs(i);
            break;
        }
    }
    long long min_cost = 1e18;
    int good_c1, good_c2;
    for(int c1 = 0; c1 < 3; c1++){
        for(int c2 = 0; c2 < 3; c2++){
            if(c1 == c2)
                continue;
            long long cur_cost = 0;
            int cur_c1 = c1, cur_c2 = c2;
            cur_cost = cost_color[path[0]][c1] + cost_color[path[1]][c2];
            for(int i = 2; i < n; i++){
                int new_c = (0 + 1 + 2) - cur_c1 - cur_c2;
                cur_cost += cost_color[path[i]][new_c];
                cur_c1 = cur_c2;
                cur_c2 = new_c;
            }
            if(cur_cost < min_cost){
                min_cost = cur_cost;
                good_c1 = c1; good_c2 = c2;
            }
        }
    }
    cout << min_cost << "\n";
    int colors[n];
    int cur_c1 = good_c1, cur_c2 = good_c2;
    colors[path[0]] = cur_c1; colors[path[1]] = cur_c2;
    for(int i = 2; i < n; i++){
        int new_c = (0 + 1 + 2) - cur_c1 - cur_c2;
        colors[path[i]] = new_c;
        cur_c1 = cur_c2;
        cur_c2 = new_c;
    }
    for(int i = 0; i < n; i++)
        cout << colors[i] + 1 << " ";
    return 0;
}
