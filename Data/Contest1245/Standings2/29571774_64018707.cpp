#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

typedef long long LL;
const int MAXN = 2e3 + 10, MAXM = MAXN * MAXN;
using namespace std;
typedef pair <LL, int> PLI;
typedef pair <LL, LL> PLL;
#define mkpr make_pair
#define fi first
#define se second

inline int in()
{
    int x = 0, flag = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') flag = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x * flag;
}

int n, m, K;

int head[MAXN], nume;
struct Adj { int nex, to; LL w; } adj[MAXM << 1]; // un g
void addedge(int from, int to, LL w)
{
    adj[++ nume] = (Adj) { head[from], to, w } ;
    head[from] = nume;
}
void link(int u, int v, LL w)
{
    addedge(u, v, w);
    addedge(v, u, w);
}



char ch[MAXN];

LL c[MAXN], w[MAXN];
struct Node
{
    LL x, y;
} a[MAXN];

struct Edge
{
    int u, v; LL w;
} edge[MAXM << 1], rec[MAXN << 1];
bool cmp(Edge a, Edge b) { return a.w < b.w; }
int fa[MAXN];
int getf(int x) { return fa[x] == x ? fa[x] : fa[x] = getf(fa[x]); }
void unite(int x, int y)
{
    fa[getf(x)]= getf(y);
}

LL ans = 0;

void Kruskal()
{
    for (int i = 0; i <= n; ++ i) fa[i] = i;
    sort(edge + 1, edge + m + 1, cmp);
    int cnt  = 0;
    for (int i = 1; i <= m; ++ i)
    {
	int u = edge[i].u, v= edge[i].v; LL w = edge[i].w;
	if (getf(u) == getf(v)) continue;
	ans += w;
	unite(u, v);
	++ cnt;
	rec[cnt] = (Edge) { u, v, w } ;
	if (cnt == n) break;
    }
}


int main()
{
    n = in();
    for (int i = 1; i <= n; ++ i) a[i] = (Node) { (int)in(), (int)in() };
    for (int i = 1; i <= n; ++ i) c[i] = in();
    for (int i = 1; i <= n; ++ i) w[i] = in();
    for (int i = 1; i <= n; ++ i)
    {
	for (int j = i + 1; j <= n; ++ j)
	{
	    LL W = (w[i] + w[j]) * (abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y));
	    edge[++ m] = (Edge) { i, j, W };
	}
	edge[++ m] = (Edge) { 0, i, c[i] };
    }
    Kruskal();
    printf("%lld\n" ,ans);
    int cnt = 0;
    for (int i = 1; i <= n; ++ i)
	if (rec[i].u == 0 || rec[i].v == 0) ++ cnt;
    printf("%d\n", cnt);
    for (int i = 1; i <= n; ++ i)
	if (rec[i].u == 0 || rec[i].v == 0) printf("%d ", rec[i].u + rec[i].v);
    puts("");
    printf("%d\n", n - cnt);
    for (int i = 1; i <= n; ++ i)
	if (rec[i].u && rec[i].v) printf("%d %d\n", rec[i].u, rec[i].v);
    puts("");
    return 0;
}
