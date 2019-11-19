#include<bits/stdc++.h>
#define LL long long 
using namespace std;

inline int read(){
	int res=0,f=1;char ch=' ';
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){res=res*10+ch-'0';ch=getchar();}
	return res*f;
}
const int N=2005;
const int mod=998244353;
int n,fa[N],S;
int findf(int x){
	return fa[x]==x?x:fa[x]=findf(fa[x]);
}
int X[N],Y[N],cnt,c[N],k[N],in[N],flag[N*N];
long long ans;
struct node{
	int x,y;long long dis;
}t[N*N];
inline long long calc(int a,int b){
	return 1ll*(k[a]+k[b])*(abs(X[a]-X[b])+abs(Y[a]-Y[b]));
}
inline bool cmp(node a,node b){return a.dis<b.dis;}
inline void krusal(){
	sort(t+1,t+1+cnt,cmp);
	int num=0;
	for(register int i=1;i<=n;i++) fa[i]=i;
	for(register int i=1;i<=cnt;i++){
		int fx=findf(t[i].x),fy=findf(t[i].y);
		if(fx==fy) continue;
		if(t[i].x==S) in[t[i].y]=1;
		flag[i]=1;
		fa[fx]=fy;
		ans+=t[i].dis;
		num++;
		if(num==n-1) break;
	}
}
int main(){
	n=read();
	for(register int i=1;i<=n;i++) X[i]=read(),Y[i]=read();
	for(register int i=1;i<=n;i++) c[i]=read();
	for(register int i=1;i<=n;i++) k[i]=read();
	for(register int i=1;i<=n;i++){
		for(register int j=i+1;j<=n;j++){
			cnt++;
			t[cnt].x=i;t[cnt].y=j;
			t[cnt].dis=calc(i,j);
		}
	}
	S=n+1;n++;
	for(register int i=1;i<=n-1;i++){
		cnt++;
		t[cnt].x=S;t[cnt].y=i;
		t[cnt].dis=c[i];
	}
	krusal();
	printf("%lld\n",ans);ans=0;
	for(register int i=1;i<=n-1;i++) if(in[i]) ans++;
	printf("%lld\n",ans);
	for(register int i=1;i<=n-1;i++){
		if(in[i]) printf("%d ",i);
	}
	printf("\n");ans=0;
	for(register int i=1;i<=cnt;i++){
		if(flag[i])	if(t[i].x!=S) ans++; 
	}
	printf("%lld\n",ans);
	for(register int i=1;i<=cnt;i++){
		if(flag[i]) if(t[i].x!=S) printf("%d %d\n",t[i].x,t[i].y);
	}
	return 0;
}