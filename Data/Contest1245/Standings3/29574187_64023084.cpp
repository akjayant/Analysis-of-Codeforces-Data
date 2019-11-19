#include<cstdio>
#include<cmath> 
#include<algorithm>
using std::sort;
typedef long long ll;
const int N=2005;
struct P{
	int x,y;
	void in(){
		scanf("%d%d",&x,&y);
	}
}p[N];
ll c[N],k[N],ans=0;
int anc[N],s,s1,s2,j1[N],j2[N*N<<1];
struct E{
	int u,v;
	ll q;
	bool operator<(const E t)const{
		return q<t.q;
	}
}e[N*N<<1];
int dis(P p1,P p2){
	return abs(p1.x-p2.x)+abs(p1.y-p2.y); 
}
int fi(int a){
	if(anc[a]==a) return a;
	return anc[a]=fi(anc[a]);
}
void add(int u,int v,ll q){
	e[++s].u=u;
	e[s].v=v;
	e[s].q=q;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) p[i].in();
	for(int i=1;i<=n;++i) scanf("%lld",&c[i]);
	for(int i=1;i<=n;++i) scanf("%lld",&k[i]);
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			add(i,j,(k[i]+k[j])*dis(p[i],p[j]));
	++n;
	for(int i=1;i<n;++i) add(i,n,c[i]);
	for(int i=1;i<=n;++i) anc[i]=i;
	sort(e+1,e+s+1);
	for(int i=1,j=0;j<n-1;++i){
		int tu=fi(e[i].u),tv=fi(e[i].v);
		if(tu!=tv){
			anc[tu]=tv,++j,ans+=e[i].q;
			if(e[i].v==n) j1[++s1]=e[i].u;
			else j2[++s2]=i;
		}
	}
	printf("%lld\n%d\n",ans,s1);
	for(int i=1;i<=s1;++i) printf("%d ",j1[i]);
	printf("\n%d\n",s2);
	for(int i=1;i<=s2;++i) printf("%d %d\n",e[j2[i]].u,e[j2[i]].v);
	return 0;
}