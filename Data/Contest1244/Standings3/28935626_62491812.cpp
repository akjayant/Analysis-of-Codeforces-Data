#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const int M = 250001;
LL fath[M][3][3],ans;
int nxt[M],D[M],root,lst[M][3][3],ver[M],nex[M],c[3][M],head[M],cnt,n,P[M],res[M];

void add(int x,int y)
{
	ver[++cnt]=y, nex[cnt]=head[x], head[x]=cnt;
}
void dfs(int x,int fa)
{
	for(int i=head[x];i;i=nex[i])
	{
		if(ver[i]==fa) continue;
		nxt[x]=ver[i];
		P[ver[i]]=x;
		dfs(ver[i],x);
	}
}
int main()
{
	int x,y;
	scanf("%d",&n);
	for(int i=0;i<3;i++) for(int j=1;j<=n;j++) scanf("%d",&c[i][j]);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
		D[x]++,D[y]++;
	}
	int B=0;
	for(int i=1;i<=n;i++)
	{
		if(D[i]>2) { B=1; break; }
		if(D[i]==1) root=i;
	}
	if(B)
	{
		puts("-1");
		return 0;
	}
	dfs(root,0);
	x=root,y=nxt[root];
	memset(fath,0x3f,sizeof(fath));
	ans=fath[0][0][0];
	for(int i=0;i<3;i++) for(int j=0;j<3;j++) if(i!=j)fath[2][i][j]=c[i][x]+c[j][y];
	for (int i=nxt[y],j=3; i&&j<=n; i=nxt[i],j++)
	{
		for (int k=0;k<3;k++)
		for (int p=0;p<3;p++) if(k!=p)
		for (int w=0; w<3; w++)
		{
			if (w==k||w==p) continue;
			fath[j][k][p]=fath[j-1][w][k]+c[p][i];
			lst[j][k][p]=w;
		}
		if (j==n) x=i;
	}
	int u,v,p;
	for(int i=0; i<3; i++) for(int j=0; j<3; j++) if(i!=j && fath[n][i][j]<ans) ans=fath[n][i][j], u=i,v=j;
	cout<<ans<<endl;
	res[x]=v;  int num=n;
	while (x&&num>1)
	{
		x=P[x], p=lst[num][u][v];
		res[x]=u, num--;
		v=u,u=p;
	}
	for (int i=1; i<=n; i++) printf("%d ",res[i]+1);
	return 0;
}