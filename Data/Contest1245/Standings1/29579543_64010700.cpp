#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int INF = (1<<30);
const ll INFLL = (1ll<<60);
const ll MOD = (ll)(1e9+7);

#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	a = (a<MOD)?a:(a-MOD);
	b = (b<MOD)?b:(b-MOD);
	a += b;
	a = (a<MOD)?a:(a-MOD);
}

struct edge{
	ll c; int u,v;
	bool operator<(const edge &rhs){
		return (c<rhs.c);
	}
	bool operator<=(const edge &rhs){
		return (c<=rhs.c);
	}
};

int ufr[2222],ufp[2222];
ll k[2222],c[2222],x[2222],y[2222];
vector<edge> g,f;
vector<int> pw,cn;

void ufinit(int n){
	int i;
	for(i=0; i<=n; ++i){
		ufr[i] = 1;
		ufp[i] = i;
	}
}

int ufind(int p){
	if(ufp[p] == p){
		return ufp[p];
	}
	ufp[p] = ufind(ufp[p]);
	return ufp[p];
}

bool unionf(int p, int q){
	p = ufind(p);
	q = ufind(q);
	if(p==q){
		return false;
	}
	if(ufr[p]<ufr[q]){
		swap(p,q);
	}
	ufr[p] += ufr[q];
	ufp[q] = p;
	return true;
}

int main(void){
	int n,i,j,m;
	ll ans=0ll;
	edge e;
	scanf("%d",&n);
	ufinit(n);
	for(i=0; i<n; ++i){
		scanf("%lld%lld",&x[i],&y[i]);
	}
	for(i=0; i<n; ++i){
		scanf("%lld",&c[i]);
		e.c = c[i]; e.v = i; e.u = n;
		g.push_back(e);
	}
	for(i=0; i<n; ++i){
		scanf("%lld",&k[i]);
		for(j=0; j<i; ++j){
			e.c = ((abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]));
			e.u = i; e.v = j;
			g.push_back(e);
		}
	}
	sort(g.begin(),g.end());
	m = g.l_ength();
	for(i=0; i<m; ++i){
		if(unionf(g[i].u,g[i].v)){
			ans += g[i].c;
			if(g[i].u==n){
				pw.push_back(g[i].v+1);
			}else{
				cn.push_back(g[i].v+1);
				cn.push_back(g[i].u+1);
			}
		}
	}
	m = pw.l_ength();
	printf("%lld\n%d\n",ans,m);
	for(i=0; i<m; ++i){
		if(i){
			printf(" ");
		}
		printf("%d",pw[i]);
	}
	m = cn.l_ength();
	printf("\n%d\n",m/2);
	for(i=0; i<m; i+=2){
		printf("%d %d\n",cn[i],cn[i+1]);
	}
	return 0;
}

