#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 100009;
ll n, m, x, y, z;
ll deg[maxn];
ll cst[4][maxn];
vector < ll > edges[maxn];

ll clr[maxn];

ll dfs(ll pos, ll par, ll prv1, ll prv2)
{
    ll xx[4];
    memset(xx, 0, sizeof(xx));
    xx[prv1] = xx[prv2] = 1;
    ll cur = -1;
    for(ll i = 1; i <= 3; i++) if(xx[i] == 0) cur = i;

    if(cur == -1) assert(false);

    ll re = cst[cur][pos];
    for(ll to : edges[pos]){
        if(par == to) continue;
        re += dfs(to, pos, cur, prv1);
    }

    return re;

}

void dfs2(ll pos, ll par, ll prv1, ll prv2)
{
    ll xx[4];
    memset(xx, 0, sizeof(xx));
    xx[prv1] = xx[prv2] = 1;
    ll cur = -1;
    for(ll i = 1; i <= 3; i++) if(xx[i] == 0) cur = i;

    clr[pos] = cur;
    for(ll to : edges[pos]){
        if(to == par) continue;
        dfs2(to, pos, cur, prv1);
    }
}

int main()
{
    cin >> n;
    for(ll j = 1; j <= 3; j++) for(ll i = 1; i <= n; i++) scanf("%lld", &cst[j][i]);

    bool flg = false;

    for(ll i = 1; i < n; i++){
        ll x, y;
        scanf("%lld %lld", &x, &y);
        deg[x]++;
        deg[y]++;
        if(deg[x] == 3 || deg[y] == 3) flg = true;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    if(flg){
        cout << -1 << endl;
        return 0;
    }

    ll xx = -1;
    for(ll i = 1; i <= n; i++){
        if(deg[i] == 2) continue;
        if(deg[i] == 1) xx = i;
    }

    ll anss1 = dfs(xx, 0, 1, 2);
    ll anss2 = dfs(xx, 0, 2, 1);
    ll anss3 = dfs(xx, 0, 2, 3);
    ll anss4 = dfs(xx, 0, 3, 2);
    ll anss5 = dfs(xx, 0, 1, 3);
    ll anss6 = dfs(xx, 0, 3, 1);


    ll anss = min({anss1, anss2, anss3, anss4, anss5, anss6});
    printf("%lld\n", anss);

    if(anss == anss1) dfs2(xx, 0, 1, 2);
    if(anss == anss2) dfs2(xx, 0, 2, 1);
    if(anss == anss3) dfs2(xx, 0, 2, 3);
    if(anss == anss4) dfs2(xx, 0, 3, 2);
    if(anss == anss5) dfs2(xx, 0, 1, 3);
    if(anss == anss6) dfs2(xx, 0, 3, 1);
    
    for(ll i = 1; i <= n; i++) printf("%lld ", clr[i]);

        

    return 0;
}