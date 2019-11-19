#include<bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define forab(i, a, b) for (int i = (a); i <= (b); i++)
#define forba(i, b, a) for (int i = (b); i >= (a); i--)
#define mset(a, n) memset(a, n, sizeof(a))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define endl '\n'
#ifdef hat
#define fast
#define de(x) cout  << #x << '=' << x << ' '
#define dee(x) cout  << #x << '=' << x << endl
#else
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define de(x) ((void) 0)
#define dee(x) ((void) 0)
#endif
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int, int> pii;

const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;

vector<int> g[maxn];
int n;
int col[3][maxn];
int dep[maxn];
int vis[maxn];
vector<int> v[3];

void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    v[dep[u] % 3].pb(u);
    forn(i, sz(g[u]))
    {
        if(g[u][i] != fa)
        {
            dfs(g[u][i], u);
        }
    }
}

ll cal(int *a)
{
    ll ans = 0;
    forn(i, 3)
    {
        for(auto x : v[i])
        {
            ans += col[a[i]][x];
        }
    }
    return ans;
}

int main()
{
    fast;
    cin >> n;
    forn(j, 3)
    forab(i, 1, n)
    {
        cin >> col[j][i];
    }
    forn(i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int s;
    forab(i, 1, n)
    {
        if(sz(g[i]) > 2)
        {
            cout << -1 << endl;
            return 0;
        } else if(sz(g[i]) == 1) {
            s = i;
        }
    }
    dfs(s, -1);
    int tt[3] = {0, 1, 2};
    ll ans = 1e18;
    do{
        ll t = cal(tt);
        if(t < ans)
        {
            ans = t;
            forn(i, 3)
            for(auto x : v[i])
            {
                vis[x] = tt[i] + 1;
            }
        }
    }
    while(next_permutation(tt, tt + 3));
    cout << ans << endl;
    forab(i, 1, n)
    {
        cout << vis[i] << ' ';
    }
    cout << endl;
}