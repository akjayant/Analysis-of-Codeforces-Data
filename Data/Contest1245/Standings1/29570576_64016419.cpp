#include<cstdio>
#include<cstring>
#include<cassert>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define fo(i,l,r) for (auto i=l,_end=r;i<=_end;++i)
#define fd(i,l,r) for (auto i=l,_end=r;i>=_end;--i)
#define FI(x) freopen(x,"r",stdin)
#define FO(x) freopen(x,"w",stdout)
using ll=long long;
using namespace std;

using Edge=tuple<ll,int,int>;


const int N=2048;
int n,f[N];
ll c[N],k[N],x[N],y[N];

Edge e[N*N];

vector<int> ans1;
vector<pair<int,int>> ans2;

int gf(int x) {
	return f[x]==x?x:f[x]=gf(f[x]);
}

bool un(int x,int y) {
	int fx=gf(x), fy=gf(y);
	if (fx==fy) return 0;
	f[fx]=fy;
	return 1;
}

int main() {
	scanf("%d",&n);
	fo(i,1,n) f[i]=i;
	fo(i,1,n) scanf("%lld%lld",x+i,y+i);
	fo(i,1,n) scanf("%lld",c+i);
	fo(i,1,n) scanf("%lld",k+i);
	int m=0;
	fo(i,1,n) e[m++]=Edge{c[i],0,i};
	fo(u,1,n) fo(v,u+1,n) e[m++]=Edge{(k[u]+k[v])*(llabs(x[u]-x[v])+llabs(y[u]-y[v])),u,v};
	sort(e,e+m);
	ll ans=0;
	fo(i,0,m-1) {
		auto &u=get<1>(e[i]),&v=get<2>(e[i]);
		if (un(u,v)) {
			ans+=get<0>(e[i]);
			if (u) ans2.push_back({u,v});
			else ans1.push_back(v);
		}
	}
	printf("%lld\n%d\n",ans,int(ans1.size()));
	for (auto v:ans1) printf("%d ",v);
	printf("\n%d\n",int(ans2.size()));
	for (auto &e:ans2) printf("%d %d\n",e.first,e.second);
}


