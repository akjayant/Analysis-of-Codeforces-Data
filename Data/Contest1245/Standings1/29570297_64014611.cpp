/* LittleFall : Hello! */
#include <bits/stdc++.h>
using namespace std; using ll = long long; inline int read();
const int M = 2048, MOD = 1000000007;

ll x[M], y[M], c[M], k[M];
ll edg[M][M], dis[M], lst[M], vis[M];

vector<int> save0;
vector<pair<int,int>> save;

ll prim(int n)
{
	ll tot = 0;

	memset(dis, 0x3f, sizeof(dis));
	dis[0] = 0;

	for(int u=0; ~u;)
	{
		if(u)
		{
			if(lst[u]==0)
				save0.push_back(u);
			else
				save.push_back({lst[u],u});
		}
		vis[u] = 1;
		tot += dis[u];
		for(int v=0; v<=n; ++v)
		{
			if(edg[u][v] < dis[v])
			{
				dis[v] = edg[u][v];
				lst[v] = u;
			}
		}

		u = -1;
		for(int v=1; v<=n; ++v) if(!vis[v])
			if(u==-1 || dis[v]<dis[u])
				u = v;
	}
	return tot;
}
int main(void)
{
	#ifdef _LITTLEFALL_
	freopen("in.txt","r",stdin);
    #endif

	int n = read();
	for(int i=1; i<=n; ++i) x[i] = read(), y[i] = read();
	for(int i=1; i<=n; ++i) c[i] = read();
	for(int i=1; i<=n; ++i) k[i] = read();

	memset(edg, 0x3f, sizeof(edg));
	for(int i=1; i<=n; ++i)
	{
		edg[i][0] = edg[0][i] = c[i];
		for(int j=i+1; j<=n; ++j) 
			edg[j][i] = edg[i][j] = (k[i] + k[j]) *
				( abs(x[i]-x[j]) + abs(y[i]-y[j]) );
	}

	ll ans = prim(n);

	cout << ans << endl;
	printf("%d\n",save0.size() );
	for(int i:save0)
		printf("%d ",i );
	printf("\n");
	printf("%d\n",save.size() );
	for(auto p:save)
		printf("%d %d\n",p.first,p.second );



    return 0;
}


inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}