#include<bits/stdc++.h>

using namespace std;

using ll = long long int;
using vi = vector<int>;
#define f(n) for(int i = 0; i < n; i++)
#define fj(n) for(int j = 0; j < n; j++)
#define ci(n) cin >> n;
#define cn cout << "\n";
#define ic(n) int n; cin >> n;
#define lc(n) int n; cin >> n;
#define all(a) a.begin(), a.end()
#define pri(a, n) for(int i = 0; i < n; i++) cout << a[i] << " "; cout << "\n";
#define sc(a, n) int a[n] = {0}; for(int i = 0; i < n; i++) cin >> a[i];
#define scl(a, n) ll a[n] = {0}; for(int i = 0; i < n; i++) cin >> a[i];
#define pb push_back
#define eb emplace_back
#define int long long
const int maxn = 100000;
int c[maxn][3];
DFS(vector<int> g[], int v, int p, vector<int> &pth)
{
    pth.pb(v);
    for(int u : g[v])
    {
        if(u == p) continue;
        DFS(g, u, v, pth);
    }
}
main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ic(n)
    f(3) fj(n) cin >> c[j][i];
    vector<int> g[n];
    f(n - 1)
    {
        int u, v;
        cin >> v >> u;
        v--, u--;
        g[v].pb(u), g[u].pb(v);
    }
    int mni;
    f(n)
    {
        if(g[i].size() > 2)
        {
            cout << -1;
            return 0;
        }
        if(g[i].size() == 1) mni = i;
    }
    vector<int> path;
    DFS(g, mni, -1, path);
    vector<int> ansc(n);
    int ans = 4e18;
    f(3)
    {
        for(int j = 0; j < 3; j++)
        {
            if(j == i) continue;
            int cans = 0;
            vector<int> cac(n);
            cac[path[0]] = i, cac[path[1]] = j;
            cans += c[path[0]][i] + c[path[1]][j];
            for(int k = 2; k < n; k++)
            {
                cac[path[k]] = 3 - cac[path[k - 1]] - cac[path[k - 2]];
                cans += c[path[k]][cac[path[k]]];
            }
            if(cans < ans) ans = cans, ansc = cac;
        }
    }
    cout << ans << "\n";
    f(n) cout << ansc[i] + 1 << " ";
}
