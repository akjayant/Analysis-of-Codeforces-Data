//ѹ�пδ�
#include<bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const int MAXN=1e5+10;
LL n,s[MAXN][3],pre[MAXN][2],ans,P[MAXN],Q[MAXN];
bool book[MAXN];
LL read(){LL sss=0,fff=1;char ccc;ccc=getchar();while(ccc<'0'||ccc>'9'){if(ccc=='-')fff=-1;ccc=getchar();}while(ccc>='0'&&ccc<='9')sss=(sss<<1)+(sss<<3)+(ccc^'0'),ccc=getchar();return sss*fff;}
template<typename T> inline void write(T x){if(!x) return;write(x/10);putchar((x%10)+'0');}
template<typename T> inline void wri(T x){write(x);puts("");}
void dfs(int step,int fa,int C,int u,int CC,LL sum)
{
	if(step==n+1)
	{
		if(sum<ans)
		{
			for(int i=1;i<=n;i++)
				P[i]=Q[i];
			ans=sum;
		}
		return;
	}
	int v=pre[u][0];
	if(v==fa) v=pre[u][1];
	if(C!=0&&CC!=0) Q[v]=0,dfs(step+1,u,CC,v,0,sum+s[v][0]);
	if(C!=1&&CC!=1) Q[v]=1,dfs(step+1,u,CC,v,1,sum+s[v][1]);
	if(C!=2&&CC!=2) Q[v]=2,dfs(step+1,u,CC,v,2,sum+s[v][2]);
}
int main()
{
//	freopen("123.in","r",stdin);
//	freopen("123.out","w",stdout);
	n=read();
	for(int j=0;j<3;j++)
		for(int i=1;i<=n;i++) 
		{
			s[i][j]=read();
			ans+=s[i][j];
		}
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		if(pre[u][0])
		{
			if(pre[u][1])
			{
				printf("-1\n");
				return 0;
			}
			else pre[u][1]=v;
		}
		else pre[u][0]=v;
		if(pre[v][0])
		{
			if(pre[v][1])
			{
				printf("-1\n");
				return 0;
			}
			else pre[v][1]=u;
		}
		else pre[v][0]=u;
	}
	int u,v;
	for(int i=1;i<=n;i++)
		if(!pre[i][1])
			u=i;
	v=pre[u][0];
	Q[u]=0;Q[v]=1;dfs(3,u,0,v,1,s[u][0]+s[v][1]);
	Q[u]=0;Q[v]=2;dfs(3,u,0,v,2,s[u][0]+s[v][2]);
	Q[u]=1;Q[v]=0;dfs(3,u,1,v,0,s[u][1]+s[v][0]);
	Q[u]=1;Q[v]=2;dfs(3,u,1,v,2,s[u][1]+s[v][2]);
	Q[u]=2;Q[v]=0;dfs(3,u,2,v,0,s[u][2]+s[v][0]);
	Q[u]=2;Q[v]=1;dfs(3,u,2,v,1,s[u][2]+s[v][1]);
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++)
		printf("%d ",P[i]+1);
	return 0;
}
