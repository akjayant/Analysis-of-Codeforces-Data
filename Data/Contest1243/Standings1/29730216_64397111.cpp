#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#ifdef DEBUG
#define debug(x) cerr << #x << " " << x << '\n'
#else
#define debug(x)
#endif
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int INF = 0x3f3f3f3f, N = 2e5 + 5;
inline int read()
{
	int sum = 0, f = 1;
	char c = getchar();
	while(c>'9'||c<'0') {if(c=='-') f = -f; c = getchar();}
	while(c>='0'&&c<='9') sum = sum*10 + c - 48, c = getchar();
	return sum*f;
}

int head[N], cnt, n, m, pre[N], nxt[N];
bool in[N], vis[N];
vector<int> scc[N]; //存每个连通块内的结点
struct node
{
	int to, next;
}e[N<<1];
inline void add(int u,int v)
{
	e[++cnt].next = head[u];
	e[cnt].to = v;
	head[u] = cnt;
}
inline void del(int x)
{
	nxt[pre[x]] = nxt[x];
	pre[nxt[x]] = pre[x];
}
int bfs()
{
	queue <int> q;
	int tot = 0;
	while(nxt[0])
	{
		int now = nxt[0];
		del(now);
		q.push(now);
		++tot;
		in[now] = 1;
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			for(int i=head[u];i;i=e[i].next)
			{
				int v = e[i].to;
				vis[v] = 1;
			}
			for(int i=nxt[0];i;i=nxt[i])
			{
				if(!in[i]&&!vis[i])
				{
					q.push(i);
					in[i] = 1;
					del(i);
					scc[tot].push_back(i);
				}
			}
			for(int i=head[u];i;i=e[i].next)
			{
				int v = e[i].to;
				vis[v] = 0;
			}
		}
	}
	return tot;
}
int main()
{
	n = read(), m = read();
	for(int i=1;i<=m;i++)
	{
		int u = read(), v = read();
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n+1;i++) pre[i] = i-1;
	for(int i=0;i<n;i++) nxt[i] = i+1; 
	nxt[n] = 0;
	int ans = bfs();
	printf("%d\n",ans-1);
	return 0;
}
