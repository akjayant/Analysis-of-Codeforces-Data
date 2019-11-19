#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef complex<double> cp;
typedef pair<ll,ll> pll;

const int maxn=(int)2e5+9;
const ll mod=(ll)1e9+7;
const db pi=acos(-1);
const db eps=1e-15;

#define dbg(x) cerr<<#x<<" is "<<x<<endl;

int n;
int vis[2009];
ll dis[2009];
int fa[2009];
ll k[2009];
ll x[2009],y[2009];
struct E{
	ll v,u,c;
	E(){
		v=0;
		u=0;
		c=0;
	}
};
E e[2009*2009];
int op;
int ord[2009*2009];
int bcj[2009];

void init(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&x[i],&y[i]);
	}
	for(int i=1;i<=n;i++){
		ll tmp;
		scanf("%lld",&tmp);
		e[op].u=0;
		e[op].v=i;
		e[op].c=tmp;
		op++;
	}
	for(int i=1;i<=n;i++){
		bcj[i]=i;
		scanf("%lld",&k[i]);
	}
}

int cmp(int a,int b){
	if(e[a].c!=e[b].c)return e[a].c<e[b].c;
	else if(e[a].v!=e[b].v)return e[a].v<e[b].v;
	return e[a].u<e[b].u;
}

int fd(int h){
	if(bcj[h]==h)return h;
	return bcj[h]=fd(bcj[h]);
}

int main(){
	op=0;
	init();
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ll tmp=(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
			e[op].u=j;
			e[op].v=i;
			e[op].c=tmp;
			op++;
		}
	}
	for(int i=0;i<op;i++){
		ord[i]=i;
	}
	sort(ord,ord+op,cmp);
	ll cst=0;
	vector<int>cp;
	vector<pll>sp;
	cp.clear();
	sp.clear();
	for(int i=0;i<op;i++){
		int l=ord[i];
		int p=fd(e[l].u),q=fd(e[l].v);
		if(p==q)continue;
		bcj[p]=q;
		if(e[l].u&&e[l].v){
			sp.push_back({e[l].u,e[l].v});
		}else if(e[l].u){
			cp.push_back(e[l].u);
		}else{
			cp.push_back(e[l].v);
		}
		cst+=e[l].c;
	}
	printf("%lld\n",cst);
	printf("%ld\n",cp.size());
	for(int i:cp){
		printf("%d ",i);
	}
	printf("\n");
	printf("%ld\n",sp.size());
	for(auto x:sp){
		printf("%lld %lld\n",x.first,x.second);
	}
	return 0;
}

