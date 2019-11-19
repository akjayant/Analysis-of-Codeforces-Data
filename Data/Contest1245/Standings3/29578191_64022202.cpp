#include <bits/stdc++.h>
 
using namespace std;
typedef long long LL;
typedef pair<int,int>pa;
priority_queue<pa,vector<pa>, greater<pa> >q;

int n,m;
const int N=2010;
const LL mod=1000000007;
int x[N],y[N];
LL c[N],p[N];
int f[N];

int fa[N];LL mn[N],sum[N];
int findf(int x){
	if(fa[x]!=x)fa[x]=findf(fa[x]);
	return fa[x];
}

void uni(int x,int y){
	x=findf(x);y=findf(y);
	if(mn[x]<mn[y])swap(x,y);
	fa[x]=y;mn[y]=min(mn[y],mn[x]);
	sum[y]+=sum[x];
}

LL _abs(int x){
	return x>0?x:-x;
}

LL calc(LL a,LL b){
	return 1LL*(p[a]+p[b])*(_abs(x[a]-x[b])+_abs(y[a]-y[b]));
}

struct edge{
	int a,b;LL w;
	edge(int _a=0,int _b=0,LL _w=0){
		a=_a;b=_b;w=_w;
	}
	bool operator <(const edge &e)const{
		return w<e.w;
	}
}E[N*N];



int main(){
#ifdef WK
	freopen("in.txt","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&p[i]);
	LL ans=0;
	
	for(int i=1;i<=n;i++)fa[i]=i,mn[i]=c[i],sum[i]=c[i];
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			E[++m]=edge(i,j,calc(i,j));
		}
	}
	
	sort(E+1,E+1+m);
	
	vector<edge>v;
	for(int i=1;i<=n;i++)ans+=c[i];
	
	for(int i=1;i<=m;i++){
		if(findf(E[i].a)==findf(E[i].b))continue;
		int xx=findf(E[i].a),yy=findf(E[i].b);
		LL sum1=sum[xx],sum2=sum[yy];
		LL mn1=mn[xx],mn2=mn[yy];
		if(mn1>mn2)swap(mn1,mn2);
		if(E[i].w<mn2){
			uni(xx,yy);
			ans-=mn2-E[i].w;
			v.push_back(E[i]);
		} 
	}
	
	
	printf("%lld\n",ans);
	int cnt=0;
	for(int i=1;i<=n;i++)if(fa[i]==i)cnt++;
	printf("%d\n",cnt);
	for(int i=1;i<=n;i++)if(fa[i]==i)printf("%d ",i);
	printf("\n%d\n",v.size());
	for(int i=0,sz=v.size();i<sz;i++)printf("%d %d\n",v[i].a,v[i].b);
	return 0; 
} 