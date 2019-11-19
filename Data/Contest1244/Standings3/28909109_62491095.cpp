#include <bits/stdc++.h>

#define ll long long
ll MOD = 1000000007;

using namespace std;

vector<vector<int> > col(3, vector<int>(100005, 0));
vector<vector<int> > t(100005);

ll dfs(int node, int c, int p = -1, int pc = -1) {
    printf("%d, %d, %d, %d called", node, c, p, pc);
    cout << endl;
    ll ret = col[c][node];
    ll temp = LLONG_MAX;
    for (auto child : t[node]) {
        if (child == p) continue;

        for (int color = 0; color < 3; color++) {
            if (color == c || color == pc) continue;
            temp = min(temp, dfs(child, color, node, c));
        }
    }
    if (temp != LLONG_MAX)
        ret += temp;
    printf("%d, %d, %d, %d returned %lld", node, c, p, pc, ret);
    cout << endl;
    return ret;
}

void seq(int node, vector<int> &v, int p = -1) {
    v.push_back(node);
    for (auto child : t[node]) {
        if (child == p) continue;
        seq(child, v, node);
    }
    return;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> col[0][i];
    for (int i = 0; i < n; i++) cin >> col[1][i];
    for (int i = 0; i < n; i++) cin >> col[2][i];

    bool poss = true;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        t[u].push_back(v);
        t[v].push_back(u);
        if (t[u].size() > 2 || t[v].size() > 2) poss = false;
    }
    if (!poss)
        cout << -1;
    else {
        // find root
        int root;
        for (int i = 0; i < n; i++) {
            if (t[i].size() == 1) {
                root = i;
                break;
            }
        }
        // find the seq
        vector<int> s;
        vector<int> colors(n);
        seq(root, s);
        // for (int c : s) cout << c << " ";
        // cout << endl
        //      << endl;
        vector<int> perm = {0, 1, 2};
        ll ans = LLONG_MAX;
        for (int i = 0; i < 6; i++) {
            ll cost = 0;
            for (int j = 0; j < n; j++) {
                cost += col[perm[j % 3]][s[j]];
            }
            if (cost < ans) {
                ans = cost;
                for (int j = 0; j < n; j++) {
                    colors[s[j]] = perm[j % 3];
                }
            }
            next_permutation(perm.begin(), perm.end());
        }
        cout << ans << endl;
        for (int i = 0; i < n; i++) {
            cout << colors[i] + 1 << " ";
        }
    }
    return 0;
}