#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int father, vector<vector<int>>& ad, vector<int>& v) {
    v.push_back(node);
    for (int nghb : ad[node])
        if (nghb != father)
            dfs(nghb, node, ad, v);
}

int main() {
    int n; cin >> n;
    vector<vector<int>> ad(n + 1);

    vector<vector<int>> cost(n + 1, vector<int>(3));
    for (int j = 0; j < 3; j++)
        for (int i = 1; i <= n; i++)
            cin >> cost[i][j];

    for (int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        ad[x].push_back(y);
        ad[y].push_back(x);
    }

    int root = 0;
    for (int i = 1; i <= n; i++)
        if (ad[i].size() >= 3) {
            cout << "-1\n";
            return 0;
        }
        else if (ad[i].size() == 1)
            root = i;

    vector<int> v;
    dfs(root, 0, ad, v);

    int64_t sol = 1e18;
    int config[3];

    int perm[] = {0, 1, 2};
    do {
        int64_t sum = 0;
        for (int i = 0; i < n; i++)
            sum += cost[v[i]][perm[i % 3]];
        if (sum < sol) {
            sol = sum;
            config[0] = perm[0];
            config[1] = perm[1];
            config[2] = perm[2];
        }
    } while (next_permutation(perm, perm + 3));

    vector<int> color(n + 1);
    for (int i = 0; i < n; i++)
        color[v[i]] = config[i % 3] + 1;

    cout << sol << '\n';
    for (int i = 1; i <= n; i++)
        cout << color[i] << ' ';
    cout << '\n';
    return 0;
}
