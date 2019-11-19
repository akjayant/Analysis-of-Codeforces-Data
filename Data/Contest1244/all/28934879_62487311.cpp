#include<bits/stdc++.h>
#define R register
#define ll long long
using namespace std;
const int N = 2e6+200;
template <class Ruby> inline void read(Ruby &x)
{
	x=0;
	char ch=getchar(), w=0;
	while(!isdigit(ch))w=(ch=='-'), ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48), ch=getchar();
	x=w?-x:x;
}
int n, deg[N], root, node3, node2, hd[N], nxt[N], to[N], bs;
ll cost[N][3]; 
ll chose[N], color[3], maxx=1e17, now;
inline void addedg(int qa, int qb){nxt[++bs]=hd[qa], to[bs]=qb, hd[qa]=bs;
}
inline void dfs(int u, int father, int color1, int color2)
{
	int tmp;
	int vis[3]; memset(vis, 0, sizeof(vis));
	vis[color1]=vis[color2]=1;
	for(R int j=0; j<=2; j++)
	{
		if(!vis[j])
		{
			now+=cost[u][j]; 
			tmp=j;
		}
	}	
	for(R int i=hd[u]; i; i=nxt[i])
	{
		int v=to[i]; if(v==father)continue;
		dfs(v, u, color2, tmp);	
	}
}
inline void getnode(int u, int father, int dep)
{
	if(dep==2)node2=u; if(dep==3)node3=u;
	if(dep>3)return;
	for(R int i=hd[u]; i; i=nxt[i])
	{
		int v=to[i]; if(v==father)continue;
		getnode(v, u, dep+1);
	}
}
inline void dfs2(int u, int father, int color1, int color2)
{
	int tmp;// cout<<u<<" "<<color1<<" "<<color2<<endl;
	int vis[4]; memset(vis, 0, sizeof(vis));vis[color1]=vis[color2]=1;
	for(R int j=0; j<=2; j++)
	{
		if(!vis[j])
		{
			chose[u]=j; tmp=j;
//			cout<<u<<" "<<color1<<" cnm "<<color2<<" "<<j<<endl;	
		}
	}	
	for(R int i=hd[u]; i; i=nxt[i])
	{
		int v=to[i]; if(v==father)continue;
			dfs2(v, u, color2, tmp);
	}
}
int main()
{
	read(n);
	for(R int j=0; j<=2; j++)
	for(R int i=1; i<=n; i++)read(cost[i][j]);
	for(R int i=1, qa, qb; i<n; i++)read(qa), read(qb), addedg(qa, qb), addedg(qb, qa), deg[qa]++, deg[qb]++;
	for(R int i=1; i<=n; i++)
	{
		if(deg[i]==1)root=i;
		if(deg[i]>2){printf("-1\n");return 0;}
	}
	getnode(root, 0, 1);// cout<<root<<" "<<node2<<" "<<node3<<endl;
	for(R int i=0; i<=2; i++)
	{
		for(R int j=0; j<=2; j++)
		{
			now=0; 
			if(i!=j)
			{
				now+=cost[root][i]+cost[node2][j];
				dfs(node3, node2, i, j);
				if(now<maxx)
				{
					maxx=now; color[0]=i, color[1]=j;
				}
			}
		}
	}
	chose[root]=color[0], chose[node2]=color[1];
//	cout<<color[0]<<" ?? "<<color[1]<<endl;
	dfs2(node3, node2, color[0], color[1]);
	printf("%I64d\n", maxx);
	for(R int i=1; i<=n; i++)printf("%d ", chose[i]+1);
	return 0;
}