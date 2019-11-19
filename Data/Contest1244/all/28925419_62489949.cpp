#include<bits/stdc++.h>
#define N 100005
using namespace std;
bool cur1;
int n;
int c[3][N];
int head[N],id;
struct edge{
	int to,nxt;
}E[N<<1];
inline void add_edge(int a,int b){
	E[++id]=(edge){b,head[a]};
	head[a]=id;
}
inline long long min3(long long a,long long b,long long c){return min(a,min(b,c));}
inline void Rd(int &res){
	char c;res=0;
	while(c=getchar(),c<48);
	do res=(res<<3)+(res<<1)+(c^48);
	while(c=getchar(),c>47);
	return;
}
inline bool check(){
	int sum=0;
	for(int i=1;i<=n;i++){
		int ct=0;
		for(int j=head[i];j;j=E[j].nxt)ct++;
		if(ct==1)sum++;
	}
	return sum==2;
}
int que[N],cnt;
void dfs(int x,int f){
	que[++cnt]=x;
	for(int i=head[x];i;i=E[i].nxt){
		int v=E[i].to;
		if(v==f)continue;
		dfs(v,x);
	}
}
inline int NUM(int x,int y){
	if(x&&y)return 0;
	if(x!=1&&y!=1)return 1;
	return 2;
}
int clo[N];
inline long long Calc(int x,int y){
	long long res=c[x][que[1]]+c[y][que[2]];
	clo[que[1]]=x;clo[que[2]]=y;
	for(int i=3;i<=n;i++){
		clo[que[i]]=NUM(clo[que[i-1]],clo[que[i-2]]);
		res+=c[clo[que[i]]][que[i]];
	}
	return res;
}
bool cur2;
int main(){
//	printf("%lf MB\n",(&cur2-&cur1)/1024.0/1024);
	Rd(n);
	for(int i=0;i<=2;i++)for(int j=1;j<=n;j++)Rd(c[i][j]);
	for(int i=1,a,b;i<n;i++){
		Rd(a);Rd(b);
		add_edge(a,b);
		add_edge(b,a);
	}
	if(!check()){puts("-1");return 0;}
	int rt=0;
	for(int i=1;i<=n;i++){
		int ct=0;
		for(int j=head[i];j;j=E[j].nxt)ct++;
		if(ct==1)rt=i;
	}
	dfs(rt,0);
	long long ans=1e18,x,y;
	for(int i=0;i<=2;i++){
		for(int j=0;j<=2;j++)if(i!=j){
			long long o=Calc(i,j);
			if(o<ans)ans=o,x=i,y=j;
		}
	}
	Calc(x,y);
	printf("%lld\n",ans);
	for(int i=1;i<n;i++)printf("%d ",clo[i]+1);printf("%d\n",clo[n]+1);
	return 0;
}