#include <bits/stdc++.h>

using namespace std;
const int maxn=2e3+5;
typedef long long ll;
int n;
typedef pair<int,int> pii;
int vis[maxn];
struct node{
	ll cost;
	int idu,idv;
	bool operator<(const node a) const{
		return cost>a.cost;
	}
};
int f[maxn],cnt;
ll cost[maxn];
int x[maxn],y[maxn],c[maxn],k[maxn],who[maxn];
priority_queue<node>Q;
ll get(int u,int v){
	return 1ll*(k[u]+k[v])*(abs(x[u]-x[v])+abs(y[u]-y[v]));
}
int getfa(int w){
	if (f[w]==w) return w;
	return f[w]=getfa(f[w]);
}
long long ans;
vector<pii>pp;
int main(){
	cin >> n;
	for (int i=1;i<=n;i++)
		cin >> x[i] >> y[i];
	for (int i=1;i<=n;i++)
		cin >> c[i];
	for (int i=1;i<=n;i++)
		f[i]=who[i]=i;
	for (int i=1;i<=n;i++)
		cin >> k[i];
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			node p={get(i,j),i,j};
			Q.push(p);			
		}
	}
	
	while (!Q.empty()){
		node p=Q.top();Q.pop();
		int fu=getfa(p.idu);
		int fv=getfa(p.idv);
		if (f[p.idu]==f[p.idv]) continue;
		int mx=max(c[fu],c[fv]);
		if (p.cost<=mx){
			if (c[fv]<c[fu])
				who[fu]=who[fv];
			c[fu]=min(c[fu],c[fv]);
			f[fv]=fu;
			pp.push_back({p.idu,p.idv});
			ans+=p.cost;
		}
	}
	for (int i=1;i<=n;i++){
		getfa(i);
		if (f[i]==i){
			cnt++;
			ans+=c[i];
		}
		
	}
	cout << ans << '\n' << cnt << '\n';
	for (int i=1;i<=n;i++){
		if (f[i]==i){
			cout << who[i] << ' ';
		}
	}
	cout << '\n' << pp.size() << '\n';
	for (auto i:pp){
		cout << i.first << ' ' << i.second << '\n';
	}
}