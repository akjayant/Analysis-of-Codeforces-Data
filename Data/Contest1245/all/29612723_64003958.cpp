#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n;
vector<int>adj[2002];
ll x[2002],y[2002],c[2002],k[2002];
int par[2002];
int find(int x){
	if(par[x]!=x) par[x]=find(par[x]);
	return par[x];
}
ll ans=0;
vector<int>ax,ay,az;
void join(int x,int y,ll z){
	int px=x,py=y;
	x=find(x);y=find(y);
	if(x!=y) par[x]=y,ans+=z;
	else return;
	if(py==n+1) ax.push_back(px);
	else ay.push_back(px),az.push_back(py);
}
vector<pair<ll,pair<int,int> > >v;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++) cin >> x[i] >> y[i];
	for(int i=1; i<=n ;i++) cin >> c[i];
	for(int i=1; i<=n ;i++) cin >> k[i];
	for(int i=1; i<=n ;i++){
		for(int j=i+1; j<=n ;j++){
			v.push_back({(k[i]+k[j])*(abs(x[j]-x[i])+abs(y[j]-y[i])),{i,j}});
		}
		v.push_back({c[i],{i,n+1}});
		par[i]=i;
	}
	par[n+1]=n+1;sort(v.begin(),v.end());
	for(auto cur:v){
		join(cur.se.fi,cur.se.se,cur.fi);
	}
	cout << ans << '\n';
	cout << ax.size() << '\n';
	for(auto cur:ax) cout << cur << ' ';
	cout << '\n';
	cout << ay.size() << '\n';
	for(int i=0; i<ay.size() ;i++){
		cout << ay[i] << ' ' << az[i] << '\n';
	} 
}