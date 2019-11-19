#include <bits/stdc++.h>
 
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
 
#define ll long long
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
#define en "\n"
#define FOR(i, j, n) for(int j = i; j < n; ++j)
#define forn(i, j, n) for(int j = i; j <= n; ++j)
#define nfor(i, j, n) for(int j = n; j >= i; --j)
#define sortv(vv) sort(vv.begin(), vv.end())
 
using namespace std;
const ll maxn=110000,inf=1e18,LOG=20,mod=998244353;

#define  int ll

int n, dp[maxn][4][4], c[maxn][4], col[maxn], deep[maxn], pos, a[maxn], uk;
vector <int> edge[maxn], vec;

void dfs(int v, int pred = 1)
{
    if(edge[v].size() > 2)
    {
        cout << -1;
        exit(0);
    }
    if(edge[v].size() <= 1)
    {
        pos = v;
    }
    FOR(0, i, edge[v].size())
    {
        int to = edge[v][i];
        if(to == pred) continue;
        dfs(to, v);
    }
}

void dfs2(int v, int pred = 0)
{
    a[++uk] = v;
    FOR(0, i, edge[v].size())
    {
        int to = edge[v][i];
        if(to == pred) continue;
        dfs2(to, v);
    }
}

main()
{
    IOS
    cin >> n;
    forn(1, i, n)
    {
        cin >> c[i][1];
    }
    forn(1, i, n)
    {
        cin >> c[i][2];
    }
    forn(1, i, n)
    {
        cin >> c[i][3];
    }
    forn(1, i, n - 1)
    {
        int l, r;
        cin >> l >> r;
        edge[l].pb(r);
        edge[r].pb(l);
    }
    dfs(1);
    dfs2(pos);
    dp[2][1][2] = c[a[1]][2] + c[a[2]][1];
    dp[2][1][3] = c[a[1]][3] + c[a[2]][1];
    dp[2][2][1] = c[a[1]][1] + c[a[2]][2];
    dp[2][2][3] = c[a[1]][3] + c[a[2]][2];
    dp[2][3][2] = c[a[1]][2] + c[a[2]][3];
    dp[2][3][1] = c[a[1]][1] + c[a[2]][3];
    forn(3, i, uk)
    {
        dp[i][1][2] = dp[i - 1][2][3] + c[a[i]][1];
        dp[i][1][3] = dp[i - 1][3][2] + c[a[i]][1];
        dp[i][2][1] = dp[i - 1][1][3] + c[a[i]][2];
        dp[i][2][3] = dp[i - 1][3][1] + c[a[i]][2];
        dp[i][3][1] = dp[i - 1][1][2] + c[a[i]][3];
        dp[i][3][2] = dp[i - 1][2][1] + c[a[i]][3];
    }
    int res = min({dp[uk][1][2],dp[uk][1][3],dp[uk][2][1],dp[uk][2][3],dp[uk][3][1],dp[uk][3][2]});
    if(res == dp[uk][1][2])
    {
        col[a[uk]] = 1;
        col[a[uk - 1]] = 2;
    }
    if(res == dp[uk][1][3])
    {
        col[a[uk]] = 1;
        col[a[uk - 1]] = 3;
    }
    if(res == dp[uk][2][1])
    {
        col[a[uk]] = 2;
        col[a[uk - 1]] = 1;
    }
    if(res == dp[uk][2][3])
    {
        col[a[uk]] = 2;
        col[a[uk - 1]] = 3;
    }
    if(res == dp[uk][3][1])
    {
        col[a[uk]] = 3;
        col[a[uk - 1]] = 1;
    }
    if(res == dp[uk][3][2])
    {
        col[a[uk]] = 3;
        col[a[uk - 1]] = 2;
    }
    nfor(1, i, uk - 2)
    {
        col[a[i]] = 6 - col[a[i + 1]] - col[a[i + 2]];
    }
    cout << res << endl;
    forn(1, i, n)
    {
        cout << col[i] << " ";
    }
}