#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
typedef struct{
	ll u, v, dis;
} node;
 
bool cmp(node a, node b){
	return a.dis<b.dis;
}
 
const ll N = 2e3+5, mod=1e9+7;
ll n, x[N], y[N], c[N], k[N], f[N];
vector<node> edges;
vector<int> aa, bb, cc;
 
int find(int x){
	return f[x] = (f[x]==x ? x : find(f[x]));
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n; f[0] = 0;
	for (int i = 1; i <= n; i++){
		cin>>x[i]>>y[i]; f[i] = i;
	}
	for (int i = 1; i <= n; i++){
		cin>>c[i]; 	
	}
	for(int i=1;i<=n;i++){
		edges.push_back((node){0, i, c[i]});
	}
	for (int i = 1; i <= n; i++){
		cin>>k[i];
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if(i==j) continue;
			edges.push_back((node){i, j, (k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]))});		
		}
	}
	sort(edges.begin(), edges.end(), cmp);
	ll ans = 0;
	for (int i = 0; i < edges.size(); i++){
		ll fu = find(edges[i].u), fv = find(edges[i].v);
		if (fu != fv){
			ans += edges[i].dis;
			f[fu] = fv;
			if (edges[i].u==0 || edges[i].v==0){
				aa.push_back(edges[i].u+edges[i].v);
			}
			else{
				bb.push_back(edges[i].u);
				cc.push_back(edges[i].v);
			}
		}
	}
	cout<<ans<<"\n";
	cout<<aa.size()<<"\n";
	if (aa.size()){
		for (int i = 0; i < aa.size(); i++){
			cout<<aa[i]<<" ";
		}
		cout<<"\n";	
	}
	cout<<bb.size()<<"\n";
	if (bb.size()){
		for(int i = 0; i < bb.size(); i++){
			cout<<bb[i]<<" "<<cc[i]<<"\n";
		}
	}
    return 0;
}