#define Kafuu signed
#define Chino main

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <time.h>

#define maxn 100005
#define inf 0x3f3f3f3f
#define px putchar
#define pn px('\n')
#define ps px(' ')
#define pd puts("======================")
#define pj puts("++++++++++++++++++++++")

using namespace std;

inline int read(){
	int x=0,y=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return y?-x:x;
}
template<typename T>
inline T read(){
	T x=0;
	int y=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return y?-x:x;
}
struct edge{
	int pre,to;
}e[maxn<<1];
int an[maxn],g[maxn][3][3],c[3][maxn],h[maxn],last[maxn],nex[maxn],deg[maxn],num;
long long f[maxn][3][3],ans=1e18;
inline void add(int from,int to){
	++deg[to];
	e[++num]=(edge){h[from],to};
	h[from]=num;
}
void __________dfs(int node,int fa=0){
	int x;
	for(register int i=h[node];i;i=e[i].pre){
		x=e[i].to;
		if(x==fa)continue;
		nex[node]=x,last[x]=node;
		__________dfs(x,node);
	}
}
void readln(string &x){
	char ch=getchar();
	while(!islower(ch)&&!isupper(ch)&&ch!='<'&&ch!='.')ch=getchar();
	while(ch!='\n'&&ch!='\r')x+=ch,ch=getchar();
}
inline int cmp(string &q,string &p){
	int ans=0;
	string x="",y="";
	for(register int i=0;i<p.size();++i){
		if(p[i]=='<'){if(!y.empty())y.erase(y.end()-1);}
		else y+=p[i];
	}
	for(register int i=0;i<q.size();++i){
		if(q[i]=='<'){if(!x.empty())x.erase(x.end()-1);}
		else x+=q[i];
	}
	for(register int i=0,j=0;i<x.size()&&j<y.size();++i,++j)if(x[i]==y[j])++ans;
	return ans;
}
Kafuu Chino(){
	int n=read(),fl=0,root,rec=n;
	for(register int i=0;i<3;++i)
		for(register int j=1;j<=n;++j)
			c[i][j]=read();
	for(register int i=1,x,y;i<n;++i)x=read(),y=read(),add(x,y),add(y,x);
	for(register int i=1;i<=n;++i)
		if(deg[i]>2){puts("-1");return 0;}
		else if(deg[i]==1)root=i;
	__________dfs(root);
	memset(f,0x3f,sizeof f);
	for(register int i=0;i<3;++i)
		for(register int j=0;j<3;++j)
			if(i!=j)f[2][i][j]=c[i][root]+c[j][nex[root]];
	int node,x,y,z;
	for(register int i=nex[nex[root]],j=3;j<=n&&i;i=nex[i],++j){
		if(j==n)node=i;
		for(register int k=0;k<3;++k)
			for(register int l=0;l<3;++l){
				if(k==l)continue;
				for(register int m=0;m<3;++m){
					if(k==m||m==l)continue;
					f[j][k][l]=f[j-1][m][k]+c[l][i];
					g[j][k][l]=m;
				}
			}
	}
	for(register int i=0;i<3;++i)
		for(register int j=0;j<3;++j)
			if(i!=j&&f[n][i][j]<ans)ans=f[n][i][j],x=i,y=j;
	an[node]=y,printf("%I64d\n",ans);
	while(node&&rec>1)node=last[node],z=g[rec][x][y],an[node]=x,y=x,x=z,--rec;
	for(register int i=1;i<=n;++i)printf("%d ",an[i]+1);
	pn;
}
