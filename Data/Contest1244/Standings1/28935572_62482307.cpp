#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define trav(a, b)   for(auto& a : (b))
#define debug(x)    clog << #x << " = " << x << endl;
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using ll = long long;
using ull = unsigned long long;

uint64_t dfs(int cur, int parent, vector<vector<int>> const &graph, vector<vector<uint64_t>> const &costs, int l, int r) {
    int color;
    for (int i = 0; i < 3; i++)if (i != l && i != r) color = i;
    uint64_t cost = costs[cur][color];
    trav(c, graph[cur]) {
        if (c != parent)
            cost += dfs(c, cur, graph, costs, r, color);
    }
    return cost;
}

void colorDfs(int cur, int parent, vector<vector<int>> const &graph, vector<int> &colors, int l, int r) {

    int color;
    for (int i = 0; i < 3; i++)if (i != l && i != r) color = i;
    colors[cur] = color;
    trav(c, graph[cur]) {
        if (c != parent)
            colorDfs(c, cur, graph, colors, r, color);
    }
}

int main(int argc, char *argv[]) {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);


    //content
    int n;
    cin >> n;
    vector<vector<uint64_t>> costs(n, vector<uint64_t>(3));
    vector<vector<int>> graph(n);
    for (int c = 0; c < 3; c++)
        for (int i = 0; i < n; i++) {
            cin >> costs[i][c];
        }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
        if (graph[u].size() >= 3 || graph[v].size() >= 3) {
            cout << "-1";
            return 0;
        }
    }
    int left = -1;
    for (int i = 0; i < n; i++) {
        if (graph[i].size() == 1) {
            left = i;
        }
    }
    int left2 = graph[left][0];
    int left3 = graph[left2][0] == left ? graph[left2][1] : graph[left2][0];
    auto best = make_pair(numeric_limits<uint64_t>::max(), make_pair(0, 0));
    for (int l = 0; l < 3; l++)
        for (int r = 0; r < 3; r++)
            if (l != r)
                best = min({dfs(left3, left2, graph, costs, l, r) + costs[left][l] + costs[left2][r], {l, r}}, best);
    cout << best.first << endl;
    vector<int> colors(n);
    colors[left] = best.second.first;
    colors[left2] = best.second.second;
    colorDfs(left3, left2, graph, colors, best.second.first, best.second.second);
    trav(a, colors) {
        cout << a + 1 << " ";
    }

    cout.flush();
    return 0;
}

