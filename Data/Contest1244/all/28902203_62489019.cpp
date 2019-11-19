#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 1e5 + 10, inf = 1e18;
vector<ll> adj[N], ver;
ll c[3][N] , ans[N], tmp[N];

void dfs(ll root, ll par) {
    ver.push_back(root);
    for (ll i = 0; i < adj[root].size(); i++) {
        ll u = adj[root][i];
        if (u != par)
            dfs(u, root);
    }
}

ll findAns(ll a[]) {
    ll res = 0;
    for (ll i = 0; i < ver.size(); i++) {
        tmp[ver[i]] = a[i % 3];
        res += c[a[i % 3]][ver[i]];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n, u, v;
    cin >> n;
    for (ll i = 0; i < 3; i++)
        for (ll j = 0; j < n; j++)
            cin >> c[i][j];
    for (ll i = 1; i < n; i++) {
        cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    bool ok = true;
    for (ll i = 0; i < n; i++)
        if (adj[i].size() > 2)
            ok = false;
    if (ok) {   
        for (ll i = 0; i < n; i++)
            if (adj[i].size() == 1) {
                dfs(i, -1);
                break;
            }
        ll arr[] = {0, 1, 2}, ans1 = inf;
        for (ll i = 0; i < 6; i++) {
            ll sum = findAns(arr);
            if (sum < ans1) {
                ans1 = sum;
                for (ll i = 0; i < n; i++)
                    ans[i] = tmp[i];
            }
            next_permutation(arr, arr + 3);
        }
        cout << ans1 << "\n";
        for (ll i = 0; i < n; i++)
            cout << ans[i] + 1 << " ";
        cout << "\n";
    }
    else
        cout << "-1\n";
    return 0;
}