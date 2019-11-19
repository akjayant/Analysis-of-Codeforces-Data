#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long

using namespace std;

const int N = 2e3 + 5;

struct node
{
	int x,y;
	ll val;
}edge[N * N];

int n,cnt;
int fa[N],x[N],y[N],size[N],pf[N],num[N];
ll ans;
ll v[N],k[N];

int cmp(node a,node b)
{
	return a.val < b.val;
}

int get(int x)
{
	return fa[x] == x ? x : fa[x] = get(fa[x]);
}

int main()
{
	//freopen("in","r",stdin);
	scanf("%d",&n);
	for (int i = 1 ; i <= n ; i++) scanf("%d%d",&x[i],&y[i]);
	for (int i = 1 ; i <= n ; i++) fa[i] = i,size[i] = 1;
	for (int i = 1 ; i <= n ; i++) scanf("%d",&v[i]);
	for (int i = 1 ; i <= n ; i++) scanf("%d",&k[i]);
	for (int i = 1 ; i <= n ; i++) edge[++cnt] = ((node){0,i,v[i]});
	for (int i = 1 ; i <= n ; i++)
		for (int j = 1 ; j <= n ; j++)
		{
			int dis = abs(x[i] - x[j]) + abs(y[i] - y[j]);
			if (dis * 1LL * (k[i] + k[j]) > v[i] + v[j]) continue;
			edge[++cnt] = ((node){i,j,dis * 1LL * (k[i] + k[j])});
		}
	sort(edge + 1,edge + cnt + 1,cmp);
	int t = 0;
	for (int i = 1 ; i <= cnt ; i++)
	{
		int x = get(edge[i].x),y = get(edge[i].y);
		if (x != y) 
		{
			if (!edge[i].x) pf[++pf[0]] = edge[i].y;
			else num[++num[0]] = i;
			t++,ans += edge[i].val;
			if (size[x] < size[y]) swap(x,y);
			size[x] += size[y],fa[y] = x;
		}
		if (t == n) break;
	}
	printf("%lld\n",ans);
	printf("%d\n",pf[0]);
	if (pf[0])
	{
		for (int i = 1 ; i <= pf[0] ; i++) printf("%d ",pf[i]);
		printf("\n");
	}
	printf("%d\n",num[0]);
	for (int i = 1 ; i <= num[0] ; i++) printf("%d %d\n",edge[num[i]].x,edge[num[i]].y);
	return 0;
}
