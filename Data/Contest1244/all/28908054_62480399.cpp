#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define nn 100002
#define nl NULL
#define pn 1000002
using namespace std;

struct node{
	int n;
	node* next;
	node() {n=0; next=nl; }
};node* a[nn];
node put[pn];
int pt;
int n;
int c[nn][3],d[nn],rtg[nn],tg[nn];

void add(int x,int y)
{
	node* p=&put[pt++]; p->n=y;
	if(a[x]!=nl) p->next=a[x];
	a[x]=p;
}

LL dfs(int u,int fa,int t1,int t2)
{
	LL sum=0;
	for(int j=0;j<3;++j)
		if(j!=t1&&j!=t2) tg[u]=j,sum=1LL*c[u][j];
	for(node* p=a[u];p!=nl;p=p->next)
	{
		if(p->n==fa) continue;
		sum+=dfs(p->n,u,t2,tg[u]);	
	}
	return sum;
}

int main()
{
	int x,y;
	scanf("%d\n",&n);
	for(int i=1;i<=n;++i) scanf("%d",&c[i][0]);
	for(int i=1;i<=n;++i) scanf("%d",&c[i][1]);
	for(int i=1;i<=n;++i) scanf("%d",&c[i][2]);
	for(int i=1;i<n;++i)
	{
		scanf("%d%d",&x,&y);
		d[x]++,d[y]++;
		add(x,y),add(y,x);
	}
	int rt=0;
	for(int i=1;i<=n;++i)
	{
		if(d[i]>=3) {printf("-1"); return 0;}
		if(d[i]==1) rt=i;
	}
	int v=a[rt]->n;
	LL sum=0;
	LL ans=(LL)1e18;
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
		{
			if(i==j) continue;
			tg[rt]=i; tg[v]=j;
			sum=1LL*c[rt][i]+1LL*c[v][j];
			for(node* p=a[v];p!=nl;p=p->next)
			{
				if(p->n==rt) continue;
				sum+=dfs(p->n,v,i,j);
			}
			if(ans>sum)
			{
				ans=sum;
				memcpy(rtg,tg,sizeof(tg));
			}
		}
	printf("%lld\n",ans);
	for(int i=1;i<=n;++i) printf("%d ",rtg[i]+1);
	
	return 0;
}
