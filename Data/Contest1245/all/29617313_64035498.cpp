#include <bits/stdc++.h> 
#define N 2010
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll read(){
	char c=getchar();bool flag=0;ll x=0;
	while(c<'0'||c>'9'){if(c=='-')flag=1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return flag?-x:x;
}
struct station{
	ll x,y,c,k;
}q[N];
struct edge{
	ll x,y,len;
}e[N*N];
ll cmp(edge a,edge b){
	return a.len<b.len;
}
inline ll prize(ll i,ll j){
	return (abs(q[i].x-q[j].x)+abs(q[i].y-q[j].y))*(q[i].k+q[j].k);
}
ll top=0,f[N],build[N],ed_x[N],ed_y[N];
ll Find(ll x){
	if(f[x]==x) return x;
	return f[x]=Find(f[x]);
} 
ll Union(ll x,ll y){
	x=Find(x);
	y=Find(y);
	if(x==y) return 0;
	f[y]=x;
} 
int main(){
	ll n=read(),p=0,top_b=0,top_e=0,ans=0;
	for(ll i=1;i<=n;i++) q[i].x=read(),q[i].y=read(),f[i]=i;
	for(ll i=1;i<=n;i++) q[i].c=read();
	for(ll i=1;i<=n;i++) q[i].k=read();
	for(ll i=1;i<=n;i++) e[++top].x=0,e[top].y=i,e[top].len=q[i].c;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			if(i==j) continue;
			e[++top].x=i,e[top].y=j,e[top].len=prize(i,j); 
		}
	}
	sort(e+1,e+1+top,cmp);
	for(ll i=1;i<=top;i++){
		if(Find(e[i].x)!=Find(e[i].y)){
			Union(e[i].x,e[i].y);
			if(e[i].x==0){
				top_b++;
				build[top_b]=e[i].y; 
			} 
			else{
				top_e++;
				ed_x[top_e]=e[i].x;
				ed_y[top_e]=e[i].y;
			} 
			ans+=e[i].len;
			p++;
		}
		if(p==n) break;
	}
	printf("%lld\n%lld\n",ans,top_b);
	for(ll i=1;i<=top_b;i++) printf("%lld ",build[i]);
	printf("\n%lld\n",top_e);
	for(ll i=1;i<=top_e;i++) printf("%lld %lld\n",ed_x[i],ed_y[i]);
}