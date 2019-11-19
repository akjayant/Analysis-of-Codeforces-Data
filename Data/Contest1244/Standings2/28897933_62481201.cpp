#include <bits\stdc++.h>

#define sc second
#define fr first
#define mk make_pair
#define pb push_back
#define int long long

using namespace std;

const int N = (1e6 + 5);
const int inf = (1e18 + 7);

int n;
int x,y;
int d[N];
int c[4][N];
int sz[N];
int res = inf;
int v;

vector <int> g[N];
vector <int> vv,vec;

void dfs (int v,int p = -1) {
    for (auto to : g[v]) if (to != p) sz[to] = sz[v] + 1,dfs(to,v);
}
main () {
    cin >> n;

    for (int i = 1; i <= n; i ++)
        cin >> c[1][i];

    for (int i = 1; i <= n; i ++)
        cin >> c[2][i];

    for (int i = 1; i <= n; i ++)
        cin >> c[3][i];

    for (int i = 1; i < n; i ++) {
        cin >> x >> y;
        d[x] ++;
        d[y] ++;
        if (d[x] > 2 || d[y] > 2) {
            puts("-1");
            return 0;
        }
        g[x].pb(y);
        g[y].pb(x);
    }
    for (int i = 1; i <= n; i ++) {
        if (d[i] == 1) v = i;
    }
    dfs(v);

    vec.pb(1);
    vec.pb(2);
    vec.pb(3);

    do {
        int ans = 0;
        for (int j = 1; j <= n; j ++) {
            if (sz[j] % 3 == 0) ans += c[vec[0]][j];
            if (sz[j] % 3 == 1) ans += c[vec[1]][j];
            if (sz[j] % 3 == 2) ans += c[vec[2]][j];
        }
        if (res > ans) {
            res = ans,vv = vec;
        }
    }while(next_permutation(vec.begin(),vec.end()));

    cout << res << endl;

    for (int j = 1; j <= n; j ++) {
        if (sz[j] % 3 == 0) cout << vv[0] << " ";
        if (sz[j] % 3 == 1) cout << vv[1] << " ";
        if (sz[j] % 3 == 2) cout << vv[2] << " ";
    }
}
