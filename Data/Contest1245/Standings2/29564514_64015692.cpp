#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define int LL
#define INF 2147483647
#define LLINF 9223372036854775807
#define LL long long
#define xyx AKIOI
#define Dilute AKIOI
#define Chtholly_Tree AKIOI
#define time_interspace AKIOI
#define memset0 AKIOI
#define Isonan AKIOI
#define Sooke AKIOI
#define yeID AKIOI
#define _szh_ AKIOI
#define scimoon AKIOI
#define xay5421 AKIOI
#define dzh caibi
using namespace std;
int inline read(){
    int num=0,neg=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')neg=-1;c=getchar();}
    while(isdigit(c)){num=(num<<3)+(num<<1)+c-'0';c=getchar();}
    return num*neg;
}
const int maxn=2010;
int n,x[maxn],y[maxn],tot,val[maxn],used[maxn*maxn],legal[maxn],ans;
struct Edge{int dis,pos,to;}edge[maxn*maxn];
int fa[maxn];bool cmp(Edge x,Edge y){return x.dis<y.dis;}
int Find(int x){return fa[x]==x?x:fa[x]=Find(fa[x]);}
int Abs(int x){return x<0?-x:x;}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++){
		x[i]=read();y[i]=read();
	}
	for(int i=1;i<=n;i++){
		edge[++tot].pos=i;edge[tot].to=0;edge[tot].dis=read();
	}
	for(int i=1;i<=n;i++){
		val[i]=read();
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
//			if(i==j)continue;
			int X=val[i]+val[j];
			int Dis=Abs(x[i]-x[j])+Abs(y[i]-y[j]);
			edge[++tot].pos=i;edge[tot].to=j;edge[tot].dis=Dis*X;
		}
	sort(edge+1,edge+tot+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=tot;i++){
		int u=Find(edge[i].pos),v=Find(edge[i].to);
		if(u!=v){ans+=edge[i].dis;used[i]=1;fa[u]=v;}
	}cout<<ans<<endl;int cnt=0,cnt1=0;
	for(int i=1;i<=tot;i++){
		if(edge[i].to==0&&used[i]){
			legal[edge[i].pos]=1;cnt++;
		}
		else if(used[i]&&edge[i].to!=0){
			cnt1++;
		}
	}cout<<cnt<<endl;
	for(int i=1;i<=n;i++)if(legal[i])cout<<i<<" ";cout<<endl;cout<<cnt1<<endl;
	for(int i=1;i<=tot;i++){
		if(used[i]&&edge[i].to!=0){
			cout<<edge[i].pos<<" "<<edge[i].to<<endl;
		}
	}
	return 0;
}
