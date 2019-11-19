#include <bits/stdc++.h>
#define int long long
typedef long double ld;
using namespace std;
//#pragma GCC optimize("O3")

const int inf = 1e18;
const int mod = 1e9+7;
const ld eps = 1e-9;
const ld pi = atan2(0, -1);

///---Some Code---///
vector<map<int, int>> g;

int32_t main() {
//    freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    cout << fixed << setprecision(15);
//    srand(time(0));
    ///---------///

    int n, m;
    cin >> n >> m;

    g.assign(n, {});
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        g[u][v] = 1;
        g[v][u] = 1;
    }

    set<int> gr;
    for(int i = 1; i < n; ++i) {
        gr.insert(i);
    }

    int res = 0;
    queue<int> added;
    added.push(0);
    while(!gr.empty()) {
        if(added.empty()) {
            added.push(*gr.begin());
            gr.erase(gr.begin());
            res++;
        }

        while(!added.empty()) {
            int v = added.front();
            added.pop();

            set<int> to_erase;
            for(auto u : gr) {
                if(g[u][v]) continue;
                added.push(u);
                to_erase.insert(u);
            }

            for(auto u : to_erase)
                gr.erase(u);
        }
    }

    cout << res << "\n";

    ///---------///
    return 0;
}

/**

///---------///

///---------///

///---------///

///---------///

*/
