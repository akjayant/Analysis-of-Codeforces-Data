#include<bits/stdc++.h>
#define pb push_back
#define pp pop_back()
#define mp make_pair
#define fr first
#define sc second
#define sz size()
#define smin(x,y) ((x)=min((x),(y)))
#define smax(x,y) ((x)=max((x),(y)))
#define all(x) x.begin(),x.end()
#define CS ios_base::sync_with_stdio(false);
#define show(x) cerr << #x << " is " << x <<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
const int M=1e5+5;
vi vec[M];
int mark[M];
set<int> s;
vi adj[M];
vi pak;
int ans;
void merg(int d1,int d2){
	ans--;
	if(vec[d2].sz > vec[d1].sz) swap(d1,d2);
	pak.pb(d2);
	for(auto v : vec[d2]){
		mark[v]=d1;
		vec[d1].pb(v);
	}
	vec[d2].clear();
}
int32_t main()
{
	int n,m; scanf("%d%d",&n,&m); ans=n;
	for(int i=1;i<=n;i++) mark[i]=i,vec[i].pb(i),s.insert(i);
	for(int i=0;i<m;i++){
		int u,v; scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(int i=1;i<=n;i++) sort(all(adj[i]));
	for(int i=1;i<=n;i++){
		pak.clear();
		for(auto p:s){
			if(p==mark[i]) continue;
			for(auto v:vec[p]){
				auto it = lower_bound(all(adj[i]),v);
				bool f=0;
				if(it==adj[i].end() || adj[i][it-adj[i].begin()]!=v) f=1;
				if(f){
					merg(mark[i],p);
					break;
				}
			}
		}
		for(auto p:pak) s.erase(p);
	}
	printf("%d",ans-1);
/*	for(int i=1;i<=n;i++) if(vec[i].sz){
		printf("\n%d ",(int)(vec[i].sz));
		for(auto v:vec[i]) printf("%d ",v);
	}
*/
	return cout<<endl,0;
}
