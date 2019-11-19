#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue> 
const int N = 2000;
using namespace std;
struct node
{
	int x,y,c,k,id;
}p[N + 5];
int n,zj[N + 5],zj_cnt,mn[N + 5],from[N * N + 5],to[N * N + 5],edge_cnt,cnt,vis[N + 5],dis[N + 5];
long long ans;
struct cmp
{
	long long d;
	int u,opt;
	bool operator<(const cmp &a) const
	{
		return d>a.d;
	}
};
priority_queue <cmp> q;
long long myabs(long long x)
{
	if (x < 0)
		return -x;
	return x;
}
int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d%d",&p[i].x,&p[i].y);
	for (int i = 1;i <= n;i++)
		scanf("%d",&p[i].c),q.push((cmp){1ll * p[i].c,i,0});
	for (int i = 1;i <= n;i++)
		scanf("%d",&p[i].k);
	while (cnt < n)
	{
		cmp u = q.top();
		q.pop();
		if (vis[u.u])
			continue;
		ans += u.d;
		cnt++;
		vis[u.u] = 1;
		if (u.opt == 0)
			zj[++zj_cnt] = u.u;
		else
		{
			edge_cnt++;
			from[edge_cnt] = u.u;
			to[edge_cnt] = u.opt;
		}
		for (int i = 1;i <= n;i++)
			if (!vis[i])
			{
				q.push((cmp){1ll * (myabs(0ll + p[u.u].x - p[i].x) + myabs(0ll + p[u.u].y - p[i].y)) * (0ll + p[i].k + p[u.u].k),i,u.u});
			}
	}
	cout<<ans<<endl;
	cout<<zj_cnt<<endl;
	for (int i = 1;i <= zj_cnt;i++)
		printf("%d ",zj[i]);
	cout<<endl;
	cout<<edge_cnt<<endl;
	for (int i = 1;i <= edge_cnt;i++)
		printf("%d %d\n",from[i],to[i]);
	return 0;
}