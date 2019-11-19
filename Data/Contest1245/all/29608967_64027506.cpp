#include<bits/stdc++.h>
#define LL long long
using namespace std;
struct point{
	int x,y;
}p[2005];
int dis(point A,point B)
{	return abs(A.x-B.x)+abs(A.y-B.y);}

int c[2005],k[2005];
struct E{
	int f,t;
	LL d;
}b[5000005];
bool cmp(E A,E B)
{	return A.d<B.d;}

int tot;
void insert(int f,int t,LL d)
{
	b[++tot]=(E){f,t,d};
}

void build(int i,int j)
{
	LL d=(LL)dis(p[i],p[j])*(LL)(k[i]+k[j]);
	insert(i,j,d);
}
int F[2005];
int find(int x)
{
	return x==F[x]?x:F[x]=find(F[x]);
}

bool use[2005];
int top2;
E cc[5000005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&p[i].x,&p[i].y);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&k[i]);
	for(int i=1;i<=n;i++)
	{
		insert(n+1,i,c[i]);
	}
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
		build(i,j);
	sort(b+1,b+tot+1,cmp);
	
	for(int i=1;i<=n+1;i++) F[i]=i;
	
	LL ans=0;
	int cnt=0;
	for(int i=1;i<=tot;i++)
	{
		int x=b[i].f,y=b[i].t;
		if(find(x)==find(y)) continue;
		ans+=b[i].d;
		F[find(x)]=find(y);
		if(x==n+1)
		{
			cnt++;
			use[y]=1;
		}
		else
		{
			cc[++top2]=(E){x,y,0};
		}
	}
	cout<<ans<<endl;
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++)
		if(use[i]) printf("%d ",i);
	puts("");
	cout<<top2<<endl;
	for(int i=1;i<=top2;i++)
		printf("%d %d\n",cc[i].f,cc[i].t);
}
