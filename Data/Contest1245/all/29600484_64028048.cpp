#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double

#define int int64_t

typedef pair<int, int> II;
typedef pair<int, II> III;

const int INF = (1 << 30) - 1;
const long long oo = (1ll << 62) - 1;
const long double PI = 3.1415926535898;
///BEGIN CODE
const int N = 2000 + 5;

int n;
II td[N];
int c[N], k[N];
vector<III> e;
vector<III> a;
int par[N];

int finds(int u)
{
    return par[u] < 0 ? u : finds(par[u]);
}
bool job(int u, int v)
{
    u = finds(u);
    v = finds(v);
    if(u == v) return false;
    if(par[u] > par[v]) swap(u, v);
    par[u] += par[v];
    par[v] = u;
    return true;
}
int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> td[i].fi >> td[i].se;
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    for(int i = 1; i <= n; i++)
        cin >> k[i];

    for(int i = 0; i <= n; i++)
        par[i] = -1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            e.pb(mp((k[i] + k[j]) * (abs(td[j].fi - td[i].fi) + abs(td[i].se - td[j].se)), mp(i, j)));
        }
    }
    for(int i = 1; i <= n; i++)
    {
        e.pb(mp(c[i], mp(0, i)));
    }
    int res = 0;
    sort(e.begin(), e.end());
    vector<int> res1;
    for(int i = 0; i < e.size(); i++)
    {
        if(job(e[i].se.fi, e[i].se.se))
        {
            res += e[i].fi;
            if(e[i].se.fi == 0) res1.pb(e[i].se.se);
            if(e[i].se.se == 0) res1.pb(e[i].se.fi);
            if(e[i].se.fi && e[i].se.se) a.pb(e[i]);
        }
    }
    cout << res << '\n';
    cout << res1.size() << '\n';
    for(int i = 0; i < res1.size(); i++)
        cout << res1[i] << " ";
    cout << '\n';
    cout << a.size() << '\n';
    for(int i = 0; i < a.size(); i++)
        cout << a[i].se.fi << " " << a[i].se.se << '\n';


}

/**
    Code by: Best_Nakroth 12TH.


*/
