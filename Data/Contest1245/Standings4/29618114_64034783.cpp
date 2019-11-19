#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
using ll = long long;

ll inf = 1e18;

struct S{
	ll x,y;
	ll c;
	ll k;
	int i;
	bool operator<(const S& o)const{
		return c<o.c;
	}
};

const int MN = 2003;

S a[MN];

struct E{
	int u;
	int v;
	ll w;
	bool operator<(const E& o)const{
		return w<o.w;
	}
};

int ufp[MN];
int ufs[MN];
int ufmi[MN];
int find(int a){
	return a==ufp[a]?a:ufp[a]=find(ufp[a]);
}
void unite(int u, int v){
	u=find(u);v=find(v);
	if(u==v)return;
	if(ufs[v]>ufs[u])swap(u,v);
	ufs[u]+=ufs[v];
	ufp[v]=u;
	ufmi[u]=(a[ufmi[u]].c<a[ufmi[v]].c?ufmi[u]:ufmi[v]);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	ll res=0;
	for(int i=0; i<n; ++i){
		cin>>a[i].x>>a[i].y;
		a[i].i=i+1;
		ufp[i]=ufmi[i]=i;
		ufs[i]=1;
	}
	for(int i=0; i<n; ++i){
		cin>>a[i].c;
		res+=a[i].c;
	}
	for(int i=0; i<n; ++i)cin>>a[i].k;
	vector<E> e;
	for(int i=0; i<n; ++i){
		for(int j=0; j<i; ++j){
			e.push_back({i,j,(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y))*(a[i].k+a[j].k)});
		}
	}
	sort(e.begin(),e.end());
	vector<E> rese;
	for(int i=0; i<e.size(); ++i){
		int u=find(e[i].u);
		int v=find(e[i].v);
		if(u==v)continue;
		if(max(a[ufmi[u]].c,a[ufmi[v]].c)>e[i].w){
			res+=e[i].w-max(a[ufmi[u]].c,a[ufmi[v]].c);
			rese.push_back(e[i]);
			unite(u,v);
		}
	}
	vector<int> resv;
	for(int i=0; i<n; ++i){
		if(i==find(i)){
			resv.push_back(ufmi[i]);
		}
	}
	cout<<res<<'\n';
	cout<<resv.size()<<'\n';
	for(auto i:resv)cout<<i+1<<' ';
	cout<<'\n'<<rese.size()<<'\n';
	for(auto i:rese)cout<<i.u+1<<' '<<i.v+1<<'\n';
	return 0;
}
