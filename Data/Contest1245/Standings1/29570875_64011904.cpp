#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
using namespace std;
int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=xx*10+ch-'0';ch=getchar();}
    return xx*ff;
}
long long READ(){
    long long xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=xx*10+ch-'0';ch=getchar();}
    return xx*ff;
}
char one(){
	char ch=getchar();
	while(ch==' '||ch=='\n')
		ch=getchar();
	return ch;
}
const int maxn=2010;
int N,x[maxn],y[maxn],c[maxn],k[maxn],tot;
struct Edge{
	int x,y;
	long long v;
	Edge(int xx=0,int yy=0,long long vv=0){
		x=xx,y=yy,v=vv;
	}
	bool friend operator<(const Edge&A,const Edge&B){
		return A.v<B.v;
	}
}E[maxn*maxn],ans2[maxn];
int father[maxn];
int getfather(int x){
	if(father[x]==x)
		return x;
	return father[x]=getfather(father[x]);
}
inline void merge(int x,int y){
	x=getfather(x),y=getfather(y);
	father[y]=x;
}
int ans1[maxn],cnt1,cnt2;
long long res=0;
int main(){
	//freopen("in","r",stdin);
	N=read();
	for(int i=1;i<=N;i++)
		x[i]=read(),y[i]=read();
	for(int i=1;i<=N;i++)
		c[i]=read();
	for(int i=1;i<=N;i++)
		k[i]=read();
	for(int i=1;i<=N;i++)
		for(int j=i+1;j<=N;j++)
			E[++tot]=Edge(i,j,1LL*(abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]));
	for(int i=1;i<=N;i++)
		E[++tot]=Edge(N+1,i,c[i]);
	sort(E+1,E+1+tot);
	for(int i=1;i<=N+1;i++)
		father[i]=i;
	int cur=0;
	for(int i=1;i<=tot;i++){
		if(getfather(E[i].x)!=getfather(E[i].y)){
			merge(E[i].x,E[i].y);
			cur++;
			res+=E[i].v;
			if(E[i].x==N+1)
				ans1[++cnt1]=E[i].y;
			else
				ans2[++cnt2]=E[i];
			if(cur==N)
				break;
		}
	}
	printf("%I64d\n",res);
	printf("%d\n",cnt1);
	for(int i=1;i<=cnt1;i++)
		printf("%d ",ans1[i]);
	puts("");
	printf("%d\n",cnt2);
	for(int i=1;i<=cnt2;i++)
		printf("%d %d\n",ans2[i].x,ans2[i].y);
	return 0;
}
