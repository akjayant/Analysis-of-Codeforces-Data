#pragma GCC optimize(2)
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
#include <queue>
using namespace std;
const int maxn=1e5+5;
typedef long long ll;
ll n,m,cnt,vis[maxn];
set<ll> adj[maxn],lef;
set<ll>::iterator p;
void bfs(int u){
	queue<ll> q;
	q.push(u);
	lef.erase(u);
	vis[u]=1;
	while(!q.empty()){
		ll t=q.front();
		q.pop();
		for (p=lef.begin();p!=lef.end();){
			ll tp=(*p);
			if (adj[t].count(tp)){
				p++;
				continue;
			}
			vis[tp]=1;
			q.push(tp);
			lef.erase(p++);
		}
	}
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		ll u,v;
		scanf("%lld%lld",&u,&v);
		adj[u].insert(v);
		adj[v].insert(u);
	}
	for (int i=1;i<=n;i++) lef.insert(i);
	ll ans=0;
	for (int i=1;i<=n;i++){
		if (vis[i]) continue;
		bfs(i);
		ans++;
	}
	cout<<ans-1<<endl;
}