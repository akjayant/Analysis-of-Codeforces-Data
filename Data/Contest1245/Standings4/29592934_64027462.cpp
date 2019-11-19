#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

typedef long long ll;

struct edge{
	int u,v;
	ll w;
};

vector<pair<int,ll>> g[2005];

int par[2005],sz[2005];

bool d[2005]={};
int cur=0;

int root(int u){
	if(par[u]==u){
		return u;
	}
	return par[u]=root(par[u]);
}

int main(){
	int n; cin >> n;
	vector<pair<int,int>> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i].fi >> a[i].se;
	}
	vector<int> c(n),k(n);
	vector<edge> e;
	for(int i=0;i<n;i++){
		cin >> c[i];
		e.push_back({i,n,c[i]});
	}
	for(int i=0;i<n;i++){
		cin >> k[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(j!=i){
				e.push_back({i,j,1ll*(k[i]+k[j])*(abs(a[i].fi-a[j].fi)+abs(a[i].se-a[j].se))});
			}
		}
	}
	for(int i=0;i<=n;i++){
		par[i]=i;
		sz[i]=1;
	}
	d[n]=1;
	sort(e.begin(),e.end(),[](edge &p, edge &q){
		return p.w<q.w;
	});
	vector<int> st;
	vector<pair<int,int>> cn;
	ll ans=0;
	for(int i=0;i<e.size();i++){
		if(cur==n){
			break;
		}
		int ru=root(e[i].u),rv=root(e[i].v);
		if(ru==rv){
			continue;
		}
		ans+=e[i].w;
		if(e[i].v==n){
			st.push_back(e[i].u+1);
		}
		else{
			cn.push_back({e[i].u+1,e[i].v+1});
		}
		if(d[ru] || d[rv]){
			if(!d[ru]){
				cur+=sz[ru];
			}
			else if(!d[rv]){
				cur+=sz[rv];
			}
			d[ru]=1;
			d[rv]=1;
		}
		if(sz[ru]>sz[rv]){
			par[rv]=ru;
			sz[ru]+=sz[rv];
		}
		else{
			par[ru]=rv;
			sz[rv]+=sz[ru];		
		}	
	}
	cout << ans << endl;
	cout << st.size() << endl;
	for(auto val:st){
		cout << val  << " ";
	}
	cout << endl;
	cout << cn.size() << endl;
	for(auto val:cn){
		cout << val.fi << " " << val.se << endl;
	}
	return 0;
}