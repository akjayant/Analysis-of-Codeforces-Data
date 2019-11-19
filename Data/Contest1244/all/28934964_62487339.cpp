#include <bits/stdc++.h>
#define int long long
typedef long double ld;
using namespace std;
//#pragma GCC optimize("O3")

const int inf = 1e18;
const int mod = 1e9+7;
const ld eps = 1e-8;
const ld pi = atan2(0, -1);

///---Some Code---///
vector<vector<int>> g;
vector<vector<int>> cost;
map<int, int> fwd;
map<int, int> inv;
vector<int> res;

int last = 0;
void dfs(int v, int p) {
    fwd[v] = last;
    inv[last] = v;
    last++;

    if(g[v].size() > 2) {
        cout << "-1\n";
        exit(0);
    }

    for(auto u : g[v])
        if(u != p) dfs(u, v);
}

int32_t main() {
//    freopen("sum.in", "r", stdin); freopen("sum.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    cout << fixed << setprecision(15);
//    srand(time(0));
    ///---------///

    int n;
    cin >> n;

    g.assign(n, {});
    cost.assign(n, vector<int> (3, 0));
    res.assign(n, 0);

    for(int i = 0; i < n; ++i)
        cin >> cost[i][0];
    for(int i = 0; i < n; ++i)
        cin >> cost[i][1];
    for(int i = 0; i < n; ++i)
        cin >> cost[i][2];

    for(int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 0; i < n; ++i) {
        if(g[i].size() == 1) {
            dfs(i, -1);
            break;
        }
    }

    int ans = inf, cur = 0;
    vector<int> clr = {0, 1, 2};

    do {
        cur = 0;
        for(int i = 0; i < n; ++i)
            cur += cost[inv[i]][clr[i % 3]];

        if(cur < ans) {
//            for(int i = 0; i < 3; ++i)
//                cout << clr[i];
//            cout << "\n";

            ans = cur;
            for(int i = 0; i < n; ++i)
                res[inv[i]] = clr[i % 3];
        }

    } while(next_permutation(clr.begin(), clr.end()));

    ///ANS
    cout << ans << "\n";
    for(int i = 0; i < n; ++i)
        cout << res[i]+1 << " ";
    cout << "\n";

    ///---------///
    return 0;
}

/**
3
3 2 3
4 3 2
3 1 3
1 2
2 3

///---------///

///---------///

///---------///

///---------///

*/
