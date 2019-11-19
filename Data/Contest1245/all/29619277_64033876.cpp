#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 2e3 + 7;
int n, pre[maxn];
ll c[maxn], k[maxn], x[maxn], y[maxn];
struct node
{
    int x, y;
    ll w;
    node(){}
    node(int xx, int yy, ll ww) : x(xx), y(yy), w(ww){}
    bool operator < (const node &a) const
    {
        return w < a.w;
    }
}e[maxn*maxn+10];
int Find(ll x)
{
    return x == pre[x] ? x : pre[x] = Find(pre[x]);
}
int join(ll x, ll y)
{
    if(Find(x) == Find(y)) return 0;
    pre[Find(y)] = Find(x);
    return 1;
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &x[i], &y[i]);
    }
    for(int i = 1; i <= n; i++) scanf("%lld", &c[i]);
    for(int i = 1; i <= n; i++) scanf("%lld", &k[i]);
    int tot = 0;
    for(int i = 1; i <= n; i++)
    {
        e[tot++] = node(0, i, c[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = i+1; j <= n; j++)
        {
            ll dis = abs(x[i]-x[j]) + abs(y[i]-y[j]);
            ll val = dis * (k[i]+k[j]);
            e[tot++] = node(i, j, val);
        }
    }
    sort(e, e+tot);
   // for(int i = 0; i < tot; i++)
   //     cout << e[i].x << ' ' << e[i].y << ' ' << e[i].w << endl;
    for(int i = 0; i < maxn; i++) pre[i] = i;
    int cnt = 0;
    ll ans = 0;
    vector<pair<int, int>> edg;
    vector<int> pos;
    for(int i = 0; i < tot; i++)
    {

        if(join(e[i].x, e[i].y))
        {
            ans += e[i].w;
            cnt++;
            if(e[i].x == 0)
                pos.push_back(e[i].y);
            else
                edg.push_back(make_pair(e[i].x, e[i].y));
        }
        if(cnt == n) break;
    }
    printf("%lld\n", ans);
    printf("%d\n", pos.size());
    for(int i = 0; i < pos.size(); i++)
        printf("%d%c", pos[i], i == pos.size()-1 ? '\n' : ' ');
    printf("%d\n", edg.size());
    for(int i = 0 ; i < edg.size(); i++)
        printf("%d %d\n", edg[i].first, edg[i].second);
    return 0;
}
