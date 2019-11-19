#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;
 
int read() {
    int x = 0, f = 1; char c = getchar();
    while(!isdigit(c)){ if(c == '-') f = -1; c = getchar(); }
    while(isdigit(c)){ x = x * 10 + c - '0'; c = getchar(); }
    return x * f;
}
 
#define maxn 100010
#define maxm 4000010
 
int n, m, head[maxn], nxt[maxm], to[maxm], Pre[maxn], Nxt[maxn];
 
void AddEdge(int a, int b) {
    to[++m] = b; nxt[m] = head[a]; head[a] = m;
    swap(a, b);
    to[++m] = b; nxt[m] = head[a]; head[a] = m;
    return ;
}
 
bool vis[maxn], tag[maxn];
int Q[maxn], hd, tl, ans, tot[maxn];
void del(int u) {
    int lp = Pre[u], ln = Nxt[u];
    Nxt[lp] = ln; Pre[ln] = lp; vis[u] = 1;
    return ;
}
void bfs(int s) {
    hd = tl = 0; Q[++tl] = s;
    del(s); tot[ans] = 1;
    while(hd < tl) {
        int u = Q[++hd];
        for(int e = head[u]; e; e = nxt[e]) tag[to[e]] = 1;
        for(int i = Nxt[0]; i; i = Nxt[i]) if(!tag[i]) del(i), tot[ans]++, Q[++tl] = i;
        for(int e = head[u]; e; e = nxt[e]) tag[to[e]] = 0;
    }
    return ;
}
 
int main() {
    n = read(); int m = read();
    for(int i = 1; i <= m; i++) {
        int a = read(), b = read();
        AddEdge(a, b);
    }
    for(int i = 0; i < n; i++) Nxt[i] = i + 1, Pre[i+1] = i;
     
    for(int i = 1; i <= n; i++) if(!vis[i]) ans++, bfs(i);
    printf("%d\n", ans - 1);
     
    return 0;
}