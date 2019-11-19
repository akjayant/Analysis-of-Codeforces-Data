#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double

//#define int int64_t

typedef pair<int, int> II;
typedef pair<int, II> III;

const int INF = (1 << 30) - 1;
const long long oo = (1ll << 62) - 1;
const long double PI = 3.1415926535898;
///BEGIN CODE
const int N = 1000000 + 5;

int n, m;
vector<int> a[N], e[N];
int num[N], low[N], vt[N], dd[N];
int Time = 0, tpltm = 0;
stack<int> s;
vector<int> res1, res2;


void minimize(int &a, int b)
{
    if(a>b) a=b;
}

void dfs(int u)
{
    num[u] = low[u] = ++Time;
    s.push(u);
    for(int v: a[u])
    {
        if(num[v]==-2) continue;
        if(num[v] > 0)
        {
            minimize(low[u],num[v]);
        }
        else
        {
            dfs(v);
            minimize(low[u],low[v]);
        }
    }
    if(low[u] >= num[u])
    {
        tpltm += 1;
        int v;
        do{
            v = s.top();
            s.pop();
            vt[v] = tpltm;
            num[v] = -2;
        }
        while(v != u);
    }
}

void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        a[i].clear();
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        if(u == v) continue;
        a[u].pb(v);
    }
    Time = 0;
    tpltm = 0;
    while(s.size()) s.pop();
    for(int i = 1; i <= n; i++)
        num[i] = 0;
    for(int i = 1; i <= n; i++)
    {
        if(num[i]) continue;
        dfs(i);
    }

    if(tpltm <= 1)
    {
        cout << "No" << '\n';
        return;
    }

    for(int i = 1; i <= tpltm; i++)
        e[i].clear();
    for(int u = 1; u <= n; u++)
    {
        for(int v: a[u])
        {
            if(vt[u] == vt[v]) continue;
            e[vt[u]].pb(vt[v]);
        }
    }
    int gt = INF, dinh = 0;
    for(int i = 1; i <= tpltm; i++)
    {
        if(e[i].size() < gt)
        {
            gt = e[i].size();
            dinh = i;
        }
    }
    res1.clear();
    res2.clear();
    for(int i = 1; i <= n; i++)
    {
        if(vt[i] == dinh)
        {
            res1.pb(i);
        }
        else res2.pb(i);
    }
    if(res1.size() == 0 || res2.size() == 0)
    {
        cout << "No" << '\n';
        return;
    }
    cout << "Yes" << '\n';
    cout << res1.size() << " " << res2.size() << '\n';
    for(int i = 0; i < res1.size(); i++) cout << res1[i] << " ";
    cout << '\n';
    for(int i = 0; i < res2.size(); i++) cout << res2[i] << " ";
    cout << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
    solve();

}

/**
    Code by: Best_Nakroth 12TH.


*/
