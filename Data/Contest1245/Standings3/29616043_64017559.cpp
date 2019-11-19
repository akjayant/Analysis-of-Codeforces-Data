/* Tuan Kkura */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define base 31
#define MOD 1e9+7
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORs(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, a, b) for(int i = a; i < b; i++)
#define __FOR(i, a, b, k) for(int i = a; i <= b; i+= k)
#define __REP(i, a, b, k) for(int i = a; i < b; i+= k)
#define pb push_back
#define _io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

typedef pair <int, int> ii;
typedef vector <ii> vii;
#define fi first
#define se second
#define mp make_pair
#define PROB "text"
#define MAXN 200005

struct edge{
    int u, v;
    ll val;
};

ii a[MAXN];

ll dist(int i, int j)
{
    return abs(a[i].fi - a[j].fi) + abs(a[i].se - a[j].se);
}

int parent[MAXN];
int Find_Set(int u)
{
    while(parent[u] >= 0)
        u = parent[u];
    return u;
}

void Union(int u, int v)
{
    int x = parent[u] + parent[v];
    if(parent[u] > parent[v])
    {
        parent[v] = x;
        parent[u] = v;
    }else{
        parent[u] = x;
        parent[v] = u;
    }
}

int c[MAXN], k[MAXN];

int main()
{
    _io
    int n; cin >> n;
    FOR(i, 1, n)
        cin >> a[i].fi >> a[i].se;
    vector <edge> edges;
    FOR(i, 1, n)
    {
        cin >> c[i];
        edges.pb({0, i, c[i]});
    }
    FOR(i, 1, n)
        cin >> k[i];
    FOR(i, 1, n)
        FOR(j, 1, n)
            edges.pb({i, j, 1LL*(k[i]+k[j])*dist(i, j)});
    FOR(i, 0, n)    parent[i] = -1;
    sort(edges.begin(), edges.end(), [](const edge &A, const edge &B)
         {
             return A.val < B.val;
         });
    ll res = 0;
    vector <int> v;
    vii e;
    REP(i, 0, edges.size())
    {
        int U = Find_Set(edges[i].u);
        int V = Find_Set(edges[i].v);
        if(U != V)
        {
            //cout << edges[i].u << ' ' << edges[i].v << '\n';
            Union(U, V);
            if(edges[i].u == 0)
                v.pb(edges[i].v);
            else e.pb(mp(edges[i].u, edges[i].v));
            res += edges[i].val;
        }
    }
    cout << res << '\n';
    cout << v.size() << '\n';
    for(int u : v)
        cout << u << ' ';
    cout << '\n';
    cout << e.size() << '\n';
    for(ii u : e)
        cout << u.fi << ' ' << u.se << '\n';
}
