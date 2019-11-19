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
const int N=2007;
const ll INF=1e18;
int n,x[N],y[N],c[N],k[N];
inline ll cst(int i,int j) { return 1ll*(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j])); }
ll dis[N],ans;
bool vis[N];
vector <int> bas;
vector <pair<int,int>> edg;
int frm[N];
void Prim()
{
	for(int i=1;i<=n;i++) dis[i]=c[i];
	for(int I=1;I<=n;I++)
	{
		ll mx=INF; int pos=-1;
		for(int i=1;i<=n;i++)
			if(!vis[i]&&dis[i]<mx)
				mx=dis[i],pos=i;
		vis[pos]=1; ans+=mx;
		if(!frm[pos]) bas.push_back(pos);
		else edg.push_back(make_pair(frm[pos],pos));
		for(int i=1;i<=n;i++)
			if(!vis[i]&&dis[i]>cst(pos,i))
				dis[i]=cst(pos,i),frm[i]=pos;
	}
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
		x[i]=read(),y[i]=read();
	for(int i=1;i<=n;i++) c[i]=read();
	for(int i=1;i<=n;i++) k[i]=read();
	Prim(); printf("%lld\n",ans);
	printf("%d\n",int(bas.size()));
	for(auto x: bas) printf("%d ",x); puts("");
	printf("%d\n",int(edg.size()));
	for(auto t: edg) printf("%d %d\n",t.first,t.second);
	return 0;
}