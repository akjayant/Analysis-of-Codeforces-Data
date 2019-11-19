#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
typedef long long ll;
inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') f=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') { x=(x<<1)+(x<<3)+(ch^48); ch=getchar(); }
	return x*f;
}
const int N=1e5+7;
const ll INF=1e18;
int fir[N],from[N<<1],to[N<<1],cntt;
inline void add(int a,int b) { from[++cntt]=fir[a]; fir[a]=cntt; to[cntt]=b; }
int n,cst[N][3],ans[3][3],col[N],pcol[N],du[N];
vector <int> V;
int main()
{
	n=read();
	for(int i=0;i<3;i++)
		for(int j=1;j<=n;j++) cst[j][i]=read();
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read();
		add(a,b); add(b,a);
		du[a]++; du[b]++;
	}
	for(int i=1;i<=n;i++)
		if(du[i]>2) { printf("-1\n"); return 0; }
	int rt=0; for(int i=1;i<=n;i++) if(du[i]==1) { rt=i; break; }
	int pre=rt,now=to[fir[rt]]; V.push_back(rt);
	while(du[now]>1)
		for(int i=fir[now];i;i=from[i])
		{
			int &v=to[i]; if(v==pre) continue;
			V.push_back(now); pre=now; now=v; break;
		}
	V.push_back(now);
	ll ans=INF;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++) if(i!=j)
		{
			int len=V.size(); ll res=cst[V[0]][i]+cst[V[1]][j];
			pcol[V[0]]=i; pcol[V[1]]=j;
			for(int k=2;k<len;k++)
			{
				for(int c=0;c<3;c++)
					if(c!=pcol[V[k-1]]&&c!=pcol[V[k-2]]) pcol[V[k]]=c;
				res+=cst[V[k]][pcol[V[k]]];
			}
			if(res<ans)
				for(int k=0;k<len;k++) col[V[k]]=pcol[V[k]];
			ans=min(ans,res);
		}
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++) printf("%d ",col[i]+1);
	puts(""); return 0;
}