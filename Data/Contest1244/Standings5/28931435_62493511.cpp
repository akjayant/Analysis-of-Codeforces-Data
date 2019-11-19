//Love and Freedom.
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define ll long long
#define inf 20021225
#define N 100010
using namespace std;
int read()
{
	int s=0,t=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')	t=-1; ch=getchar();}
	while(ch>='0' && ch<='9')	s=s*10+ch-'0',ch=getchar();
	return s*t;
}
int d[N],c[N][4],n,dfn[N],tms,idfn[N];ll f[N][4][4]; int fr[N][4][4];
struct node{int to,lt;}e[N<<1]; int in[N],cnt;
void dfs(int x,int fr)
{
	dfn[x]=++tms; idfn[tms]=x;
	for(int i=in[x];i;i=e[i].lt)
		if(e[i].to!=fr)	dfs(e[i].to,x);
}
void add(int x,int y)
{
	e[++cnt].to=y; e[cnt].lt=in[x]; in[x]=cnt;
	e[++cnt].to=x; e[cnt].lt=in[y]; in[y]=cnt;
}
int stk[N],top;
int main()
{
	n=read();
	for(int i=1;i<=3;i++)	for(int x=1;x<=n;x++)
		c[x][i]=read();
	int x,y;
	for(int i=1;i<n;i++)	x=read(),y=read(),add(x,y),d[x]++,d[y]++;
	int rt=0;
	for(int i=1;i<=n;i++)
	{
		if(d[i]>2)	return puts("-1"),0;
		if(d[i]==1)	rt=i;
	}
	dfs(rt,rt); memset(f,48,sizeof(f));
	f[1][1][0]=c[idfn[1]][1]; f[1][2][0]=c[idfn[1]][2]; f[1][3][0]=c[idfn[1]][3];
	//printf("%d %d %d\n",idfn[1],f[1][2][0],f[1][3][0]);
	for(int i=2;i<=n;i++)
	{
		int x=idfn[i];
		for(int cc=1;cc<=3;cc++)	for(int dd=0;dd<=3;dd++)
			for(int tt=1;tt<=3;tt++)
			{
				if(tt==cc || dd==cc || tt==dd)	continue;
				if(f[i-1][cc][dd]+c[x][tt]<f[i][tt][cc])
				{
					f[i][tt][cc]=f[i-1][cc][dd]+c[x][tt];
					fr[i][tt][cc]=dd;
				}
			}
	}
	ll ans=f[0][0][0]; int remi,remj;
	for(int i=0;i<=3;i++)	for(int j=1;j<=3;j++)
	{
		if(f[n][j][i]<ans)	ans=f[n][j][i],remi=i,remj=j;
	}
	printf("%I64d\n",ans);
	for(int i=n;i;i--)
	{
		//printf("%d %d %d %d\n",i,f[i][remj][remi],remj,remi);
		stk[idfn[i]]=remj; int t=fr[i][remj][remi]; remj=remi; remi=t;// printf("%d ",remi);
	}
	for(int i=1;i<=n;i++)	printf("%d ",stk[i]);
	return 0;
}
