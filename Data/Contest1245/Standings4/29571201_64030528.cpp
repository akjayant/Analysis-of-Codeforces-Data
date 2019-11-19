#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;
const int N = 2010, M = 4010000;
struct edge{
    int u, v;
    long long w;
}e[M];
struct point{
    int x, y;
    int det(const point& a) const {
        return abs(x - a.x) + abs(y - a.y);
    }
}p[N];
inline int cmp(const edge &a, const edge &b){return a.w < b.w;}
long long c[N], k[N];
int fa[N], flag[M];
inline int getf(int x){return fa[x] == x ? x : fa[x] = getf(fa[x]);} 
int main()
{
    int n, te = 0; 
    cin>>n;
    for (int i = 1; i <= n; ++i) fa[i] = i;
    fa[n + 1] = n + 1;
    for (int i = 1; i <= n; ++i) scanf("%d%d", &p[i].x, &p[i].y);
    for (int i = 1; i <= n; ++i) scanf("%lld", &c[i]);
    for (int i = 1; i <= n; ++i) scanf("%lld", &k[i]); 
    for (int i = 1; i <= n; ++i){
        e[++te] = (edge){i, n + 1, c[i]};
        for (int j = i + 1; j <= n; ++j){
            long long w = 1ll * (long long)(k[i] + k[j]) * (long long)(p[i].det(p[j]));
            e[++te] = (edge){i, j, w};
        }
    }
    sort(e + 1, e + te + 1, cmp);
    int cnt = 0, cntv = 0, cnte = 0;
    long long ans = 0;
    for (int i = 1; i <= te; ++i){
        int fx = getf(e[i].u), fy = getf(e[i].v);
        if (fx != fy){
            fa[fx] = fy, flag[i] = 1;
            cnt++, ans += e[i].w;
            if (e[i].u == n + 1 || e[i].v == n + 1) cntv++;
            else cnte ++;
            if (cnt == n) break;
        }
    }
    printf("%lld\n%d\n", ans, cntv);
    for (int i = 1; i <= te; ++i){
        if (flag[i] && e[i].v == n + 1){
            if (cntv != 1) printf("%d ", e[i].u);
            else printf("%d\n", e[i].u);
            cntv--;
        }
    }
    printf("%d\n", cnte);
    for (int i = 1; i <= te; ++i){
        if (flag[i] && e[i].v != n + 1) printf("%d %d\n", e[i].u, e[i].v);
    }
    // system("pause");
}