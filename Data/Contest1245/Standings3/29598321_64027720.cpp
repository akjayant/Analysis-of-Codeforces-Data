#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 100005;
const int MOD = 1000000007;
const int MAMOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
struct node
{
    ll x, y;
    int id;
} city[2005];
ll c[2005], k[2005];
int n;
struct edge
{
    int from, to;
    ll dis;
} tmp;
vector<edge> graph;
vector<int> P;
vector<pair<int, int>> E;
int pre[2005];

bool cmp(edge a, edge b)
{
    return a.dis < b.dis;
}

int find(int x)
{
    return pre[x] == x ? x : pre[x] = find(pre[x]);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i <= n; ++i)
        pre[i] = i;
    for (int i = 1; i <= n; ++i)
        scanf("%lld%lld", &city[i].x, &city[i].y), city[i].id = i;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &c[i]);
        graph.push_back({0, i, c[i]});
    }
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &k[i]);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            tmp.from = i;
            tmp.to = j;
            tmp.dis = (llabs(city[i].x - city[j].x) + llabs(city[i].y - city[j].y)) * (k[i] + k[j]);
            graph.push_back(tmp);
            tmp.from = j;
            tmp.to = i;
            graph.push_back(tmp);
        }
    }
    sort(graph.begin(), graph.end(), cmp);
    ll ret = 0;
    int sz = graph.size(), u, v, prex, prey, num = 0;
    ll w;
    for (int i = 0; i < sz; ++i)
    {
        u = graph[i].from;
        v = graph[i].to;
        w = graph[i].dis;
        prex = find(u);
        prey = find(v);
        if (prex != prey)
        {
            ret += w;
            pre[prey] = prex;
            if (u == 0)
                P.push_back(v);
            else
                E.push_back({u, v});
            if (++num == n)
                break;
        }
    }
    printf("%lld\n", ret);
    printf("%d\n", (int) P.size());
    sz = P.size();
    for (int i = 0; i < sz; ++i)
    {
        if (i != 0)
            printf(" ");
        printf("%d", P[i]);
    }
    printf("\n");
    printf("%d\n", (int) E.size());
    sz = E.size();
    for (int i = 0; i < sz; ++i)
        printf("%d %d\n", E[i].first, E[i].second);
    return 0;
}