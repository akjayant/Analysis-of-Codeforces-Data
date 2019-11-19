#include <bits/stdc++.h>
#define int long long

using namespace std;

const int k = 3, inf = 4e18;

int dfs(int v, int p, int ind, const vector<vector<int>>& adjList, const vector<vector<int>>& cost, const vector<int>& color) {
    int ans = cost[v][color[ind]];
    for (int to : adjList[v])
        if (to != p)
            ans += dfs(to, v, (ind + 1) % 3, adjList, cost, color);
    return ans;
}

void dfs_ans(int v, int p, int ind, const vector<vector<int>>& adjList, vector<int>& ans, const vector<int>& color) {
    ans[v] = color[ind];
    for (int to : adjList[v])
        if (to != p)
            dfs_ans(to, v, (ind + 1) % 3, adjList, ans, color);
}

int32_t main() {
    int n;
    cin >> n;
    vector<vector<int>> cost(n, vector<int>(k));
    for (int j = 0; j < k; ++j)
        for (int i = 0; i < n; ++i)
            cin >> cost[i][j];
    vector<vector<int>> adjList(n);
    for (int i = 1; i < n; ++i) {
        int v, u;
        cin >> v >> u;
        adjList[v - 1].push_back(u - 1);
        adjList[u - 1].push_back(v - 1);
    }
    int s = 0;
    for (int i = 0; i < n; ++i) {
        if (adjList[i].size() > 2) {
            cout << -1;
            return 0;
        }
        if (adjList[i].size() == 1)
            s = i;
    }
    int sum = inf;
    vector<int> best;
    vector<int> color = {0, 1, 2};
    do {
        int new_sum = dfs(s, -1, 0, adjList, cost, color);
        if (sum > new_sum) {
            sum = new_sum;
            best = color;
        }
    } while (next_permutation(color.begin(), color.end()));
    cout << sum << "\n";
    vector<int> ans(n);
    dfs_ans(s, -1, 0, adjList, ans, best);
    for (int e : ans)
        cout << e + 1 << " ";
}
