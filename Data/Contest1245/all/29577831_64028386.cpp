#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<stack>
#include<vector>
#include<deque>
#include<climits>

#define mem(a) memset((a),0,sizeof((a)));
#define mod 1000000007
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define tv t[p].val
#define tl t[p].l
#define tr t[p].r
#define eps 1e-5
#define maxa 4000005
using namespace std;

long long read(){
	long long xyz135=0,paage46=1;
	char cc1=getchar();
	while(cc1>'9'||cc1<'0'){
		if(cc1=='-')paage46=-1;
		cc1=getchar();
	}
	while(cc1>='0'&&cc1<='9'){
		xyz135=xyz135*10+cc1-'0';
		cc1=getchar();
	}
	return xyz135*paage46;
}
inline void read(long long &x){
	x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=((x<<1)+(x<<3))+c-'0';
		c=getchar();
	}
	return ;
}
inline void w1(long long x){
	if(x){
		w1(x/10);
		putchar(x%10+48);
	}
	return ;
}
inline void write(long long x){
	if(x)w1(x);
	else putchar('0');
	return ;
}
struct node{
	long long u,v,val;
}c[maxa];long long top;
struct dd{
	long long val,xu;
}d[maxa];
bool cmp(node x,node y){
	return x.val<y.val;
}
bool cmp1(dd x,dd y){
	return x.val<y.val;
}
long long fa[maxa];
long long get(long long x){return x==fa[x]?x:fa[x]=get(fa[x]);}
void merge(long long x,long long y){fa[get(x)]=get(y);return ;}
void psh(long long u,long long v,long long va){
	c[++top].u=u;c[top].v=v;c[top].val=va;
	c[++top].v=u;c[top].u=v;c[top].val=va;
	return ;
}
long long n;
long long b[maxa];
int x[maxa],y[maxa];
long long ans,cnt;bool vis[maxa];
long long t1,t2;
void prim(){
	sort(c+1,c+top+1,cmp);
	sort(d+1,d+n+1,cmp1);
	long long p1=2,p2=1;//点，边
	cnt++;vis[d[1].xu]=1;
	ans+=d[1].val;
	b[++t1]=d[1].xu;
	while(cnt<n){
		if(d[p1].val<=c[p2].val){
			if(vis[get(d[p1].xu)]==1){
				p1++;
				continue;
			}
			b[++t1]=d[p1].xu;
			vis[get(d[p1].xu)]=1;
			ans+=d[p1].val;
			p1++;
		}
		else{
			if((vis[get(c[p2].u)]==1&&vis[get(c[p2].v)]==1)||(get(c[p2].u)==get(c[p2].v))){
				p2++;
				continue;
			}
			ans+=c[p2].val;
			if(vis[get(c[p2].u)])fa[get(c[p2].v)]=get(c[p2].u);
			else fa[get(c[p2].u)]=get(c[p2].v);
			c[++t2]=c[p2];
			p2++;
		}
		cnt++;
	}
	return ;
}
main(){
	cin>>n;
	for(long long i=1;i<=n;i++)cin>>x[i]>>y[i],fa[i]=i;
	for(long long i=1;i<=n;i++)cin>>d[i].val,d[i].xu=i;
	for(long long i=1;i<=n;i++)cin>>b[i];
	for(long long i=1;i<=n;i++)for(long long j=i+1;j<=n;j++){
		psh(i,j,(abs(x[i]-x[j])+abs(y[i]-y[j]))*(b[i]+b[j]));
		if(x[i]==x[j]&&y[i]==y[j])merge(i,j),cnt++;
	}
	prim();
	cout<<ans<<endl;
	cout<<t1<<endl;
	for(long long i=1;i<=t1;i++)cout<<b[i]<<" ";cout<<endl;
	cout<<t2<<endl;
	for(long long i=1;i<=t2;i++)cout<<c[i].u<<" "<<c[i].v<<endl;
	return 0;
}