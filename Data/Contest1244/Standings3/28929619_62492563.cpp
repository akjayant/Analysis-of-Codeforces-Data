#include<iostream>
#include<cstdio>
using namespace std;
int n,w[101010][4],du[101010];
int cnt,top,fir[101010],nxt[202020],to[202020],st[101010],cl[101010];
long long sw[10][10];
long long mi=0x3f3f3f3f3f3f3f3f;
void add(int x,int y)
{
	nxt[++cnt]=fir[x];fir[x]=cnt;to[cnt]=y;
}
void dfs(int x,int fa)
{
	st[++top]=x;
	for(int i=fir[x];i;i=nxt[i])
	if(to[i]!=fa) dfs(to[i],x);
}
void print(int x,int y,int z)
{
	printf("%I64d\n",mi);
	for(int i=1;i<=n;i+=3)
	cl[st[i]]=y,cl[st[i+1]]=z,cl[st[i+2]]=x;
	for(int i=1;i<=n;i++)
	printf("%d ",cl[i]);
	puts("");
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&w[i][1]);
	for(int i=1;i<=n;i++)
	scanf("%d",&w[i][2]);
	for(int i=1;i<=n;i++)
	scanf("%d",&w[i][3]);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
		du[x]++;du[y]++;
	}
	if(n==1)
	{
		printf("%d\n",min(min(w[1][1],w[1][2]),w[1][3]));
		return 0;
	}
	for(int i=1;i<=n;i++)
	if(du[i]>2)
	{
		puts("-1");
		return 0;
	}
	else if(du[i]==1) st[1]=i;
	dfs(st[1],0);
	for(int i=1,x;i<=n;i++)
	x=st[i],sw[i%3][1]+=w[x][1];
	for(int i=1,x;i<=n;i++)
	x=st[i],sw[i%3][2]+=w[x][2];
	for(int i=1,x;i<=n;i++)
	x=st[i],sw[i%3][3]+=w[x][3];
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
		if(i!=j)
		{
			int k=6-i-j;
			mi=min(sw[0][i]+sw[1][j]+sw[2][k],mi);
		}
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
		if(i!=j)
		{
			int k=6-i-j;
			if(sw[0][i]+sw[1][j]+sw[2][k]==mi)
			{
				print(i,j,k);
				return 0;
			}
		}
	return 0;
}
		
	
