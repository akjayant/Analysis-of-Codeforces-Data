#include<bits/stdc++.h>
using namespace std;
#define maxn 4000500
#define ll long long
#define cin(x) scanf("%d",&x)
#define cout(x) printf("%d\n",x)
#define rep(i,k,n) for(ll i=k;i<=n;i++)
#define mst(a,k) memset(a,k,sizeof(a));
const ll INF = 1e12 + 5;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
inline void write(int x){
	char c[20];int l=0;
	while(x) c[++l]=x%10+48,x/=10;
	while(l) putchar(c[l--]);
	putchar('\n');
}
struct node{
	int x,y,c,k;
}a[maxn];
struct Edges{
	int u,v;
	ll w;
}edge[maxn]; 
int fa[maxn],cnt=1;
ll cost;
bool cmp(Edges a,Edges b){
	return a.w<b.w;
}
int n,z,ans[maxn][2],anslen,t;
void link(int u,int v,ll w){
	edge[++z].u=u;
	edge[z].v=v;
	edge[z].w=w;
}
ll dist(int a,int b,int c,int d){
	return (ll)abs(a-c)+(ll)abs(b-d);
}
int find(int x){
	return fa[x]==x?x:find(fa[x]);
}
void kruskal(){
	sort(edge+1,edge+1+z,cmp);
	for(int i=1;i<=z;i++){
		int u=find(edge[i].u),v=find(edge[i].v);
		if(u!=v){
			cost+=edge[i].w;
			fa[u]=v;
			ans[++anslen][0]=edge[i].u;
			ans[anslen][1]=edge[i].v;
			if(ans[anslen][0]==(n+1)||ans[anslen][1]==(n+1)){
				t++;
			}
			if(++cnt==n+1){
			return;	
			}
		}
	} 
	return;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	rep(i,1,n) scanf("%d",&a[i].c);
	rep(i,1,n) scanf("%d",&a[i].k);
	rep(i,1,n+1) fa[i]=i;
	rep(i,1,n)
		rep(j,i+1,n){
			ll co=dist(a[i].x,a[i].y,a[j].x,a[j].y)*(ll)(a[i].k+a[j].k);
			link(i,j,co);
		}
	rep(i,1,n){
		link(i,n+1,a[i].c);
	}
	kruskal();
	printf("%lld\n%d\n",cost,t);
	rep(i,1,anslen){
		if(ans[i][0]==n+1){
			printf("%d ",ans[i][1]);
		}
		else if(ans[i][1]==n+1){
			printf("%d ",ans[i][0]);
		}
	}
	printf("\n%d\n",anslen-t);
	rep(i,1,anslen){
		if(ans[i][0]!=n+1&&ans[i][1]!=n+1){
			printf("%d %d\n",ans[i][0],ans[i][1]);
		}
	}
	return 0;
}
/*
3
2 3
1 1
3 2
3 2 3
3 2 3
*/