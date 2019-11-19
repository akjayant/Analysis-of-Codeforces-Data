#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
#define mod 1000000007
using namespace std;
LL read() {
	LL k = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9')
		k = k * 10 + c - 48, c = getchar();
	return k * f;
}
struct zzz {
    int f, t, nex;
}e[1000010 << 1]; int head[1000010], tot;
void add(int x, int y) {
    e[++tot].t = y;
    e[tot].f = x;
    e[tot].nex = head[x];
    head[x] = tot;
}
int vis[1000010], dfn[1000010], low[1000010], colnum, belong[1000010], deth, s[1000010], top;
int in[1000010];
void Tarjan(int x){
    low[x] = dfn[x] = ++deth;
    s[++top] = x; vis[x] = 1;
    for(int i = head[x]; i; i = e[i].nex) {
        if(!dfn[e[i].t]) {
            Tarjan(e[i].t);
            low[x] = min(low[x], low[e[i].t]);
        }
        else
          if(vis[e[i].t]) low[x] = min(low[x], dfn[e[i].t]);
    }
    if(dfn[x] == low[x]) {
        ++colnum; int k=0;
        do{
            k = s[top--];
            belong[k] = colnum;
            vis[k] = 0;
        }while(k != x);
    }
}
int main() {
	int t = read();
	while(t--) {
		int n = read(), m = read(); tot = top = deth = colnum = 0;
		for(int i = 1; i <= n; ++i)
			head[i] = vis[i] = low[i] = belong[i] = dfn[i] = in[i] = 0;
		for(int i = 1; i <= m; ++i) {
			int x = read(), y = read(); if(x == y) continue;
			add(x, y);
		}
		for(int i = 1; i <= n; ++i)
      		if(!dfn[i]) Tarjan(i);
      	if(colnum == 1) printf("NO\n");
      	else {
      		int cnt = tot, pos = 0;
		    for(int i = 1; i <= cnt; ++i)
		        if(belong[e[i].f] != belong[e[i].t])
		        	++in[belong[e[i].t]];
		    for(int i = 1; i <= colnum; ++i)
		    	if(!in[i]) pos = i;
		    int num = 0;
		    for(int i = 1; i <= n; ++i)
		    	if(belong[i] == pos) ++num;
      		printf("YES\n%d %d\n", n - num, num);
      		for(int i = 1; i <= n; ++i)
      			if(belong[i] != pos) printf("%d ", i);
      		printf("\n");
      		for(int i = 1; i <= n; ++i)
      			if(belong[i] == pos) printf("%d ", i);
		}
	}
	
	return 0;
}