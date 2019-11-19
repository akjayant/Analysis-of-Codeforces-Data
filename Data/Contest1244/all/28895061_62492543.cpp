#include <bits/stdc++.h>
#define Task "D"

using namespace std;
const int maxN = 1e5 + 5;
vector<int> adj[maxN];
long long n, c[maxN][4];
long long root, mH = 0, res[maxN];

void test(int u, int dad){
    for(int v : adj[u])
        if (v != dad){
            for(int c3 = 1; c3 <= 3; ++c3)
            if ((c3 != res[dad]) && (c3 != res[u])){
                res[v] = c3;
                test(v, u);
            }
        }
}

int main(){
    // freopen(Task".inp","r",stdin);
    // freopen(Task".out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i<=n; ++i) cin >> c[i][1];
    for(int i = 1; i<=n; ++i) cin >> c[i][2];
    for(int i = 1; i<=n; ++i) cin >> c[i][3];
    int u, v;
    for(int i = 1; i<n; ++i){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i<=n; ++i)
        if (adj[i].size() > 2){
            cout << -1;
            return 0;
        }
    for(int i = 1; i<=n; ++i)
        if (adj[i].size() == 1){
            root = i;
            break;
        }
    long long mincost = 1e18;
    pair<int,int> st = {0,0};
    for(int c1 = 1; c1 <= 3; ++c1){
        int v = adj[root][0];
        for(int c2 = 1; c2 <= 3; ++c2)
            if (c1 != c2){
                res[root] = c1; res[v] = c2;
                test(v, root);
                long long ans = 0;
                for(int i = 1; i<=n; ++i) ans += c[i][res[i]];
                if (ans < mincost){
                    mincost = ans;
                    st = {c1, c2};
                }
            }
    }
    cout << mincost << "\n";
    res[root] = st.first;
    res[adj[root][0]] = st.second;
    test(adj[root][0], root);
    for(int i = 1; i<=n; ++i) cout << res[i] << " ";

    return 0;
}
