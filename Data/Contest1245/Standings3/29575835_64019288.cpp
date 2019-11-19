#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <limits>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#define lowbit(x) ( x&(-x) )
#define pi 3.141592653589793
#define e 2.718281828459045
#define INF 0x3f3f3f3f
#define eps 1e-6
#define HalF (l + r)>>1
#define lsn rt<<1
#define rsn rt<<1|1
#define Lson lsn, l, mid
#define Rson rsn, mid+1, r
#define QL Lson, ql, qr
#define QR Rson, ql, qr
#define myself rt, l, r
using namespace std;
typedef unsigned long long ull;
typedef unsigned int uit;
typedef long long ll;
const int maxN = 2005;
int N, root[maxN], cnt, out_c[maxN];
pair<int, int>out_k[maxN];
ll k[maxN];
bool vis[maxN] = {false};
inline int fid(int x) { return x == root[x] ? x : root[x] = fid(root[x]); }
struct Eddge
{
    int u, v;
    ll w;
    Eddge(int a=0, int b=0, ll c=0):u(a), v(b), w(c) {}
    friend bool operator < (Eddge e1, Eddge e2) { return e1.w < e2.w; }
}edge[maxN * maxN + maxN];
struct node
{
    int x, y;
    node(int a=0, int b=0):x(a), y(b) {}
}a[maxN];
inline void init()
{
    for(int i=0; i<=N; i++) root[i] = i;
}
inline ll dis(int i, int j)
{
    return 1LL * (k[i] + k[j]) * (abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y));
}
int main()
{
    scanf("%d", &N);
    init();
    for(int i=1; i<=N; i++) scanf("%d%d", &a[i].x, &a[i].y);
    for(int i=1, c; i<=N; i++)
    {
        scanf("%d", &c);
        edge[i] = Eddge(0, i, c);
    }
    cnt = N;
    for(int i=1; i<=N; i++) scanf("%lld", &k[i]);
    for(int i=1; i<=N; i++)
    {
        for(int j=i+1; j<=N; j++)
        {
            edge[++cnt] = Eddge(i, j, dis(i, j));
        }
    }
    sort(edge + 1, edge + cnt + 1);
    int ans_c = 0, ans_k = 0;
    ll mst = 0;
    for(int i=1, u, v; i<=cnt; i++)
    {
        u = fid(edge[i].u); v = fid(edge[i].v);
        if(u == v) continue;
        mst += edge[i].w;
        if(edge[i].u == 0 || edge[i].v == 0)
        {
            out_c[++ans_c] = (edge[i].u | edge[i].v);
            root[u] = v;
        }
        else
        {
            out_k[++ans_k] = make_pair(edge[i].u, edge[i].v);
            root[u] = v;
        }
    }
    printf("%lld\n", mst);
    printf("%d\n", ans_c);
    for(int i=1; i<=ans_c; i++) printf("%d ", out_c[i]);
    puts("");
    printf("%d\n", ans_k);
    for(int i=1; i<=ans_k; i++) printf("%d %d\n", out_k[i].first, out_k[i].second);
    printf("\n");
    return 0;
}
//const int maxN = 1e5 + 7;
//int N;
//char s[maxN];
//int main()
//{
//    scanf("%s", s + 1);
//    N = (int)strlen(s + 1);
//    bool flag = true;
//    for(int i=1; i<=N; i++) if(s[i] == 'w' || s[i] == 'm') { flag = false; break; }
//    if(!flag) { printf("0\n"); return 0; }
//
//    return 0;
//}

