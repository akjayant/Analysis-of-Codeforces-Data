#include <bits/stdc++.h>
#define for_(i,a,b) for(int i=a;i<b;++i)
#define for__(i,a,b) for(int i=a;i<=b;++i)
#define rof_(i,a,b) for(int i=a;i>b;--i)
#define rof__(i,a,b) for(int i=a;i>=b;--i)
#define ms(a,b) memset((a),(b),sizeof((a)))

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const int MN = 3e3 + 5;
const int P = 1e9 + 7;

int n,x[MN],y[MN],c[MN],k[MN];
//inline hsh(int i){
//	return x[i]*n+y[i];
//}
inline ll d(int a,int b){
	return (ll)abs(x[a]-x[b])+abs(y[a]-y[b]);
}

int rt[MN],tot;
struct ST{
	int x,y;
	ll w;
	bool usd;
	bool operator<(ST r){
		return w<r.w;	//��ȨС������ǰ�� 
	}
}edge[MN*MN];
int get(int x){
	if(rt[x]==x) return x;
	return rt[x]=get(rt[x]);
}
//vector<int> e[MN];

inline void solve(){
	scanf("%d",&n);
	for__(i,0,n) rt[i]=i;
	for_(i,0,n) scanf("%d%d",x+i,y+i);
	for_(i,0,n) scanf("%d",c+i);
	for_(i,0,n) scanf("%d",k+i);
	for_(i,0,n) for_(j,i+1,n) edge[tot++]={i,j,d(i,j)*((ll)k[i]+k[j])};
	for_(i,0,n) edge[tot++]={n,i,c[i]};
	sort(edge,edge+tot);
	
	ll ans=0;
	int cnt=0;
	vector<int>v;
	for_(i,0,tot){
		int x=edge[i].x, y=edge[i].y, rx, ry;
		if((rx=get(x))==(ry=get(y))) continue;
		if(x==n || y==n) v.push_back(x+y-n+1);
		rt[rx]=ry;//rt[min(rx,ry)]=max(rx,ry);
		ans+=edge[i].w;
		if(x!=n) edge[i].usd=1;
		if(cnt>n) break;
	}
	
//for__(i,0,n) printf("r %d: %d\n",i,rt[i]);
	printf("%lld\n",ans);
//	for_(i,0,n) if(get(i)==get(n)) v.push_back(i+1);
	printf("%d\n",v.size());
	for(auto i:v) printf("%d ",i);
//	for_(i,0,n) e[rt[i]+1].push_back(i+1);
//	ans=0;
//	for_(i,0,n) if(rt[i]!=i/* && rt[i]!=rt[n]*/) ++ans;
	printf("\n%d\n",n-v.size());
	for_(i,0,tot) if(edge[i].usd)
		printf("%d %d\n",edge[i].x+1,edge[i].y+1);
}

int main(int argc, char** argv){
//	ios::sync_with_stdio(0);
//	int _; scanf("%d",&_); for_(i,0,_)
		solve();
	
	return 0;
}

