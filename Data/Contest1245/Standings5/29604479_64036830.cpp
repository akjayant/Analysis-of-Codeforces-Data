









#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2010;
#define ll long long
#define Max(a, b) ((a) > (b) ? (a) : (b))
int father[N], c[N], k[N], x[N], y[N], idx[N];
int n, tot;
bool vis[N * N];
ll ans;
struct Node {int x,y;ll val;}road[N*N];
int find(int x) {return father[x]==x?x:father[x]=find(father[x]);}
bool cmp(const Node &a, const Node &b)
{
	return a.val < b.val;
}
int main()
{
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; i ++)
		scanf("%d%d", &x[i], &y[i]);
	for(int i = 1 ; i <= n ; i ++)
		scanf("%d", &c[i]), father[i] = i, idx[i] = i;
	for(int i = 1 ; i <= n ; i ++)
		scanf("%d", &k[i]);
	for(int i = 1 ; i <= n; i ++)
		for(int j = i + 1 ; j <= n ; j ++)
		road[++ tot] = (Node) {i, j, 1ll * (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]))};
	sort(road + 1, road + 1 + tot , cmp);
	for(int i = 1 ; i <= tot ; i++)
	{
		int fx = find(road[i].x);
		int fy = find(road[i].y);
		if(fx == fy || (fx != fy && Max(c[idx[fx]],c[idx[fy]]) <= road[i].val))
			continue;
		father[fx] = fy;
		vis[i] = 1;
		ans += road[i].val;
		if(c[idx[fx]] < c[idx[fy]])
			idx[fy] = idx[fx];
	}
	for(int i = 1 ; i <= n ; i ++)
		if(find(i) == i)
			ans += c[idx[i]];
	printf("%I64d\n", ans);
	int cnt = 0;
	for(int i = 1 ; i <= n ; i ++)
		if(find(i) == i)
			cnt ++;
	printf("%d\n", cnt);
	cnt = 0;
	for(int i = 1 ; i <= n ; i++)
		if(find(i) == i)
			printf("%d ", idx[i]);
	printf("\n");
	for(int i = 1 ; i <= tot ; i ++)
		if(vis[i])
			cnt ++;
	printf("%d\n", cnt);
	for(int i = 1 ; i <= tot ; i ++)
		if(vis[i])
			printf("%d %d\n", road[i].x, road[i].y);
	return 0;
}
