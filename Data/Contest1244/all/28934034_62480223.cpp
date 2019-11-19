#include <bits/stdc++.h>
#define int long long
#define ld long double
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pii pair<int,int>
using namespace std;
int n, c[100005][3], a, b, visit[100005], poczatek, color[100005];
vector<int> g[100005], ord;
void dfs(int v)
{
    visit[v] = 1;
    ord.push_back(v);
    for(auto u : g[v])
    {
        if(!visit[u])
            dfs(u);
    }
}
int dp[100005][3][3][3];
int32_t main()
{
    //srand(chrono::steady_clock::now().time_since_epoch().count());
    cin >> n;
    for(int k = 0; k <= 2; k++)
        for(int i = 1; i <= n; i++)
            cin >> c[i][k];
    for(int i = 1; i < n; i++)
        cin >> a >> b,
            g[a].push_back(b),
            g[b].push_back(a);
    for(int i = 1; i <= n; i++)
    {
        if(g[i].size() > 2)
        {
            cout << -1;
            return 0;
        }
        if(g[i].size() == 1)
        {
            poczatek = i;
        }
    }
    dfs(poczatek);
    //cout << ord.size() << endl;
    for(int i = 1; i <= n; i++)
    {
        for(int x = 0; x < 3; x++)
            for(int y = 0; y < 3; y++)
                for(int z = 0; z < 3; z++)
                {
                    if(x == y || x == z || y == z)
                        continue;
                    dp[i][x][y][z] = dp[i - 1][z][x][y] + c[ord[i - 1]][z];
                }
    }
    int res = 1e18;
    for(int x = 0; x < 3; x++)
        for(int y = 0; y < 3; y++)
            for(int z = 0; z < 3; z++)
            {
                if(x == y || x == z || y == z)
                    continue;
                if(res > dp[n][x][y][z])
                    res = dp[n][x][y][z];
            }
    for(int x = 0; x < 3; x++)
        for(int y = 0; y < 3; y++)
            for(int z = 0; z < 3; z++)
            {
                if(x == y || x == z || y == z)
                    continue;
                if(res == dp[n][x][y][z])
                {
                    for(int i = n; i >= 1; i--)
                    {
                        int v = ord[i - 1];
                        if(i % 3 == n % 3)
                            color[v] = z + 1;
                        else if(i % 3 == ((n % 3) + 2) % 3)
                        {
                            color[v] = y + 1;
                        }
                        else
                            color[v] = x + 1;
                    }
                }
            }
    cout << res << "\n";
    for(int  i = 1; i <= n; i++)
        cout << color[i] << " ";
}
