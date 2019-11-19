#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
ll MAXN = 1e16;
vector<vector<ll>> c, g;
vector<vector<vector<ll>>> dp(3);
vector<ll> col;
void dfs(ll v, ll p)
{
    ll to = -1;
    for(int i = 0; i < g[v].size(); i++)
    {
        ll kek = g[v][i];
        if(kek != p)
        {
            dfs(kek, v);
            to = kek;
        }
    }


    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(i == j)
            {
                continue;
            }


            if(to == -1)
            {
                dp[i][j][v] = c[i][v];
                continue;
            }


            ll ans = 0;
            for(int k = 0; k < 3; k++)
            {
                if(k != i && k != j)
                {
                    ans = dp[j][k][to];
                }
            }


            ans += c[i][v];
            if(ans >= MAXN)
            {
                ans = MAXN;
            }

            dp[i][j][v] = ans;
        }
    }
}
void wrt(ll v, set<ll> cur, ll p)
{
    /*cout << v + 1 << endl;
    for(auto x = cur.begin(); x != cur.end(); x++)
    {
        cout << *x + 1 << ' ';
    }
    cout << endl << endl;*/
    ll to = -1;
    for(int i = 0; i < g[v].size(); i++)
    {
        ll kek = g[v][i];
        if(kek != p)
        {
            to = kek;
        }
    }
    if(to == -1)
    {
        return;
    }


    ll ind;
    ll mn = 1e18;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(cur.find(i) != cur.end() || i == j || j == col[v])
            {
                continue;
            }


            if(mn > dp[i][j][to])
            {
                mn = dp[i][j][to];
                ind = i;
            }


        }
    }


    col[to] = ind;
    set<ll> s;
    s.insert(col[v]);
    s.insert(ind);
    wrt(to, s, v);
}
int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    ll n;
    cin >> n;
    c.resize(3);
    g.resize(n);
    col.resize(n);
    for(int i = 0; i < 3; i++)
    {
        dp[i].resize(3);
        for(int j = 0; j < 3; j++)
        {
            dp[i][j].assign(n, MAXN);
        }
    }
    for(int i = 0; i < 3; i++)
    {
        c[i].resize(n);
        for(int j = 0; j < n; j++)
        {
            cin >> c[i][j];
        }
    }
    for(int i = 0; i < n - 1; i++)
    {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ll st;
    for(int i = 0; i < n; i++)
    {
        if(g[i].size() > 2)
        {
            cout << -1;
            return 0;
        }
        if(g[i].size() == 1)
        {
            st = i;
        }
    }


    dfs(st, -1);
    ll mn = 1e18;
    set<ll> cur;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(mn > dp[i][j][st] && dp[i][j][st] < MAXN)
            {
                mn = dp[i][j][st];
                cur.clear();
                cur.insert(i);
                col[st] = i;
            }
        }
    }
    cout << mn << endl;

    wrt(st, cur, -1);
    for(int i = 0; i < n; i++)
    {
        cout << col[i] + 1 << ' ';
    }
}
