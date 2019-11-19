#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

ll inf = 1e18;
int mod = 1e9 + 7;

signed main()
{
    //freopen("IN.txt", "r", stdin);
    //freopen("OUT.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    ll c[3][N];
    for(int i = 0; i < 3; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }

    vector<int> graph[N];

    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int color[n + 1];
    memset(color, -1, sizeof(color));
    ll cost = 0;
    int par[n + 1];
    par[1] = 0;

    function<bool(int,int)> dfs = [&](int cur, int prev) {
        par[cur] = prev;
        bool marked[3];
        for(int i = 0; i < 3; i++) {
            marked[i] = false;
        }
        marked[color[prev]] = true;
        marked[color[par[prev]]] = true;
        int x = 0;
        for(int i = 0; i < 3; i++) {
            if(!marked[i]) {
                x = i;
                break;
            }
        }
        color[cur] = x;
        cost += c[x][cur];
        int cnt = 0;
        for(int u : graph[cur]) {
            if(u != prev) {
                cnt++;
            }
        }
        if(cnt > 1) {
            return false;
        }
        for(int u : graph[cur]) {
            if(u != prev) {
                if(!dfs(u, cur)) {
                    return false;
                }
            }
        }
        return true;
    };

    ll mini = inf;
    int c1, c2, c3;

    for(int i = 0; i < 3; i++) {
        color[1] = i;
        if((int)graph[1].size() > 2) {
            cout << "-1\n";
            return 0;
        }
        int u = graph[1][0];

        for(int j = 0; j < 3; j++) {
            if(j == i) {
                continue;
            }
            cost = c[i][1];
            int T;
            for(int k = 0; k < 3; k++) {
                if(k != i && k != j) {
                    T = k;
                    break;
                }
            }
            bool key = true;
            color[0] = T;
            if(!dfs(u, 1)) {
                key = false;
            }
            if((int)graph[1].size() > 1) {
                color[0] = j;
                if(!dfs(graph[1][1], 1)) {
                    key = false;
                }
            }
            if(!key) {
                cout << "-1\n";
                return 0;
            }
            if(mini > cost) {
                mini = cost;
                c1 = i; c2 = j, c3 = T;
            }
        }
    }

    color[1] = c1;
    color[0] = c3;
    dfs(graph[1][0], 1);

    if((int)graph[1].size() > 1) {
        color[0] = c2;
        dfs(graph[1][1], 1);
    }

    cout << mini << "\n";
    for(int i = 1; i <= n; i++) {
        cout << color[i] + 1 << " ";
    }
    cout << "\n";

    return 0;
}
