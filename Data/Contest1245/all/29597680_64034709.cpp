#include<cmath>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#define lnt long long
#define rnt register int
using namespace std;
inline void read(int &x)
{
	char c;
	while(!isdigit(c=getchar()));x=c-'0';
	while(isdigit(c=getchar()))
		x=(x<<3)+(x<<1)+c-'0';
}
struct node{
	int x,y,k;
}t[2019];
struct nd{
	int x,y;lnt v;
	bool operator <(const nd&o)const
	{
		return v<o.v;
	}
	nd(int xx,int yy,lnt vv)
	{
		x=xx,y=yy,v=vv;
	}
	nd(){}
}edge[4000010];
int n,x,c[2019],fa[2019],cnt;
int ans[2019][2],f[2019],a;
inline int find(int wz){return wz==fa[wz]?wz:fa[wz]=find(fa[wz]);}
int main()
{
	read(n);
	for(rnt i=1;i<=n;i=-~i)
		read(t[i].x),read(t[i].y);
	for(rnt i=1;i<=n;i=-~i)
		read(x),edge[cnt++]=nd(0,i,x);
	for(rnt i=1;i<=n;i=-~i) read(c[i]);
	for(rnt i=1;i<n;i=-~i)
		for(rnt j=i+1;j<=n;j=-~j)
		{
			int dis=abs(t[i].x-t[j].x)+abs(t[i].y-t[j].y);
			edge[cnt++]=nd(i,j,1ll*dis*(c[i]+c[j]));
		}
	sort(edge,edge+cnt);lnt tot=0;
	for(rnt i=1;i<=n;i=-~i) fa[i]=i;
	for(rnt i=0;i<cnt;i=-~i)
	{
		int fx=find(edge[i].x);
		int fy=find(edge[i].y);
		if(fx!=fy)
		{
			fa[fx]=fy;tot+=edge[i].v;
			if(!edge[i].x) f[++f[0]]=edge[i].y;
			else
			{
				ans[a][0]=edge[i].x;
				ans[a][1]=edge[i].y;
				a=-~a;
			}
		}
	}
	printf("%lld\n%d\n",tot,f[0]);
	for(rnt i=1;i<=f[0];i=-~i)
		printf("%d ",f[i]);puts("");
	printf("%d\n",a);
	for(rnt i=0;i<a;i=-~i)
		printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}