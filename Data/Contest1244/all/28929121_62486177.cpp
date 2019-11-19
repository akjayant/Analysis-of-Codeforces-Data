#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <tuple>
#include <map>
#include <queue>
using namespace std;
vector<vector<int>> c;
vector<vector<int>> g;
vector<bool> used;
vector<long long> summ(6, 0);
vector<int> color;
vector<vector<int>> pr({{1, 2, 3},
                        {1, 3, 2},
                        {2, 1, 3},
                        {2, 3, 1},
                        {3, 1, 2},
                        {3, 2, 1}});

void dfs(int v, int k){
    used[v] = true;
    for (int i = 0; i < 6; i++){
        summ[i] += c[pr[i][k % 3]][v];
    }
    for (auto u : g[v]){
        if (!used[u]){
            dfs(u, k + 1);
        }
    }
}


void get_color(int v, int k, int ind){
    used[v] = true;
    color[v] = pr[ind][k % 3];
    for (auto u : g[v]){
        if (!used[u]){
            get_color(u, k + 1, ind);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    g.resize(n + 1);
    used.resize(n + 1);
    c.resize(4, vector<int> (n + 1));
    for (int j = 1; j <= 3; j++) {
        for (int i = 1; i <= n; i++) {
            cin >> c[j][i];
        }
    }
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++){
        if (g[i].size() > 2){
            cout << -1;
            return 0;
        }
    }
    int st_v = 0;
    for (int i = 1; i <= n; i++){
        if (g[i].size() == 1){
            dfs(i, 0);
            st_v = i;
            break;
        }
    }
    long long minn = 1e18;
    int k = 0;
    for (int i = 0; i < 6; i++){
        if (minn > summ[i]) {
            k = i;
            minn = summ[i];
        }
    }
    cout << minn << "\n";
    color.resize(n + 1);
    used.clear();
    used.resize(n + 1, false);
    get_color(st_v, 0, k);
    for (int i = 1; i <= n; i++){
        cout << color[i] << " ";
    }
    return 0;
}