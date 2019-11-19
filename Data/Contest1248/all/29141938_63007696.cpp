#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 1000005;
int n,m;
struct Node
{
	int u,v;
	Node *next;
}*h[MAXN],pool[MAXN<<1];
int tot = 0;
inline void addEdge(int u, int v)
{
	Node *p = &pool[++tot];
	p->v = v; p->next = h[u]; h[u] = p;
}
int dfn[MAXN],low[MAXN],scc[MAXN],size[MAXN],stack[MAXN],top = 0, cnt = 0;
bool vis[MAXN];
inline void dfs(int u)
{
    stack[++top] = u;
    vis[u] = true;
    dfn[u] = low[u] = ++cnt;
    for(Node *p = h[u]; p; p=p->next)
    {
        if(!dfn[p->v])
        {
            dfs(p->v);
            low[u] = min(low[u],low[p->v]);
		}
		else if(vis[p->v]) low[u] = min(low[u],dfn[p->v]);
	}
	if(low[u]==dfn[u])
	{
		size[u] = 0;
        while(1)
        {
            scc[stack[top]] = u;
            size[u]++;
            vis[stack[top]] = false;
            if(stack[top--]==u)
			    break;
			size[stack[top+1]] = 0;
		}
    }
}
int du[MAXN];
inline void init()
{
	for(int i = 1; i<=n; i++)
	{
	    h[i] = NULL;
        vis[i] = false;
        dfn[i] = low[i] = 0;
	    size[i] = 1, scc[i] = i;
	    du[i] = 0;
	}    
	tot = cnt = top = 0;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        scanf("%d%d",&n,&m);
        init();
        int u,v;
        for(int i = 1; i<=m; i++)
        {
            scanf("%d%d",&u,&v);
			addEdge(u,v); 
		}
		for(int i = 1; i<=n; i++)
		    if(!dfn[i])
		        dfs(i);
		bool flag = false;
		for(int i = 1; i<=n; i++)
		    if(scc[i]!=scc[1])
		        flag = true;
	    if(!flag)
	    {
	        printf("No\n");
	        continue;
		}    
		for(int i = 1; i<=n; i++)
		    for(Node *p = h[i]; p; p=p->next)
		        if(scc[i]!=scc[p->v])
		            du[scc[i]]++;
		int num = 0;
		for(int i = 1; i<=n; i++)
		    if(i==scc[i]&&!du[i])
	            num = i;
	    printf("Yes\n%d %d\n",size[num],n-size[num]);
	    for(int i = 1; i<=n; i++)
	        if(scc[i]==num)
	            printf("%d ",i);
	    printf("\n");
	    for(int i = 1; i<=n; i++)
	        if(scc[i]!=num)
	            printf("%d ",i);
	    printf("\n");
	}
	return 0;
}
